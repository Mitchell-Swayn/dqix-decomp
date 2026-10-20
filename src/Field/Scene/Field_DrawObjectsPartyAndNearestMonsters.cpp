#include <globaldefs.h>
ARM
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" int _ZNK8Object3D10GetField06Ev(void*);
extern "C" void Graphics_DrawObjectRangeAndShadows(void*);
extern "C" int GameResources_GetMaskedSecondaryFlags(void*,int);
extern "C" void Field_DrawPartyMembersForZone(void*,int,int);
extern "C" void FieldMonster_DrawNearestZoneMonstersAndShadows(void*,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
// Original: arm9/ov017 @ 0x02196398; symbol: UpdateObjectFromProtagonistFieldWithMaskGuards; size: 0x98.
extern "C" void Field_DrawObjectsPartyAndNearestMonsters(void* self) {
 void* gs=_ZN9GameState11GetInstanceEv();GameState_ReadUnknownB0(gs);int value=_ZNK8Object3D10GetField06Ev(_ZN9GameState14GetProtagonistEv(gs));Graphics_DrawObjectRangeAndShadows(self);
 if(!GameResources_GetMaskedSecondaryFlags(self,4))Field_DrawPartyMembersForZone(self,value,1);
 if(!GameResources_GetMaskedSecondaryFlags(self,16))FieldMonster_DrawNearestZoneMonstersAndShadows(self,value);
 if(!GameResources_GetMaskedSecondaryFlags(self,4))Field_DrawPartyMembersForZone(self,value,2);
}
