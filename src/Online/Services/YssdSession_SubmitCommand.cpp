#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" int YssdSession_CanSubmitCommand(int,unsigned);
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" int Network_ClearMessageWordsAndTrySend(void*);
// Original data: arm9/ov031 @ 0x224e590; symbol: data_ov031_0224e590.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02211310; symbol: SubmitValidatedActiveContextRecord; size: 0xb0.
// Validates parameter, writes type3 active context record, submits and marks active state.
extern "C" int YssdSession_SubmitCommand(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e){
 if(!YssdSession_CanSubmitCommand(0,a))return 0;VectorizedMemset(YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage+20,0,40);
 U(YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage,20)=3;U(YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage,24)=a;U(YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage,32)=b;U(YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage,40)=c;U(YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage,64)=d;U(YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage,68)=e;
 if(!Network_ClearMessageWordsAndTrySend(YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage+20))return 0;U(YssdSessionTryDestroy_UnknownRoleZeroInitializedStorage,16)=1;return 1;
}
