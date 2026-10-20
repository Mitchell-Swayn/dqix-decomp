#include <globaldefs.h>
#include <System/Matrix.h>
extern "C" long long FX_SinFx64c(int);
extern "C" float _ll_sto_f(long long);
struct Object {unsigned first;unsigned char flag;char pad5[11];int value;char pad14[8];int elapsed;};
// Original: arm9/main @ 0x020DE038; symbol: func_020de038; size: 0x90.
extern "C" void AdvanceFixedPointElapsedValueAndMarkComplete(Object* p) {p->elapsed+=0x800;float fraction=_ll_sto_f(FX_SinFx64c(p->elapsed))/4294967296.0f;int value=(int)(4096.0f*fraction);long long scaled=(long long)(0xc800-p->elapsed)*value+0x800;int result=fix32_Divide((int)(scaled>>12),0x3000);p->value=(int)((float)result/4096.0f);if(p->elapsed>=0xc800){p->elapsed=0;p->flag=1;}}
