#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "System/Memory.h"
typedef unsigned int undefined4;
struct State {
    unsigned char pad[0x150];
    unsigned char reserved:6;
    unsigned char cleanup:1;
    unsigned char active:1;
};

extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* GameState_GetFieldOrbitCamera(GameState* state);
extern "C" int GameState_GetFieldVisualObject(int param_1);
extern "C" void* GameState_ReadUnkF8(GameState* state);
extern "C" void* Script_ReadGlobalExecutionValue();
extern "C" void TimedMessageQueue_CancelAndClear(State* p);
extern "C" void FieldVisualActor_DisableMovementInput(int param_1);
extern "C" void FieldVisualActor_EnableMovementInput(int param_1);
extern "C" void* Text_LookupStandardString(unsigned key);
extern "C" void TextWindow_StartFormattedMessage(void*, unsigned, unsigned, unsigned);
extern "C" void Camera_SetFollowControlFlags(int self, unsigned char mask);
extern "C" void Camera_ClearFollowControlFlags(unsigned char* p, unsigned char mask);
extern "C" undefined4 TextWindow_GetChoiceResult(int param_1);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void* p);

// Original: arm9/ov017 @ 0x021A9454; symbol: func_ov017_021a9454; size: 0x1e4.
// Two-phase yes/no prompt for a fixed field destination: opens the formatted
// confirm window, then on accept fills the field-transition request and marks
// the command complete.
extern "C" void Field_AdvanceFixedDestinationConfirmation(unsigned char* self) {
    GameState* game = GameState::GetInstance();
    unsigned int text = TextContext_GetSharedInstance();
    Zone3D_GetMainInstance();
    void* camera = GameState_GetFieldOrbitCamera(game);
    int phase = *(int*)(self + 8);
    if (phase == 0) {
        TimedMessageQueue_CancelAndClear((State*)Script_ReadGlobalExecutionValue());
        FieldVisualActor_DisableMovementInput(GameState_GetFieldVisualObject((int)game));
        char* buffer = *(char**)((char*)text + 0x5c);
        if (*(int*)(self + 0x10) == 0) {
            sprintf(buffer, (char*)Text_LookupStandardString(0x3a));
        } else {
            sprintf(buffer, (char*)Text_LookupStandardString(0x3b));
            *(int*)(self + 0xc) = 0x170c;
        }
        TextWindow_StartFormattedMessage((void*)text, (unsigned)buffer, 0, 0xe3);
        *((unsigned char*)text + 0x1000 + 0x9b2) = 0;
        *(int*)((char*)text + 0x998) = 1;
        Camera_SetFollowControlFlags((int)camera, 2);
        *(int*)(self + 8) = 1;
        return;
    }
    if (phase == 1 && *(int*)((char*)text + 0x9a0) == 0) {
        Camera_ClearFollowControlFlags((unsigned char*)camera, 2);
        if (TextWindow_GetChoiceResult((int)text) == 0) {
            GameState_GetFieldVisualObject((int)game);
            char* request = (char*)GameState_ReadUnkF8(game);
            VectorizedMemset(request, 0, 0x70);
            request[4] = 1;
            request[8] = 1;
            request[9] = 1;
            request[11] = -1;
            *(int*)(request + 32) = -1;
            *(int*)(request + 36) = -1;
            *(int*)(request + 40) = -1;
            *(int*)(request + 44) = -1;
            *(short*)(request + 30) = -1;
            request[12] = 0;
            *(short*)(request + 108) = -1;
            *(short*)request = (short)*(int*)(self + 0xc);
            request[2] = 1;
            request[7] = 1;
            if (*(int*)(self + 0x10) == 0) {
                *(int*)(request + 0x10) = 0x100000;
                *(int*)(request + 0x14) = 0;
                *(int*)(request + 0x18) = 0x100000;
                *(short*)(request + 0x1c) = 0;
            } else {
                *(int*)(request + 0x10) = 0x5f0a;
                *(int*)(request + 0x14) = 0x3614;
                *(int*)(request + 0x18) = 0x570;
                *(short*)(request + 0x1c) = 0x4b66;
            }
            TextWindow_ResetGlyphBuffersAndFrameContexts((void*)text);
            self[1] = 1;
            return;
        }
        TextWindow_ResetGlyphBuffersAndFrameContexts((void*)text);
        FieldVisualActor_EnableMovementInput(GameState_GetFieldVisualObject((int)game));
        self[1] = 1;
    }
}
