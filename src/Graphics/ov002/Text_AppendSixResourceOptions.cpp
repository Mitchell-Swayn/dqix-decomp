#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void* ReadGlobalValueAt02108844();
extern "C" unsigned int ReadNonnegativeIndexedBit(void*,unsigned char*,int);
extern "C" void* LookupGlobalResourceByKey(unsigned);
extern "C" short data_ov002_0216ca04[];
extern "C" int data_ov002_0216ca58[];
extern "C" char data_ov002_0216d26e[];
// Original: arm9/ov002 @ 0x0215C178; symbol: func_ov002_0215c178; size: 0x150.
extern "C" void Text_AppendSixResourceOptions(char* obj,char* out,int prefix) {
 if(out) {
 int cursor=*(short*)(obj+0x1be0);
 void* global=ReadGlobalValueAt02108844();
 int enabled=ReadNonnegativeIndexedBit(global,(unsigned char*)global+0x8c,0x119a)!=0;
 int width=0;
 for(int i=0;i<3;i++) {
 int w=TextLayout_ComputeWidthWithGlyphSpacing((const char*)LookupGlobalResourceByKey(data_ov002_0216ca04[i]),0);
 if(width<w) width=w;
 }
 if(prefix) AppendFiveFormattedArguments(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 for(int i=0;i<6;i++) {
 if(i==3 && !enabled) Text_AppendFormattedIntegerFragmentAt020EFF74(out,3);
 int k=data_ov002_0216ca58[i];
 Text_AppendFormattedIntegerAndStringFragment(out,k,(const char*)LookupGlobalResourceByKey(data_ov002_0216ca04[k]));
 if(i==1 || i==3) AppendFormatText(out,data_ov002_0216d26e);
 else Text_AppendFormattedIntegerFragmentAt020EFE78(out,width+32);
 if(i==3 && !enabled) Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
 }
 }
}
