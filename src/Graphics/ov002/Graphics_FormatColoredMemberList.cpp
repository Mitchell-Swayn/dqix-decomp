#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
extern "C" int AppendFormattedNumberAndText(char*,const char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int Graphics_SelectObjectRatioColor(char*,int,int,int,unsigned char);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
extern "C" int AppendFormatText(char*,const char*);
// Original: arm9/ov002 @ 0x0215D72C; symbol: func_ov002_0215d72c; size: 0x138.
extern "C" void Graphics_FormatColoredMemberList(char* self,char* out,int decorated){
 if(!out)return;
 _ZN9GameState11GetInstanceEv();
 int cursor=*(short*)(self+0x1bee);
 if(decorated)AppendFiveFormattedArguments(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 const char* text=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)0x514);
 AppendFormattedNumberAndText(out,text,16);
 char* names=self+0xab0;int i=0;
 names+=0x1000;
 for(;i<*(unsigned char*)(self+0x1c6d)+1;i++){
  int index;
  if(i<*(unsigned char*)(self+0x1c6d))index=*(unsigned char*)(self+0x1c68+i);else index=4;
  if(index==4){
   const char* text=(const char*)ResolveIndexedRecordAndReturnSecondWord(self+0x20,(void*)0x515);
   Text_AppendFormattedIntegerAndStringFragment(out,i,text);break;
  }
  int color=Graphics_SelectObjectRatioColor(self,index,1,0,0);
  Text_AppendFormattedIntegerFragmentAt020EFF74(out,color);
  Text_AppendFormattedIntegerAndStringFragment(out,i,names+index*60);
  Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
  AppendFormatText(out,*(const char**)(self+0x1bdc));
 }
}
