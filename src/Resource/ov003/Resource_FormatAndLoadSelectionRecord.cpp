#include <globaldefs.h>
ARM
extern "C" { void __clear(void*,unsigned); int AppendFiveFormattedArguments(char*,int,int,int,int,int); int AppendFormatText(char*,const char*); int LoadMatchingReadyRecordAndRefreshOwner(void*,unsigned,void*,unsigned,unsigned char); int Selection_ReadEnabledIndexFromControl(void*); void* ResolveIndexedRecordAndReturnSecondWord(void*,void*); }
// Original: arm9/ov003 @ 0x0216DC58; symbol: func_ov003_0216dc58; size: 0x98.
extern "C" void Resource_FormatAndLoadSelectionRecord(unsigned char* object) {
 char text[256];
 char scratch[64];
 __clear(text,256);
 __clear(scratch,64);
 if(*(int*)(object+16)==2) {
  int selected=Selection_ReadEnabledIndexFromControl(*(void**)(object+0x12c0));
  AppendFiveFormattedArguments(text,selected,8,5,5,5);
 }
 AppendFormatText(text,(const char*)ResolveIndexedRecordAndReturnSecondWord(object+0x1324,(void*)0x5c));
 LoadMatchingReadyRecordAndRefreshOwner(*(void**)(object+0x12c0),0,text,1,0);
}
