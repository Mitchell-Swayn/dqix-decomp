#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/ZoneFeatures.h>
#pragma always_inline on
#pragma force_active on
ARM
extern "C" bool GameObject_HasQueuedActions(signed char*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* GameState_ReadUnknownB0(GameState*);
extern "C" int ZoneFeatures_TestPointInsideEntry(ZoneFeatures::Opcode6aEntry*,const Vector3fix*);
extern "C" void Field_InitializeInteractionCandidate(unsigned char*);
extern "C" void Field_SelectBetterInteractionCandidate(void*,void*);
extern "C" bool LinkedQueue_IsEmpty(const int*);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
extern "C" void BuildRotationVectorFromFixedPointAngle(void*,int,int,int,unsigned char);
extern "C" short FieldInteraction_ComputeSignedFacingAngleToTarget(void*,int,void*);
// Original: arm9/ov017 @ 0x021983E0; symbol: func_ov017_021983e0; size: 0x114.
// Selects a containing type-five region when the field command queue and leader actions are idle.
extern "C" void Field_SelectContainingTypeFiveInteraction(void* owner)
{
    if (!LinkedQueue_IsEmpty(*(const int**)((unsigned char*)owner+0x36fc))) return;
    GameState* game=GameState::GetInstance();
    unsigned char* zone=(unsigned char*)Zone3D_GetMainInstance();
    GameState_ReadUnknownB0(game);
    GameObject* actor=game->GetUnknownGameObject();
    if (GameObject_HasQueuedActions((signed char*)actor)) return;
    Vector3fix position=*(Vector3fix*)((unsigned char*)actor+0x44);
    ZoneFeatures::Opcode6aEntry* entry=((ZoneFeatures*)(zone+0x6c))->GetTypeEntries(5);
    while(entry) {
        if (ZoneFeatures_TestPointInsideEntry(entry,&position)) {
            int angle=_Z22fix32ReduceAngle0To2Pii(entry->unk_20+0x3244);
            BuildRotationVectorFromFixedPointAngle(owner,(short)angle,0xccc,-0x4cc,0);
            unsigned char candidate[20];
            Field_InitializeInteractionCandidate(candidate);
            candidate[0]=7;
            *(void**)(candidate+8)=entry;
            *(short*)(candidate+16)=FieldInteraction_ComputeSignedFacingAngleToTarget((unsigned char*)actor+0x44,(short)*(int*)((unsigned char*)actor+0x54),(unsigned char*)entry+8);
            Field_SelectBetterInteractionCandidate(owner,candidate);
            break;
        }
        entry=*(ZoneFeatures::Opcode6aEntry**)((unsigned char*)entry+0x70);
    }
}
