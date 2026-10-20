#include <globaldefs.h>
ARM
extern "C" {
int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
int TextMarkup_AppendCursorTag(char*,int);
void* GameState_GetSerializedProgressState();
int PartyMenu_AdvanceOrderedCommandIndex(void*,int);
int Script_GetOrderedLookupId(void*,int);
int TextMarkup_AppendPaletteTag(char*,int);
const char* ResourceStringTable_GetTextByKey(void*,int);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
int Text_AppendFormatString(char*,const char*);
void Util_SetRecordProgressFlags(void*,int,int,int);
extern char Text_AppendPagedLookupGrid_MarkupX116[];
}
// Original: arm9/ov002 @ 0x02160AA0; symbol: func_ov002_02160aa0; size: 0x1C8.
extern "C" void Text_AppendPagedLookupGrid(char* p,char* out,int format){
if(!out)return;
int cursor=*(short*)(p+0x1c0c);
int remainder=cursor%16;
int page=cursor/16;
cursor=remainder;
*(unsigned char*)(p+0x2484)=page;
if(format)TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
TextMarkup_AppendCursorTag(out,cursor);
short row=0;
unsigned char start=*(unsigned char*)(p+0x2484)<<4;
unsigned char end=start+16;
void* lookup=GameState_GetSerializedProgressState();
for(;start<end;start++){
int value=Script_GetOrderedLookupId(lookup,PartyMenu_AdvanceOrderedCommandIndex(p,start));
if(!value){
TextMarkup_AppendPaletteTag(out,15);
Text_AppendFormattedIntegerAndStringFragment(out,row,ResourceStringTable_GetTextByKey(p+0x20,0x119d));
}else if(*(unsigned*)(p+0x2480)&(1<<(value-1))){
TextMarkup_AppendPaletteTag(out,15);
Text_AppendFormattedIntegerAndStringFragment(out,row,ResourceStringTable_GetTextByKey(p+0x20,(short)(value+0x119d)));
}else{
TextMarkup_AppendPaletteTag(out,15);
Text_AppendFormattedIntegerAndStringFragment(out,row,ResourceStringTable_GetTextByKey(p+0x20,0x119c));
}
row++;
if(start&1)Text_AppendFormatString(out,*(char**)(p+0x1bdc));else Text_AppendFormatString(out,Text_AppendPagedLookupGrid_MarkupX116);
}
TextMarkup_AppendPaletteTag(out,15);
Util_SetRecordProgressFlags(p,0x22,*(unsigned char*)(p+0x2484),2);
}
