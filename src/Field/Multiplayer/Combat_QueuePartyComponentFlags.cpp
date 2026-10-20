#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void Network_QueueOutgoingRecord(void*,const void*,short);
extern "C" unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);
extern "C" char* GameResources_GetInstance();
extern "C" unsigned char* FieldBattle_GetEncounterRequest(void*);
struct Flags { unsigned char a:1,b:1,c:1,d:1,e:4;
unsigned GetA() { return a; }
unsigned GetB() { return b; }
unsigned GetC() { return c; }
unsigned GetD() { return d; }
unsigned GetE() { return e; }
};
struct LastFlags { unsigned char other:7,f:1; };
struct SourceFlags { unsigned char f:1,other:7; Flags flags; };
struct Record { unsigned short a,b; char padding[9]; Flags flags; char padE; LastFlags last;
void SetA(unsigned char v) { flags.a=v; }
void SetB(unsigned char v) { flags.b=v; }
void SetC(unsigned char v) { flags.c=v; }
void SetD(unsigned char v) { flags.d=v; }
void SetE(unsigned char v) { flags.e=v; }
void SetF(unsigned char v) { last.f=v; }
};
struct Command { unsigned char opcode; char pad[3]; Record record; };
// Original: arm9/ov017 @ 0x021C71A4; symbol: func_ov017_021c71a4; size: 0x190.
extern "C" void Combat_QueuePartyComponentFlags() {
 void* game=_ZN9GameState11GetInstanceEv();
 unsigned char* context=FieldBattle_GetEncounterRequest(*(void**)(GameResources_GetInstance()+0x3718));
 void* queue=Network_GetCommandRecordPool();
 Command cmd;
 cmd.opcode=0x71;
 Record* record=&cmd.record;
 for(int i=0;i<4;i++) {
 if(PartySelection_GetMemberMask(context,(unsigned char)i)) {
 char* obj=_ZN9GameState19GetCombatantByIndexEi(game,i);
 if(obj && *(unsigned char*)(*(char**)(obj+0x138)+0x26)) {
 record->a=*(unsigned short*)(context+8);
 record->b=i;
 record->SetA(((SourceFlags*)(*(char**)(obj+0x138)+0x3a))->flags.GetA());
 record->SetB(((SourceFlags*)(*(char**)(obj+0x138)+0x3a))->flags.GetB());
 record->SetC(((SourceFlags*)(*(char**)(obj+0x138)+0x3a))->flags.GetC());
 record->SetD(((SourceFlags*)(*(char**)(obj+0x138)+0x3a))->flags.GetD());
 record->SetE(((SourceFlags*)(*(char**)(obj+0x138)+0x3a))->flags.GetE());
 record->last.f=*(unsigned char*)(*(char**)(obj+0x138)+0x3a);
 Network_QueueOutgoingRecord(queue,&cmd,0);
 }
 }
 }
}
