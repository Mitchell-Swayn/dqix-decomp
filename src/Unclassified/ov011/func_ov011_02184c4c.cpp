#include <globaldefs.h>
struct Argument { unsigned kind; int value; };
extern "C" float _fflt(int);
// Original: arm9/ov011 @ 0x02184C4C; symbol: func_ov011_02184c4c; size: 0x1C.
extern "C" float func_ov011_02184c4c(Argument* self) { unsigned kind=self->kind; int value=self->value; if(kind==0) return _fflt(value); return *(float*)&self->value; }
