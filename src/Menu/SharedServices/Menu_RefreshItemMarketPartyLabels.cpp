#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Entry{virtual void Slot0();virtual void Slot1();virtual void Slot2();virtual void Slot3();virtual void Slot4();virtual void Slot5();virtual void Slot6();virtual void Slot7();virtual void Slot8();virtual void Slot9();virtual void Slot10();virtual void Slot11();virtual void Slot12();virtual void Slot13();virtual void Slot14();virtual void Slot15();virtual void Slot16();virtual void Slot17();virtual void Slot18();virtual void Slot19();virtual void Slot20();virtual void Slot21();virtual void Slot22();virtual void Slot23();virtual void Slot24();virtual void Slot25();virtual void Slot26();virtual void Slot27();virtual void Slot28();virtual void Slot29();virtual void Slot30();virtual void Slot31();virtual void Slot32();virtual void Slot33();virtual void Slot34();virtual void Slot35();virtual void Slot36();virtual void Slot37();virtual void Slot38();virtual void Slot39();virtual void Slot40();virtual void Slot41();virtual void Slot42();virtual void Slot43();virtual void Slot44();virtual void Slot45();virtual void Slot46();virtual void Slot47();virtual void Slot48();virtual void Slot49();virtual void Slot50();virtual void Slot51();virtual void Slot52();virtual void Slot53();virtual void Apply(int);};
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* GameState_GetIndexList(void*);extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);extern "C" int Menu_GetListedPartyMemberIndex(int);extern "C" Entry* Menu_FindInventoryTextEntryByKey(void*,unsigned);extern "C" int SelectThresholdStateFromMemberAmountRatio(int);extern "C" char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x02159470; symbol: RefreshPartyEntryRatioThresholdStates; size: 0xac.
extern "C" int Menu_RefreshItemMarketPartyLabels(void* self){
void* state=_ZN9GameState11GetInstanceEv();GameState_GetIndexList(state);unsigned count=*(short*)(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)+0x3a)&255;unsigned id=802;for(unsigned i=0;i<count;){int index=Menu_GetListedPartyMemberIndex(i);char* member=_ZN9GameState21GetPartyMemberByIndexEi(state,index);if(member){Entry* entry=Menu_FindInventoryTextEntryByKey(self,id);if(entry){W(entry,32)=W(member,0x134);int value=SelectThresholdStateFromMemberAmountRatio(index);entry->Apply(value);}}unsigned next=i+1;id++;i=next&255;}return 0;
}
