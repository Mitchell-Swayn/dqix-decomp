#include <globaldefs.h>
ARM
extern "C" { void* memset(void*,int,unsigned); void TextSprite_FormatAndUpdateTextReference(unsigned char*,const char*); void* ResourceStringTable_GetTextByKey(void*,void*); int BattleMenu_HasCommandBlockingStatus(char*); }
// Original: arm9/ov000 @ 0x0217F480; symbol: func_ov000_0217f480; size: 0x98.
extern "C" void Resource_InitializeTextCommandState(unsigned char* object) {
 unsigned char* p=object+8;
 memset(p+8,0,8);
 *(signed char*)(p+16)=0;
 (p+*(signed char*)(object+24))[8]=13;
 ++*(signed char*)(p+16);
 (p+*(signed char*)(object+24))[8]=100;
 p[20]=6;
 *(unsigned short*)(p+30)=0;
 if(!BattleMenu_HasCommandBlockingStatus((char*)object)) {
  const char* format=(const char*)ResourceStringTable_GetTextByKey(*(void**)(object+4),(void*)0x7531);
  TextSprite_FormatAndUpdateTextReference(object+0x50,format);
 }
 object[0x24]&=~4;
}
