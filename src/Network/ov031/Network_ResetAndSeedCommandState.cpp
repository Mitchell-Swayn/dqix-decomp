#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" unsigned short WirelessCommand_IncrementTimeSeededSequence();
extern "C" void func_ov031_02239bc0(void*);
extern "C" char* data_ov031_02290d20;
// Original: arm9/ov031 @ 0x0223A698; symbol: func_ov031_0223a698; size: 0x80.
extern "C" void Network_ResetAndSeedCommandState() {
func_ov031_02239bc0(*(void**)(data_ov031_02290d20+0xac8));
data_ov031_02290d20[0xa90]=1;
*(unsigned short*)(data_ov031_02290d20+0x648)=WirelessCommand_IncrementTimeSeededSequence();
MI_CpuCopy8(*(void**)(data_ov031_02290d20+0xaa4),data_ov031_02290d20+0xa50,0x40);
data_ov031_02290d20[0xa93]=0;
*(int*)(data_ov031_02290d20+0x204)=0;
++*(unsigned short*)(data_ov031_02290d20+0x648);
}
