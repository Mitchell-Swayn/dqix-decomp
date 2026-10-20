#include <globaldefs.h>
ARM
extern "C" unsigned char* TextContext_GetSharedInstance(void*);extern "C" void TextWindow_SelectFrameTransitionRecord(void*,void*);extern "C" int UI_IsPanelTransitionVisible(void*);extern "C" void TextWindow_SelectPrimaryFrameTransition(void*);
// Original: arm9/main @ 0x0205CDE8; symbol: func_0205cde8; size: 0x40.
extern "C" bool TextLayout_IsPanelVisible(unsigned char* p){unsigned char* q=TextContext_GetSharedInstance(p);TextWindow_SelectFrameTransitionRecord(q,p+180);bool result=UI_IsPanelTransitionVisible(q+0x19e0)!=0;TextWindow_SelectPrimaryFrameTransition(q);return result;}
