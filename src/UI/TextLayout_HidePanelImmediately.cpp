#include <globaldefs.h>
ARM
extern "C" unsigned char* TextContext_GetSharedInstance(void*);extern "C" void TextWindow_SelectFrameTransitionRecord(void*,void*);extern "C" void TextWindow_SelectPrimaryFrameTransition(void*);
// Original: arm9/main @ 0x0205CE94; symbol: func_0205ce94; size: 0x38.
extern "C" void TextLayout_HidePanelImmediately(unsigned char* p){unsigned char* q=TextContext_GetSharedInstance(p);TextWindow_SelectFrameTransitionRecord(q,p+180);unsigned* obj=*(unsigned**)(q+0x1e20);if(obj)obj[2]=0;TextWindow_SelectPrimaryFrameTransition(q);}
