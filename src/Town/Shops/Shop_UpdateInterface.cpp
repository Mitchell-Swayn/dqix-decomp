#include <globaldefs.h>
ARM
struct KeyRepeater;
struct Obj;
struct A { char pad[0x3f]; unsigned char bit : 1; };
struct Screen { void Handler(); };
typedef void (Screen::*Handler)();
extern "C" {
ARM int Field_IsHostDisconnectPending();
void BeginDisplayResetAndClearLinkedOwner(char* self);
void Graphics_AdvanceDisplayCommandFlag40(unsigned char* p);
void Owner_DispatchAndClearPendingFlag(unsigned char *owner);
void Shop_RefreshPendingDisplayPart(char *p);
void Shop_AdvanceTransactionMessage(unsigned char* self);
unsigned int TextContext_GetSharedInstance();
void TextWindow_ResetGlyphBuffersAndFrameContexts(void* p);
ARM void DisplayLayout_AdvanceActiveCanvases(unsigned char *param_1, unsigned int param_2);
unsigned char KeyRepeater_Update(KeyRepeater* repeater, int elapsed);
unsigned TextCanvas_UpdateSelectionFromTouchOrDirection(unsigned char*, short*, int, unsigned short, unsigned char, int);
void TextCanvas_ClearGroupEntrySelection(unsigned char* p, int key);
int TextCanvas_CreateAndConfigureDisplayPart(char* self, int index);
unsigned int Window_IsVisible(A **p);
ARM void Window_UpdateOptionSelectionAndEntry(Obj* p, int arg);
extern unsigned ShopUpdateInterface_UnknownRoleZeroInitializedStorage;
extern Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
extern Handler ShopUpdateInterface_UnknownRoleProcedureReferenceRecords[];
}

// Original: arm9/ov003 @ 0x021745FC; symbol: func_ov003_021745fc; size: 0x210.
// Advances shop display parts and input, then dispatches the active stage
// member handler from ShopUpdateInterface_UnknownRoleProcedureReferenceRecords.
extern "C" int Shop_UpdateInterface(unsigned char* self, int ticks)
{
    *(int*)(self + 0xfe0) = ticks;
    if (Field_IsHostDisconnectPending())
        BeginDisplayResetAndClearLinkedOwner((char*)self);
    Graphics_AdvanceDisplayCommandFlag40(self);
    Owner_DispatchAndClearPendingFlag(self);
    Shop_RefreshPendingDisplayPart((char*)self);
    if (self[0x103e] != 0) {
        if (*(short*)(self + 0x1036) >= 0) {
            Shop_AdvanceTransactionMessage(self);
            return 0;
        }
        *(unsigned char*)((char*)TextContext_GetSharedInstance() + 0x19ae) = 0;
        unsigned char* canvas = *(unsigned char**)(self + 0x89c);
        if (canvas)
            DisplayLayout_AdvanceActiveCanvases(canvas, (unsigned)ticks);
        if (*(short**)(self + 0xff8)) {
            KeyRepeater_Update((KeyRepeater*)(self + 0x88c), ticks);
            *(short*)(self + 0x1000) = **(short**)(self + 0xff8);
            *(unsigned*)(self + 0xfe4) = TextCanvas_UpdateSelectionFromTouchOrDirection(
                canvas,
                *(short**)(self + 0xff8),
                *(short*)(self + 0x1000),
                *(unsigned short*)(self + 0x898),
                self[0x89a],
                (*(unsigned short*)(self + 0x1046) & 0x400) != 0);
            *(short*)(canvas + 0x36) = **(short**)(self + 0xff8);
            if (*(unsigned*)(self + 0xfe4))
                TextCanvas_ClearGroupEntrySelection(canvas, *(short*)(self + 0xffe));
            if (*(short*)(self + 0x1000) != **(short**)(self + 0xff8))
                TextCanvas_CreateAndConfigureDisplayPart((char*)canvas, *(short*)(self + 0xffe));
        }
    }
    if (*(void**)self && Window_IsVisible((A**)*(void**)self))
        Window_UpdateOptionSelectionAndEntry((Obj*)*(void**)self, *(int*)(self + 0xfe0));
    if (!(ShopUpdateInterface_UnknownRoleZeroInitializedStorage & 1)) {
        ShopUpdateInterface_UnknownRoleProcedureReferenceRecords[9] =
            ShopUpdateInterface_UnknownRoleInitializedBytes;
        ShopUpdateInterface_UnknownRoleZeroInitializedStorage |= 1;
    }
    unsigned char mode = self[0x103e];
    if (!ShopUpdateInterface_UnknownRoleProcedureReferenceRecords[mode]) {
        TextWindow_ResetGlyphBuffersAndFrameContexts((void*)TextContext_GetSharedInstance());
        return (*(unsigned short*)(self + 0x1046) & 0x80) == 0;
    }
    (((Screen*)self)->*ShopUpdateInterface_UnknownRoleProcedureReferenceRecords[mode])();
    return 0;
}
