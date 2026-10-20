#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
struct Flags {unsigned int a:1; unsigned int b:1;unsigned int rest:30;};
struct Record {unsigned int first; unsigned int type:12; unsigned int rest:20;};
inline bool ValidIndex(int i){return i>=0 && i<=3;}
// Original: arm9/ov024 @ 0x021EA500; symbol: func_ov024_021ea500; size: 0x84.
extern "C" int GameState_HasObjectLowFlags(void*,Record* record,int index){
 void* gs=_ZN9GameState11GetInstanceEv();
 if(record->type==1){
 if((int)(index>=0 && index<=3)!=0){
 unsigned char* o=(unsigned char*)GameState_GetObjectWithFlag100(gs,index);
 Flags* f=(Flags*)(*(unsigned char**)(o+0x150)+0x2f4);
 if(f && (f->b || f->a))return 1;
 }}return 0;
}
