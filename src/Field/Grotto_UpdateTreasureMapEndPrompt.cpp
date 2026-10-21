#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <Memory/AllocatorUnion.h>
#include <Resource/Script.h>
#include <System/Memory.h>
#include <std_library_functions.h>

typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
struct Flags { unsigned char low:2; unsigned char rest:6; };
struct Object { unsigned char pad[0xc1]; Flags flags; unsigned char pad2[0x190]; unsigned char a,b; };
struct LoaderTaskOwner;
struct State { unsigned char pad[0x150]; unsigned char reserved:6; unsigned char cleanup:1; unsigned char active:1; };
struct Buffer { char pad[0x4ac]; char names[16][64]; };
struct E { short key; short pad; unsigned int value; };
struct T { E* data; short count; };

extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion* a, unsigned size);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* Network_GetConnectionManager();
extern "C" void* GameState_GetFieldOrbitCamera(GameState* state);
extern "C" void GameState_ResetGrottoAndTreasureMapInitialFlags(GameState* state);
extern "C" void GameObject_DisableMovementInput(Object* p, int reset);
extern "C" void GameObject_RequestMovementInputEnable(int param_1);
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" unsigned int DisplayContext_GetGlobalInstance();
extern "C" void DisplayContext_IgnoreRequest(void* context, int request, int argument);
extern "C" undefined4 DisplayContext_ReportRequestComplete(void);
extern "C" void DisplayContext_IgnoreRequestToken(void* object, unsigned int requestToken);
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(LoaderTaskOwner* owner);
extern "C" void TextWindow_StartFormattedMessage(void*, unsigned, unsigned, unsigned);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void* p);
extern "C" undefined4 TextWindow_GetChoiceResult(int param_1);
extern "C" void TextLayout_ResetFormattingWorkspace(signed char* object);
extern "C" void TextContext_SetStringArgument(Buffer* p, int i, const char* s);
extern "C" void Script_ExecuteCodeWithGlobalContextValues(void* a, void* b, const void* code, unsigned length, void* c, unsigned short value, unsigned char flag);
extern "C" unsigned int MessageTextTable_FindTextById(T* p, int key);
extern "C" void* Script_ReadGlobalExecutionValue();
extern "C" void TimedMessageQueue_CancelAndClear(State* p);
extern "C" void Camera_DisableOrbitInput(int param_1);
extern "C" void ComputeGrottoAndContextDependentStateFlags(int mode);
extern "C" void Grotto_ReleaseTreasureMapEndPrompt(void* context);
extern "C" char Grotto_UpdateTreasureMapEndPrompt_PathDataBinTmsEndGp2[];
extern "C" char Grotto_UpdateTreasureMapEndPrompt_MarkupTmsEndLGBin[];

// Original: arm9/ov017 @ 0x021BF014; symbol: func_ov017_021bf014; size: 0x34c.
// Loads tms_end script, then advances the treasure-map completion prompt through
// discovery-state text, choice, grotto reset, and resource release.
extern "C" void Grotto_UpdateTreasureMapEndPrompt(unsigned char* self)
{
    void* loadedFile;
    unsigned loadedSize;
    GameState* game = GameState::GetInstance();
    Network_GetConnectionManager();
    GameResources_GetInstance();
    unsigned int text = TextContext_GetSharedInstance();
    Zone3D_GetMainInstance();
    GrottoStruct* grotto = game->GetGrottoStruct();
    GameObject* unknown = game->GetUnknownGameObject();
    void* camera = GameState_GetFieldOrbitCamera(game);
    int state = *(int*)(self + 8);
    if (state == 0) {
        TimedMessageQueue_CancelAndClear((State*)Script_ReadGlobalExecutionValue());
        GameObject_DisableMovementInput((Object*)unknown, 1);
        Camera_DisableOrbitInput((int)camera);
        void* buffer = AllocatorUnion_AllocateFourByteAligned(
            &Main_UnknownRoleZeroInitializedStorage_Variant3, 0x320);
        ((SafeAllocator*)(self + 0x14))->CreateTypeA(buffer, 0x320);
        *(int*)(self + 0x28) = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(
            Grotto_UpdateTreasureMapEndPrompt_PathDataBinTmsEndGp2,
            Grotto_UpdateTreasureMapEndPrompt_MarkupTmsEndLGBin,
            (SafeAllocator*)0);
        *(int*)(self + 8) = 1;
    } else if (state == 1) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (!loader->GetTaskStatus(*(int*)(self + 0x28))) {
            return;
        }
        loader = BackgroundLoader::GetInstance();
        loader->GetLoadedFileByID(*(int*)(self + 0x28), &loadedFile, &loadedSize);
        ((SafeAllocator*)(self + 0x14))->Reset();
        Script_ExecuteCodeWithGlobalContextValues(
            self + 0xc, self + 0x14, loadedFile, loadedSize, 0, 0, 0);
        BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0x28));
        *(int*)(self + 0x28) = -1;
        TextLayout_ResetFormattingWorkspace((signed char*)text);
        unsigned char* object = (unsigned char*)game->GetUnknownGameObject();
        TextContext_SetStringArgument((Buffer*)text, 0, *(const char**)(object + 0x134));
        DisplayContext_IgnoreRequest((void*)DisplayContext_GetGlobalInstance(), 0x203, 0);
        *(int*)(self + 8) = 2;
    }
    state = *(int*)(self + 8);
    if (state == 2) {
        DisplayContext_GetGlobalInstance();
        if (!DisplayContext_ReportRequestComplete()) {
            return;
        }
        if (grotto->activeMapData.GetDiscoveryState() == 1)
            *(int*)(self + 8) = 3;
        else
            *(volatile int*)(self + 8) = 4;
        return;
    }
    if (state == 3) {
        char* dest = *(char**)((char*)text + 0x5c);
        strcpy(dest, (char*)MessageTextTable_FindTextById((T*)(self + 0xc), 1));
        TextWindow_StartFormattedMessage((void*)text, (unsigned)dest, 0, 0xe3);
        ((unsigned char*)text)[0x19b2] = 0;
        *(int*)((char*)text + 0x2c8) = 0;
        *(int*)((char*)text + 0x998) = 1;
        *(int*)(self + 8) = 5;
        return;
    }
    if (state == 4) {
        char* dest = *(char**)((char*)text + 0x5c);
        strcpy(dest, (char*)MessageTextTable_FindTextById((T*)(self + 0xc), 2));
        TextWindow_StartFormattedMessage((void*)text, (unsigned)dest, 0, 0xe3);
        ((unsigned char*)text)[0x19b2] = 0;
        *(int*)((char*)text + 0x998) = 1;
        *(int*)((char*)text + 0x2c8) = 0;
        *(int*)(self + 8) = 5;
        return;
    }
    if (state == 5) {
        GameObject_DisableMovementInput((Object*)unknown, 1);
        if (*(int*)((char*)text + 0x998)) {
            return;
        }
        ((unsigned char*)grotto)[2] = 1;
        undefined4 choice = TextWindow_GetChoiceResult((int)text);
        if (choice == 0) {
            *(int*)(self + 8) = 6;
            return;
        }
        if (choice == 1) {
            *(int*)(self + 8) = 9;
        }
        return;
    }
    if (state == 6) {
        GameState_ResetGrottoAndTreasureMapInitialFlags(game);
        ComputeGrottoAndContextDependentStateFlags(0);
        *(int*)(self + 8) = 7;
        return;
    }
    if (state == 7) {
        *(int*)(self + 8) = 8;
        return;
    }
    if (state == 8) {
        GameObject_DisableMovementInput((Object*)unknown, 1);
        if (*(int*)((char*)text + 0x9a0) == 0) {
            *(int*)(self + 8) = 9;
        }
        return;
    }
    if (state == 9) {
        TextWindow_ResetGlyphBuffersAndFrameContexts((void*)text);
        GameObject_RequestMovementInputEnable((int)unknown);
        unsigned int display = DisplayContext_GetGlobalInstance();
        DisplayContext_IgnoreRequestToken((void*)display, 0x203);
        BackgroundLoader_CancelEightTasksAndResetState((LoaderTaskOwner*)display);
        Grotto_ReleaseTreasureMapEndPrompt(self);
    }
}
