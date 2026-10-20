#include <globaldefs.h>
ARM
extern "C" char* GameResources_GetInstance();
extern "C" char* Combat_GetCommandActorSnapshot(char*,int);
extern "C" int Field_GetCombatantAppearanceFlags(char*,int);
extern "C" void Graphics_SetPolygonIdForPartyObjectGroup(char*,int,int);
extern "C" void GameState_ApplyIndexedObjectSlotValues(char*,int);
// Original: arm9/ov025 @ 0x021E8670; symbol: ApplyPrimaryRecordIndexedSlotMode; size: 0x80.
extern "C" int Combat_RestorePrimaryActorGroupPolygonIds(int unused,char* source){
char* resources=GameResources_GetInstance();int index=*(unsigned short*)(Combat_GetCommandActorSnapshot(source,0)+32);int valid=(index>=0&&index<=3);if(valid&&(Field_GetCombatantAppearanceFlags(resources,index)&2)){Graphics_SetPolygonIdForPartyObjectGroup(resources,index,8);return 1;}GameState_ApplyIndexedObjectSlotValues(resources,index);return 1;
}
