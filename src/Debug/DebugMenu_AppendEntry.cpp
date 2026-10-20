#include <globaldefs.h>
ARM
extern "C" unsigned char* DebugMenu_GetEntryByIndex(void*,int);
// Original: arm9/main @ 0x0202A944; symbol: func_0202a944; size: 0x68.
extern "C" void DebugMenu_AppendEntry(unsigned char* p,unsigned char* entry){*(void**)(entry+52)=0;unsigned count=*(unsigned short*)(p+90);if(!count){*(void**)(p+68)=entry;entry[60]=0;*(short*)(p+90)=1;}else{unsigned char* last=DebugMenu_GetEntryByIndex(p,count-1);if(last){*(void**)(last+52)=entry;entry[60]=*(unsigned short*)(p+90);++*(unsigned short*)(p+90);}}if(*(int*)entry==1)*(void**)(entry+72)=p;}
