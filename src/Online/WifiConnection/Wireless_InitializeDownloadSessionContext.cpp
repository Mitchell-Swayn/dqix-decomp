#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
extern "C" void InitializeEmbeddedBlockAndClearTwoFields(void*);
extern "C" void Wireless_ClearDownloadSessionPacketBuffers();
extern "C" unsigned long long _Z19GetCurrentTimestampv();
extern "C" unsigned WfcUtility_ReadFourSettingsPages(int);
extern "C" int WfcUtility_GetConnectionProfileStorage();
// Original: arm9/ov031 @ 0x0223A4CC; symbol: InitializeSharedResourceContext; size: 0xf0.
// Installs shared context, resets control fields and copies six settings words and one byte.
extern "C" void Wireless_InitializeDownloadSessionContext(unsigned char *object,unsigned char *settings){
Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage=object;InitializeEmbeddedBlockAndClearTwoFields(object+0xb00);
 *(unsigned short*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x648)=0;*(unsigned short*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x64a)=0;
 Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa90]=1;Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa91]=1;*(int*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xa9c)=0;
 Wireless_ClearDownloadSessionPacketBuffers();
 *(int*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+2740)=*(int*)(settings+0);
 *(int*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+2744)=*(int*)(settings+4);
 *(int*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+2748)=*(int*)(settings+8);
 *(int*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+2752)=*(int*)(settings+12);
 *(int*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+2756)=*(int*)(settings+16);
 *(int*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+2760)=*(int*)(settings+20);
 Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa92]=(unsigned char)settings[24];Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xacc]=2;
 _Z19GetCurrentTimestampv();WfcUtility_ReadFourSettingsPages((int)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0x64c));
 _Z19GetCurrentTimestampv();*(int*)(Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage+0xaa4)=WfcUtility_GetConnectionProfileStorage();
}
