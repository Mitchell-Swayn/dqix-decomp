#include <globaldefs.h>
ARM
struct State; struct GameState; struct GameResources;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned DisplayContext_GetGlobalInstance();
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
extern "C" void Graphics_BuildProfileSummaryPage(unsigned char*);
extern "C" int Menu_IsConfirmOrCanvasActionPressed(void*);
extern "C" int Menu_TestCancelKeyOrCanvasTouchKindTwo(void*);
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(unsigned char*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov012 @ 0x02186A7C; symbol: func_ov012_02186a7c; size: 0x1A0.
extern "C" void Graphics_UpdateSixChoiceMenuState(char* p) {
 GameState_ReadPResources((GameState*)_ZN9GameState11GetInstanceEv());
 _ZN16BackgroundLoader11GetInstanceEv();
 DisplayContext_GetGlobalInstance();
 if(*(unsigned char*)(p+0x1370)==0) {
  *(unsigned char*)(p+0x13a0)=0; *(int*)(p+0x13d4)=0;
  Window_BindNextCanvasResourceByFormatAndLayer(p+0xac,0,2);
  Menu_ConfigurePairedSelectionGridsForActiveCanvas((unsigned char*)p);
  Graphics_BuildProfileSummaryPage((unsigned char*)p);
  ++*(unsigned char*)(p+0x1370);
 } else if(*(unsigned char*)(p+0x1370)==1) {
  *(unsigned char*)(p+0x13a0)=1;
  *(int*)(p+0x13d4)=Selection_ReadEnabledIndexFromControl(p+0xac);
  int cancel=0;
  if(Menu_IsConfirmOrCanvasActionPressed(p)) {
   *(unsigned char*)(p+0x164)=*(unsigned char*)(p+0x1371);
   *(unsigned char*)(p+0x13a0)=0;
   SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   switch(*(unsigned*)(p+0x13d4)) {
   case 0: *(unsigned char*)(p+0x1371)=2; *(unsigned char*)(p+0x1370)=0; break;
   case 1: *(unsigned char*)(p+0x1371)=9; *(unsigned char*)(p+0x1370)=0; break;
   case 2: *(unsigned char*)(p+0x1371)=10; *(unsigned char*)(p+0x1370)=0; break;
   case 3: *(unsigned char*)(p+0x1371)=13; *(unsigned char*)(p+0x1370)=0; break;
   case 4: *(unsigned char*)(p+0x1371)=14; *(unsigned char*)(p+0x1370)=0; break;
   case 5: cancel=1; break;
   }
  } else if(Menu_TestCancelKeyOrCanvasTouchKindTwo(p)) cancel=1;
  if(cancel) {
   *(unsigned char*)(p+0x13a0)=0; *(int*)(p+0x13d4)=0;
   Window_PopCanvasesAndResetSelection((State*)(p+0xac),1);
   *(unsigned char*)(p+0x1371)=15; *(unsigned char*)(p+0x1370)=0;
  }
 }
}
