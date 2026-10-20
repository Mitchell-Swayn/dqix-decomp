#include <globaldefs.h>
ARM
#pragma opt_common_subs off
extern "C" {void* Network_GetConnectionManager();bool Network_IsClientSession(unsigned*);int Grid_ComputeSelectedLinearIndex(int*);void Graphics_SetCellPaletteBank(void*,void*,unsigned short);void Graphics_SetCellPriority(void*,void*,int);void Graphics_SubmitTransformedCellToOam(void*,void*);}
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov008 @ 0x02188730; symbol: func_ov008_02188730; size: 0x140.
// Positions and submits six visible statistic rows, selecting row modes and the optional stored-record text row.
extern "C" void Graphics_SubmitVisibleStatisticRows(char* self) {
 char* stateBase;int drawn,row;unsigned char index;char* record;unsigned short mode;int offset;
 if(W(self,0xb18)&0x80000) {
  drawn=0;stateBase=self+0xb00;
  for(row=0;row<6;row++) {
   index=B(self+(B(self,0xb29)+row),0x744);
   if(index!=255) {
    record=P(self,0x734)+index*40;
    W(record,0x14)=0x10000;W(record,0x18)=((drawn%6)<<16)+0x8000;
    int selected=Grid_ComputeSelectedLinearIndex((int*)(self+0x750))-B(self,0xb29);
    mode=1;
    if(selected==row)mode=2;
    else if(*(signed char*)(stateBase+0x10)==12)mode=3;
    if(Network_IsClientSession((unsigned*)Network_GetConnectionManager())&&index==5)mode=3;
    offset=index*40;
    Graphics_SetCellPaletteBank(P(self,0x730),P(self,0x734)+offset,mode);Graphics_SetCellPriority(P(self,0x730),P(self,0x734)+offset,1);Graphics_SubmitTransformedCellToOam(P(self,0x730),P(self,0x734)+offset);
    drawn++;
   }
  }
 }
 if(W(self,0xb18)&0x10000) {
  char* record=P(self,0x740);W(record,0x14)=W(self,0xb2c);W(record,0x18)=0x4000;B(record,0x26)=1;B(record,0x25)=0;B(record,0x22)=127;Graphics_SubmitTransformedCellToOam(P(self,0x73c),record);
 }
}
