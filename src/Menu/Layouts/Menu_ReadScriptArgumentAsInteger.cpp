#include <globaldefs.h>
struct Argument { unsigned kind; float value; };
extern "C" int _ffix(float);
// Original: arm9/ov011 @ 0x02184C30; symbol: func_ov011_02184c30; size: 0x1C.
extern "C" int Menu_ReadScriptArgumentAsInteger(Argument* self) { unsigned kind=self->kind; float value=self->value; if(kind==1) return _ffix(value); return *(int*)&self->value; }
