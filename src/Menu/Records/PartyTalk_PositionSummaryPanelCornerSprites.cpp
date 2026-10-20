struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#pragma opt_propagation off
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
// Original: arm9/ov008 @ 0x0218AEE4; symbol: PositionPairedRecordsAroundReadyRecord; size: 0x9c.
extern "C" void PartyTalk_PositionSummaryPanelCornerSprites(char* self){
if(*(signed char*)(self+0xe99)!=1)return;char* record=(char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+24),0);if(!record)return;short width=*(short*)(record+0xa8);int x=(short)(*(short*)(record+0xac)<<3);int rawY=*(short*)(record+0xae);char* parts=P(self,0x1f8);int left=x-1;int y=(short)(rawY<<3);int bottom=(y-1)<<12;W(parts,0x104)=left<<12;W(parts,0x108)=bottom;Graphics_SubmitTransformedCellToOam(P(self,0x1f4),parts+0xf0);parts=P(self,0x1f8);W(parts,0x12c)=(x+(short)(width<<3)-8)<<12;W(parts,0x130)=bottom;Graphics_SubmitTransformedCellToOam(P(self,0x1f4),parts+0x118);
}
