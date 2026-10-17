#include <globaldefs.h>
extern "C" void _ZN8Object3D11DisableFlagEi(void*,int);extern "C" void InitializeRecordWithEnabledAndPercentDefaults(void*);extern "C" void ShiftCurrentByteValueToPreviousAndRefresh(void*,int);
// Original: arm9/main @ 0x02039D84; symbol: func_02039d84; size: 0x38.
extern "C" ARM void Object_ResetAnimationAndOffset26CState(unsigned char* p){p[0xe0]&=~1;_ZN8Object3D11DisableFlagEi(p,0x1190);InitializeRecordWithEnabledAndPercentDefaults(p+0x26c);ShiftCurrentByteValueToPreviousAndRefresh(p,0);}
