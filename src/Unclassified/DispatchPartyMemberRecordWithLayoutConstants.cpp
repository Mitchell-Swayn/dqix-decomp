#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);extern "C" void func_0201fdd0(unsigned,unsigned,int,int,unsigned,int,int,int,int,int,int,int);struct Entry{int id;unsigned reserved,value,rest[5];};extern "C" Entry data_020fdcb0[];
// Original: arm9/main @ 0x0201FCA0; symbol: func_0201fca0; size: 0x98.
extern "C" ARM void DispatchPartyMemberRecordWithLayoutConstants(unsigned first,unsigned second,int index){if(_ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(),index)){Entry* entry=&data_020fdcb0[index];int id=entry->id;if(id>=0)func_0201fdd0(first,second,index,id,entry->value,48,16,7,24,9,10,0);}}
