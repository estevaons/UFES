#ifndef GENERICD_H
#define GENERICD_H

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE double
#define TYPED(THING) THING ## _D
#define TIPO "lf"

#include "complexo.h"

#undef TYPE
#undef TYPED
#undef TIPO

#endif