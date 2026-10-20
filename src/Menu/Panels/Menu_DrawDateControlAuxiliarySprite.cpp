struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" {WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);void Graphics_SubmitTransformedCellToOam(void*,void*);}
// Original: arm9/ov023 @ 0x021E6A14; symbol: PositionModeSevenThroughNineDisplay; size: 0x7c.
// Positions display from ready record10 coordinates for modes7 through9.
extern "C" void Menu_DrawDateControlAuxiliarySprite(char* self) {unsigned char mode=*(unsigned char*)(self+0x1371);if(mode!=7 && mode!=8 && mode!=9)return;char* record=(char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0xac),16);if(!record)return;short x=*(short*)(record+0xac),y=*(short*)(record+0xae);char* target=*(char**)(self+0x1364);*(int*)(target+0x1cc)=((short)(x<<3)+5)<<12;*(int*)(target+0x1d0)=((short)(y<<3)+3)<<12;Graphics_SubmitTransformedCellToOam(*(void**)(self+0x135c),target+0x1b8);}
