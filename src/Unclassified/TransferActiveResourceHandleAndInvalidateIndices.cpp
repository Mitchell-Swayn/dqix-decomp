#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void InvokeHandleStateWhenPresent(char*,unsigned);
extern "C" void ApplyScaledValueToChannelIndices(char*,unsigned);
extern "C" void Object_Invokewhile();
// Original: arm9/main @ 0x0205E8EC; symbol: func_0205e8ec; size: 0x40.
extern "C" void TransferActiveResourceHandleAndInvalidateIndices(char* p){
    if(*(unsigned*)(p+0xb8)){
        InvokeHandleStateWhenPresent(p,*(unsigned*)(p+0xb8));
        *(unsigned*)(p+0xc0)=*(unsigned*)(p+0xb8);
        *(short*)(p+0xbc)=-1;
        *(short*)(p+0xc4)=-1;
    }
    ApplyScaledValueToChannelIndices(p,127);
    Object_Invokewhile();
}
