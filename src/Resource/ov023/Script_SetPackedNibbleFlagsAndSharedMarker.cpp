#include <globaldefs.h>
ARM
extern "C" unsigned char* data_ov023_021fff08[];
extern "C" void* ReadGlobalValueAt02108844();
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" unsigned TestOneOf204PackedNibbleHighFlags(unsigned char*,int);
extern "C" void SetPackedHalfByteFlagAt2CC(void*,int);
extern "C" void BitArray_SetIndexedBoolean(void*,unsigned char*,int,int);
struct Flags { unsigned short bits:13; unsigned short other:3; };
// Original: arm9/ov023 @ 0x021F5A1C; symbol: func_ov023_021f5a1c; size: 0xBC.
extern "C" int Script_SetPackedNibbleFlagsAndSharedMarker(unsigned char* params,int count) {
 unsigned char* object=(unsigned char*)ReadGlobalValueAt02108844();
 for(int i=0;i<count;i++) {
  int key=_ZNK6Script9Parameter5ToIntEv(params);
  params+=8;
  if(!TestOneOf204PackedNibbleHighFlags(object,key)) {
   SetPackedHalfByteFlagAt2CC(object,key);
   Flags* flags=(Flags*)(data_ov023_021fff08[3]+0x10c);
   flags->bits=(unsigned short)(flags->bits|0x40);
   BitArray_SetIndexedBoolean(object,object+0x8c,0x797,1);
  }
 }
 return 1;
}
