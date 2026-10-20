#include "GameState/GameState.h"
struct State;
extern "C" int SaveData_WriteNamedChecksumPacket(int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void Graphics_ClearAndStageSharedBuffers(char*);
extern "C" void* Menu_FindTextCanvasWidgetByKey(void*,unsigned short);
extern "C" void MenuTextCanvas_SetLabelPalettePair(unsigned char*,unsigned short,unsigned short);
extern "C" void Menu_QueueScriptEntry(State*,unsigned);
extern "C" void GameState_WriteUnknownF70(GameState*,unsigned char);
// Original: arm9/ov004 @ 0x0216E414; symbol: func_ov004_0216e414; size: 0x7C.
// Failure resets display resources and selects501; success marks game state and selects999.
extern "C" ARM int SavePacketAndRouteOverlayState(State* self){
 if(!SaveData_WriteNamedChecksumPacket(1)){
  char* display=(char*)TextContext_GetSharedInstance();TextWindow_ResetGlyphBuffersAndFrameContexts(display);Graphics_ClearAndStageSharedBuffers(display);
  void* entry=Menu_FindTextCanvasWidgetByKey(self,0xd4);MenuTextCanvas_SetLabelPalettePair((unsigned char*)entry,0,7);
  Menu_QueueScriptEntry(self,501);
 }else{GameState_WriteUnknownF70(GameState::GetInstance(),1);Menu_QueueScriptEntry(self,999);}
 return 0;
}
