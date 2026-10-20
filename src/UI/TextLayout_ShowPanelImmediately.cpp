#include <globaldefs.h>
ARM
extern "C" unsigned char* TextContext_GetSharedInstance();extern "C" void TextWindow_SelectFrameTransitionRecord(void*,void*);extern "C" int UI_IsPanelTransitionVisible(void*);extern "C" void TextWindow_SelectPrimaryFrameTransition(void*);
// Original: arm9/main @ 0x0205CD94; symbol: func_0205cd94; size: 0x54.
extern "C" void TextLayout_ShowPanelImmediately(unsigned char* p){unsigned char* ctx=TextContext_GetSharedInstance();TextWindow_SelectFrameTransitionRecord(ctx,p+180);if(!UI_IsPanelTransitionVisible(ctx+0x19e0)){(*(unsigned**)(ctx+0x1e20))[2]=2;(*(unsigned**)(ctx+0x1e20))[5]=4096;}TextWindow_SelectPrimaryFrameTransition(ctx);}
