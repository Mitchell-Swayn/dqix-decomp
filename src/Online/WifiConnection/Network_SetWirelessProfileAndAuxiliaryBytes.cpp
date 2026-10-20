#include <globaldefs.h>
#include "System/Memory.h"
ARM
extern "C" int Network_GetConnectionWorkspace(unsigned);
extern "C" void Network_SetSelectedWirelessNameAndKey(const unsigned char*,const void*,int);
// Original: arm9/ov031 @ 0x022130E8; symbol: func_ov031_022130e8; size: 0x64.
// Copies or clears ten auxiliary bytes and stores their option before setting the wireless name/key.
extern "C" void Network_SetWirelessProfileAndAuxiliaryBytes(const unsigned char* name,const void* key,int mode,const void* extra,unsigned option) {
 unsigned char* state=(unsigned char*)Network_GetConnectionWorkspace(1);
 if(extra)MI_CpuCopy8(extra,state+0x18,10);
 else VectorizedMemset(state+0x18,0,10);
 state[0x22]=option;
 Network_SetSelectedWirelessNameAndKey(name,key,mode);
}
