#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/GameResources.h>
#include <Resource/Brightness.h>
#include <World/Object3D.h>
#include <World/Zone3D.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;

struct Flags { unsigned char low:2; unsigned char rest:6; };
struct Object { unsigned char pad[0xc1]; Flags flags; unsigned char pad2[0x190]; unsigned char a, b; };
struct State { unsigned char pad[0x150]; unsigned char reserved:6; unsigned char cleanup:1; unsigned char active:1; };
struct Node { signed char tag; char pad[3]; Node* next; };
struct FieldEventBeginScriptFrame { int count; int indices[4]; };

extern "C" void* GameState_GetFieldOrbitCamera(GameState* state);
extern "C" void* GameState_GetIndexList(GameState* state);
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState* state);
extern "C" void GameState_CopyIndexedObjectList(GameState* state, int index, int* indices, int* count);
extern "C" int GameState_GetFieldAddress5CA4(int param_1);
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsSessionActive(int* param_1);
extern "C" void* Zone3D_GetMainInstance();
extern "C" int LinkedList_ContainsTag(Node** p, int tag);
extern "C" bool LinkedQueue_IsEmpty(const int* value);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_SetFlags(unsigned int* word, unsigned int mask);
extern "C" int GameObject_GetLadderTraversalState(int param_1);
extern "C" undefined1 GameObject_GetLadderTraversalActive(int param_1);
extern "C" void GameObject_DisableMovementInput(Object* p, int reset);
extern "C" void Camera_DisableOrbitInput(int param_1);
extern "C" void* Script_ReadGlobalExecutionValue();
extern "C" void TimedMessageQueue_CancelAndClear(State* p);
extern "C" undefined4 Camera_GetOrbitHeading(int param_1);
extern "C" void GameResources_SetPrimaryFlags(unsigned int* word, unsigned int mask);
extern "C" uint GameResources_GetMaskedPrimaryFlags(uint* param_1, uint param_2);
extern "C" int OverlayLoader_GetPrimarySelectionOrMinusOne();
extern "C" void OverlayLoader_PushPrimarySelection(unsigned int index);
extern "C" void Memory_ResetAllocatorCache(void* allocator);
extern "C" void GameObject_SetUnknownTrackingContext(int param_1, undefined4 param_2);
extern "C" void Object3D_SaveIdentifierPositionAndRotation(unsigned char* p);
extern "C" void GameObject_DisableMotionUpdates(int param_1);
extern "C" void* GameObject_ResetFollowTrail(unsigned char* p);
extern "C" void Field_ResetEventCommandScratchRecord(unsigned* record);
extern "C" void FieldEvent_ReleaseResourcesAndResumeFieldControl(void*);
extern "C" char FieldEvent_BeginScriptLoadAndSuspendFieldControl_TextStand[];
extern "C" char FieldEvent_BeginScriptLoadAndSuspendFieldControl_PathDataMapIneventdata3Bin[];
extern "C" char FieldEventBeginScriptLoadAndSuspendFieldControl_TextR0[];
extern "C" char FieldEvent_BeginScriptLoadAndSuspendFieldControl_TextM01[];
extern "C" char FieldEvent_BeginScriptLoadAndSuspendFieldControl_PathDataEvsptLv5EventlistLv5Bin[];
extern "C" char FieldEvent_BeginScriptLoadAndSuspendFieldControl_PathDataEventEvlQuestBin[];
extern "C" char FieldEvent_BeginScriptLoadAndSuspendFieldControl_PathDataEventEventlist6Bin[];

// Original: arm9/ov017 @ 0x021BBC10; symbol: func_ov017_021bbc10; size: 0x3b4.
// Suspends field control, stages party animation, and queues the event script
// load selected by map/quest range.
extern "C" unsigned FieldEvent_BeginScriptLoadAndSuspendFieldControl(unsigned char* self)
{
    FieldEventBeginScriptFrame frame;
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameObject* unknown = game->GetUnknownGameObject();
    void* camera = GameState_GetFieldOrbitCamera(game);
    GameResources* resources = GameResources_GetInstance();
    void* network = Network_GetConnectionManager();
    if (LinkedList_ContainsTag((Node**)*(void**)((char*)resources + 0x36fc), 1)) {
        self[0xff] = 1;
        self[1] = 1;
        return *(unsigned short*)(self + 0xa);
    }
    SystemState_SetFlags((unsigned int*)SystemState_GetGlobalFlags(), 0x400e);
    if (*(int*)((char*)resources + 0x4080))
        return *(unsigned short*)(self + 0xa);
    int ladder = GameObject_GetLadderTraversalState((int)unknown);
    if (GameObject_GetLadderTraversalActive((int)unknown)
        && *(unsigned char*)(ladder + 1) != 2)
        return *(unsigned short*)(self + 0xa);
    if (!self[0xfd]) {
        if (!LinkedQueue_IsEmpty((const int*)*(void**)((char*)resources + 0x3700)))
            return *(unsigned short*)(self + 0xa);
    }
    GameResources_SetPrimaryFlags((unsigned int*)resources, 0x10);
    if (!GameResources_GetMaskedPrimaryFlags((uint*)resources, 0x1000)) {
        if (OverlayLoader_GetPrimarySelectionOrMinusOne() != 1)
            OverlayLoader_PushPrimarySelection(1);
    }
    Memory_ResetAllocatorCache(0);
    GameObject_DisableMovementInput((Object*)unknown, 1);
    Camera_DisableOrbitInput((int)camera);
    TimedMessageQueue_CancelAndClear((State*)Script_ReadGlobalExecutionValue());
    *(unsigned short*)((char*)camera + 0x21e) = Camera_GetOrbitHeading((int)camera);
    if (Network_IsSessionActive((int*)network)) {
        unsigned char* list = (unsigned char*)GameState_GetIndexList(game);
        int i;
        for (i = 0; i < list[0xf7c]; ++i) {
            unsigned char* entry = list + i;
            GameObject* object = GameState_GetObjectWithFlag100(game, entry[0xf78]);
            if (!object)
                continue;
            GameObject_SetUnknownTrackingContext((int)object, 3);
            Object3D_SaveIdentifierPositionAndRotation((unsigned char*)object);
        }
    }
    GameState_CopyIndexedObjectList(
        game, GameState_ReadProtagonistObjectIndex(game), frame.indices, &frame.count);
    int n;
    for (n = 0; n < frame.count; ++n) {
        GameObject* member = game->GetPartyMemberByIndex(frame.indices[n]);
        if (!member)
            continue;
        GameObject_DisableMotionUpdates((int)member);
        if (!GameObject_GetLadderTraversalActive((int)member)
            || *(unsigned char*)(GameObject_GetLadderTraversalState((int)member) + 1) != 2) {
            member->obj3D_.SetAnimationByName(
                FieldEvent_BeginScriptLoadAndSuspendFieldControl_TextStand, 0x10);
        }
        GameObject_ResetFollowTrail((unsigned char*)member);
    }
    GameObject* extra = game->GetPartyMemberByIndex(0xce);
    if (extra)
        GameObject_ResetFollowTrail((unsigned char*)extra);
    Field_ResetEventCommandScratchRecord((unsigned*)(self + 0xd0));
    int* field = (int*)GameState_GetFieldAddress5CA4((int)game);
    field[0] = 0;
    field[1] = 0;
    loader->AddFence();
    if (self[0x9c]) {
        *(int*)(self + 0x74) = loader->QueueLoadFile(
            FieldEvent_BeginScriptLoadAndSuspendFieldControl_PathDataMapIneventdata3Bin, 0);
    } else if (self[0xcc]) {
        unsigned char* zone = (unsigned char*)Zone3D_GetMainInstance();
        char* name = *(char**)(zone + 8);
        GameObject* object = game->GetGameObjectByIndex(self[0xcd]);
        if (!object
            || !strstr(name + 5, FieldEventBeginScriptLoadAndSuspendFieldControl_TextR0)
            || !strstr(name + 5, FieldEvent_BeginScriptLoadAndSuspendFieldControl_TextM01)) {
            SetBrightness(resources, 0, 0x28);
            FieldEvent_ReleaseResourcesAndResumeFieldControl(self);
            self[1] = 1;
            return *(unsigned short*)(self + 0xa);
        }
        return 0xc;
    } else {
        unsigned short code = *(unsigned short*)(self + 8);
        if (code >= 0x5208 && code < 0x9c40) {
            *(int*)(self + 0x74) = loader->QueueLoadFile(
                FieldEvent_BeginScriptLoadAndSuspendFieldControl_PathDataEvsptLv5EventlistLv5Bin, 0);
            loader->GetNumQueuedTasks();
        } else if (code >= 0x9c40) {
            *(int*)(self + 0x74) = loader->QueueLoadFile(
                FieldEvent_BeginScriptLoadAndSuspendFieldControl_PathDataEventEvlQuestBin, 0);
        } else {
            *(int*)(self + 0x74) = loader->QueueLoadFile(
                FieldEvent_BeginScriptLoadAndSuspendFieldControl_PathDataEventEventlist6Bin, 0);
        }
    }
    return 1;
}
