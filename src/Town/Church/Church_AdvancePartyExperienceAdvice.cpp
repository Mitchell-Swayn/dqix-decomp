#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
ARM
#pragma scheduling off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
#pragma opt_repositioncode off
#pragma opt_optimizecontrolflow off
extern "C" {
unsigned int TextContext_GetSharedInstance();
void Window_SetCanvasDisplayAttribute(char* p,int a,int value);
void* ResourceStringTable_GetTextByKey(void* a,void* b);
int Text_AppendFormatString(char* p,const char* text);
void* __clear(void* destination, unsigned int count);
unsigned int GameState_CopyActivePartySlotList(GameState* state, void* destination);
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
void Church_FormatMemberExperienceAdvice(void* self, void* member, void* buffer);
int Church_StartConfiguredMessage(...);
void Church_SetWindowEmphasisAndRefreshText(char* self,int id,int enabled);
}

// Original: arm9/ov003 @ 0x0215A5B4; symbol: func_ov003_0215a5b4; size: 0x18C.
// Builds the church experience-advice message from present party members whose
// linked record nibble at +0x56b is clear, then restores window emphasis.
extern "C" void Church_AdvancePartyExperienceAdvice(unsigned char* self)
{
    char* message;
    unsigned char phase;
    unsigned int shared = TextContext_GetSharedInstance();
    phase = self[0x580];
    if (phase == 0) {
        GameState* game = GameState::GetInstance();
        Window_SetCanvasDisplayAttribute((char*)(self + 0xf4), 0, 1);
        Window_SetCanvasDisplayAttribute((char*)(self + 0xf4), 1, 1);
        Window_SetCanvasDisplayAttribute((char*)(self + 0xf4), 2, 1);
        memset(*(void**)(self + 0x7c), 0, 0x960);
        Text_AppendFormatString(
            *(char**)(self + 0x7c),
            (const char*)ResourceStringTable_GetTextByKey(self + 0x64, (void*)0x3fc));
        message = *(char**)(self + 0x7c);
        unsigned char slots[4];
        __clear(slots, 4);
        unsigned int count = GameState_CopyActivePartySlotList(game, slots);
        int i = 0;
        goto check;
    body:
        {
            GameObject* member = GameState_GetObjectWithFlag100(game, slots[i]);
            if (member) {
                unsigned char* record = *(unsigned char**)((char*)member + 0x150);
                int flagged;
                if (record) {
                    unsigned int bits = record[0x56b];
                    bits = bits << 28;
                    bits = bits >> 28;
                    if (bits != 0)
                        flagged = 1;
                    else
                        flagged = 0;
                } else {
                    flagged = 0;
                }
                if (flagged == 0) {
                    memset(message + 0x860, 0, 0x80);
                    Church_FormatMemberExperienceAdvice(self, member, message + 0x860);
                    Text_AppendFormatString(*(char**)(self + 0x7c), message + 0x860);
                }
            }
            i = i + 1;
        }
    check:
        if (i < (int)count)
            goto body;
        Text_AppendFormatString(
            *(char**)(self + 0x7c),
            (const char*)ResourceStringTable_GetTextByKey(self + 0x64, (void*)0x42e));
        Church_StartConfiguredMessage(self, *(void**)(self + 0x7c));
        self[0x580] = (unsigned char)(self[0x580] + 1);
    }
    if (phase == 1) {
        if (*(int*)((char*)shared + 0x9a0) != 3)
            return;
        Church_SetWindowEmphasisAndRefreshText((char*)self, 1, 0);
        self[0x588] = 2;
        self[0x580] = 0;
    }
}
