#ifndef PRIV_H_GUARD
#define PRIV_H_GUARD

#ifdef __cplusplus
extern "C" {
#endif

#include "amatrix.h"
#include "glbopts.h"
#include "linAlg.h"
#include "scs.h"

struct scs_private_data {
  scs_float total_solve_time;
};

/*hack to marry scs and superscs*/
typedef ScsPrivWorkspace ScsLinSysWork;

#ifdef __cplusplus
}
#endif
#endif
