#include <globaldefs.h>
ARM
struct Flag25 {unsigned low:25;unsigned flag:1;unsigned high:6;};
struct E{short key,pad;unsigned value;};struct T{E* data;short count;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
// Original: arm9/ov012 @ 0x0218A9EC; symbol: func_ov012_0218a9ec; size: 0xD0.
// Appends eight record strings indexed by packed flag25 and sequential keys.
extern "C" void Text_AppendEightMappedRecordValues(char* p,char* output,int header) {
 if(!output)return;
 int cursor=*(unsigned*)(p+0x13f4)&7;
 Flag25* flags=(Flag25*)((char*)_ZN9GameState11GetInstanceEv()+0x569c);
 if(header) TextMarkup_AppendFrameTag(output,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(output,cursor);
 for(int i=0;i<8;i++) {
 if(i) Text_AppendFormatString(output,*(char**)(p+0x1378));
 int key=(i<<1)+flags->flag;
 key+=30000;
 Text_AppendFormattedIntegerAndStringFragment(output,i,(const char*)MessageTextTable_FindTextById((T*)(p+0x133c),(short)key));
 }
}
