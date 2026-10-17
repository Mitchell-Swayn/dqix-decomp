#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Pair{void*value;int index;};extern "C" void* memset(void*,int,unsigned);extern "C" void* data_02109cc4[49];extern "C" Pair data_020f1758[];extern "C" void Script_SetOpcodeHandlerTable(void*,void**,int);
// Original: arm9/main @ 0x0209DC4C; symbol: func_0209dc4c; size: 0x80.
extern "C" void Script_RegisterFortyNineIndexedOpcodeHandlers(void*p){memset(data_02109cc4,0,196);Pair*pair=data_020f1758;while(pair){void*value=pair->value;if(!value)break;int index=pair->index;if(index>=0&&index<49){if(data_02109cc4[index]){for(;;){}}data_02109cc4[index]=value;}++pair;}Script_SetOpcodeHandlerTable(p,data_02109cc4,49);}
