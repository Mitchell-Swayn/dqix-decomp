#pragma optimize_for_size off
#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" char data_021065d8[],data_02105fd8[];
struct MemorySlots {char pad[0x40];unsigned slots[8];};
// Original: arm9/main @ 0x0203B718; symbol: func_0203b718; size: 0x6C.
extern "C" void FillSelectedBankBufferAndMarkSlot(MemorySlots* p,int bank,unsigned slot,int value) {switch(bank){case 0:case 1:switch(slot){case 0:memset(data_021065d8,value,0x1000);break;case 1:memset(data_02105fd8,value,0x600);break;}break;}p->slots[slot+bank*4]=1;}
