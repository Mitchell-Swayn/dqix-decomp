#include <globaldefs.h>
ARM
struct Flags { unsigned char enabled:1; unsigned char active:1; unsigned char rest:6; };
extern "C" void ZoneContainerRenderPart_DrawFrameWithObjectTransform(char*,unsigned,unsigned);
// Original: arm9/main @ 0x020473C8; symbol: Graphics_DrawSelectedResource; size: 0x80.
// Draws the selected twelve-byte resource entry when both enable bits are set.
extern "C" void Graphics_DrawSelectedResource(char* self,unsigned flags) {
 if (!((Flags*)(self+0x84))->enabled) return;
 if (!((Flags*)(self+0x84))->active) return;
 if (*(short*)(self+0x82)<=0) return;
 if (!*(char**)(self+0xc)) return;
 char* entry=*(char**)(*(char**)(self+0xc)+*(unsigned*)(self+0x74)*8+4)+*(unsigned*)(self+0x70)*12;
 *(volatile unsigned*)0x04000444=0;
 ZoneContainerRenderPart_DrawFrameWithObjectTransform(self,*(unsigned*)(entry+8),flags);
 *(volatile unsigned*)0x04000448=1;
}
