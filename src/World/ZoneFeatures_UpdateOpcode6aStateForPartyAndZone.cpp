#include "GameState/GameState.h"
#include "World/ZoneFeatures.h"
#include <globaldefs.h>

extern "C" {
int SystemState_GetGlobalFlags();
void* Zone3D_GetMainInstance();
void* GameState_GetSerializedProgressState();
unsigned char* GameState_GetIndexList(GameState*);
int SystemState_TestAnyFlags(int, unsigned int);
bool ZoneFeatures_TestGameObjectInsideEntry(void*, int);
void GameState_SetMemberMaskAndObjectFlags(void*, unsigned int);
void ZoneFeatures_BeginSubtypeThreeMemberMotion(void*, unsigned int);
void ZoneFeatures_AdvanceSubtypeTwoMemberRotationAndFade(void*, unsigned int);
void ZoneFeatures_AdvanceSubtypeThreeMemberMotion(void*, unsigned int);
unsigned int GameState_ReadFirstObjectIndex(GameState*);
void ZoneFeatures_ActivateNetworkedTrigger(void*);
void ZoneFeatures_DeactivateNetworkedTrigger(void*);
void BMDJ_AdvanceCountdownAndCollisionFlag(void*);
int BitArray_ReadNonnegativeIndexMask(void*, void*, unsigned int);
void Zone3D_UpdateZone1644PartyCircularMotion();
}

// Original: arm9/main @ 0x020A84E0; symbol: func_020a84e0; size: 0x1D8.
extern "C" ARM void ZoneFeatures_UpdateOpcode6aStateForPartyAndZone()
{
    GameState* state = GameState::GetInstance();
    GameResources_GetInstance();
    int mode = SystemState_GetGlobalFlags();
    unsigned short* zoneData = (unsigned short*)Zone3D_GetMainInstance();
    void* waitState = GameState_GetSerializedProgressState();
    int index = 0;
    for (;;)
    {
        ZoneFeatures::Opcode6aEntry* feature = ((ZoneFeatures*)(zoneData + 0x36))->GetOpcode6aEntry(index++);
        if (feature == 0) break;
        if (*(int*)((char*)feature + 4) != 0x0c)
            continue;
        unsigned char* party = GameState_GetIndexList(state);
        for (int i = 0; i < *((unsigned char*)party + 0xf7c); ++i)
        {
            unsigned char memberId = *((unsigned char*)party + 0xf78 + i);
            void* member = state->GetPartyMemberByIndex(memberId);
            if (member != 0)
            {
                if (SystemState_TestAnyFlags(mode, 0x200000) == 0 &&
                    ZoneFeatures_TestGameObjectInsideEntry(feature, *(short*)((char*)member + 4)))
                {
                    switch (*((unsigned char*)feature + 0x2c)) {
                    case 2: GameState_SetMemberMaskAndObjectFlags((char*)feature + 0x2c, (*(short*)((char*)member + 4)) & 0xff); break;
                    case 3: ZoneFeatures_BeginSubtypeThreeMemberMotion((char*)feature + 0x2c, (*(short*)((char*)member + 4)) & 0xff); break;
                    }
                }
                switch (*((unsigned char*)feature + 0x2c)) {
                case 2: ZoneFeatures_AdvanceSubtypeTwoMemberRotationAndFade((char*)feature + 0x2c, (*(short*)((char*)member + 4)) & 0xff); break;
                case 3: ZoneFeatures_AdvanceSubtypeThreeMemberMotion((char*)feature + 0x2c, (*(short*)((char*)member + 4)) & 0xff); break;
                }
            }
        }
        if (SystemState_TestAnyFlags(mode, 0x200000) == 0 && ZoneFeatures_TestGameObjectInsideEntry(feature, GameState_ReadFirstObjectIndex(state))) {
            if (*((unsigned char*)feature + 0x2c) == 1)
                ZoneFeatures_ActivateNetworkedTrigger((char*)feature + 0x2c);
        }
        else if (*((unsigned char*)feature + 0x2c) == 1)
        {
            ZoneFeatures_DeactivateNetworkedTrigger((char*)feature + 0x2c);
        }
        if (*((unsigned char*)feature + 0x2c) == 1)
            BMDJ_AdvanceCountdownAndCollisionFlag((char*)feature + 0x2c);
    }
    if (*zoneData == 0x1644 && BitArray_ReadNonnegativeIndexMask(waitState, (char*)waitState + 0x8c, 0x384) != 0)
        Zone3D_UpdateZone1644PartyCircularMotion();
}
