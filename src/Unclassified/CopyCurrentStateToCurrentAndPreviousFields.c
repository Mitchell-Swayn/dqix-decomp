#include <globaldefs.h>
typedef struct { unsigned words[10]; } Block; typedef struct {unsigned a,b;} Pair;
typedef struct {Block before,state;unsigned a,b;Pair current,previous;unsigned c,d;} Object;
// Original: arm9/main @ 0x0207DFC8; symbol: func_0207dfc8; size: 0x98.
void CopyCurrentStateToCurrentAndPreviousFields(const Object *src,Object *dst) {dst->before=src->state;dst->state=src->state;dst->b=src->b;dst->a=src->a;dst->current=src->previous;dst->previous=src->previous;dst->d=src->d;dst->c=src->c;}
