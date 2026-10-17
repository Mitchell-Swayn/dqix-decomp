#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadUnknownCb8(void*);
extern "C" int data_ov017_021d8438[];
// Original: arm9/ov017 @ 0x021B9BCC; symbol: func_ov017_021b9bcc; size: 0x134.
extern "C" bool GameState_TrySelectIndexedEntry(int index,int selection)
{
 void* game=_ZN9GameState11GetInstanceEv();
 int group=(index%80)/16;
 int entry=(index%80)%16;
 int current=data_ov017_021d8438[2];
 if(index/80 != current/80) return false;
 if(group==0) {
 if(entry<=data_ov017_021d8438[6]) data_ov017_021d8438[5]=selection;
 else return false;
 } else if(group==1) {
 if(entry<=data_ov017_021d8438[8]) data_ov017_021d8438[5]=selection;
 else return false;
 } else if(group==2) {
 if(index==current) data_ov017_021d8438[5]=selection;
 else return false;
 } else if(group==3) {
 if(index==current) data_ov017_021d8438[5]=selection;
 else return false;
 } else if(group==4) {
 if(entry<=GameState_ReadUnknownCb8(game) && entry>=data_ov017_021d8438[3]) {
 data_ov017_021d8438[5]=selection;data_ov017_021d8438[3]=entry;
 } else return false;
 }
 return true;
}
