#include <globaldefs.h>
ARM
struct Entry { int a,b,value; };
struct State { Entry* arrays[2]; int count; unsigned char pad[0x3c]; short lengths[2];short total; };
extern "C" State* data_ov004_0217101c;
// Original: arm9/ov004 @ 0x021660F4; symbol: func_ov004_021660f4; size: 0xA4.
extern "C" void Object_ClearTwoEntryArrayValuesAndCounts() {
short i=0;
State* state=data_ov004_0217101c;
Entry* arrays[2]={state->arrays[0],state->arrays[1]};
short lengths[2]={state->lengths[0],state->lengths[1]};
for(;i<2;++i){
Entry* entry=arrays[i];
short count=lengths[i];
for(short j=0;j<count;++j){entry->value=0;++entry;}
}
state->count=0;state->total=0;
}
