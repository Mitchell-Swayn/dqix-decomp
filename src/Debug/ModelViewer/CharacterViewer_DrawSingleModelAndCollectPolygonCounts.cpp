#include <globaldefs.h>
ARM
extern "C" void _ZN8Object3D4DrawEb(void*,bool);
extern "C" void _ZN12RenderConfig12SubmitToFifoEv();
// Original: arm9/ov015 @ 0x0218EDCC; symbol: func_ov015_0218edcc; size: 0x6c.
// Draws the viewer model between matrix pushes/pops and copies its polygon and vertex counts.
extern "C" void CharacterViewer_DrawSingleModelAndCollectPolygonCounts(unsigned char* self) {
 *(volatile unsigned*)0x04000444=0;
 _ZN8Object3D4DrawEb(*(void**)(self+0x24),false);
 _ZN12RenderConfig12SubmitToFifoEv();
 *(volatile unsigned*)0x04000448=1;
 *(unsigned short*)(self+0x34)=*(unsigned short*)(self+0x36)=0;
 unsigned char* object=*(unsigned char**)(self+0x24);
 unsigned char* model=*(unsigned char**)(object+8);
 unsigned char* header=*(unsigned char**)(model+0x54);
 *(unsigned short*)(self+0x34)=*(unsigned short*)(header+0x28);
 object=*(unsigned char**)(self+0x24);
 model=*(unsigned char**)(object+8);
 header=*(unsigned char**)(model+0x54);
 *(unsigned short*)(self+0x36)=*(unsigned short*)(header+0x2a);
}
