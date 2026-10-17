#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" int Unclassified_CountNonzeroBytePrefix(const char*,int);
extern "C" void Graphics_DrawFixedWidthCenteredText(void*,int,int,int,int,const unsigned short*,int);
extern "C" char* data_ov031_02290c8c[];
// Original: arm9/ov031 @ 0x0222C45C; symbol: func_ov031_0222c45c; size: 0x178.
extern "C" void Text_DrawSplitAsciiRow(int index,int slot) {
 int length;
 int y;
 int offset=index*42;
 length=Unclassified_CountNonzeroBytePrefix(*(char**)data_ov031_02290c8c[1]+offset,32);
 y=slot*28;
 if(index>=*(unsigned char*)(data_ov031_02290c8c[1]+0x51)) return;
 unsigned short text[17];
 if(length<=16) y+=6;
 VectorizedMemset(text,0,34);
 int count=length<=16?length:16;
 int i=0;
 if(count>0) {
 char* state=data_ov031_02290c8c[1];
 do {text[i]=(unsigned char)(*(char**)state)[offset+i];i++;} while(i<count);
 }
 Graphics_DrawFixedWidthCenteredText(*(void**)(data_ov031_02290c8c[1]+12),10,y,2,10,text,1);
 if(length<=16) return;
 VectorizedMemset(text,0,34);
 int rest=length-16;
 index=0;
 if(rest>0) {
 char* state=data_ov031_02290c8c[1];
 do {text[index]=(unsigned char)(*(char**)state)[offset+index+16];index++;} while(index<rest);
 }
 Graphics_DrawFixedWidthCenteredText(*(void**)(data_ov031_02290c8c[1]+12),10,y+12,2,10,text,1);
}
