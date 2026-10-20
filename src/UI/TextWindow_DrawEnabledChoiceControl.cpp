#include <globaldefs.h>
extern "C" void TextLayout_DrawSelectionPanelAndCursor(void*,unsigned);
// Original: arm9/main @ 0x02044530; symbol: func_02044530; size: 0x2C.
extern "C" ARM void TextWindow_DrawEnabledChoiceControl(unsigned char* p,unsigned value){if(*(int*)(p+0x9a0)!=6)return;if(!p[0x19ba])return;TextLayout_DrawSelectionPanelAndCursor(p+0x90,value);}
