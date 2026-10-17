#include <globaldefs.h>
ARM
struct Pair { void* first; void* second; };
typedef void (*Release)(const char*,void*,unsigned);
extern "C" { void VectorizedMemset(void*,int,unsigned); void Unclassified_InvokeRecordCleanupAndClear(void*,unsigned*); void ReleaseAndClearPairedPointers(char*,Pair*,int); extern char data_ov031_02249e2c[],data_ov031_02249e44[]; }
// Original: arm9/ov031 @ 0x022183B4; symbol: func_ov031_022183b4; size: 0xB4.
extern "C" void Memory_ReleaseContextBuffersAndReset(unsigned char* object) {
 Release release=*(Release*)(object+0x1014);
 if(!object) return;
 ReleaseAndClearPairedPointers((char*)object,(Pair*)(object+0x1a38),32);
 Unclassified_InvokeRecordCleanupAndClear(object,(unsigned*)(object+0x1a08));
 Unclassified_InvokeRecordCleanupAndClear(object,(unsigned*)(object+0x19f8));
 if(*(void**)(object+0x19cc)) {
  release(data_ov031_02249e2c,*(void**)(object+0x19cc),0);
  *(void**)(object+0x19cc)=0;
 }
 if(*(void**)(object+0x19d0)) {
  release(data_ov031_02249e44,*(void**)(object+0x19d0),0);
  *(void**)(object+0x19d0)=0;
 }
 VectorizedMemset(object,0,0x1c14);
}
