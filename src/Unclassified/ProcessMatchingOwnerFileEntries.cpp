#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct Cursor {unsigned a,b;};struct Entry {unsigned char type,pad;unsigned short key,owner;char rest[6];};extern "C" void WordPair_ClearWithVolatileTemporary(Cursor*);extern "C" int ReadNextTypedSerializedTableEntry(void*,Entry*,Cursor*);extern "C" int func_020be53c(void*,unsigned short,int,int);
// Original: arm9/main @ 0x020BE604; symbol: func_020be604; size: 0xC0.
extern "C" int ProcessMatchingOwnerFileEntries(void* p,void* file,unsigned owner,int a,int b){Entry entry;Cursor cursor,original;WordPair_ClearWithVolatileTemporary(&original);cursor=original;Cursor* next=&cursor;if(!file)return 0;int n=ReadNextTypedSerializedTableEntry(file,&entry,next);if(n){do{if(entry.type==1&&owner==entry.owner&&!func_020be53c(p,entry.key,a,b))return 0;n=ReadNextTypedSerializedTableEntry(file,&entry,&cursor);}while(n);}return 1;}
