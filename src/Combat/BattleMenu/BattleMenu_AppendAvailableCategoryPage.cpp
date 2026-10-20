#include <globaldefs.h>
ARM
extern "C" void Selection_ComputeBoundedPageEntryRange(void*,int*,int*);
extern "C" void* ResourceStringTable_GetTextByKey(void*,int);
extern "C" int BattleMenu_HasTouchSelectionChanged(void*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" unsigned FindSetFlagIndexByOrdinal(void*,unsigned);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int Text_AppendFormatString(char*,const char*);

// Original: arm9/ov000 @ 0x02177F74; symbol: Text_AppendSelectedPageFlagEntries; size: 0x100.
extern "C" void BattleMenu_AppendAvailableCategoryPage(char* self,char* output){
int selected;signed char end;const char *separator;int line;signed char begin;int first,last;Selection_ComputeBoundedPageEntryRange(self+0x1dc,&first,&last);begin=first;end=last;separator=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,0);selected=*(signed char*)(self+0x1d6e);line=0;
 if(BattleMenu_HasTouchSelectionChanged(self))TextMarkup_AppendFrameTag(output,selected-begin,8,5,5,5);
 TextMarkup_AppendCursorTag(output,selected-begin);
 for(;begin<end;++begin){short index=(short)FindSetFlagIndexByOrdinal(self,begin);index+=7;const char *text=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,index);Text_AppendFormattedIntegerAndStringFragment(output,line,text);if(begin!=end-1)Text_AppendFormatString(output,separator);++line;}
}
