#include <globaldefs.h>
ARM
extern "C" int VectorizedMemset(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0220D61C; symbol: ConfigureAlignedGlobalScratchBufferAndCallback.
extern "C" void Network_ConfigureAccessPointListAndCallback(unsigned*configuration,int callback){
if(!configuration){W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,620)=3;W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,624)=0;W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,628)=0;W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,632)=0;}else{W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,620)=configuration[0]&3;unsigned address=configuration[1];unsigned size=configuration[2];unsigned padding=(4-(address&3))&3;if(padding+12>size){W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,624)=0;W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,628)=0;}else{W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,624)=(address+3)&~3;W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,628)=configuration[2]-((4-(configuration[1]&3))&3);VectorizedMemset((void*)W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,624),0,W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,628));}W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,632)=configuration[3];}W(P(NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage,0)+8192,636)=callback;
}
