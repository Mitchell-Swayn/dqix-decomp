#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/GameResources.h>
#include <std_library_functions.h>
ARM
#pragma opt_propagation off

struct State;
struct E {
    short key;
    short pad;
    unsigned int value;
};
struct T {
    E* data;
    short count;
};

extern "C" {
void GameState_ClearMaskFromKeyedEntry(State* self, unsigned short value, unsigned char mask);
void* SystemState_GetGlobalFlags();
void SystemState_SetFlags(unsigned int* word, unsigned int mask);
void SystemState_ClearFlags(unsigned int* word, unsigned int mask);
int SaveData_AdvanceStagedSaveWrite(int, int, int, int);
void* GameState_AppendValueAndSetNodeFlags(void* unused, unsigned short value, unsigned int flags);
unsigned int TextContext_GetSharedInstance();
void* Filesystem_FindTypeFourEmbeddedValue(void* state, unsigned short key);
unsigned int MessageTextTable_FindTextById(T* p, int key);
void Menu_CommitPendingListingAndRemoveInventoryItems(void* self);
void* Zone3D_GetMainInstance();
ARM void ResourceHandle_SwitchTargetUnlessBlocked(State* p, int arg);
void Bgm_SetVolumeSetting(State* self, int mode);
void* OnlineDownload_GetArchiveEntryTable(unsigned char* p);
void Menu_SetSharedDataBufferAndSize(State* self, unsigned value, unsigned other);
void Menu_QueueScriptEntry(State* self, unsigned value);
void TextWindow_StartFormattedMessage(void*, unsigned, unsigned, unsigned);
// Original data: arm9/ov004 @ 0x21707d8; symbol: MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x211e33c; symbol: Main_UnknownRoleZeroInitializedStorage_Variant6.
extern char Main_UnknownRoleZeroInitializedStorage_Variant6[];
// Original data: arm9/main @ 0x2109bf4; symbol: Main_UnknownRoleZeroInitializedStorage_Variant2.
extern char Main_UnknownRoleZeroInitializedStorage_Variant2[];
extern char Menu_SaveItemMarketStateAndResumeRequestResult_TextInfo[];
}

#define P(p, o) (*(char**)((char*)(p) + (o)))
#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))

// Original: arm9/ov004 @ 0x0215C974; symbol: func_ov004_0215c974; size: 0x278.
// Writes staged item-market save state, then resumes the listing result
// message from either committed inventory or overlay-31 archive entries.
extern "C" int Menu_SaveItemMarketStateAndResumeRequestResult(void* self)
{
    GameState_ClearMaskFromKeyedEntry((State*)self, 0x36, 8);
    unsigned int* flags = (unsigned int*)SystemState_GetGlobalFlags();
    SystemState_SetFlags(flags, 0x80);
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    int saved = SaveData_AdvanceStagedSaveWrite(
        (int)(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8) + 0x84),
        (int)Main_UnknownRoleZeroInitializedStorage_Variant6,
        0xa,
        0);
    int success = saved != 0 ? 1 : 0;
    BackgroundLoader::RemoveLockGlobal();
    if (success == 0)
        return 1;
    SystemState_ClearFlags(flags, 0x80);
    GameState_AppendValueAndSetNodeFlags(self, 0x36, 8);
    char* gs;
    unsigned int ctx;
    char* buffer;
    T* table;
    ctx = TextContext_GetSharedInstance();
    buffer = *(char**)((char*)ctx + 0x5c);
    memset(buffer, 0, 0x960);
    gs = (char*)GameState::GetInstance() + 0x26c;
    table = (T*)Filesystem_FindTypeFourEmbeddedValue(self, 4);
    char* text = (char*)MessageTextTable_FindTextById(table, 0x21);
    unsigned int length = strlen(text);
    memcpy(buffer, text, length);
    buffer += length;
    if (B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x15) != 0) {
        Menu_CommitPendingListingAndRemoveInventoryItems(self);
        char* zone = (char*)Zone3D_GetMainInstance();
        unsigned kind = B(P(zone, 8), 0xd);
        kind <<= 25;
        kind >>= 25;
        ResourceHandle_SwitchTargetUnlessBlocked((State*)Main_UnknownRoleZeroInitializedStorage_Variant2, (int)kind);
        Bgm_SetVolumeSetting(
            (State*)Main_UnknownRoleZeroInitializedStorage_Variant2,
            B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x2d));
        goto show_window;
    }
    if (B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x14) == 0)
        goto show_window;
    {
        unsigned char* request = *(unsigned char**)((char*)GameResources_GetInstance() + 0x3000 + 0xb48);
        char* entry = (char*)OnlineDownload_GetArchiveEntryTable(request);
        char* cursor = *(char**)(request + 0x34);
        int i = 0;
        goto compare;
        for (;;) {
            if (strstr(entry + 0x88, Menu_SaveItemMarketStateAndResumeRequestResult_TextInfo) != 0) {
                Menu_SetSharedDataBufferAndSize((State*)self, (unsigned)cursor, *(unsigned*)(entry + 0xac));
                goto found;
            }
            unsigned size = *(unsigned*)(entry + 0xac);
            entry += 0xb0;
            cursor += size;
            i = i + 1;
        compare:
            if (i < 4)
                continue;
            break;
        }
    found:
        if (i == 4)
            goto queue_3ad;
        Menu_QueueScriptEntry((State*)self, 0x394);
        goto after_queue;
    queue_3ad:
        Menu_QueueScriptEntry((State*)self, 0x3ad);
    after_queue:
        unsigned bits = *(unsigned short*)(gs + 0x5d00 + 0xc);
        bits <<= 19;
        bits >>= 19;
        if (bits & 0x40) {
            char* extra = (char*)MessageTextTable_FindTextById(table, 0x1c);
            unsigned int extraLen = strlen(extra);
            memcpy(buffer, extra, extraLen);
            buffer += extraLen;
        }
        bits = *(unsigned short*)(gs + 0x5d00 + 0xc);
        bits <<= 19;
        bits >>= 19;
        if (bits & 0x200) {
            char* extra = (char*)MessageTextTable_FindTextById(table, 0x1f);
            memcpy(buffer, extra, strlen(extra));
        }
    }
show_window:
    TextWindow_StartFormattedMessage((void*)ctx, *(unsigned*)((char*)ctx + 0x5c), 0, 0xe3);
    *(unsigned*)((char*)ctx + 0x998) = 1;
    return 0;
}
