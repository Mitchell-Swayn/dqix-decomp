#include <globaldefs.h>
ARM
struct State;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_WriteUnknownF70(void*,int);
extern "C" void* func_ov011_021849c8(State*);
extern "C" void func_ov011_02184ad8(State*);
extern "C" void* func_ov023_021f6880(void**,unsigned short);
extern "C" unsigned int OV023_ReadHalfwordField04(void*);
extern "C" unsigned char data_ov004_02171034[];
// Original: arm9/ov004 @ 0x0216E8F0; symbol: func_ov004_0216e8f0; size: 0x94.
extern "C" int Graphics_RevealSelectedListEntries(State* self) {
void** head=(void**)func_ov011_021849c8(self);
if(head){unsigned char* entry=(unsigned char*)func_ov023_021f6880(head,*(unsigned short*)(data_ov004_02171034+10));if(entry)entry[12]&=~16;}
func_ov011_02184ad8(self);
void* state=_ZN9GameState11GetInstanceEv();
if(data_ov004_02171034[3]!=6){
unsigned char* entry=(unsigned char*)func_ov023_021f6880(head,1);
if(entry && OV023_ReadHalfwordField04(entry)==11){entry[12]&=~8;GameState_WriteUnknownF70(state,1);}
}
return 0;
}
