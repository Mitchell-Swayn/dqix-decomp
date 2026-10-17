#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
static inline void CopyCoordinates(void *out,const void *in) {struct Coordinates { int values[3]; };*(Coordinates *)out=*(const Coordinates *)in;}
extern "C" {
void ReadRemoteScaledPositionOrLocalPositionFallback(Vector3fix *,GameObject *);void SetObjectAngleAndClearFlagC48000(Object3D *,int);void ChangeCurrentValueAndNotifyUpdate(Object3D *,int);
// Original: arm9/main @ 0x020776A0; symbol: func_020776a0; size: 0xE8.
int Object3D_FaceSelectedPartyMemberAndResetMovement(Object3D *object) {
    unsigned char *p=(unsigned char *)object;
    GameState *state=GameState::GetInstance();
    GameObject *member=state->GetPartyMemberByIndex(*(unsigned short *)(p+0x166));
    if(!member)return 0;
    p[0x17d]|=64;
    Vector3fix copy,delta,point;
    ReadRemoteScaledPositionOrLocalPositionFallback((Vector3fix *)&point,member);CopyCoordinates(&copy,&point);
    Vector3fix_Subtract((Vector3fix *)&copy,(Vector3fix *)(p+0x44),(Vector3fix *)&delta);Vector3fix_Normalize((Vector3fix *)&delta,(Vector3fix *)&delta);
    SetObjectAngleAndClearFlagC48000(object,fix32_Atan2(delta.x,delta.z));
    *(short *)(p+0xb0)=151;*(short *)(p+0xb4)=450;*(short *)(p+0xb2)=450;ChangeCurrentValueAndNotifyUpdate(object,1);
    unsigned int field=state->GetProtagonist()->obj3D_.GetField06();
    if(field==object->GetField06())object->DisableFlag(128);
    p[0x17a]=0;return 1;
}
}
