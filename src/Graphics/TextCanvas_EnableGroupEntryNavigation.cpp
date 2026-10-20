#include <globaldefs.h>
ARM
extern "C" unsigned char* DisplayLayout_FindGroupById(void*,int);extern "C" void DisplayLayout_ClearPartFlags(void*,int,unsigned);
// Original: arm9/main @ 0x0208065C; symbol: func_0208065c; size: 0x54.
extern "C" void TextCanvas_EnableGroupEntryNavigation(unsigned char* p,int key){unsigned char* entry=DisplayLayout_FindGroupById(p+12,key);if(!entry)return;for(unsigned char i=0;i<entry[19];i++)DisplayLayout_ClearPartFlags(p+4,(*(short**)entry)[i],2);}
