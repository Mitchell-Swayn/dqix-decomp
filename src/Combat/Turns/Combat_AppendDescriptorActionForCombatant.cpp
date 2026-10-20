#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma always_inline on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" bool GameObject_IsDead(void*);
extern "C" int Combat_IsCombatantExcludedFromSelection(char*);
extern "C" void Combat_InitializeTargetResultRecord(void*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultFromCombatantSnapshot(void*,void*,void*,short,short,short,void*,void*,unsigned char);
extern "C" void Combat_AppendTargetResultToCategoryList(void*,void*,int);
extern "C" void Combat_InitializeCommandRecord(unsigned char*);
extern "C" void Combat_AppendActorSnapshotToCommand(void*,void*);
extern "C" void Combat_AppendActionTargetRecord(void*,void*);
struct Component {short a,b; short GetA() {return a;} short GetB() {return b;} };
struct Header { char bytes[40]; };
struct Source { char bytes[52]; };
struct Node { char bytes[36]; };
// Original: arm9/ov000 @ 0x0215AF54; symbol: func_ov000_0215af54; size: 0x244.
extern "C" void Combat_AppendDescriptorActionForCombatant(char* self,int index,int alternative) {
 unsigned char* header;
 char* source;
 char* node;
 char* record;
 if(*(unsigned char*)(self+0x8e10)>=16 || *(unsigned char*)(self+0x8e11)>=16 || *(unsigned char*)(self+0x8e12)>=16 || *(unsigned char*)(self+0x8e13)>=16) return;
 char* obj=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),index);
 if(!obj) return;
 if(GameObject_IsDead(obj)) return;
 if(Combat_IsCombatantExcludedFromSelection(obj)) return;
 header=(unsigned char*)&((Header*)(self+0x6d30))[*(unsigned char*)(self+0x8e10)];
 Combat_InitializeCommandRecord(header);
 source=(char*)&((Source*)(self+0x6fb0))[*(unsigned char*)(self+0x8e11)];
 memset(source,0,48);
 *(short*)(source+0x1c)=-1;
 *(int*)(source+0x30)=0;
 node=(char*)&((Node*)(self+0x72f0))[*(unsigned char*)(self+0x8e12)];
 Combat_InitializeTargetResultRecord(node);
 record=(char*)&((Node*)(self+0x7530))[*(unsigned char*)(self+0x8e13)];
 memset(record,0,32);
 *(int*)(record+0x20)=0;
 if(!alternative) {
 int party;
 if(index>=0 && index<=3) party=1;else party=0;
 if(party) *(short*)header=0x39c; else *(short*)header=0x39d;
 Combat_AppendResultMessage(self,record,0x35);
 } else {
 *(short*)header=0x39a;
 Combat_AppendResultMessage(self,record,0x213);
 }
 header[0xb]|=4;
 *(short*)(source+0x20)=index;
 *(unsigned short*)(source+0x22)=*(unsigned short*)(*(char**)(obj+0x138));
 *(unsigned short*)(source+0x24)=*(unsigned short*)(*(char**)(obj+0x138)+2);
 Combat_PopulateResultFromCombatantSnapshot(self,record,obj,0,(*(Component**)(obj+0x138))->GetA(),(*(Component**)(obj+0x138))->GetB(),0,0,0);
 *(short*)(node+0xe)=index;
 node[0x17]=1;
 Combat_AppendTargetResultToCategoryList(node,record,0);
 Combat_AppendActorSnapshotToCommand(header,source);
 Combat_AppendActionTargetRecord(header,node);
 ++*(unsigned char*)(self+0x8e10);
 ++*(unsigned char*)(self+0x8e11);
 ++*(unsigned char*)(self+0x8e12);
 ++*(unsigned char*)(self+0x8e13);
}
