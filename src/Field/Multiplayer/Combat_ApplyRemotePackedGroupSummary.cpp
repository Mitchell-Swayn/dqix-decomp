#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#pragma force_active on
ARM
struct NibblePair { unsigned char low:4,high:4; };
struct GroupSummaryPayload {
    unsigned short encounter;
    unsigned short ids[3];
    unsigned char values[3];
    NibblePair counts[3];
    unsigned char phase;
    unsigned char reserved;
};
struct GroupSummaryPacket { unsigned char header[4]; GroupSummaryPayload payload; };
struct SummaryGroup {
    unsigned short identifier;
    unsigned char unknown_2[8];
    NibblePair counts;
    unsigned char value;
    unsigned char unknown_c[12];
};
struct GroupSummary {
    unsigned char lowTotal;
    unsigned char highTotal:4,groupCount:2,phase:2;
    unsigned char unknown_2[2];
    SummaryGroup groups[3];
};
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" unsigned FieldBattle_GetCombatContext(void*);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
// Original: arm9/ov017 @ 0x021C6534; symbol: func_ov017_021c6534; size: 0x1B4.
// Applies a remote encounter's three group summaries and recomputes their aggregate counts.
extern "C" void Combat_ApplyRemotePackedGroupSummary(int unused,unsigned char* record,void* game,void* resourceContext,void* connection)
{
    const GroupSummaryPacket* packet=(const GroupSummaryPacket*)record;
    void* battle=((GameResources*)resourceContext)->unknown_ptr_3718;
    unsigned char* request=(unsigned char*)FieldBattle_GetEncounterRequest(battle);
    if(!request) return;
    unsigned char* context=(unsigned char*)FieldBattle_GetCombatContext(battle);
    if(!context) return;
    if(*(signed char*)(request+0x2a)==GameState_ReadProtagonistObjectIndex((GameState*)game)) return;
    const GroupSummaryPayload* payload=&packet->payload;
    if(*(unsigned short*)(request+8)!=payload->encounter) return;
    GroupSummary* summary=(GroupSummary*)(context+0x81b0);
    unsigned char low[3]={payload->counts[0].low,payload->counts[1].low,payload->counts[2].low};
    unsigned char high[3]={payload->counts[0].high,payload->counts[1].high,payload->counts[2].high};
    int groupCount=0,lowTotal=0,highTotal=0;
    for(int i=0;i<3;++i) {
        SummaryGroup* group=&summary->groups[i];
        group->identifier=payload->ids[i];
        group->value=payload->values[i];
        group->counts.low=low[i];
        group->counts.high=high[i];
        if(group->identifier) {
            ++groupCount;
            lowTotal+=group->counts.low;
            highTotal+=group->counts.high;
        }
    }
    summary->groupCount=(unsigned char)groupCount;
    summary->phase=payload->phase;
    summary->lowTotal=lowTotal;
    summary->highTotal=(unsigned char)highTotal;
}
