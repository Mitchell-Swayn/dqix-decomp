#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {int IsObjectActiveForPressedOrReleasedInput(void*);void Graphics_ClearAllocatedTwentyFourKilobyteBuffer();void DebugText_SetPaletteIndex(unsigned);void DebugMenu_UpdateAndRender(void*,int);void Graphics_FillClippedPackedNibbleRectangle(unsigned,int,int,int,int);void Graphics_DrawModeAndAnimationLabels(void*);void Graphics_CleanInvalidateCharacterBuffer();void Graphics_DrainTransferQueue();}
// Original: arm9/ov015 @ 0x02190428; symbol: Graphics_DrawScaledValueBarAndRefresh; size: 0xe4.
extern "C" void CharacterViewer_DrawMenuAndScrollbar(unsigned char* self){if(!IsObjectActiveForPressedOrReleasedInput(self))return;Graphics_ClearAllocatedTwentyFourKilobyteBuffer();if(self[0x330]!=2)self[0x350]=0;DebugText_SetPaletteIndex(W(self,0x354));DebugMenu_UpdateAndRender(self+0x2c4,1);self[0x334]=0;DebugText_SetPaletteIndex(0);Graphics_FillClippedPackedNibbleRectangle(15,129,23,6,158);Graphics_FillClippedPackedNibbleRectangle(1,130,24,4,156);int height=(int)(24.0f+*(float*)(self+0x34c)*(float)(int)U(self,0x328));Graphics_FillClippedPackedNibbleRectangle(15,130,height,4,W(self,0x348));Graphics_DrawModeAndAnimationLabels(self);Graphics_CleanInvalidateCharacterBuffer();Graphics_DrainTransferQueue();}
