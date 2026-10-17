#include <globaldefs.h>
ARM
typedef void(*Callback)(void*);
extern "C" Callback data_ov031_02248eb4[];
extern "C" unsigned char* data_ov031_02290c94;
extern "C" void SetMainLoopCallback(void(*)());
extern "C" void ReadOptionalSharedWords18And1C(unsigned*,unsigned*);
extern "C" int HasSharedObjectPointer();
extern "C" void func_ov031_0222ce24();
extern "C" void func_ov031_0222d1b8();
// Original: arm9/ov031 @ 0x0222D474; symbol: func_ov031_0222d474; size: 0xB0.
extern "C" void System_DispatchSelectedSharedCallback() {
Callback callbacks[2]={data_ov031_02248eb4[4],data_ov031_02248eb4[5]};
if(HasSharedObjectPointer())return;
if(!data_ov031_02290c94[0x2a]){
**(unsigned int**)(data_ov031_02290c94+4)&=0xc1fffcff;
SetMainLoopCallback(func_ov031_0222ce24);return;
}
unsigned int index;ReadOptionalSharedWords18And1C(&index,0);
callbacks[index](data_ov031_02290c94+8);
SetMainLoopCallback(func_ov031_0222d1b8);
}
