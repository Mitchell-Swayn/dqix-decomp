#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Matrix.h>
ARM
extern "C" {
void* GameState_GetIndexList(GameState* state);
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
int GameState_ReadProtagonistObjectIndex(GameState* state);
int PartyRoster_ContainsActiveObjectIndex(unsigned char* p, unsigned int value);
void Network_QueuePartyRecoveryCommand(const unsigned char* source);
}
struct Action { char pad[0x18]; unsigned low : 5, type : 7, rest : 20; };
struct Item { unsigned char kind, pad; short value; short extra; };
struct Encoded { signed short value : 11, other : 5; };
struct Event {
    unsigned char enabled, mode, submode, state;
    signed char members[3], count;
    Encoded values[3];
    unsigned char protagonist, pad;
};
// Original: arm9/ov002 @ 0x0216C42C; symbol: func_ov002_0216c42c; size: 0x1FC.
// Packs a 16-byte recovery event for input members absent from the current
// index list, records action-dependent modes, and copies a selected actor
// position for mode 4 / kind 3.
extern "C" void PartyMenu_QueueRemoteActionResultNotification(char* p, unsigned char* input, Action* action) {
    if (!input || !action)
        return;
    GameState* state = GameState::GetInstance();
    unsigned char* list = (unsigned char*)GameState_GetIndexList(state);
    Event event;
    memset(&event, 0, 16);
    event.enabled = 1;
    switch (action->type) {
    case 79:
    case 80:
        event.submode = 3;
    case 2:
        event.mode = 1;
        break;
    case 7:
        event.mode = 3;
        break;
    case 18:
        event.mode = 4;
        break;
    case 26:
        event.mode = 2;
        break;
    }
    if (action->low == 5)
        event.submode = 3;
    event.state = *(signed char*)(p + 0x1c20);
    signed char n = 0;
    for (int i = 0; i < input[3]; i++) {
        int member = *(signed char*)(input + 4 + i);
        if (PartyRoster_ContainsActiveObjectIndex(list, member))
            continue;
        event.members[n] = member;
        Encoded& encoded = event.values[n];
        Item* item = (Item*)(input + 8) + i;
        encoded.value = item->value;
        encoded.other = *(short*)(input + 0x22 + i * 6);
        if (event.mode == 4 && item->kind == 3) {
            char* actor = (char*)GameState_GetObjectWithFlag100(state, member);
            if (actor) {
                p[0x2522] = 1;
                p[0x2523] = 0;
                *(Vector3i*)(p + 0x2524) = *(const Vector3i*)(actor + 0x44);
            }
        }
        n = (signed char)(n + 1);
    }
    event.count = n;
    event.protagonist = (unsigned char)GameState_ReadProtagonistObjectIndex(state);
    Network_QueuePartyRecoveryCommand((unsigned char*)&event);
}
