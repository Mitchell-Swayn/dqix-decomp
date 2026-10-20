#include <globaldefs.h>
struct Reset {unsigned short a,flags,b,c;unsigned d;unsigned char e; signed char f;char rest[0x30e];};
extern "C" void ActorPathGraph_InitializeEmpty(void*);
extern "C" void Script_ClearSelectedIdCount(void*);
extern "C" void Actor_ClearChoiceEntries(void*);
extern "C" void Clear456ByteBufferAndInitializeTrailingWords(void*);
extern "C" void MonsterData_ClearView(void*);
extern "C" void ScriptRecordList_InitializeEmpty(void*);
extern "C" void MonsterOverrideTable_Reset(void*);
// Original: arm9/main @ 0x020289C4; symbol: func_020289c4; size: 0x90.
extern "C" void ZoneState_ResetTrackedZone(Reset* p) {unsigned mask=0xffff000f;p->flags&=~4;p->flags&=~8;p->a=0;p->d=0;p->c=0;p->e=0;p->flags&=mask;p->b=0;p->f=(int)mask>>16;ActorPathGraph_InitializeEmpty((char*)p+0x18);Script_ClearSelectedIdCount((char*)p+0x44);Actor_ClearChoiceEntries((char*)p+0x60);Clear456ByteBufferAndInitializeTrailingWords((char*)p+0x124);MonsterData_ClearView((char*)p+0x2f8);ScriptRecordList_InitializeEmpty((char*)p+0x304);MonsterOverrideTable_Reset((char*)p+0x30c);}
