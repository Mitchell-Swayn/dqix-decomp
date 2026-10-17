#include <globaldefs.h>
ARM
#include <System/Matrix.h>
struct GameState; struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*, int);
extern "C" int GameState_ReadFirstObjectIndex(GameState*);
extern "C" void* GameState_GetIndexList(GameState* state);
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(char* object,int value);
extern "C" void ShiftCurrentByteValueToPreviousAndRefresh(unsigned char *p,unsigned char value);
extern "C" void* ClearThreeBytesAnd128ByteBuffer(unsigned char* p);
extern "C" void SetMaskedFlagsAtOffset1CE(int self);
struct PartyList { unsigned char pad[0xc00]; unsigned char indices[4]; unsigned char count; };
struct IndexList { unsigned char pad[0x378]; PartyList party; };
// Original: arm9/ov017 @ 0x021921FC; symbol: func_ov017_021921fc; size: 0xB0.
extern "C" void GameState_SetListedPartyPositionAndAngle(const Vector3i *position, int angle, int reset) {
    GameState *state = (GameState*)_ZN9GameState11GetInstanceEv();
    IndexList *list = (IndexList*)GameState_GetIndexList(state);
    PartyList &party = list->party;
    int i = 0;
    for (; i < list->party.count; i++) {
        unsigned char *object = (unsigned char*)_ZN9GameState21GetPartyMemberByIndexEi(state, party.indices[i]);
        if (!object) continue;
        *(Vector3i*)(object + 0x44) = *position;
        Object3D_SetNormalizedAngleAndUpdatePosition((char*)object, angle);
        if (reset) {
            ShiftCurrentByteValueToPreviousAndRefresh(object, 0);
            *(short*)(object + 0xb2) = 0;
            ClearThreeBytesAnd128ByteBuffer(object);
        }
        if (party.indices[i] != GameState_ReadFirstObjectIndex(state)) SetMaskedFlagsAtOffset1CE((int)object);
    }
}
