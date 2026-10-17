#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct State; struct Object;
extern "C" void Graphics_FinalizeRecordBuffers(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void ProcessActiveObjectAndClearActiveFlag(Object*);
extern "C" void Object_ResetSelectionAndApplyConfiguredMode(State*,int);
extern "C" void ClearEachIndexedEntryResource(unsigned char*);
extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);
extern "C" void ResetEachIndexedEntryResource(void*);
extern "C" void CleanupTwoRecordArraysAndClearOwnerPointers(unsigned char*);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);
// Original: arm9/ov003 @ 0x021700DC; symbol: func_ov003_021700dc; size: 0xC0.
extern "C" void Graphics_CleanupRecordResourcesAndClearMainBG1(unsigned char* self) {
 Graphics_FinalizeRecordBuffers(self+0x68);
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0xbc)) _ZN13SafeAllocator7DestroyEv(self+0xbc);
 ProcessActiveObjectAndClearActiveFlag((Object*)(self+0x48));
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|(*(unsigned*)(self+0x5c)<<8);
 if(*(void**)(self+0x3c)) {
  Object_ResetSelectionAndApplyConfiguredMode(*(State**)(self+0x3c),1);
  ClearEachIndexedEntryResource(*(unsigned char**)(self+0x3c));
  Graphics_ResetCountedThirtyTwoByteTransfers(*(void**)(self+0x3c));
  ResetEachIndexedEntryResource(*(void**)(self+0x3c));
  CleanupTwoRecordArraysAndClearOwnerPointers(*(unsigned char**)(self+0x3c));
 }
 *(void**)(self+0x3c)=0;
 memset(*(void**)(self+0x14),0,32);
 _Z25CleanInvalidateCacheRangePKvj(*(void**)(self+0x14),32);
 LoadToMainBG1CharacterData(*(void**)(self+0x14),0,32);
 *(volatile unsigned short*)0x04000050=0;
}
