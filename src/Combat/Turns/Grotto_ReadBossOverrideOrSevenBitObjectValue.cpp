#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_FindIndexedObjectWithFlag400(void*,unsigned);
extern "C" char* FindNonPartyObjectResourceRecord(void*,unsigned);
extern "C" char* Zone3D_GetMainInstance();
extern "C" bool GameState_IsCurrentZoneGrotto(void*);
extern "C" char* _ZN17ActiveGrottoClass15GetDetailedDataEv(void*);
extern "C" int _ZNK23DetailedTreasureMapData17LegacyBossMapData26MaybeGetCurrentAlternateIDEv(void*);
struct SevenBitValue {unsigned short value:7;unsigned short rest:9;};
// Original: arm9/ov000 @ 0x02159DBC; symbol: Grotto_ReadBossOverrideOrSevenBitObjectValue; size: 0xa4.
// Returns boss map override byte56 for matching alternate ID in grotto; otherwise low7 bits of object record value.
extern "C" unsigned Grotto_ReadBossOverrideOrSevenBitObjectValue(char* self,unsigned index) {
 void* game=_ZN9GameState11GetInstanceEv();char* object=GameState_FindIndexedObjectWithFlag400(_ZN9GameState11GetInstanceEv(),index);if(!object)return 1;
 char* record=FindNonPartyObjectResourceRecord(self,index);if(!record)return 1;
 char* world=Zone3D_GetMainInstance();
 if(GameState_IsCurrentZoneGrotto(game)&&*(unsigned char*)(*(char**)(self+0x8e18)+0x25)){
 char* detail=_ZN17ActiveGrottoClass15GetDetailedDataEv(world+0x23ec);int id=*(short*)(object+2);int alternate=_ZNK23DetailedTreasureMapData17LegacyBossMapData26MaybeGetCurrentAlternateIDEv(detail+0x4c);
 if(alternate==id)return *(unsigned char*)(detail+0x56);
 }return ((SevenBitValue*)(record+10))->value;
}
