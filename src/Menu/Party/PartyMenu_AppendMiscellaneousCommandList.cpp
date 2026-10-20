#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedXYPair(char*,int,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendLineTag(char*,int);
extern "C" int TextMarkup_AppendPaletteTag(char*,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" void* Text_LookupStandardString(unsigned);
extern "C" void PartyMenu_BuildAvailableConnectionActions(char*,short*,short*);
extern "C" int GameState_CheckConnectionIndexListStatus(void);
// Original: arm9/ov002 @ 0x0215F4E8; symbol: func_ov002_0215f4e8; size: 0x15C.
// Appends available action names, marking action six when the connection list is ready.
extern "C" void PartyMenu_AppendMiscellaneousCommandList(char* self,char* out,int prefix) {
 if(!out)return;
 short cursor=*(short*)(self+0x1bfe);
 if(prefix)TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 Text_AppendFormatString(out,(const char*)Text_LookupStandardString(22));
 Text_AppendFormatString(out,*(const char**)(self+0x1bdc));
 TextMarkup_AppendLineTag(out,24);
 Text_AppendFormattedXYPair(out,12,31);
 short count=0,indices[8];
 PartyMenu_BuildAvailableConnectionActions(self,indices,&count);
 // The original caller supplies an ignored receiver; preserve the canonical callee declaration.
 int status=((int(*)(char*))GameState_CheckConnectionIndexListStatus)(self);
 for(unsigned char i=0;i<count;i++) {
  short action=indices[i];
  if(status==1 && action==6)TextMarkup_AppendPaletteTag(out,3);
  const char* text=(const char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)(int)(short)(action+0xfa1));
  Text_AppendFormattedIntegerAndStringFragment(out,i,text);
  if(i!=count-1)Text_AppendFormatString(out,*(const char**)(self+0x1bdc));
  if(status==1 && action==6)TextMarkup_AppendPaletteTag(out,15);
 }
}
