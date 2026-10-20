#include <globaldefs.h>
ARM
struct GameState;
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned TextContext_GetSharedInstance();
void TextLayout_ResetPanelControlCountersAndSetMode(unsigned char*,unsigned char);
void TextLayout_StartPanelOpening(char*);
void UpdateEmbeddedDisplayContextWhenEnabled(unsigned char*,int);
void SpriteAnimation_AdvanceAllTracks(char*,unsigned);
bool TextLayout_IsPanelVisible(unsigned char*);
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
int Object_ReadSelectionResultWhenGridReady(unsigned char*);
int Selection_ReadEnabledIndexFromEmbeddedControl(unsigned char*);
unsigned char GameState_ReadByteAtOffset4(GameState*);
int SaveData_GetBankHeaderValidationStatus(int);
void GameState_SetUnk4Element0(GameState*,unsigned char);
void TextLayout_DrawSelectionPanelAndCursor(void*,unsigned);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov020 @ 0x218d974; symbol: data_ov020_0218d974.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 04000000000000000200000064000000060000000100000003000000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov020.md.
// Original data: arm9/ov020 @ 0x218d990; symbol: data_ov020_0218d990.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0400000000000000050000000200000064000000060000000100000003000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov020.md.
extern unsigned UpdateDisplaySelectionAndSetGameStateByte4_UnknownRoleInitializedBytes_Variant2[],UpdateDisplaySelectionAndSetGameStateByte4_UnknownRoleInitializedBytes[];
}
// Original: arm9/ov020 @ 0x0218C840; symbol: func_ov020_0218c840; size: 0x14C.
// Updates the embedded display selection and maps accepted input into GameState byte 4.
extern "C" void UpdateDisplaySelectionAndSetGameStateByte4(unsigned char* p){
 GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
 char* global=(char*)TextContext_GetSharedInstance();
 if(*(int*)(p+4)==0){
 p[0x23f]=1;p[0x240]=1;
 TextLayout_ResetPanelControlCountersAndSetMode(p+0x10,1);
 TextLayout_StartPanelOpening((char*)p+0xc);
 }
 UpdateEmbeddedDisplayContextWhenEnabled(p+0xc,1);
 if(*(char**)(global+0x2e0))SpriteAnimation_AdvanceAllTracks(*(char**)(global+0x2e0),1);
 if(TextLayout_IsPanelVisible(p+0xc)){
 if(*(int*)(p+4)>5)*(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x1300;
 int pressed=Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x401);
 int ready=Object_ReadSelectionResultWhenGridReady(p+0xc)>=0;
 if(pressed|ready){
 int selection=Selection_ReadEnabledIndexFromEmbeddedControl(p+0xc);
 if(GameState_ReadByteAtOffset4(state)==6)return;
 if(SaveData_GetBankHeaderValidationStatus(1)==4){
 GameState_SetUnk4Element0(state,(unsigned char)UpdateDisplaySelectionAndSetGameStateByte4_UnknownRoleInitializedBytes_Variant2[selection]);
 *(int*)p=-1;*(int*)(p+4)=-1;return;
 }else{
 GameState_SetUnk4Element0(state,(unsigned char)UpdateDisplaySelectionAndSetGameStateByte4_UnknownRoleInitializedBytes[selection]);
 *(int*)p=-1;*(int*)(p+4)=-1;return;
 }
 }
 }
 TextLayout_DrawSelectionPanelAndCursor(p+0xc,0);
}
