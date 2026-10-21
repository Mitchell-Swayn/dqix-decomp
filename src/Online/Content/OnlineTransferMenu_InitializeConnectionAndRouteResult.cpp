#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
#pragma optimization_level 4

struct State;
struct Tree;

extern "C" {
Tree* Menu_FindSessionArenaById(Tree* tree, unsigned id);
void Menu_QueueScriptEntry(State* self, unsigned value);
void* Menu_GetDisplayRecordRegistry(State* self);
void Field_InitializeOverlayThirtyOneRequest(void*, unsigned, unsigned);
void Field_AdvanceOverlayThirtyOneRequest(void*, void*);
unsigned int OnlineDownload_HasInitializationResult(void* object);
unsigned int OnlineDownload_HasInitializationFailed(void* object);
void* MenuRecordList_LocateByKey(void** head, unsigned short value);
// Original data: arm9/ov004 @ 0x2171048; symbol: GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern unsigned char* GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[];
}

#define P(p, o) (*(char**)((char*)(p) + (o)))
#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define W(p, o) (*(unsigned*)((char*)(p) + (o)))

// Original: arm9/ov004 @ 0x0216F3B0; symbol: func_ov004_0216f3b0; size: 0x14c.
// Starts overlay-31 connection when shared[0x2e] is 0, then routes success or
// failure scripts once OnlineDownload reports an initialization result.
extern "C" int OnlineTransferMenu_InitializeConnectionAndRouteResult(void* self)
{
    char* resources = (char*)GameResources_GetInstance();
    unsigned char* shared = GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[1];
    char* overlayState = P(resources + 0x3000, 0x6fc);
    char* request = P(resources + 0x3000, 0xb48);
    unsigned char flag = shared[0x2e];
    char* arena;

    if (flag == 0) {
        arena = (char*)Menu_FindSessionArenaById((Tree*)self, 1);
        if (!arena) {
            Menu_QueueScriptEntry((State*)self, 0xd2);
            GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[1][0x2e] = 0;
            return 0;
        }
        Field_InitializeOverlayThirtyOneRequest(request, 2, 1);
        P(request, 8) = arena + 4;
        GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[1][0x2e] =
            GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[1][0x2e] + 1;
        goto done;
    }
    if (flag == 1) {
        Field_AdvanceOverlayThirtyOneRequest(request, overlayState);
        if (OnlineDownload_HasInitializationResult(request)) {
            if (OnlineDownload_HasInitializationFailed(request) && W(resources + 0x4000, 0x494) == 0) {
                Menu_QueueScriptEntry((State*)self, 0xcc);
                return 0;
            }
            if (!OnlineDownload_HasInitializationFailed(request)) {
                Menu_QueueScriptEntry((State*)self, 0xc9);
                GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[1][0x2e] =
                    GameStateSetState67AndFlags_UnknownRoleZeroInitializedStorage[1][0x2e] + 1;
                char* record = (char*)MenuRecordList_LocateByKey(
                    (void**)Menu_GetDisplayRecordRegistry((State*)self), 0x97);
                if (record) {
                    B(record, 0xc) = B(record, 0xc) & ~8;
                }
                return 0;
            }
        }
    }
done:
    return 1;
}
