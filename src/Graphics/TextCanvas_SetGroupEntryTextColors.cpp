#include <globaldefs.h>
ARM
struct List {short* indices;char pad[15];unsigned char count;};extern "C" List* DisplayLayout_FindGroupById(void*,int);extern "C" unsigned char* DisplayLayout_FindPartById(void*,int);
// Original: arm9/main @ 0x02080CEC; symbol: func_02080cec; size: 0x68.
extern "C" void TextCanvas_SetGroupEntryTextColors(char* p,int index,unsigned flags){List* list=DisplayLayout_FindGroupById(p+12,index);if(!list)return;for(unsigned char i=0;i<list->count;i++){unsigned char* record=DisplayLayout_FindPartById(p+4,list->indices[i]);if(record)record[19]=(record[19]&~0xf0)|((flags<<28)>>24);}}
