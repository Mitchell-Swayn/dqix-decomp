#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
#pragma force_active on
ARM
struct State { int pad[12]; int count; };
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* GameState_GetSerializedProgressState();
extern "C" bool Script_ExecuteFirstSatisfiedTriggerGroup(void*,int,State*);
extern "C" void Script_DispatchResultCommandsToWorld(State*);
extern "C" void FieldTransition_InitializeFeatureExitCommand(void*);
extern "C" void* GameState_ReadUnkF8(GameState*);
extern "C" void FieldTransition_SetExitFeatureDescriptor(void*,unsigned);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int*,unsigned int);
// Original: arm9/ov017 @ 0x02198F84; symbol: func_ov017_02198f84; size: 0x1B4.
// Dispatches selected type-two features and optionally queues their destination transition.
extern "C" void Field_ActivateSelectedTypeTwoFeatures(unsigned char* owner)
{
    Zone3D* zone=(Zone3D*)Zone3D_GetMainInstance();
    for(int i=0;i<owner[0x36b8];++i) {
        ZoneFeatures::Opcode6aEntry* entry=*(ZoneFeatures::Opcode6aEntry**)(owner+0x36bc+i*4);
        if(!entry) continue;
        int clearDelay=0;
        State result;
        void* progress=GameState_GetSerializedProgressState();
        *(short*)((unsigned char*)&result+0x28)=entry->unk_20;
        *(short*)((unsigned char*)&result+0x1e)=entry->unk_2c.type2.unk_1;
        *(short*)((unsigned char*)&result+0x1c)=entry->unk_2c.type2.unk_0;
        if(Script_ExecuteFirstSatisfiedTriggerGroup(progress,17,&result)) Script_DispatchResultCommandsToWorld(&result);
        if(!(entry->unk_2c.type2.unk_2_high&4)) {
            zone->ActivateType2Feature(entry,true,true,1);
            int transitionFlag=entry->unk_2c.type2.unk_2_high&8;
            if(transitionFlag && entry->unk_2c.type2.maybeZone) {
                FieldTransition_InitializeFeatureExitCommand(*(void**)(owner+0x3b10));
                unsigned char* saved=(unsigned char*)GameState_ReadUnkF8(GameState::GetInstance());
                if(saved[2]) {
                    entry->unk_2c.type2.maybeZone=*(unsigned short*)saved;
                    entry->unk_2c.type2.vectors_c[0]=*(Vector3fix*)(saved+0x10);
                    entry->unk_2c.type2.unk_3c=*(short*)(saved+0x1c);
                    entry->unk_2c.type2.unk_3e=*(signed char*)(saved+0xb);
                    entry->unk_2c.type2.vectors_c[1]=*(Vector3fix*)(saved+0x3c);
                    entry->unk_2c.type2.vectors_c[2]=*(Vector3fix*)(saved+0x48);
                    entry->unk_2c.type2.vectors_c[3]=*(Vector3fix*)(saved+0x54);
                    saved[2]=0;
                }
                FieldTransition_SetExitFeatureDescriptor(*(void**)(owner+0x3b10),(unsigned)entry);
                LinkedQueue_AppendAndMarkActive(*(unsigned int**)(owner+0x36fc),*(unsigned int*)(owner+0x3b10));
            } else if(!transitionFlag) clearDelay=1;
        } else {
            *(short*)(owner+0x42ec)=0;
            entry->unk_2c.type2.unk_2_high&=~4;
        }
        if(clearDelay) *(short*)(owner+0x42ec)=0;
    }
}
