#include <globaldefs.h>
ARM
struct State; struct Owner; struct A; struct Flag;
struct Canvas { unsigned char pad[20]; unsigned screen; unsigned other; unsigned char first:4; unsigned char second:4; unsigned char tail[3]; };
extern "C" {
void* memset(void*,int,unsigned);
void Graphics_InitializeCanvasTransferState(char*);
void Graphics_TransferScreenBuffer(void*,int);
int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
void Graphics_CopyScreenAtPosition(char*,const short*,unsigned,unsigned,unsigned short);
void Graphics_ResetCountedTransferEntriesWithModeZero(State*);
unsigned char* TextCanvas_FindDisplayPartByKey(unsigned char*,unsigned);
unsigned GetSubBG0ScreenBase();
void Window_SetWidgetPositionAndToggleTwoOptions(Owner*);
unsigned Window_IsVisible(A**);
void WindowControl_SetEnabled(Flag*,unsigned);
void KrakPot_UpdateSceneDisplayTransfers(char*);
void Graphics_InitializeBackgroundPriorities(char*);
int SetFlag800AndUpdateEmbeddedScreen(char*,int);
int KrakPot_IsDisplayPartPresentAndFlagFiveClear(unsigned char*,unsigned);
}
// Original: arm9/ov006 @ 0x02158478; symbol: func_ov006_02158478; size: 0x134.
// Draws the selected display record to sub BG0 and updates active transfer owners.
extern "C" void RenderSelectionScreenAndResetTransfers(unsigned char* self) {
 if(self[0x38f]) {
  unsigned screen=GetSubBG0ScreenBase();
  memset((void*)screen,0,0x800);
  if(KrakPot_IsDisplayPartPresentAndFlagFiveClear(*(unsigned char**)(self+0x14),1)) {
   unsigned char* record=TextCanvas_FindDisplayPartByKey(*(unsigned char**)(self+0x14),1);
   if(!record) return;
   int x,y;
   const short* position=(const short*)(record+0xc8);
   if(!position) return;
   x=*(short*)(record+0xac); y=*(short*)(record+0xae);
   Canvas canvas;
   Graphics_InitializeCanvasTransferState((char*)&canvas);
   canvas.first=1; canvas.second=0; canvas.screen=screen;
   Graphics_InvokeTwoIndexTransferCallback((State*)&canvas,0,0);
   Graphics_CopyScreenAtPosition((char*)&canvas,position,x,y,0xffff);
  }
  KrakPot_UpdateSceneDisplayTransfers(*(char**)(self+0x10));
  if(self[0x432]) {
   Graphics_InitializeBackgroundPriorities(*(char**)(self+0x10));
   SetFlag800AndUpdateEmbeddedScreen(*(char**)(self+0x10),1);
   self[0x432]=0;
  }
  Graphics_TransferScreenBuffer(self+0x54,0);
  unsigned char* window=*(unsigned char**)(self+0x18);
  if(window) {
   unsigned char* child=*(unsigned char**)(window+0x10);
   unsigned bit=Window_IsVisible((A**)window);
   WindowControl_SetEnabled((Flag*)(child+0x28),bit);
   Window_SetWidgetPositionAndToggleTwoOptions(*(Owner**)(self+0x18));
  }
  if(*(State**)(self+0x14)) Graphics_ResetCountedTransferEntriesWithModeZero(*(State**)(self+0x14));
 }
}
