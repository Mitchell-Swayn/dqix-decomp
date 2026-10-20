#include <globaldefs.h>
ARM
extern "C" void Graphics_SubmitTransformedCellToOam(void*,void*);
extern "C" void Object_ConvertMappedKeyToTwoHalfwords(void*,int,short*,short*);
// Original: arm9/ov006 @ 0x0215868C; symbol: func_ov006_0215868c; size: 0x144.
// Positions and submits three display records for page and screen-toggle controls.
extern "C" void SubmitPageAndToggleDisplayRecords(unsigned char* self) {
 if(*(unsigned short*)(self+0x394)&0x10) {
  short x,y;
  Object_ConvertMappedKeyToTwoHalfwords(self+0x100,0x78,&x,&y);
  unsigned char* records=*(unsigned char**)(self+0x24);
  *(int*)(records+0x1a4)=x<<12; *(int*)(records+0x1a8)=y<<12;
  records[0x1b2]=0xc; records[0x1b5]=9; records[0x1b6]=2;
  if(self[0x38c]>1 || self[0x38d]>=1) records[0x1b5]=8;
  Graphics_SubmitTransformedCellToOam(self+0xac,records+0x190);
  Object_ConvertMappedKeyToTwoHalfwords(self+0x100,0x10,&x,&y);
  records=*(unsigned char**)(self+0x24);
  *(int*)(records+0x17c)=x<<12; *(int*)(records+0x180)=y<<12;
  records[0x18a]=0xe; records[0x18e]=2;
  Graphics_SubmitTransformedCellToOam(self+0xac,records+0x168);
  Object_ConvertMappedKeyToTwoHalfwords(self+0x100,0x25,&x,&y);
  records=*(unsigned char**)(self+0x24);
  unsigned char* selected=records+0x258;
  if(!(*(unsigned short*)(*(unsigned char**)(self+0x10)+0x1258)&0x800)) selected=records+0x280;
  *(int*)(selected+0x14)=x<<12; *(int*)(selected+0x18)=y<<12;
  selected[0x22]=0x10; selected[0x26]=2;
  Graphics_SubmitTransformedCellToOam(self+0xac,selected);
 }
}
