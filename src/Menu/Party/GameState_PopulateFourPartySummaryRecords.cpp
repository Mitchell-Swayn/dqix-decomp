#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_GetObjectWithFlag100(void*,int);
struct Summary { char text[0x30];unsigned int value;unsigned short a,b,c,d; };
// Original: arm9/ov002 @ 0x0215B814; symbol: func_ov002_0215b814; size: 0xB4.
extern "C" void GameState_PopulateFourPartySummaryRecords(unsigned char* p) {
void* state=_ZN9GameState11GetInstanceEv();
Summary* record;
int i=0;
for(;i<4;++i){
record=(Summary*)(p+0x1ab0)+i;
memset(record,0,4);
unsigned char* object=GameState_GetObjectWithFlag100(state,i);
if(object && **(signed char**)(object+0x134)){
sprintf(record->text,*(char**)(object+0x134));
record->a=*(unsigned short*)(*(unsigned char**)(object+0x130)+4);
record->b=*(unsigned short*)(*(unsigned char**)(object+0x134)+0x30);
record->c=*(unsigned short*)(*(unsigned char**)(object+0x130)+6);
record->d=*(unsigned short*)(*(unsigned char**)(object+0x134)+0x32);
record->value=**(unsigned int**)(object+0x130);
}
}
}
