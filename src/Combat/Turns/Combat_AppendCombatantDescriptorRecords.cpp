#include <globaldefs.h>
ARM
struct Record;struct Owner;struct Node;struct Lists;struct List;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" bool GameObject_IsDead(void*);
extern "C" int Combat_IsCombatantExcludedFromSelection(char*);
extern "C" void Combat_InitializeCommandRecord(unsigned char*);
extern "C" void* memset(void*,int,unsigned);
extern "C" void Combat_InitializeTargetResultRecord(Record*);
extern "C" void Combat_PopulateResultFromCombatantSnapshot(void*,Record*,Owner*,short,short,short,void*,void*,unsigned char);
extern "C" void Combat_AppendResultMessage(void*,void*,int);
extern "C" void Combat_AppendTargetResultToCategoryList(Lists*,Node*,int);
extern "C" void Combat_AppendActorSnapshotToCommand(List*,Node*);
extern "C" void Combat_AppendActionTargetRecord(Owner*,Node*);
// Original: arm9/ov000 @ 0x0215ACB8; symbol: func_ov000_0215acb8; size: 0x1C8.
extern "C" void Combat_AppendCombatantDescriptorRecords(unsigned char* self,int index,int offset,short z) {
 if((unsigned)self[0x8e0f]>=16) return;
 unsigned char* combatant=(unsigned char*)_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),index);
 if(!combatant) return;
 if(GameObject_IsDead(combatant)) return;
 if(Combat_IsCombatantExcludedFromSelection((char*)combatant)) return;
 unsigned char* base=self+0x7770;
 unsigned int slotOffset=self[0x8e0f]*40;
 Combat_InitializeCommandRecord(base+slotOffset);
 unsigned char* second=self+0x79f0+self[0x8e0f]*52;
 memset(second,0,48);
 *(short*)(second+0x1c)=-1;
 *(int*)(second+0x30)=0;
 unsigned char* third=self+0x7d30+self[0x8e0f]*36;
 Combat_InitializeTargetResultRecord((Record*)third);
 unsigned char* fourth=self+0x7f70+self[0x8e0f]*36;
 memset(fourth,0,32);
 *(int*)(fourth+0x20)=0;
 *(short*)(base+slotOffset)=0x3af;
 *(short*)(second+0x20)=index;
 *(unsigned short*)(second+0x22)=**(unsigned short**)(combatant+0x138);
 *(unsigned short*)(second+0x24)=*(unsigned short*)(*(unsigned char**)(combatant+0x138)+2);
 Combat_PopulateResultFromCombatantSnapshot(self,(Record*)fourth,(Owner*)combatant,(short)-offset,**(short**)(combatant+0x138),z,0,(void*)8,0);
 Combat_AppendResultMessage(self,fourth,0x243);
 *(short*)(third+0xe)=index;
 third[0x17]=1;
 Combat_AppendTargetResultToCategoryList((Lists*)third,(Node*)fourth,0);
 Combat_AppendActorSnapshotToCommand((List*)(base+slotOffset),(Node*)second);
 Combat_AppendActionTargetRecord((Owner*)(base+slotOffset),(Node*)third);
 ++self[0x8e0f];
}
