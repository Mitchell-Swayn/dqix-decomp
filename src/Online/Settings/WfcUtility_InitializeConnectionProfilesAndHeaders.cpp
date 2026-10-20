#include <globaldefs.h>
ARM
#pragma optimization_level 4
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x2290cfc; symbol: data_ov031_02290cfc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage;
extern "C" void MIi_CpuClear16(int,void*,unsigned);
extern "C" void WfcUtility_GenerateMissingPersistentIdentifier(void*);
extern "C" void* WfcUtility_EncodePersistentIdentifierFields(void*);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void WfcUtility_UpdateProfileAvailabilityChecksumsAndPersist(int);
// Original: arm9/ov031 @ 0x022364C0; symbol: InitializeFourContextPagesWithSharedHeader; size: 0xb0.
// Clears four pages, initializes three sentinel bytes, copies shared14-byte header twice and initializes pages.
extern "C" void WfcUtility_InitializeConnectionProfilesAndHeaders(){
 MIi_CpuClear16(0,NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage,1024);for(int i=0;i<3;i++)B(NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+i*256,0xe7)=255;
 char local[20];WfcUtility_GenerateMissingPersistentIdentifier(local);void* header=WfcUtility_EncodePersistentIdentifierFields(local);
 int offset;int i=0;offset=0;for(;i<2;i++,offset+=256)MI_CpuCopy8(header,NetworkSetEncodedKey_UnknownRoleZeroInitializedStorage+offset+0xf0,14);
 for(int i=0;i<4;i++)WfcUtility_UpdateProfileAvailabilityChecksumsAndPersist(i);
}
