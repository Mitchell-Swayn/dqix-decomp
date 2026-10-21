#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma scheduling off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
#pragma opt_repositioncode off
#pragma opt_optimizecontrolflow off
struct Buffer {
    char pad[0x4ac];
    char names[16][64];
};
struct State;
struct StateTail {
    char padding[0xb3c];
    int value;
};
extern "C" {
unsigned int TextContext_GetSharedInstance();
void* Network_GetConnectionManager();
void* Zone3D_GetMainInstance();
bool Network_IsSessionActive(int* param_1);
bool Network_IsClientSession(unsigned int* p);
bool Network_IsParentOrOffline(unsigned* p);
int Text_AppendFormatString(char* p, const char* text);
void TextLayout_ResetFormattingWorkspace(signed char* object);
void TextContext_SetStringArgument(Buffer* p, int i, const char* s);
void TextContext_SetNumericArgument(unsigned int* p, int i, unsigned int v);
void TextContext_SetNumericArgumentWidth(char* p, int i, int v);
void Selection_EnableTouchInput(int param_1);
void Selection_EnableDirectionalInput(int param_1);
void Selection_DisableTouchInput(int param_1);
void Selection_DisableDirectionalInput(int param_1);
void Window_PopCanvasesAndResetSelection(State* p, int flag);
int Selection_ReadEnabledIndexFromControl(void* p);
void Window_SetCanvasDisplayAttribute(char* p, int a, int value);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
void* ResourceStringTable_GetTextByKey(void* a, void* b);
void Inn_StartStayDialogMessage(void* owner, unsigned int selected);
int Inn_IsStayChoiceConfirmed(unsigned char* object);
int Inn_IsStayChoiceCancelled(void* self);
void Inn_InitializeStayChoiceSelections(unsigned char* p);
void InitializeFormattedMenuStateAndBindText(char* self);
void Inn_CreateStayChoiceWindow(char* self);
extern char Main_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov003 @ 0x0215D150; symbol: func_ov003_0215d150; size: 0x3AC.
// Advances inn stay-choice dialogue: formats guest/cost message text, then
// creates and reads the stay-choice window until confirm or cancel.
extern "C" void Inn_AdvanceStayChoice(unsigned char* self)
{
    GameState* game = GameState::GetInstance();
    unsigned int shared = TextContext_GetSharedInstance();
    char* context = (char*)shared;
    int* connection = (int*)Network_GetConnectionManager();
    char* zone = (char*)Zone3D_GetMainInstance();
    if (*(int*)(context + 0x9a0) == 3)
        context[0x1000 + 0x9ae] = 0;
    unsigned char phase = self[0x3b8];
    if (phase == 0) {
        TextLayout_ResetFormattingWorkspace((signed char*)shared);
        TextContext_SetNumericArgument((unsigned int*)shared, 0, self[0x3c3]);
        TextContext_SetNumericArgumentWidth(context, 0, 0);
        TextContext_SetNumericArgument((unsigned int*)shared, 1, *(unsigned*)(self + 0x3cc));
        TextContext_SetNumericArgumentWidth(context, 1, 0);
        int kind;
        if (*(int*)(self + 0x3d0) == 0)
            kind = 1;
        else
            kind = 0;
        if (Network_IsSessionActive(connection)) {
            if (Network_IsClientSession((unsigned int*)connection))
                kind = 2;
        }
        *(int*)(context + 0x998) = 1;
        char* format = *(char**)(context + 0x5c);
        if (self[0x3f0] != 0) {
            GameObject* member = game->GetPartyMemberByIndex(0);
            TextContext_SetStringArgument((Buffer*)shared, 0, *(const char**)((char*)member + 0x134));
            unsigned* net = (unsigned*)connection;
            connection = 0;
            if (Network_IsParentOrOffline(net) &&
                *(short*)((char*)game->GetUnknownGameObject() + 4) == 0)
                connection = (int*)1;
            if (connection) {
                Text_AppendFormatString(
                    format,
                    (const char*)ResourceStringTable_GetTextByKey(self + 0x64, (void*)0x64));
            }
            int key;
            StateTail* tail = (StateTail*)(zone + 0x1840);
            if (tail->value == 6)
                key = 0x67;
            else if (*(int*)(self + 0x3d0) != 0)
                key = 0x65;
            else
                key = 0x68;
            Text_AppendFormatString(
                format,
                (const char*)ResourceStringTable_GetTextByKey(self + 0x64, (void*)(int)(short)key));
            if (!connection) {
                Text_AppendFormatString(
                    format,
                    (const char*)ResourceStringTable_GetTextByKey(self + 0x64, (void*)0x6f));
            } else {
                if (*(int*)(self + 0x3d0) != 0)
                    key = 0x66;
                else
                    key = 0x69;
                Text_AppendFormatString(
                    format,
                    (const char*)ResourceStringTable_GetTextByKey(self + 0x64, (void*)(int)(short)key));
            }
        } else {
            Text_AppendFormatString(
                format,
                (const char*)ResourceStringTable_GetTextByKey(
                    self + 0x64, (void*)(int)(short)(kind + 0x3e8)));
        }
        Inn_StartStayDialogMessage(self, (unsigned)format);
        self[0x3b8] = (unsigned char)(self[0x3b8] + 1);
    }
    if (phase == 1) {
        if (*(int*)(context + 0x9a0) != 3)
            return;
        self[0x3ec] = 1;
        self[0x3ed] = 0;
        self[0x3b8] = (unsigned char)(self[0x3b8] + 1);
    }
    if (phase == 2) {
        if (self[0x3ec] != 0)
            return;
        if (self[0x3f2] == 0)
            InitializeFormattedMenuStateAndBindText((char*)self);
        Inn_CreateStayChoiceWindow((char*)self);
        Window_SetCanvasDisplayAttribute((char*)(self + 0x98), 0, 0);
        self[0x3b8] = (unsigned char)(self[0x3b8] + 1);
    }
    if (phase == 3) {
        self[0x3c1] = 0;
        Inn_InitializeStayChoiceSelections(self);
        Selection_EnableTouchInput((int)(self + 0x98));
        Selection_EnableDirectionalInput((int)(self + 0x98));
        self[0x3b8] = (unsigned char)(self[0x3b8] + 1);
    }
    if (phase != 4)
        return;
    self[0x3c2] = 1;
    self[0x3c1] = (unsigned char)Selection_ReadEnabledIndexFromControl(self + 0x98);
    if (Inn_IsStayChoiceConfirmed(self) != 0) {
        self[0x3c2] = 0;
        Window_PopCanvasesAndResetSelection((State*)(self + 0x98), 0);
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
        Selection_DisableTouchInput((int)(self + 0x98));
        Selection_DisableDirectionalInput((int)(self + 0x98));
        signed char index = *(signed char*)((char*)(self + 0x300) + 0xc1);
        unsigned char choice = (self + index)[0x3bd];
        switch (choice) {
        case 0:
            self[0x3bc] = 2;
            break;
        case 1:
            self[0x3bc] = 3;
            break;
        case 2:
            self[0x3bc] = 4;
            break;
        }
        self[0x3b8] = 0;
        return;
    }
    if (Inn_IsStayChoiceCancelled(self) == 0)
        return;
    self[0x3c2] = 0;
    Window_PopCanvasesAndResetSelection((State*)(self + 0x98), 0);
    Selection_DisableTouchInput((int)(self + 0x98));
    Selection_DisableDirectionalInput((int)(self + 0x98));
    self[0x3bc] = 4;
    self[0x3b8] = 0;
}
