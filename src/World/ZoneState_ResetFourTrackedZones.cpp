#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void ActorPathGraph_InitializeEmpty(char*);
extern "C" void Script_ClearSelectedIdCount(char*);
extern "C" void Actor_ClearChoiceEntries(char*);
extern "C" void Clear456ByteBufferAndInitializeTrailingWords(char*);
extern "C" void MonsterData_ClearView(char*);
extern "C" void ScriptRecordList_InitializeEmpty(char*);
extern "C" void MonsterOverrideTable_Reset(char*);
// Original: arm9/main @ 0x020287B4; symbol: func_020287b4; size: 0xE0.
extern "C" void ZoneState_ResetFourTrackedZones(char* base){
    for(int i=0;i<4;++i){
        char* p=base+i*0x318;
        volatile unsigned short* flags=(volatile unsigned short*)(p+2);
        *flags &= ~4;*flags &= ~8;*flags &= ~3;
        *(unsigned short*)(base+i*0x318)=0;
        *(unsigned*)(p+16)=0;*(unsigned*)(p+20)=0;*(unsigned*)(p+8)=0;
        *(unsigned short*)(p+6)=0;p[12]=0;
        *flags &= 0xffff000f;
        *(unsigned short*)(p+4)=0;p[13]=-1;
        ActorPathGraph_InitializeEmpty(p+24);Script_ClearSelectedIdCount(p+0x44);Actor_ClearChoiceEntries(p+0x60);
        Clear456ByteBufferAndInitializeTrailingWords(p+0x124);MonsterData_ClearView(p+0x2f8);ScriptRecordList_InitializeEmpty(p+0x304);MonsterOverrideTable_Reset(p+0x30c);
        *flags=(*flags&~3)|((unsigned short)i&3);
    }
}
