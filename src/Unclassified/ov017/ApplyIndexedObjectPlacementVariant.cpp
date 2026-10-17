#include <globaldefs.h>
#pragma optimize_for_size off
#include <GameState/GameState.h>
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned char* ReadWordFieldAtOffset150(void*);
extern "C" unsigned char* ReadGlobalAt02109A54();
extern "C" unsigned char ReadFieldAtOffset1A0(void*,int);
extern "C" void Object_SetByteAtOffset1A7(void*,int);
extern "C" void Object_SetUnsignedIntAtOffset44AndSetUnsignedIntAtOffset48AndSetUnsignedIntAtOffset4C(void*,int,int,int);
extern "C" void Object_SetUnsignedIntAtOffset50AndSetUnsignedIntAtOffset54AndSetUnsignedIntAtOffset58(void*,int,int,int);
// Original: arm9/ov017 @ 0x021917F0; symbol: func_ov017_021917f0; size: 0x1D8.
extern "C" ARM void ApplyIndexedObjectPlacementVariant(int index, int variant)
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
    data=ReadWordFieldAtOffset150(object);
    if(!data)return;
    record=ReadGlobalAt02109A54()+((*(unsigned int*)(data+0x29c)<<23)>>27)*28;
    if(variant==1)
    {
        attachment=ReadFieldAtOffset1A0(object,record[14]);
        Object_SetByteAtOffset1A7(object,attachment);
        Object_SetUnsignedIntAtOffset44AndSetUnsignedIntAtOffset48AndSetUnsignedIntAtOffset4C(target,*(short*)(record+16),*(short*)(record+18),*(short*)(record+20));
        Object_SetUnsignedIntAtOffset50AndSetUnsignedIntAtOffset54AndSetUnsignedIntAtOffset58(target,*(short*)(record+22),*(short*)(record+24),*(short*)(record+26));
        target->Detach();
        target->Attach(&object->obj3D_,(short)attachment);
        if(*(short*)(record+22)||*(short*)(record+24)||*(short*)(record+26))target->SetFlag16();
        else target->ClearFlag16();
    }
    else if(variant==0)
    {
        attachment=ReadFieldAtOffset1A0(object,record[1]);
        Object_SetByteAtOffset1A7(object,attachment);
        Object_SetUnsignedIntAtOffset44AndSetUnsignedIntAtOffset48AndSetUnsignedIntAtOffset4C(target,*(short*)(record+2),*(short*)(record+4),*(short*)(record+6));
        Object_SetUnsignedIntAtOffset50AndSetUnsignedIntAtOffset54AndSetUnsignedIntAtOffset58(target,*(short*)(record+8),*(short*)(record+10),*(short*)(record+12));
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
