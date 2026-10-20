#include <globaldefs.h>
// Original data: arm9/main @ 0x20fdcb0; symbol: data_020fdcb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);extern "C" void PartyStatus_DrawMemberValueDigitsAndBar(unsigned,unsigned,int,int,unsigned,int,int,int,int,int,int,int);struct Entry{int id;unsigned reserved,value,rest[5];};extern "C" Entry GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0201FCA0; symbol: func_0201fca0; size: 0x98.
extern "C" ARM void PartyStatus_DrawMemberValueWithDefaultLayout(unsigned first,unsigned second,int index){if(_ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(),index)){Entry* entry=&GraphicsSelectObjectRatioColor_UnknownRoleZeroInitializedStorage[index];int id=entry->id;if(id>=0)PartyStatus_DrawMemberValueDigitsAndBar(first,second,index,id,entry->value,48,16,7,24,9,10,0);}}
