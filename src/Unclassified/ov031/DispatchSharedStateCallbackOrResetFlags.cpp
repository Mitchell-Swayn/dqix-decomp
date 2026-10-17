#include <globaldefs.h>
ARM
struct Callbacks {void (*handlers[5])(void*);};
extern "C" Callbacks data_ov031_02248f0c;
extern "C" char* data_ov031_02290c98;
extern "C" int HasSharedObjectPointer();
extern "C" void SetMainLoopCallback(void(*)());
extern "C" void ReadOptionalSharedWords18And1C(unsigned*,unsigned*);
extern "C" void func_ov031_0222d9a4();
extern "C" void func_ov031_0222dee0();
// Original: arm9/ov031 @ 0x0222E0F8; symbol: func_ov031_0222e0f8; size: 0xB4.
extern "C" void DispatchSharedStateCallbackOrResetFlags() {
Callbacks callbacks=data_ov031_02248f0c;
if(HasSharedObjectPointer()) return;
if(!*(unsigned char*)(data_ov031_02290c98+0x15)) {
**(unsigned**)(data_ov031_02290c98+4)&=0xc1fffcff;
SetMainLoopCallback(func_ov031_0222d9a4);
return;
}
unsigned index;
ReadOptionalSharedWords18And1C(&index,0);
callbacks.handlers[index](data_ov031_02290c98+8);
SetMainLoopCallback(func_ov031_0222dee0);
}
