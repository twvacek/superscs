#ifndef PRIV_H_GUARD
#define PRIV_H_GUARD

#include "glbopts.h"
#include "scs.h"
#include "../common.h"

struct PRIVATE_DATA{
	pfloat * p;
	pfloat * r;
	pfloat * Gp;
	pfloat * M; /* pre-conditioner */
	pfloat * z;
  /* Gram matrix */
	pfloat * G;
};

#endif
