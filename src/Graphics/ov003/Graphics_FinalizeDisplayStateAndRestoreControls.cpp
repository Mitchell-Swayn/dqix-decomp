#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void ResetRecordAndIndexedEntries(unsigned char*);
extern "C" void ResetEmbeddedResourceAndRecord(int);
extern "C" void ClearOutputWordAndHalfword(unsigned*);
extern "C" void Graphics_FinalizeRecordBuffers(void*);
extern "C" void CleanupTwoRecordArraysAndClearOwnerPointers(unsigned char*);
extern "C" void CancelOwnerTaskAndResetEmbeddedState(void*);
// Original: arm9/ov003 @ 0x0217DB88; symbol: func_ov003_0217db88; size: 0xB8.
extern "C" void Graphics_FinalizeDisplayStateAndRestoreControls(unsigned char* p){
 CleanupTwoRecordArraysAndClearOwnerPointers(*(unsigned char**)(p+0x90));
 for(int i=0;i<2;i++)ResetRecordAndIndexedEntries(*(unsigned char**)(p+0x94)+i*32);
 for(int i=0;i<1;i++)ResetEmbeddedResourceAndRecord((int)(*(unsigned char**)(p+0x98)+i*224));
 ClearOutputWordAndHalfword(*(unsigned**)(p+0x38));
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0xa4))_ZN13SafeAllocator7DestroyEv(p+0xa4);
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0xb8))_ZN13SafeAllocator7DestroyEv(p+0xb8);
 Graphics_FinalizeRecordBuffers(p+0x3c);
 CancelOwnerTaskAndResetEmbeddedState(p+0xcc);
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|(*(unsigned*)p<<8);
}
