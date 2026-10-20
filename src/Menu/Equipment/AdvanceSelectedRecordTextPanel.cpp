struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
struct Owner;struct State;struct Record;
extern "C" {
int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned);
WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
bool TextCanvas_IsReady(int);
void ConfigureSelectedRecordTextPanel(unsigned char*);
int EquipmentMenu_FormatEquipmentActionMessage(unsigned char*,char*);
int EquipmentMenu_IsConfirmPressed(void*);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void* memset(void*,int,unsigned);
int Window_ReplaceCanvasTextById(Owner*,unsigned,void*,unsigned,unsigned char);
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
void Window_PopCanvasesAndResetSelection(State*,int);
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
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];extern char Main_UnknownRoleZeroInitializedStorage[];
}
#define B(o) (*(unsigned char*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
// Original: arm9/ov005 @ 0x02158878; symbol: func_ov005_02158878; size: 0x17C.
// Advances text-panel setup, ready state and confirm/cancel transitions.
// The second input is forwarded unchanged to the display update's canonical value argument.
extern "C" void AdvanceSelectedRecordTextPanel(unsigned char* p,unsigned value){
 Window_UpdateCanvasesAndSelection(p+0xee4,value);
 if(B(0x3dd0)==0){ConfigureSelectedRecordTextPanel(p);++B(0x3dd0);}
 else if(B(0x3dd0)==1){
  if(TextCanvas_IsReady((int)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(p+0xee4)),0))){
   if(B(0x3dd1)==12 || B(0x3dd1)==13)W(0x3dcc)|=0x10000;
  }
  ++B(0x3dd0);
 }else if(B(0x3dd0)==2){
  bool close=false;unsigned char pressed=Main_UnknownRoleZeroInitializedStorage_Variant4[0x55];
  int confirmed=EquipmentMenu_IsConfirmPressed(p);
  confirmed |= pressed;
  if(confirmed){
   SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   if(B(0x3dd2)){
    B(0x3dd1)=B(0x3dd2);B(0x3dd2)=0;
    memset(*(void**)(p+0xe10),0,0x960);
    EquipmentMenu_FormatEquipmentActionMessage(p,*(char**)(p+0xe10));
    Window_ReplaceCanvasTextById((Owner*)(p+0xee4),0,*(void**)(p+0xe10),1,0);return;
   }else close=true;
  }else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2))close=true;
  if(close){Window_PopCanvasesAndResetSelection((State*)(p+0xee4),0);B(0x3dd0)=0;B(0x3dd1)=0;}
 }
}
