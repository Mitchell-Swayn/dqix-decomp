#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma force_active on
ARM
struct ExperienceAwards {
    unsigned short encounter;
    unsigned short low[4];
    unsigned char high[4];
    unsigned char flag;
    unsigned char statistics;
};
struct ExperiencePacket { unsigned char command; char reserved[3]; ExperienceAwards payload; };
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" unsigned FieldBattle_GetScene(void*);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" void Statistics_AddExperienceEarned(unsigned*,unsigned);
extern "C" void Statistics_AddCompactExperienceEarned(char*,unsigned);
extern "C" int GameState_StoreStatisticsRecord(const void*);
extern "C" void GameState_CopyFourWordsAndSetFlag(unsigned char*,const unsigned*,unsigned char);
// Original: arm9/ov017 @ 0x021CD608; symbol: func_ov017_021cd608; size: 0xD0.
// Applies matching-encounter experience awards to battle state or the protagonist's statistics.
extern "C" void Combat_ApplyPartyExperienceAwards(int unused,unsigned char* recordData,void* unusedGame,void* resourceContext,void* connection)
{
    int i;
    void* request=((GameResources*)resourceContext)->unknown_ptr_3718;
    const ExperienceAwards* payload=&((const ExperiencePacket*)recordData)->payload;
    unsigned short currentEncounter=*(unsigned short*)((unsigned char*)FieldBattle_GetEncounterRequest(request)+8);
    if(currentEncounter!=payload->encounter) return;
    unsigned char* scene=(unsigned char*)FieldBattle_GetScene(request);
    if(!scene) return;
    unsigned awards[4];
    for(i=0;i<4;++i) awards[i]=payload->low[i]+((unsigned)payload->high[i]<<16);
    if(payload->statistics) {
        int protagonist=GameState_ReadProtagonistObjectIndex(GameState::GetInstance());
        __declspec(align(4)) char record[176];
        GameState_CopyStatisticsRecord(record);
        Statistics_AddExperienceEarned((unsigned*)record,awards[protagonist]);
        Statistics_AddCompactExperienceEarned(record+0x68,awards[protagonist]);
        GameState_StoreStatisticsRecord(record);
    } else GameState_CopyFourWordsAndSetFlag(scene,awards,payload->flag);
}
