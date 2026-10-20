#include <globaldefs.h>
ARM
struct Item { unsigned short id; char pad[8]; unsigned char low:4; unsigned char high:4; char tail[13]; };
struct Unique { unsigned char active; char pad; unsigned short id; int value; };
struct Header { unsigned char sum:4; unsigned char count:2; unsigned char unique:2; };
// Original: arm9/ov000 @ 0x0215D414; symbol: func_ov000_0215d414; size: 0x174.
extern "C" void Resource_InitializeThreeEntryCounts(char* self, char* input) {
 *(void**)(self+0x8e18)=*(void**)input;
 unsigned char count=0,total=0,unique=0;
 for(int i=0;i<3;i++) {
  Item* entry=(Item*)(self+0x81b4)+count;
  if(*(unsigned char*)(input+0xc+i)) {
   int found=0;
   for(int j=0;j<unique;j++) {
    if(((Unique*)(self+0x81fc))[j].id==*(unsigned short*)(input+4+i*2)) {found=1;break;}
   }
   if(!found) {
    Unique* u=(Unique*)(self+0x81fc)+unique++;
    u->id=*(unsigned short*)(input+4+i*2);
    u->active=1;
    u->value=0;
   }
   entry->id=*(unsigned short*)(input+4+i*2);
   count++;
   entry->low=*(unsigned char*)(input+0xc+i);
   entry->high=*(unsigned char*)(input+0xc+i);
   total+=entry->low;
  }
 }
 ((Header*)(self+0x81b1))->unique=unique;
 *(unsigned char*)(self+0x81b0)=total;
 ((Header*)(self+0x81b1))->sum=total;
 ((Header*)(self+0x81b1))->count=count;
 *(unsigned short*)(self+0x81b2)=*(unsigned short*)(input+0xa);
 *(unsigned char*)(self+0x8e49)=*((unsigned char*)*(void**)(self+0x8e18)+0x35);
}
