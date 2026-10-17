#include <globaldefs.h>
ARM
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" void Selection_ComputeBoundedPageEntryRange(char*,int*,int*);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" unsigned char* Object_FindByteKeyIn44ByteEntries(unsigned char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFormatText(char*,const char*);
extern "C" void __clear(void*,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" int AppendFormattedPair_Main02041A90(char*,int,int);
extern "C" char data_ov002_0216d2a8[];
// Original: arm9/ov002 @ 0x0215F224; symbol: func_ov002_0215f224; size: 0x17C.
extern "C" void Graphics_FormatPagedByteKeyEntries(char* self,char* out,int decorated) {
 if(!out || !*(void**)(self+0x2474))return;
 int cursor=*(short*)(self+0x1bfc)%6;
 if(decorated)AppendFiveFormattedArguments(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 char* selection=self+0xec8;
 int begin,end;
 Selection_ComputeBoundedPageEntryRange(selection+0x54,&begin,&end);
 const char* text=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)0x578);
 AppendFormattedNumberAndText(out,text,16);
 for(int i=begin;i<end;i++) {
  unsigned char* entry=Object_FindByteKeyIn44ByteEntries(*(unsigned char**)(self+0x2474),(short)i);
  if(entry) {
   Text_AppendFormattedIntegerAndStringFragment(out,i%6,*(const char**)(entry+4));
   if(i!=end-1)AppendFormatText(out,*(const char**)(self+0x1bdc));
  }
 }
 int pages=*(int*)(selection+0x58);
 if(pages>1) {
  int page=*(int*)(selection+0x68);
  char buffer[4];__clear(buffer,4);
  sprintf(buffer,data_ov002_0216d2a8,page+1,pages);
  int width=TextLayout_ComputeWidthWithGlyphSpacing(buffer,0);
  AppendFormattedPair_Main02041A90(out,(120-(width+(width&1)))>>1,99);
  AppendFormatText(out,buffer);
 }
}
