#include <globaldefs.h>
ARM
#pragma always_inline on
#pragma optimize_for_size on
#pragma optimization_level 4
extern "C" {extern char data_02108760[];void DispatchStoredHalfwordIndexWithTwoArguments(char*,int,void*);void UpdateIndexedStatusFields(void*,int);}
struct Object {char pad[0x6e8];unsigned char current,previous;short timer,elapsed;};
inline void ClearStatus(Object* p){p->previous=0;p->current=0;p->timer=0;}
// Original: arm9/ov000 @ 0x021823DC; symbol: func_ov000_021823dc; size: 0xBC.
extern "C" void SetBoundedStatusAndDispatchTransition(Object* p,int status){
if(status>3)status=3;
if(status>0){
if(status==p->current){if(p->timer!=0)return;}
p->previous=p->current;p->current=status;p->timer=30;p->elapsed=0;
if(status==1)DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,26,0);
else if(status==2)DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,23,0);
else DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,24,0);
}else{
if(p->current!=0){UpdateIndexedStatusFields(p,1);return;}
ClearStatus(p);
}
}
