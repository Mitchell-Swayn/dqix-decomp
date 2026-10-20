#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" char* BattleMenu_FindPartyCommandRecord(char*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void* BattleMenu_FindItemByEquipmentKey(char*,int);
extern "C" void BattleMenu_RefreshMemberCommandLabel(unsigned char*);
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x02174428; symbol: BattleMenu_ApplyMemberCommandSelection; size: 0xCC.
// Updates an available party selection record and refreshes its equipment lookup and formatted text.
// Byte selection modes and the notification dispatch retain unresolved semantics.
extern "C" void BattleMenu_ApplyMemberCommandSelection(char* self,int index,int mode,signed char kind,signed char subkind,short equipmentKey,signed char flag,unsigned short textKey) {
    char* record=BattleMenu_FindPartyCommandRecord(self,index);
    if (!record) return;
    if (index!=GameState_ReadProtagonistObjectIndex(GameState::GetInstance()) && mode==100 && mode!=*(signed char*)(record+0x10+*(signed char*)(record+0x18)))
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,25,0);
    if (((unsigned char*)record)[0x43e]) return;
    int objectIndex=*(int*)(record+0x4c);
    int valid=0;
    if (objectIndex>=0) valid=objectIndex<=3;
    if (valid) {
    (record+*(signed char*)(record+0x18))[0x10]=mode;
    record[0x1c]=kind;
    record[0x1d]=subkind;
    *(short*)(record+0x2c)=equipmentKey;
    record[0x2e]=flag;
    *(unsigned short*)(record+0x26)=textKey;
    BattleMenu_FindItemByEquipmentKey(record,equipmentKey);
    BattleMenu_RefreshMemberCommandLabel((unsigned char*)record);
    }
}
