#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" {
GameResources* GameState_ReadPResources(GameState* state);
unsigned int TextContext_GetSharedInstance();
void UI_InitializePanelGridAndKeepSavedOptionVisible(char* self);
int UI_UpdatePanelGridFromTouchOrDirections(char* self, int ticks);
bool GameState_CopyStatisticsRecord(void* out);
void Statistics_AddPartyTalkCount(unsigned char* p, unsigned delta);
int GameState_StoreStatisticsRecord(const void* in);
void _ZN16BackgroundLoader13AddLockGlobalEv(void);
void _ZN16BackgroundLoader16RemoveLockGlobalEv();
void* _Z18LoadFileIntoMemoryPKcPvPj(const char*, void*, unsigned*);
void* Filesystem_ExtractLocalizedGp2FileToScratch(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
void MessageTextTable_Reset(char* p);
void Script_ExecuteCodeWithOwnerModeAndOutputValue(unsigned owner, void* code, unsigned size, unsigned value, unsigned arg, unsigned char enabled);
int GameState_ReadProtagonistObjectIndex(GameState* state);
GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);
void* ResourceStringTable_GetTextByKey(void* a, void* b);
int Text_AppendFormatString(char* p, const char* text);
void TextWindow_StartFormattedMessage(void*, unsigned, unsigned, unsigned);
int Grid_ComputeSelectedLinearIndex(int* p);
int Input_IsKeyMaskNewlyPressed(unsigned short* p, unsigned int mask);
void* Network_GetConnectionManager();
bool Network_IsClientSession(unsigned int* p);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
extern char RecordsScreen_AdvancePanelInitialization_PathDataScenarioCmtFileTblBin[];
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
extern char Main_UnknownRoleZeroInitializedStorage[];
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
}
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
struct LowBit { unsigned char value:1, other:7; };
inline bool HasFlag(char* self, unsigned mask) { return (W(self, 0xb18) & mask) != 0; }
// Original: arm9/ov008 @ 0x02185DC0; symbol: func_ov008_02185dc0; size: 0x4C0.
// Advances records-screen fade and scripted summary, then applies selected or cancel option input.
extern "C" void RecordsScreen_UpdateSummaryAndOptionSelection(char* self, int ticks) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = GameState_ReadPResources(game);
    char* context = (char*)TextContext_GetSharedInstance();
    if (W(context, 0x998)) B(context, 0x19ae) = 0;
    signed char phase = *(signed char*)(self + 0xb11);
    if (phase == 0) { UI_InitializePanelGridAndKeepSavedOptionVisible(self); B(self, 0xb11)++; }
    if (phase == 1) {
        if (HasFlag(self, 0x20000) && HasFlag(self, 0x200)) { if (W(context, 0x9a0) != 3) return; W(self, 0xb18) &= ~0x20000; }
        if (HasFlag(self, 0x20000)) phase++;
        else SetBrightness(resources, 0, 15);
        B(self, 0xb11)++;
    }
    if (phase == 2) {
        if (IsBrightnessTransitionActive(resources)) return;
        if (!HasFlag(self, 0x80)) {
            W(context, 0x998) = 1;
            if (H(self, 0xb14) > 0) {
                if (!HasFlag(self, 0x200)) {
                    if (HasFlag(self, 1) && !HasFlag(self, 0x8000)) { unsigned char config[176]; GameState_CopyStatisticsRecord(config); Statistics_AddPartyTalkCount(config, 1); GameState_StoreStatisticsRecord(config); }
                    memset(P(self, 0xb8), 0, 0x960); char* archive = P(self, 0xb8); char* inner = archive + 128; char* message = archive + 256;
                    _ZN16BackgroundLoader13AddLockGlobalEv(); char script[8]; unsigned size; void* code = _Z18LoadFileIntoMemoryPKcPvPj(RecordsScreen_AdvancePanelInitialization_PathDataScenarioCmtFileTblBin, Main_UnknownRoleZeroInitializedStorage_Variant6, &size);
                    if (code) {
                        MessageTextTable_Reset(script); Script_ExecuteCodeWithOwnerModeAndOutputValue((unsigned)script, code, size, H(self, 0xb16), (unsigned)archive, 0);
                        MessageTextTable_Reset(script); Script_ExecuteCodeWithOwnerModeAndOutputValue((unsigned)script, code, size, H(self, 0xb16), (unsigned)inner, 1);
                    }
                    code = Filesystem_ExtractLocalizedGp2FileToScratch(archive, inner, &size);
                    if (code) {
                        int index = GameState_ReadProtagonistObjectIndex(game); GameObject* member = GameState_GetObjectWithFlag100(game, index);
                        MessageTextTable_Reset(script);
                        unsigned char bit = ((LowBit*)(P(member, 0x150) + 0x49c))->value;
                        Script_ExecuteCodeWithOwnerModeAndOutputValue((unsigned)script, code, size, H(self, 0xb14), (unsigned)message, bit);
                    }
                    _ZN16BackgroundLoader16RemoveLockGlobalEv(); Text_AppendFormatString(message, (char*)ResourceStringTable_GetTextByKey(self + 0xa0, (void*)1000));
                    TextWindow_StartFormattedMessage(context, (unsigned)message, 0, 0xe3); B(context, 0x19b2) = 1; B(context, 0x19c8) = 1; W(context, 0x99c) = 2;
                    if (P(self, 0xb0c)) { W(self, 0xb18) |= 0x200; B(self, 0xb10) = 2; B(self, 0xb11) = 0; return; }
                }
            } else if (!HasFlag(self, 0x200)) {
                char* text = (char*)ResourceStringTable_GetTextByKey(self + 0xa0, (void*)10000);
                TextWindow_StartFormattedMessage(context, (unsigned)text, 0, 0xe3); B(context, 0x19b2) = 1; B(context, 0x19c8) = 1; W(context, 0x99c) = 2;
            }
            if (HasFlag(self, 0x20000)) { B(context, 0x19c5) = 1; B(context, 0x19b2) = 0; W(self, 0xb18) |= 0x200; B(self, 0xb11) = 1; return; }
            W(self, 0xb18) |= 0x20;
        }
        W(self, 0xb18) |= 8; B(self, 0xb11)++;
    }
    if (phase == 3) {
        int action = UI_UpdatePanelGridFromTouchOrDirections(self, ticks);
        int index = Grid_ComputeSelectedLinearIndex((int*)(self + 0x750));
        if (index > B(self, 0xb29) + 5) B(self, 0xb29) = index - 5;
        else if (index < B(self, 0xb29)) B(self, 0xb29) = index;
        unsigned char selected = B(self + index, 0x744);
        if (Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x401) || action == 1) {
            if (Network_IsClientSession((unsigned int*)Network_GetConnectionManager()) && selected == 5) return;
            SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0); B(self, 0xb10) = selected + 5; B(self, 0xb11) = 0; W(self, 0xb18) &= ~8; W(self, 0xb18) &= ~0x20;
        } else if (Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0x806) || action == -2) {
            B(self, 0xb10) = 13; B(self, 0xb11) = 0; W(self, 0xb18) &= ~8; W(self, 0xb18) &= ~0x20;
        }
    }
}
