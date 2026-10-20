#include <globaldefs.h>
ARM
// Original data: arm9/ov023 @ 0x21fff08; symbol: data_ov023_021fff08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned char* ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage[];
extern "C" void* GameState_GetSerializedProgressState();
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" unsigned Script_GetEntryHighFlagMask(unsigned char*,int);
extern "C" void Script_MarkEntryHighFlag(void*,int);
extern "C" void BitArray_SetIndexedBoolean(void*,unsigned char*,int,int);
struct Flags { unsigned short bits:13; unsigned short other:3; };
// Original: arm9/ov023 @ 0x021F5A1C; symbol: func_ov023_021f5a1c; size: 0xBC.
extern "C" int Script_SetPackedNibbleFlagsAndSharedMarker(unsigned char* params,int count) {
 unsigned char* object=(unsigned char*)GameState_GetSerializedProgressState();
 for(int i=0;i<count;i++) {
  int key=_ZNK6Script9Parameter5ToIntEv(params);
  params+=8;
  if(!Script_GetEntryHighFlagMask(object,key)) {
   Script_MarkEntryHighFlag(object,key);
   Flags* flags=(Flags*)(ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage[3]+0x10c);
   flags->bits=(unsigned short)(flags->bits|0x40);
   BitArray_SetIndexedBoolean(object,object+0x8c,0x797,1);
  }
 }
 return 1;
}
