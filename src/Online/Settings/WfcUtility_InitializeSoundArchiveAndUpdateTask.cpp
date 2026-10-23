#include <globaldefs.h>
ARM
extern "C" int NNS_SndArcInitOnMemory(...);
extern "C" int ResourceHandle_InitializeSequenceHandle(...);
extern "C" int Sound_InitializeManagerAndLifecycleCallbacks(...);
extern "C" int NNS_SndArcPlayerSetup(...);
extern "C" int Memory_AllocateZeroedBlock(...);
extern "C" int ResourceManager_SetIndexedThirtySixByteRecordValue(...);
extern "C" int Sound_SetPlayerSequenceLimit(...);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
extern "C" int Sound_SetPlayerVolume(...);
extern "C" int NNS_SndArcInitOnMemory(...);
extern "C" void WfcUtility_UpdateSoundPlaybackTask(void*,void*);
extern "C" int WfcUtility_LoadArchiveResource(...);
extern "C" int Memory_AllocateZeroedBlock(...);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
extern "C" char WfcUtility_InitializeSoundArchiveAndUpdateTask_TextSoundSoundDataSdatL[];
// Original data: arm9/ov031 @ 0x2290d00; symbol: data_ov031_02290d00.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0223677C; symbol: InitializeResourceBucketsAndInstallTimedCallback.
extern "C" void WfcUtility_InitializeSoundArchiveAndUpdateTask(void){
P(WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage,0)=C(Memory_AllocateZeroedBlock(160,4));unsigned size;P(P(WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage,0),152)=C(WfcUtility_LoadArchiveResource(WfcUtility_InitializeSoundArchiveAndUpdateTask_TextSoundSoundDataSdatL,&size,32));Sound_InitializeManagerAndLifecycleCallbacks();NNS_SndArcInitOnMemory(P(WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage,0),P(P(WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage,0),152));NNS_SndArcPlayerSetup(0);ResourceHandle_InitializeSequenceHandle(P(WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage,0)+148);int i=0;do{Sound_SetPlayerVolume(i,127);Sound_SetPlayerSequenceLimit(i,1);ResourceManager_SetIndexedThirtySixByteRecordValue(i,0);i++;}while(i<32);P(P(WfcUtilityDestroySoundContextAndUpdateTask_UnknownRoleZeroInitializedStorage,0),156)=(char*)WfcUtility_CreateTaskWithBorrowedContext(0,WfcUtility_UpdateSoundPlaybackTask,0,200);
}
