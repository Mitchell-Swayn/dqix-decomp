#include <globaldefs.h>
ARM
struct IndexedFields { unsigned char pad[0x130];unsigned char kind;unsigned char gap[15];unsigned char attribute; };
// Original: arm9/ov025 @ 0x021ED5F0; symbol: func_ov025_021ed5f0; size: 0x44.
// Appends a word and two byte fields when kind<6 and count<16.
extern "C" void Presentation_AppendWordAndTwoByteFields(unsigned char* self,int value,int kind,int attribute) {
 if(kind>=6)return;
 if(self[0x151]>=16)return;
 *(int*)(self+0xf0+self[0x151]*4)=value;
 ((IndexedFields*)(self+self[0x151]))->kind=kind;
 ((IndexedFields*)(self+self[0x151]))->attribute=attribute;
 ++self[0x151];
}
