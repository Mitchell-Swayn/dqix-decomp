#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/main @ 0x20f2a30; symbol: data_020f2a30.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 612a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2a38; symbol: data_020f2a38.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex c82a0f02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {void* _ZN9GameState11GetInstanceEv();void* _ZN16BackgroundLoader11GetInstanceEv();void* GameState_GetObjectWithFlag100(void*,int);unsigned FieldAppearance_ReadMemberRefreshRequest(void*);int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);void GameState_BuildEquipmentObjectIdsAndDefaultValues(int,int*,short*);unsigned char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);extern char* CharacterViewerRun_UnknownRoleDataReferences_Variant2;extern char* CharacterViewerRun_UnknownRoleDataReferences;}
// Original: arm9/ov017 @ 0x021B3444; symbol: Resource_QueueEquipmentArchiveWhenStateDiffers; size: 0x108.
// Queues equipment archive when nested status is active or expected equipment values differ.
extern "C" int Resource_QueueEquipmentArchiveWhenStateDiffers(unsigned char* self){void* game=_ZN9GameState11GetInstanceEv();void* loader=_ZN16BackgroundLoader11GetInstanceEv();void* member=GameState_GetObjectWithFlag100(game,H(self,8));if(member&&FieldAppearance_ReadMemberRefreshRequest(member)){W(self,16)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,CharacterViewerRun_UnknownRoleDataReferences_Variant2,CharacterViewerRun_UnknownRoleDataReferences,0);return 1;}int ids[11];short values[12];GameState_BuildEquipmentObjectIdsAndDefaultValues(H(self,8),ids,values);unsigned reset=self[11]&1;for(int i=0;i<11;++i){unsigned char* object=_ZN9GameState20GetGameObjectByIndexEi(game,ids[i]);if(!object)continue;if(reset)H(object,2)=-1;int expected=values[i];if(expected!=H(object,2)){W(self,16)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,CharacterViewerRun_UnknownRoleDataReferences_Variant2,CharacterViewerRun_UnknownRoleDataReferences,0);return 1;}}return 0;}
