#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#include <System/Interrupts.h>
extern "C" void* ComputeMaskedIndexPopulationStrideAndBase(void*,unsigned,void*,unsigned);extern "C" void MIi_CpuClear16(unsigned,void*,unsigned);extern "C" void MIi_CpuCopy16(unsigned,void*,unsigned);
// Original: arm9/main @ 0x020D6610; symbol: func_020d6610; size: 0xCC.
extern "C" void CopySelectedEnabledBitBlockToDestination(unsigned char* object,unsigned bit,unsigned destination){unsigned short mask=1<<bit;unsigned enabled=*(unsigned short*)(object+0x80e);if(!(enabled&mask))return;unsigned block=*(unsigned short*)(object+0x808);if(!(*(unsigned short*)(object+block*0x200)&mask)){if(*(unsigned short*)(object+0x818)!=1)return;block=(block+1)&3;if(!(*(unsigned short*)(object+block*0x200)&mask))return;}void* data=ComputeMaskedIndexPopulationStrideAndBase(object,enabled,object+block*0x200+4,bit);if(destination)MIi_CpuCopy16(destination,data,*(unsigned short*)(object+0x810));else MIi_CpuClear16(0,data,*(unsigned short*)(object+0x810));int state=DisableIRQInterrupts();*(unsigned short*)(object+block*0x200)&=~mask;*(unsigned short*)(object+2+block*0x200)|=mask;SetIRQInterruptState(state);}
