/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_scs_IndirectSolver */

#ifndef _Included_org_scs_IndirectSolver
#define _Included_org_scs_IndirectSolver
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_scs_IndirectSolver
 * Method:    csolve
 * Signature: (Lorg/scs/AMatrix;[D[DLorg/scs/Cone;Lorg/scs/Settings;Lorg/scs/Solution;Lorg/scs/Info;)V
 */
JNIEXPORT void JNICALL Java_org_scs_IndirectSolver_csolve
  (JNIEnv *, jclass, jobject, jdoubleArray, jdoubleArray, jobject, jobject, jobject, jobject);

/*
 * Class:     org_scs_IndirectSolver
 * Method:    cversion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_scs_IndirectSolver_cversion
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif