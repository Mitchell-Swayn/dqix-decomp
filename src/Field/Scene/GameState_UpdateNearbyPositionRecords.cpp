#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Network_GetConnectionManager();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" int GameObject_GetMovementInputEnabled(void*);
extern "C" int GameObject_HasQueuedActions(signed char*);
extern "C" int GameState_ReadFirstObjectIndex(void*);
extern "C" void GameState_ConsumeNearbyMatchingPositionRecord(int,int);
extern "C" int Network_IsParentOrOffline(unsigned*);
// Original: arm9/ov017 @ 0x021C25AC; symbol: GameState_UpdateNearbyPositionRecords; size: 0xDC.
// Scans party and field-object index ranges, consuming a nearby matching position record for each slot.
extern "C" void GameState_UpdateNearbyPositionRecords(void) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* connection = Network_GetConnectionManager();
    void* gameObject = _ZN9GameState20GetUnknownGameObjectEv(state);
    if (gameObject && GameObject_GetMovementInputEnabled(gameObject) && !GameObject_HasQueuedActions((signed char*)gameObject)) {
        for (int member = 0; member < 4; ++member)
            GameState_ConsumeNearbyMatchingPositionRecord(member, GameState_ReadFirstObjectIndex(state));
    }
    if (Network_IsParentOrOffline((unsigned*)connection)) {
        for (int party = 0; party < 4; ++party)
            for (int index = 0; index < 48; ++index)
                GameState_ConsumeNearbyMatchingPositionRecord(party, index + 0x70);
    } else {
        for (int index = 0; index < 48; ++index)
            GameState_ConsumeNearbyMatchingPositionRecord(GameState_ReadFirstObjectIndex(state), index + 0x70);
    }
}
