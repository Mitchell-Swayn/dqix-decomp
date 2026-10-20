#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void*,int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*,int);
extern "C" void Window_ResetResourceTransfers(unsigned char*);
extern "C" void TextLayout_FinalizePanelNoOp(void*);
// Original: arm9/ov013 @ 0x02184AEC; symbol: func_ov013_02184aec; size: 0x60.
// Refreshes text timing and resets embedded resources outside inactive/closing states.
extern "C" void ResetActiveAllocationTextResources(unsigned char* p){
 int state=p[0x63c];if(state==0)return;if(state==5)return;if(state==6)return;
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();void* owner=(void*)TextContext_GetSharedInstance();
 TextWindow_AdvanceTextForRequestedTicks(owner,_ZNK9GameState12GetTickCountEv(game));TextWindow_RenderAndTransferDisplayBuffers(owner,0);Window_ResetResourceTransfers(p+0x38);TextLayout_FinalizePanelNoOp(p+0x3d4);
}
