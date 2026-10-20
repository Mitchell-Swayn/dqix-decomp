#include <globaldefs.h>
ARM
extern "C" { void __clear(void*,unsigned); int TextMarkup_AppendFrameTag(char*,int,int,int,int,int); int Text_AppendFormatString(char*,const char*); int Window_ReplaceCanvasTextById(void*,unsigned,void*,unsigned,unsigned char); int Selection_ReadEnabledIndexFromControl(void*); void* ResourceStringTable_GetTextByKey(void*,void*); }
// Original: arm9/ov003 @ 0x0216DC58; symbol: func_ov003_0216dc58; size: 0x98.
extern "C" void Resource_FormatAndLoadSelectionRecord(unsigned char* object) {
 char text[256];
 char scratch[64];
 __clear(text,256);
 __clear(scratch,64);
 if(*(int*)(object+16)==2) {
  int selected=Selection_ReadEnabledIndexFromControl(*(void**)(object+0x12c0));
  TextMarkup_AppendFrameTag(text,selected,8,5,5,5);
 }
 Text_AppendFormatString(text,(const char*)ResourceStringTable_GetTextByKey(object+0x1324,(void*)0x5c));
 Window_ReplaceCanvasTextById(*(void**)(object+0x12c0),0,text,1,0);
}
