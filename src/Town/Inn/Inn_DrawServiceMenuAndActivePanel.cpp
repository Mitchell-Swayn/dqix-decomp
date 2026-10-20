#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void Window_ClearResourceBuffers(void*);extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*);extern "C" void Window_FillCanvasRectanglesOnAlternateLayer(void*,int,int,int);extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(void*);extern "C" void Inn_DrawOfflineServiceMenuMarker(void*);extern "C" void Inn_DrawAnimatedServiceMenuCursor(void*);extern "C" void System_UpdateSelectedResourceList(void*);extern "C" void GuestList_RefreshWindowAndRowIcons(void*);extern "C" void Inn_DrawStayDialogCanvases(void*);extern "C" void Town_DrawFacilityNavigationAndStateIcons(void*);
// Original: arm9/ov003 @ 0x0216D468; symbol: UpdateConditionalDisplayRecordsAndModeSubstates; size: 0xD4.
extern "C" void Inn_DrawServiceMenuAndActivePanel(char* self){if(P(self,0x12c0)&&(H(self,6)==0||H(self,6)==1||H(self,4)==2)){Window_ClearResourceBuffers(P(self,0x12c0));ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(P(self,0x12c0));Window_FillCanvasRectanglesOnAlternateLayer(P(self,0x12c0),2,1,1);Graphics_ResetCountedThirtyTwoByteTransfers(P(self,0x12c0));}Inn_DrawOfflineServiceMenuMarker(self);Inn_DrawAnimatedServiceMenuCursor(self);System_UpdateSelectedResourceList(self);if(H(self,4)==4)GuestList_RefreshWindowAndRowIcons(self+0x410);else if(H(self,4)==3){if(H(self,6)==1)Inn_DrawStayDialogCanvases(self+0x14);}else if(H(self,4)==5&&H(self,6)==6)Town_DrawFacilityNavigationAndStateIcons(self+0xf1c);}
