#include <globaldefs.h>
ARM
extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*,void*);
// Original: arm9/ov023 @ 0x021F8944; symbol: func_ov023_021f8944; size: 0x1C.
// Stores a four-bit descriptor value and optionally refreshes it using the supplied context.
extern "C" void Graphics_SetDescriptorNibbleAndOptionallyRefresh(char* self,void* context,unsigned value,int refresh){
 *(unsigned short*)(self+0xe2)=value&15;
 if(refresh)MenuTextCanvas_RefreshConfiguredFrameAndContents(self,context);
}
