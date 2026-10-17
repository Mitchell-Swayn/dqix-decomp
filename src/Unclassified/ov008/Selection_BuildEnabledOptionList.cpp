#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalValueAt02108844();
extern "C" unsigned int ReadNonnegativeIndexedBit(void*,unsigned char*,int);
// Original: arm9/ov008 @ 0x02186CEC; symbol: func_ov008_02186cec; size: 0x160.
extern "C" void Selection_BuildEnabledOptionList(unsigned char* self) {
 self[0x74c]=0;
 for(int i=0;i<8;++i) (self+i)[0x744]=255;
 (self+self[0x74c]++)[0x744]=0;
 (self+self[0x74c]++)[0x744]=1;
 (self+self[0x74c]++)[0x744]=2;
 unsigned char* global=(unsigned char*)ReadGlobalValueAt02108844();
 if(ReadNonnegativeIndexedBit(global,global+0x8c,0x1198)) (self+self[0x74c]++)[0x744]=3;
 if(*(int*)(self+0xb18)&0x2000) (self+self[0x74c]++)[0x744]=4;
 if(ReadNonnegativeIndexedBit(global,global+0x8c,0x119d)) (self+self[0x74c]++)[0x744]=5;
 if(ReadNonnegativeIndexedBit(global,global+0x8c,0x119b)) (self+self[0x74c]++)[0x744]=6;
 if(*(int*)(self+0xb18)&4) (self+self[0x74c]++)[0x744]=7;
}
