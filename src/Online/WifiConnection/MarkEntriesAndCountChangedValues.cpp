#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Entry { unsigned char disabled;char pad[2];unsigned char value:7;unsigned char marked:1; };
struct Bits {unsigned char value:7;unsigned char marked:1;};
struct Object { char pad[0x444];Entry entries[1]; };
// Original: arm9/ov031 @ 0x02214854; symbol: func_ov031_02214854; size: 0x90.
extern "C" unsigned char MarkEntriesAndCountChangedValues(Object* p){
int i;unsigned char count=0;
i=0;if(i<((unsigned char*)p)[0xd12]){
Bits* entry=(Bits*)((char*)p+0x447);char* current=(char*)p;
do{
if(p->entries[i].disabled!=0)goto mark;
if(*(unsigned short*)(current+0x4a6)-1==entry->value)goto mark;
entry->marked=0;count++;goto next;
mark: entry->marked=1;
next:;
++i;entry=(Bits*)((char*)entry+4);current+=0xc0; }while(i<((unsigned char*)p)[0xd12]);}
return count;
}
