#include <globaldefs.h>
ARM
extern "C" void* TextContext_GetSharedInstance();
extern "C" void TextWindow_AdvanceTextForRequestedTicks(void*,int);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*,int);
extern "C" void Window_ResetResourceTransfers(void*);
extern "C" void Resource_ResetIndexedEntriesWhenEnabled(void*);
extern "C" void GuestList_AdvanceMessagesAndTransfers(void*);
extern "C" void Town_RefreshFacilityPreviewTransfers(void*);
// Original: arm9/ov003 @ 0x0216D53C; symbol: Graphics_RefreshResourcesForSignedModePair; size: 0xb4.
// Configures text count and refreshes resource groups selected by signed mode/submode pair.
extern "C" void Graphics_RefreshResourcesForSignedModePair(char* self) {
 void* display=TextContext_GetSharedInstance();TextWindow_AdvanceTextForRequestedTicks(display,2);TextWindow_RenderAndTransferDisplayBuffers(display,0);
 void* entries=*(void**)(self+0x12c0);if(entries&&(*(short*)(self+6)==0||*(short*)(self+6)==1||*(short*)(self+4)==2))Window_ResetResourceTransfers(entries);
 if(*(short*)(self+4)==4&&*(short*)(self+6)>0)GuestList_AdvanceMessagesAndTransfers(self+0x410);
 else if(*(short*)(self+4)==3){if(*(short*)(self+6)==1)Resource_ResetIndexedEntriesWhenEnabled(self+0x14);}
 else if(*(short*)(self+4)==5&&*(short*)(self+6)==6)Town_RefreshFacilityPreviewTransfers(self+0xf1c);
}
