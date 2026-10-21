#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM

struct State;
struct Tree;
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
Tree* Menu_FindSessionArenaById(Tree* tree, unsigned id);
void Menu_ResetItemListingSelection(void* record);
void Menu_QueueScriptEntry(State* self, unsigned value);
void Field_InitializeOverlayThirtyOneRequest(void*, unsigned, unsigned);
unsigned Menu_GetSharedDataBufferSize(State* self);
unsigned Menu_GetSharedDataBuffer(State* self);
void* Filesystem_FindTypeFourEmbeddedValue(void* state, unsigned short key);
unsigned int TextContext_GetSharedInstance();
unsigned int MessageTextTable_FindTextById(T* p, int key);
void TextWindow_StartFormattedMessage(void*, unsigned, unsigned, unsigned);
// Original data: arm9/ov004 @ 0x21707d8; symbol: MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
}

#define P(p, o) (*(char**)((char*)(p) + (o)))
#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define W(p, o) (*(unsigned*)((char*)(p) + (o)))

// Original: arm9/ov004 @ 0x0215BB54; symbol: func_ov004_0215bb54; size: 0x148.
// Starts the item-listing overlay request when the shared phase byte is 0, or
// queues the follow-up script when it is 1.
extern "C" int Menu_StartItemListingRequest(void* self)
{
    char* request;
    char* arena;
    unsigned size;

    request = P((char*)GameResources_GetInstance() + 0x3000, 0xb48);
    unsigned char flag = B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x13);
    if (flag == 0) {
        arena = (char*)Menu_FindSessionArenaById((Tree*)self, 1);
        if (!arena) {
            Menu_ResetItemListingSelection(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8));
            Menu_QueueScriptEntry((State*)self, 0x39e);
            B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x13) = 0;
            return 0;
        }
        Field_InitializeOverlayThirtyOneRequest(request, 4, 1);
        P(request, 8) = arena + 4;
        size = Menu_GetSharedDataBufferSize((State*)self);
        W(request, 0x34) = Menu_GetSharedDataBuffer((State*)self);
        W(request, 0x38) = size;
        B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x13) =
            B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x13) + 1;
        Menu_QueueScriptEntry((State*)self, 0x3aa);
        void* table = Filesystem_FindTypeFourEmbeddedValue(self, 4);
        unsigned int ctx = TextContext_GetSharedInstance();
        unsigned int text = MessageTextTable_FindTextById((T*)table, 0x13);
        TextWindow_StartFormattedMessage((void*)ctx, text, 0, 0xe3);
        W((char*)ctx, 0x998) = 1;
        goto done;
    }
    if (flag == 1) {
        Menu_QueueScriptEntry((State*)self, 0x3ab);
        B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x13) =
            B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage, 8), 0x13) + 1;
        return 0;
    }
done:
    return 1;
}
