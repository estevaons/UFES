#include "genericD.h"

#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE double
#define TYPED(THING) THING ## _D
#define TIPO "lf"


#include "complexo.c"

#undef TYPE
#undef TYPED
#undef TIPO