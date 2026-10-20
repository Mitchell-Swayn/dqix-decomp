#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma force_active on
ARM
struct TextEntry;
struct Record;
struct Flags;
struct PartyAddressRecord { unsigned char address[6]; signed char member; unsigned char a,b; signed char c; };
struct PartyAddressBank { PartyAddressRecord entries[3]; };
extern "C" {
void* Network_GetConnectionManager();
int Network_GetLocalMemberId(char*);
unsigned char GameState_ReadFirstObjectIndex(GameState*);
int GameState_ReadProtagonistObjectIndex(GameState*);
void Network_ClearMemberDisconnectFlag(unsigned char*,int);
void Network_ClearMemberDisconnectNoticeQueued(unsigned char*,int);
void* PartySync_GetSharedRecordTable();
void Network_UpdateTextEntryTimeoutsAndStatus(TextEntry*);
void Field_ClearPartySyncFlagMask(unsigned char*);
void Network_RemoveMember(int,unsigned);
void Field_RemovePartyMemberAndEquipment(void*,int);
void ClearIndexedTextRecordStatesAndNotify(Record*,int);
void VectorizedMemset(void*,int,unsigned);
void* NetworkOwnership_GetRegistry();
void NetworkOwnership_ClearPeerEntries(unsigned char*,unsigned);
unsigned FieldBattle_GetCombatContext(void*);
void Combat_RemovePendingPartyJoin(void*,int);
bool FieldMonster_TestSelectedPartyMember(unsigned char*,unsigned);
unsigned short FieldBattle_GetLifecyclePhase(char*);
void* FieldBattle_GetEncounterRequest(void*);
unsigned FieldBattle_GetScene(void*);
void FieldMonster_CollectPartyHideResponseAndComplete(unsigned,int,int);
void FieldMonster_ClearPartyPlacementSelection(unsigned char*);
void* Network_GetTaggedAcknowledgementTable();
void Network_ClearPlayerTaggedAcknowledgements(Flags*,int);
}
// Original: arm9/ov017 @ 0x021905B8; symbol: func_ov017_021905b8; size: 0x224.
// Removes a remote member's party objects, synchronization state, ownership and monster placement selections.
extern "C" void Field_RemoveRemoteMemberAndSynchronizationState(char* owner,int member,int notify)
{
    GameState* game=GameState::GetInstance();
    unsigned char* connection=(unsigned char*)Network_GetConnectionManager();
    if(member<=0) return;
    if(member==Network_GetLocalMemberId((char*)connection) || member==GameState_ReadFirstObjectIndex(game) || member==GameState_ReadProtagonistObjectIndex(game)) {
        Network_ClearMemberDisconnectFlag(connection,member);
        Network_ClearMemberDisconnectNoticeQueued(connection,member);
        return;
    }
    void* shared=PartySync_GetSharedRecordTable();
    Network_UpdateTextEntryTimeoutsAndStatus((TextEntry*)shared);
    Field_ClearPartySyncFlagMask((unsigned char*)owner);
    Network_ClearMemberDisconnectFlag(connection,member);
    Network_ClearMemberDisconnectNoticeQueued(connection,member);
    if(notify) Network_RemoveMember((int)connection,member);
    Field_RemovePartyMemberAndEquipment(owner,member);
    ClearIndexedTextRecordStatesAndNotify((Record*)shared,(unsigned char)member);
    PartyAddressRecord* address=((PartyAddressBank*)((unsigned char*)game+0x74c0))->entries;
    for(int i=0;i<3;++i,++address) {
        if(address->member==member) {
            VectorizedMemset(address->address,0,6);
            address->member=-1;
            address->a=0;
            address->b=0;
            address->c=-1;
            break;
        }
    }
    NetworkOwnership_ClearPeerEntries((unsigned char*)NetworkOwnership_GetRegistry(),member);
    GameResources* resources=(GameResources*)owner;
    unsigned char* battle=(unsigned char*)resources->unknown_ptr_3718;
    if(battle[2]) {
        unsigned combat=FieldBattle_GetCombatContext(battle);
        if(combat) Combat_RemovePendingPartyJoin((void*)combat,member);
    }
    for(int i=0;i<48;++i) {
        GameObject* monster=game->GetMaybeFieldMonsterByIndex(i+112);
        if(!monster || !FieldMonster_TestSelectedPartyMember((unsigned char*)monster,member)) continue;
        int hide;
        unsigned char* request=(unsigned char*)resources->unknown_ptr_3718;
        hide=1;
        if(request[2] && FieldBattle_GetLifecyclePhase((char*)request)==0) {
            unsigned char* encounter=(unsigned char*)FieldBattle_GetEncounterRequest(request);
            if(encounter && *(unsigned short*)(encounter+8)==*(unsigned short*)((unsigned char*)monster+0x16a)) {
                unsigned char* scene=(unsigned char*)FieldBattle_GetScene(request);
                if(scene && *(int*)(scene+0xea8)==7) hide=0;
            }
        }
        FieldMonster_CollectPartyHideResponseAndComplete(Network_GetLocalMemberId((char*)connection),*(unsigned short*)((unsigned char*)monster+0x16a),hide);
        FieldMonster_ClearPartyPlacementSelection((unsigned char*)monster);
    }
    Network_ClearPlayerTaggedAcknowledgements((Flags*)Network_GetTaggedAcknowledgementTable(),member);
}
