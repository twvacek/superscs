#include <Python.h>
#include "numpy/arrayobject.h"
#include "private.h"

#define SCS_LINSYS_STRING_LENGTH 128

// The following are shared with scsmodule.c, which
// sets the callbacks and defines helper functions.
extern PyObject *scs_init_lin_sys_work_cb;
extern PyObject *scs_solve_lin_sys_cb;
extern PyObject *scs_accum_by_a_cb;
extern PyObject *scs_accum_by_atrans_cb;
extern PyObject *scs_normalize_a_cb;
extern PyObject *scs_un_normalize_a_cb;

extern int getFloatType(void);
extern int getIntType(void);
extern PyArrayObject *getContiguous(PyArrayObject *array, int typenum);

scs_int scs_validate_linsys(
            const ScsAMatrix *A){
  return 0;
}

char *scs_get_linsys_method(const ScsAMatrix *A, const ScsSettings *stgs) {
  char *str = (char *)scs_malloc(sizeof(char) * 128);
  snprintf(str, SCS_LINSYS_STRING_LENGTH, "Python");
  return str;
}

char *scs_get_linsys_summary(ScsLinSysWork *p, const ScsInfo *info) {
  char *str = (char *)scs_malloc(sizeof(char) * 128);
  snprintf(str, SCS_LINSYS_STRING_LENGTH,
          "\tLin-sys: avg solve time: %1.2es\n",
          p->total_solve_time / (info->iter + 1) / 1e3);
  p->total_solve_time = 0;
  return str;
}

scs_int scs_linsys_is_indirect(void){
  return 0;
}

scs_int scs_linsys_total_cg_iters(ScsPrivWorkspace *priv){
  return (scs_int) -1;
}

scs_float scs_linsys_total_solve_time_ms(ScsPrivWorkspace *priv){
  return priv->total_solve_time; 
}

void scs_free_priv(ScsPrivWorkspace *p) {
  if (p) {
    scs_free(p);
  }
}

void scs_accum_by_atrans(const ScsAMatrix *A, ScsLinSysWork *p,
                          const scs_float *x, scs_float *y) {
  int scs_float_type = getFloatType();

  npy_intp veclen[1];
  veclen[0] = A->m;
  PyObject *x_np = PyArray_SimpleNewFromData(1, veclen, scs_float_type, (void *)x);

  veclen[0] = A->n;
  PyObject *y_np = PyArray_SimpleNewFromData(1, veclen, scs_float_type, y);

  // TODO: Should we not let numpy own the data since we're just
  // using this in a callback?
  PyArray_ENABLEFLAGS((PyArrayObject *)x_np, NPY_ARRAY_OWNDATA);
  PyArray_ENABLEFLAGS((PyArrayObject *)y_np, NPY_ARRAY_OWNDATA);

  PyObject *arglist = Py_BuildValue("(OO)", x_np, y_np);
  PyObject_CallObject(scs_accum_by_atrans_cb, arglist);
  Py_DECREF(arglist);
}

void scs_accum_by_a(const ScsAMatrix *A, ScsLinSysWork *p, const scs_float *x,
                     scs_float *y) {
  int scs_float_type = getFloatType();

  npy_intp veclen[1];
  veclen[0] = A->n;
  PyObject *x_np = PyArray_SimpleNewFromData(1, veclen, scs_float_type, (void *)x);

  veclen[0] = A->m;
  PyObject *y_np = PyArray_SimpleNewFromData(1, veclen, scs_float_type, y);

  // TODO: Should we not let numpy own the data since we're just
  // using this in a callback?
  PyArray_ENABLEFLAGS((PyArrayObject *)x_np, NPY_ARRAY_OWNDATA);
  PyArray_ENABLEFLAGS((PyArrayObject *)y_np, NPY_ARRAY_OWNDATA);

  PyObject *arglist = Py_BuildValue("(OO)", x_np, y_np);
  PyObject_CallObject(scs_accum_by_a_cb, arglist);
  Py_DECREF(arglist);
}

ScsLinSysWork *scs_init_priv(const ScsAMatrix *A,
                                      const ScsSettings *stgs) {
  _import_array();

  ScsLinSysWork *p = (ScsLinSysWork *)scs_calloc(1, sizeof(ScsLinSysWork));
  p->total_solve_time = 0;

#ifdef SFLOAT
  PyObject *arglist = Py_BuildValue("(f)", stgs->rho_x);
#else
  PyObject *arglist = Py_BuildValue("(d)", stgs->rho_x);
#endif
  PyObject_CallObject(scs_init_lin_sys_work_cb, arglist);
  Py_DECREF(arglist);

  return p;
}

scs_int scs_solve_lin_sys(const ScsAMatrix *A, const ScsSettings *stgs,
                           ScsLinSysWork *p, scs_float *b, const scs_float *s,
                           scs_int iter) {
  ScsTimer linsys_timer;
  scs_tic(&linsys_timer);

  npy_intp veclen[1];
  veclen[0] = A->n + A->m;
  int scs_float_type = getFloatType();
  PyObject *b_py = PyArray_SimpleNewFromData(1, veclen, scs_float_type, b);
  PyArray_ENABLEFLAGS((PyArrayObject *)b_py, NPY_ARRAY_OWNDATA);

  PyObject *s_py = Py_None;
  if (s) {
    s_py = PyArray_SimpleNewFromData(1, veclen, scs_float_type, (void *)s);
    PyArray_ENABLEFLAGS((PyArrayObject *)s_py, NPY_ARRAY_OWNDATA);
  }

  PyObject *arglist = Py_BuildValue("(OOi)", b_py, s_py, iter);
  PyObject_CallObject(scs_solve_lin_sys_cb, arglist);
  Py_DECREF(arglist);

  p->total_solve_time += scs_toc_quiet(&linsys_timer);
  return 0;
}


void scs_normalize_a(ScsAMatrix *A, const ScsSettings *stgs,
                      const ScsCone *k, ScsScaling *scal) {
  _import_array();

  int scs_int_type = getIntType();
  int scs_float_type = getFloatType();

  scs_int *boundaries;
  npy_intp veclen[1];
  veclen[0] = scs_get_cone_boundaries(k, &boundaries);
  PyObject *boundaries_py = PyArray_SimpleNewFromData(
    1, veclen, scs_int_type, boundaries);
  PyArray_ENABLEFLAGS((PyArrayObject *)boundaries_py, NPY_ARRAY_OWNDATA);

#ifdef SFLOAT
  PyObject *arglist = Py_BuildValue("(Of)", boundaries_py, stgs->scale);
#else
  PyObject *arglist = Py_BuildValue("(Od)", boundaries_py, stgs->scale);
#endif
  PyObject *result = PyObject_CallObject(scs_normalize_a_cb, arglist);
  Py_DECREF(arglist);
  scs_free(boundaries);

#ifdef SFLOAT
  char *argparse_string = "O!O!ff";
#else
  char *argparse_string = "O!O!dd";
#endif

  PyArrayObject *D_py = SCS_NULL;
  PyArrayObject *E_py = SCS_NULL;
  PyArg_ParseTuple(result, argparse_string, &PyArray_Type, &D_py,
                   &PyArray_Type, &E_py,
                   &scal->meanNormRowA, &scal->meanNormColA);

  D_py = getContiguous(D_py, scs_float_type);
  E_py = getContiguous(E_py, scs_float_type);

  scal->D = (scs_float *)PyArray_DATA(D_py);
  scal->E = (scs_float *)PyArray_DATA(E_py);
}


void scs_un_normalize_a(ScsAMatrix *A, const ScsSettings *stgs,
                         const ScsScaling *scal) {
  int scs_float_type = getFloatType();

  npy_intp veclen[1];
  veclen[0] = A->m;
  PyObject *D_py = PyArray_SimpleNewFromData(1, veclen,
                                             scs_float_type, scal->D);
  PyArray_ENABLEFLAGS((PyArrayObject *)D_py, NPY_ARRAY_OWNDATA);

  veclen[0] = A->n;
  PyObject *E_py = PyArray_SimpleNewFromData(1, veclen,
                                             scs_float_type, scal->E);
  PyArray_ENABLEFLAGS((PyArrayObject *)E_py, NPY_ARRAY_OWNDATA);


#ifdef SFLOAT
  PyObject *arglist = Py_BuildValue("(OOf)", D_py, E_py, stgs->scale);
#else
  PyObject *arglist = Py_BuildValue("(OOd)", D_py, E_py, stgs->scale);
#endif
  PyObject_CallObject(scs_un_normalize_a_cb, arglist);
  Py_DECREF(arglist);
}
