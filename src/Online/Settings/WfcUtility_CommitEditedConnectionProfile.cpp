#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct HighTwoBits{unsigned char low:6,high:2;};
extern "C" unsigned MI_CpuCopy8(...);
extern "C" unsigned VectorizedMemset(...);
extern "C" unsigned CountSetBitsInFourBytes(...);
extern "C" unsigned WfcUtility_UpdateProfileAvailabilityChecksumsAndPersist(...);
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02236174; symbol: CopySelectedDisplayPageAndApplyOptionalFields.
extern "C" void WfcUtility_CommitEditedConnectionProfile(){unsigned char* base=(unsigned char*)U(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage,0);unsigned char* source=base+0x400;unsigned char* destination=base+(B(source,0xf4)<<8);int count=120;unsigned char* dst=destination;unsigned char* src=source;do{unsigned char a=src[0],b=src[1];src+=2;dst[0]=a;dst[1]=b;dst+=2;}while(--count);if(B(source,0xf5)){VectorizedMemset(destination+0xc0,0,4);VectorizedMemset(destination+0xc4,0,4);B(destination,0xd0)=0;}else{MI_CpuCopy8(source+0xc0,destination+0xc0,4);MI_CpuCopy8(source+0xc4,destination+0xc4,4);B(destination,0xd0)=CountSetBitsInFourBytes(source+0xf0);}if(B(source,0xf6))VectorizedMemset(destination+0xc8,0,8);else MI_CpuCopy8(source+0xc8,destination+0xc8,8);WfcUtility_UpdateProfileAvailabilityChecksumsAndPersist(B(source,0xf4));}
