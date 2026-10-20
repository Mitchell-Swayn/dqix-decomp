#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance();
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void Inn_ShowServiceMessage(char*,int,int,int,int);
// Original: arm9/ov003 @ 0x0216D3F0; symbol: func_ov003_0216d3f0; size: 0x78.
// Starts the selection message, then advances state only after both owner counters clear.
extern "C" void GameState_UpdateSelectionMessageTransition(char* self) {
 char* owner=(char*)TextContext_GetSharedInstance();
 short phase=*(short*)(self+6);
 if(phase==0) {
 Inn_ShowServiceMessage(self,0x1c,-1,-1,-1);
 *(int*)(owner+0x998)=1;
 *(short*)(self+6)=1;
 return;
 }
 if(phase!=1)return;
 if(*(int*)(owner+0x9a0)!=0 || *(int*)(owner+0x998)!=0)return;
 TextWindow_ResetGlyphBuffersAndFrameContexts(owner);
 *(short*)(self+4)=7;
 *(short*)(self+6)=0;
}
