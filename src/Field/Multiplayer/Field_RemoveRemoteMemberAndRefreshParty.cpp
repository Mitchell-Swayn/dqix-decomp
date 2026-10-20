#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameResources_GetInstance();
extern "C" char* Network_GetConnectionManager();
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" void InitializeConnectionRecordState(void*);
extern "C" void Resource_RemoveTaggedFifteenByteRecord(char*,int);
extern "C" void Network_SetMemberHostTrackingFlag(char*,int);
extern "C" void Field_RebuildDisplayedAndProtagonistRosters(char*);
extern "C" void Field_RemoveRemoteMemberAndSynchronizationState(char*,int,int);
extern "C" void Util_ClearBitAtOffsetA(unsigned char*,unsigned);
// Original: arm9/ov017 @ 0x0219558C; symbol: RemoveNonProtagonistSlotAndRefreshLists; size: 0x8c.
extern "C" void Field_RemoveRemoteMemberAndRefreshParty(char* self,int index){
void* state=_ZN9GameState11GetInstanceEv();char* resources=GameResources_GetInstance();char* connection=Network_GetConnectionManager();if(!index){InitializeConnectionRecordState(self);return;}if(index==GameState_ReadProtagonistObjectIndex(state))return;Resource_RemoveTaggedFifteenByteRecord(resources,index);Network_SetMemberHostTrackingFlag(connection,index);Field_RebuildDisplayedAndProtagonistRosters(resources);Field_RemoveRemoteMemberAndSynchronizationState(resources,index,1);Util_ClearBitAtOffsetA(*(unsigned char**)(self+0x3b34),index&255);
}
