#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Owner;
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int Window_ReplaceCanvasTextById(Owner*,unsigned,void*,unsigned,unsigned char);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
// Original: arm9/ov023 @ 0x021D9D34; symbol: func_ov023_021d9d34; size: 0x70.
// Rebuilds the description text and reloads record two when flag 0x4000 is set.
extern "C" void RefreshFlaggedDescriptionRecord(char* self){
 if(!(*(unsigned*)(self+0xd9c)&0x4000))return;
 char* text=*(char**)(self+0xf8);memset(text,0,0x960);
 Text_AppendFormatString(text,(char*)ResourceStringTable_GetTextByKey(self+0xe0,(void*)0x4274));
 Window_ReplaceCanvasTextById((Owner*)(self+0x2b4),2,text,1,0);
 *(unsigned*)(self+0xd9c)&=~0x4000;
}
