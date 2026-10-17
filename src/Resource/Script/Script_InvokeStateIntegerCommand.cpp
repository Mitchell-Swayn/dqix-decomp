#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
int _ZNK6Script9Parameter5ToIntEv(void *);extern unsigned int data_020fdc4c[];void Object_AllocateSixteenByteRecordArray(unsigned int,int,unsigned int);
// Original: arm9/main @ 0x0201F580; symbol: func_0201f580; size: 0x28.
bool Script_InvokeStateIntegerCommand(void *p){int v=_ZNK6Script9Parameter5ToIntEv(p);Object_AllocateSixteenByteRecordArray(data_020fdc4c[4],v,data_020fdc4c[2]);return true;}
}
