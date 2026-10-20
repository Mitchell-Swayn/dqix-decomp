#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" unsigned MessageTextTable_FindTextById(void*,int);
struct ProfileFlags { unsigned short mode:5; unsigned short rest:11; };
// Original: arm9/ov012 @ 0x02189934; symbol: func_ov012_02189934; size: 0x144.
extern "C" void ProfileEditor_AppendPhraseCategoryChoices(char* screen,char* out,int positioned) {
 if(out) {
  const int cursor=*(int*)(screen+0x13d8);
  if(positioned) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
  TextMarkup_AppendCursorTag(out,cursor);
  Text_AppendFormattedIntegerAndStringFragment(out,0,(const char*)MessageTextTable_FindTextById(screen+0x133c,7));
  Text_AppendFormatString(out,*(const char**)(screen+0x1378));
  Text_AppendFormattedIntegerAndStringFragment(out,1,(const char*)MessageTextTable_FindTextById(screen+0x133c,8));
  Text_AppendFormatString(out,*(const char**)(screen+0x1378));
  if(!((ProfileFlags*)(screen+0x13c4))->mode) TextMarkup_AppendPaletteTag(out,3);
  Text_AppendFormattedIntegerAndStringFragment(out,2,(const char*)MessageTextTable_FindTextById(screen+0x133c,9));
  Text_AppendFormatString(out,*(const char**)(screen+0x1378));
  if(!((ProfileFlags*)(screen+0x13c4))->mode) TextMarkup_AppendPaletteTag(out,15);
  Text_AppendFormattedIntegerAndStringFragment(out,3,(const char*)MessageTextTable_FindTextById(screen+0x133c,109));
 }
}
