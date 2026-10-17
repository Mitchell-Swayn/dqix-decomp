#include <globaldefs.h>
#include <World/Object3D.h>
struct Flag { unsigned char blocked:1; unsigned char rest:7; };
// Original: arm9/main @ 0x02041538; symbol: func_02041538; size: 0x60.
extern "C" ARM void Object3D_ApplyPendingNamedOrIndexedAnimation(Object3D* self) { unsigned char* bytes=(unsigned char*)self; if(((Flag*)(bytes+212))->blocked)return; *(unsigned short*)(bytes+172)&=~1; const char* animation=*(const char**)(bytes+204); if(animation) { if(*(const char**)(bytes+20)==animation)return; self->MaybeSetRegularAnimation(animation,*(int*)(bytes+208)); }else { int index=bytes[196]; if(index==*(signed char*)(bytes+24))return; self->MaybeSetBCFGAnimation(index,*(int*)(bytes+208)); } }
