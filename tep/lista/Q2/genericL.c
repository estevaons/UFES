#include "genericL.h"


#undef TYPE
#undef TYPED
#undef TIPO

#define TYPE long double
#define TYPED(THING) THING ## _Ld
#define TIPO "Lf"

#include "complexo.c"

#undef TYPE
#undef TYPED
#undef TIPO