#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
char *TextContext_GetSharedInstance();void TextWindow_SelectFrameTransitionRecord(char *,void *);int UI_IsPanelTransitionVisible(void *);void WindowFrame_BeginOpenTransition(void *);void TextWindow_SelectPrimaryFrameTransition(void *);
// Original: arm9/main @ 0x0205CD28; symbol: func_0205cd28; size: 0x44.
void TextLayout_StartPanelOpening(char *p){char *q=TextContext_GetSharedInstance();TextWindow_SelectFrameTransitionRecord(q,p+0xb4);if(!UI_IsPanelTransitionVisible(q+0x19e0))WindowFrame_BeginOpenTransition(q+0x19e0);TextWindow_SelectPrimaryFrameTransition(q);}
}
