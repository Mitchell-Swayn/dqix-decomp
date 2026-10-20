#include <globaldefs.h>
#pragma optimize_for_size off
#include <GameState/GameState.h>
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" unsigned char* WeaponPosition_GetGlobalConfiguration();
extern "C" unsigned char GameObject_GetResolvedAttachmentBone(void*,int);
extern "C" void GameObject_SetSelectedAttachmentBone(void*,int);
extern "C" void Object3D_SetPositionComponents(void*,int,int,int);
extern "C" void Object3D_SetRotationComponents(void*,int,int,int);
// Original: arm9/ov017 @ 0x021917F0; symbol: func_ov017_021917f0; size: 0x1D8.
extern "C" ARM void Field_ApplyMemberWeaponAttachmentVariant(int index, int variant)
{
    unsigned char* data;
    GameObject* object;
    Object3D* target;
    unsigned char* record;
    GameState* state;
    int attachment;
    state=GameState::GetInstance();
    object=GameState_GetObjectWithFlag100(state,index);
    target=(Object3D*)state->GetGameObjectByIndex(index*12+28);
    if(!object || !target)return;
    data=GameObject_GetLinkedIndexedState(object);
    if(!data)return;
    record=WeaponPosition_GetGlobalConfiguration()+((*(unsigned int*)(data+0x29c)<<23)>>27)*28;
    if(variant==1)
    {
        attachment=GameObject_GetResolvedAttachmentBone(object,record[14]);
        GameObject_SetSelectedAttachmentBone(object,attachment);
        Object3D_SetPositionComponents(target,*(short*)(record+16),*(short*)(record+18),*(short*)(record+20));
        Object3D_SetRotationComponents(target,*(short*)(record+22),*(short*)(record+24),*(short*)(record+26));
        target->Detach();
        target->Attach(&object->obj3D_,(short)attachment);
        if(*(short*)(record+22)||*(short*)(record+24)||*(short*)(record+26))target->SetFlag16();
        else target->ClearFlag16();
    }
    else if(variant==0)
    {
        attachment=GameObject_GetResolvedAttachmentBone(object,record[1]);
        GameObject_SetSelectedAttachmentBone(object,attachment);
        Object3D_SetPositionComponents(target,*(short*)(record+2),*(short*)(record+4),*(short*)(record+6));
        Object3D_SetRotationComponents(target,*(short*)(record+8),*(short*)(record+10),*(short*)(record+12));
        target->Detach();
        target->Attach(&object->obj3D_,(short)attachment);
        if(*(short*)(record+8)||*(short*)(record+10)||*(short*)(record+12))target->SetFlag16();
        else target->ClearFlag16();
    }
    if(((*(unsigned int*)(data+0x29c)<<23)>>27)==6) *(unsigned int*)((char*)object+0x18c)|=32;
    else *(unsigned int*)((char*)object+0x18c)&=~32;
    if(*(short*)((char*)target+2)<0)target->MakeHidden();
    else target->MakeVisible();
}
