#include <globaldefs.h>
ARM
struct State;
extern "C" {
void EquipmentMenu_OpenActionChoices(void*);void Selection_EnableTouchInput(void*);void Selection_EnableDirectionalInput(void*);
int Selection_ReadEnabledIndexFromControl(void*);int EquipmentMenu_IsConfirmPressed(void*);
int TestSelectedRecordReadyAndByteFlagBitOne(char*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void Selection_DisableTouchInput(void*);void Selection_DisableDirectionalInput(void*);
void Window_PopCanvasesAndResetSelection(State*,int);
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[];extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
}
#define B(o) (*(unsigned char*)(p+(o)))
#define S(o) (*(signed char*)(p+(o)))
// Original: arm9/ov005 @ 0x02158F80; symbol: func_ov005_02158f80; size: 0x1EC.
// Opens record-action choices and maps confirmed/cancelled selection to action codes.
extern "C" void EquipmentMenu_AdvanceActionChoice(unsigned char* p){
 if(B(0x3ddc)==0){EquipmentMenu_OpenActionChoices(p);Selection_EnableTouchInput(p+0xee4);Selection_EnableDirectionalInput(p+0xee4);++B(0x3ddc);return;}
 if(B(0x3ddc)!=1)return;
 B(0x3dde)=Selection_ReadEnabledIndexFromControl(p+0xee4);
 int confirm=EquipmentMenu_IsConfirmPressed(p);
 if(confirm | ((int(*)(char*,int))TestSelectedRecordReadyAndByteFlagBitOne)((char*)p+0xee4,20)){
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
  Selection_DisableTouchInput(p+0xee4);Selection_DisableDirectionalInput(p+0xee4);Window_PopCanvasesAndResetSelection((State*)(p+0xee4),0);
  if(S(0x3dbb)>=0 && S(0x3dbb)<8){switch(S(0x3dde)){case 0:B(0x3ddf)=1;break;case 1:B(0x3ddf)=3;break;case 2:B(0x3ddf)=4;break;}}
  else{switch(S(0x3dde)){case 0:B(0x3ddf)=1;break;case 1:B(0x3ddf)=2;break;case 2:B(0x3ddf)=3;break;case 3:B(0x3ddf)=4;break;}}
  B(0x3ddc)=0;
 }else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)){
  Selection_DisableTouchInput(p+0xee4);Selection_DisableDirectionalInput(p+0xee4);Window_PopCanvasesAndResetSelection((State*)(p+0xee4),0);
  B(0x3ddf)=4;B(0x3ddc)=0;
 }
}
