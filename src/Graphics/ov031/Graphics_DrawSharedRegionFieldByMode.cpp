#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
struct Options { unsigned char count:2; unsigned char half:6; };
extern "C" {
char* GetSharedObjectRegionAtOffset1024();
void Graphics_DrawTwoLineLabelWithSpaceGlyph(const unsigned char*,int);
void Graphics_DrawIpv4AddressRow(void*,int);
void VectorizedMemset(void*,int,unsigned);
void* memset(void*,int,unsigned);
}
// Original: arm9/ov031 @ 0x0222FAAC; symbol: func_ov031_0222faac; size: 0x19C.
extern "C" void Graphics_DrawSharedRegionFieldByMode(int mode,int row) {
 char* region=GetSharedObjectRegionAtOffset1024();
 switch(mode) {
 case 0:Graphics_DrawTwoLineLabelWithSpaceGlyph((unsigned char*)region+0x40,row);return;
 case 1: {
  int count;
  switch(((Options*)(region+0xe6))->count) {
  case 0:return;
  case 1:count=10;break;
  case 2:count=26;break;
  case 3:count=32;break;
  }
  if(((Options*)(region+0xe6))->half==1)count/=2;
  unsigned char buffer[33];
  VectorizedMemset(buffer,0,33);
  memset(buffer,42,count);
  Graphics_DrawTwoLineLabelWithSpaceGlyph(buffer,row);
  return;
 }
 case 3:
  if(*(unsigned char*)(region+0xf5))return;
  Graphics_DrawIpv4AddressRow(region+0xc0,row);return;
 case 4:
  if(*(unsigned char*)(region+0xf5))return;
  Graphics_DrawIpv4AddressRow(region+0xf0,row);return;
 case 5:
  if(*(unsigned char*)(region+0xf5))return;
  Graphics_DrawIpv4AddressRow(region+0xc4,row);return;
 case 7:
  if(*(unsigned char*)(region+0xf6))return;
  Graphics_DrawIpv4AddressRow(region+0xc8,row);return;
 case 8:
  if(*(unsigned char*)(region+0xf6))return;
  Graphics_DrawIpv4AddressRow(region+0xcc,row);return;
 }
}
