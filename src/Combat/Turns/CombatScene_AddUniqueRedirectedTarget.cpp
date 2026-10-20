#include <globaldefs.h>
ARM
struct ListTail {unsigned char pad[0xf0];short values[5];short count;};
struct Owner {unsigned char pad[0x6e00];ListTail list;};
// Original: arm9/ov000 @ 0x0216346C; symbol: func_ov000_0216346c; size: 0x5C.
// Appends a signed halfword only when it is absent from the five-entry list. Capacity is not checked here.
extern "C" void CombatScene_AddUniqueRedirectedTarget(Owner* owner,int value) {
 int index=0,count;
 while(index<(count=owner->list.count)) {
  if(value==owner->list.values[index])break;
  index++;
 }
 if(index==count) {
  owner->list.count++;
  owner->list.values[count]=value;
 }
}
