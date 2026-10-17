#include <Resource/Script.h>
struct Entry { unsigned short id:9; unsigned short flag9:1; unsigned short flag10:1; unsigned short flag11:1; unsigned short flag12:1; unsigned short rest:3; };
struct State { unsigned char pad0; unsigned char skip; unsigned char result; unsigned char pad3[3]; unsigned short count; };
struct Queue { unsigned char pad[0xa8]; volatile Entry *entries; };
extern "C" { extern State data_02109404; extern Queue data_02109418; extern const short data_020f13d8; }
// Original: arm9/main @ 0x02095364; symbol: func_02095364; size: 0x14C.
// Script command appends packed flags and captures the selected command's result.
extern "C" int Script_AppendPackedCommandFlagsAndCaptureResult(Script::Parameter *p) {
 if(data_02109404.skip) { ++data_02109404.count; return 1; }
 unsigned short id=p[0].ToInt();
 unsigned short a=p[5].ToInt();
 unsigned short b=p[7].ToInt();
 unsigned short c=p[8].ToInt();
 unsigned short d=p[9].ToInt();
 volatile Entry *entries=data_02109418.entries;
 if(entries) {
 unsigned index=data_02109404.count;
 entries[index].id=id;
 entries[index].flag9=a;
 entries[index].flag11=b;
 entries[index].flag10=c;
 entries[index].flag12=d;
 }
 ++data_02109404.count;
 if(data_020f13d8>=0 && id==data_020f13d8) data_02109404.result=c!=0;
 return 1;
}
