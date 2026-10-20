#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
#pragma force_active on
ARM
struct Pool;
struct DiscoveryScratch { char name[20]; int indices[4]; };
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* Network_GetConnectionManager();
extern "C" void* Network_GetCommandRecordPool();
extern "C" void* NetworkOwnership_GetRegistry();
extern "C" void* Network_GetPartySynchronizationFlags();
extern "C" unsigned char Network_InitializeTransitionAndCopyPartyAddress(char*);
extern "C" void Field_EndMultiplayerSessionAndRestoreLocalParty();
extern "C" void Network_EnableSessionAdvertisementFlags(char*);
extern "C" int SetStateThreeAndRegisterGlobalCallback(unsigned*);
extern "C" void Network_InitializeRecordPoolAndPeerBuffers(Pool*);
extern "C" void NetworkOwnership_ResetRegistry(char*);
extern "C" void Network_ResetPartySynchronizationFlags(unsigned char*);
extern "C" void Field_ResetActivePartyJoinRequest(char*);
extern "C" void GameState_CollectPresentIndicesAmongFirstFour(GameState*,int*,int*);
extern "C" void __clear(void*,unsigned);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
extern "C" void Network_SetAdvertisedNameAndPartyCount(char*,void*);
extern "C" void ClearEmbeddedFieldsAtOffsets45B8And44C0(void*);
extern "C" void Field_ClearPendingMemberJoinMask(void*);
// Original: arm9/ov017 @ 0x021C36A0; symbol: func_ov017_021c36a0; size: 0x104.
// Starts guest discovery after resetting session pools, ownership and pending join state.
extern "C" void Field_BeginGuestSessionDiscovery()
{
    GameState* game=GameState::GetInstance();
    GameResources* resources=GameResources_GetInstance();
    char* connection=(char*)Network_GetConnectionManager();
    GameObject* protagonist=game->GetProtagonist();
    Pool* pool=(Pool*)Network_GetCommandRecordPool();
    char* ownership=(char*)NetworkOwnership_GetRegistry();
    unsigned char* flags=(unsigned char*)Network_GetPartySynchronizationFlags();
    if(Network_InitializeTransitionAndCopyPartyAddress(connection)) Field_EndMultiplayerSessionAndRestoreLocalParty();
    else {
        Network_EnableSessionAdvertisementFlags(connection);
        SetStateThreeAndRegisterGlobalCallback((unsigned*)connection);
        Network_InitializeRecordPoolAndPeerBuffers(pool);
        NetworkOwnership_ResetRegistry(ownership);
        Network_ResetPartySynchronizationFlags(flags);
        Field_ResetActivePartyJoinRequest((char*)resources);
        DiscoveryScratch scratch;
        int count;
        GameState_CollectPresentIndicesAmongFirstFour(game,scratch.indices,&count);
        __clear(scratch.name,20);
        int length=String_CountBytesUntilTerminator((const signed char*)protagonist->baseStats_);
        if(length>20) length=20;
        memcpy(scratch.name,protagonist->baseStats_,length);
        ((unsigned char*)&scratch)[length]=0;
        ((unsigned char*)&scratch)[19]=count;
        Network_SetAdvertisedNameAndPartyCount(connection,protagonist->baseStats_);
        ClearEmbeddedFieldsAtOffsets45B8And44C0(resources);
        Field_ClearPendingMemberJoinMask(resources);
    }
}
