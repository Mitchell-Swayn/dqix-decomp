#include <globaldefs.h>
ARM
extern "C" void Graphics_SetCellAffineMode(void*,void*,unsigned,int);
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
// Original: arm9/main @ 0x0208BAEC; symbol: ConfigureRecordFixedPointCoordinatesAndScale; size: 0x8c.
extern "C" void QuestMessagePanel_SubmitScaledIndicatorCell(void* self,char* __restrict record,int* __restrict source,unsigned char mode,float scale,int origin,unsigned char value){
record[0x22]=mode;Graphics_SetCellAffineMode(self,record,1,1);*(unsigned short*)(record+0x20)=value;int x=source[0]-origin;int y=source[1]-origin;*(int*)(record+0x14)=x<<12;*(int*)(record+0x18)=y<<12;*(int*)(record+12)=(int)(4096.f*scale);*(int*)(record+16)=(int)(4096.f*scale);*(unsigned short*)(record+0x1c)=*(unsigned short*)((char*)source+12);Graphics_SubmitTransformedCellToOam(self,record);
}
