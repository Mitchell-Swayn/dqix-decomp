#include <globaldefs.h>
ARM
extern "C" unsigned char* GameState_GetIndexedByteField(void*,int);
// Original: arm9/ov017 @ 0x02191AAC; symbol: func_ov017_02191aac; size: 0x94.
extern "C" void Field_UpdateCombatantAppearanceFlags(void* p,int mode,int key,unsigned mask){
if(!GameState_GetIndexedByteField(p,key))return;
unsigned char* record=GameState_GetIndexedByteField(p,key);
if(record)*record|=1;
if(mode==1){record=GameState_GetIndexedByteField(p,key);if(record)*record|=mask;}
else if(mode==0){record=GameState_GetIndexedByteField(p,key);if(record)*record&=~mask;}
}
