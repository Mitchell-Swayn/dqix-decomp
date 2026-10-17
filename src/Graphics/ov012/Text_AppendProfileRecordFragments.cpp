#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int AppendFiveFormattedArguments(char*,int,int,int,int,int);
extern "C" int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int AppendFormatText(char*,const char*);
extern "C" unsigned FindRecordValueByKeyOrZero(void*,int);
struct ProfileFlags { unsigned short mode:5; unsigned short rest:11; };
// Original: arm9/ov012 @ 0x02189934; symbol: func_ov012_02189934; size: 0x144.
extern "C" void Text_AppendProfileRecordFragments(char* screen,char* out,int positioned) {
 if(out) {
  const int cursor=*(int*)(screen+0x13d8);
  if(positioned) AppendFiveFormattedArguments(out,cursor,8,5,5,5);
  TextMarkup_AppendCursorTag(out,cursor);
  Text_AppendFormattedIntegerAndStringFragment(out,0,(const char*)FindRecordValueByKeyOrZero(screen+0x133c,7));
  AppendFormatText(out,*(const char**)(screen+0x1378));
  Text_AppendFormattedIntegerAndStringFragment(out,1,(const char*)FindRecordValueByKeyOrZero(screen+0x133c,8));
  AppendFormatText(out,*(const char**)(screen+0x1378));
  if(!((ProfileFlags*)(screen+0x13c4))->mode) Text_AppendFormattedIntegerFragmentAt020EFF74(out,3);
  Text_AppendFormattedIntegerAndStringFragment(out,2,(const char*)FindRecordValueByKeyOrZero(screen+0x133c,9));
  AppendFormatText(out,*(const char**)(screen+0x1378));
  if(!((ProfileFlags*)(screen+0x13c4))->mode) Text_AppendFormattedIntegerFragmentAt020EFF74(out,15);
  Text_AppendFormattedIntegerAndStringFragment(out,3,(const char*)FindRecordValueByKeyOrZero(screen+0x133c,109));
 }
}
