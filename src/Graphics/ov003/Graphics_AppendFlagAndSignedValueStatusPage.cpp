#include <globaldefs.h>
ARM
extern "C" {
void* memset(void*,int,unsigned);
int sprintf(char*,const char*,...);
void __clear(void*,unsigned);
int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
int AppendFormattedPair_Main02041A90(char*,int,int);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
int AppendFiveFormattedArguments(char*,int,int,int,int,int);
int TextMarkup_AppendSizeTag(char*,int);
int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
int AppendThreeFormattedArguments(char*,int,int,int);
int Text_AppendFormattedThreeIntegerFragment(char*,int,int,int);
int AppendFormatText(char*,const char*);
const char* ResolveIndexedRecordAndReturnSecondWord(void*,int);
extern const char data_ov003_02180137[],data_ov003_02180145[],data_ov003_02180156[],data_ov003_02180159[];
}
// Original: arm9/ov003 @ 0x02169D10; symbol: func_ov003_02169d10; size: 0x1DC.
extern "C" void Graphics_AppendFlagAndSignedValueStatusPage(unsigned char* p,char* out,int format) {
 if(!out) return;
 char buffer[2]={0};
 signed char row=*(signed char*)(p+0x4ee);
 int coordinate=row*8;
 AppendFormattedPair_Main02041A90(out,coordinate+0x23,5);
 if(p[0x5a6]) Text_AppendFormattedIntegerFragmentAt020EFF74(out,13);
 else Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
 AppendFormatText(out,data_ov003_02180137);
 AppendFormattedPair_Main02041A90(out,coordinate+0x23,27);
 if(p[0x5a7]) Text_AppendFormattedIntegerFragmentAt020EFF74(out,13);
 else Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
 AppendFormatText(out,data_ov003_02180145);
 Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
 if(format) AppendFiveFormattedArguments(out,row,3,11,3,10);
 AppendThreeFormattedArguments(out,row,p[0x5a6],2);
 Text_AppendFormattedThreeIntegerFragment(out,row,p[0x5a7],2);
 TextMarkup_AppendSizeTag(out,12);
 for(int i=0;i<7;i++) {
  memset(buffer,0,2);
  sprintf(buffer,data_ov003_02180156,*(signed char*)(p+0x4ef+i));
  AppendFormattedPair_Main02041A90(out,i*8+0x24,16);
  if(i<4) Text_AppendFormattedIntegerAndStringFragment(out,i,buffer);
  else AppendFormatText(out,data_ov003_02180159);
 }
 Text_AppendFormattedIntegerFragmentAt020EFE78(out,0x5c);
 AppendFormatText(out,ResolveIndexedRecordAndReturnSecondWord(p+0x64,0x66));
}
