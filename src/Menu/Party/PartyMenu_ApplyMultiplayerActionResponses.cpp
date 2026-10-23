#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct PartyMenuActionResponse {
    unsigned char action;
    unsigned char unknown01;
    short value;
    unsigned char pending;
    unsigned char unknown05;
};
extern "C" void Resource_UpdateStateForIndexedMode(void*, unsigned);
// Original: arm9/ov002 @ 0x0216C2D8; symbol: func_ov002_0216c2d8; size: 0x154.
// Copies both response records to matching member slots and advances when none remain pending.
extern "C" void PartyMenu_ApplyMultiplayerActionResponses(char* self, signed char* members,
    PartyMenuActionResponse* first, PartyMenuActionResponse* second, int count)
{
    PartyMenuActionResponse* actions = (PartyMenuActionResponse*)(self + 0x1cd0);
    PartyMenuActionResponse* replies = (PartyMenuActionResponse*)(self + 0x1ce8);
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < (unsigned char)self[0x1ccb]; ++j) {
            if (*(signed char*)(self + 0x1ccc + j) == members[i]) {
                actions[j].value = first[i].value;
                actions[j].action = first[i].action;
                actions[j].pending = 0;
                replies[j].value = second[i].value;
                replies[j].action = second[i].action;
                replies[j].pending = 0;
            }
        }
    }
    int pending = 0;
    for (int i = 0; i < (unsigned char)self[0x1ccb]; ++i)
        pending += actions[i].pending;
    if (!pending) Resource_UpdateStateForIndexedMode(self, 21);
    if (actions[0].action != 3) {
        self[0x2522] = 0;
        self[0x2523] = 0;
        memset(self + 0x2524, 0, 12);
        *(int*)(self + 0x2530) = 0;
    }
}
