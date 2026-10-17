#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" {
void VectorizedMemset(void*,int,unsigned);
int Unclassified_CountNonzeroBytePrefix(const char*,int);
void Graphics_DrawFixedWidthCenteredText(void*,int,int,int,int,const unsigned short*,int);
extern char* data_ov031_02290ca0[];
}
// Original: arm9/ov031 @ 0x0222FF34; symbol: func_ov031_0222ff34; size: 0x154.
extern "C" void Graphics_DrawTwoLineLabelWithSpaceGlyph(const unsigned char* text,int row) {
 unsigned short buffer[17];
 VectorizedMemset(buffer,0,34);
 int length=Unclassified_CountNonzeroBytePrefix((const char*)text,32);
 int first=length<=16?length:16;
 for(int i=0;i<first;i++) {
  if(text[i]==32)buffer[i]=0xe01d;else buffer[i]=text[i];
 }
 int y=row*29+2;
 if(length<=16)y+=5;
 Graphics_DrawFixedWidthCenteredText(*(void**)(data_ov031_02290ca0[2]+0x14),72,y,2,8,buffer,1);
 if(length<=16)return;
 VectorizedMemset(buffer,0,34);
 length-=16;
 for(int i=0;i<length;i++) {
  if(text[i+16]==32)buffer[i]=0xe01d;else buffer[i]=text[i+16];
 }
 Graphics_DrawFixedWidthCenteredText(*(void**)(data_ov031_02290ca0[2]+0x14),72,y+12,2,8,buffer,1);
}
