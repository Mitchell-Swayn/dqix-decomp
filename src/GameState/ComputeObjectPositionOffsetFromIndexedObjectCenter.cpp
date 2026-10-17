#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" void __clear(void*,unsigned);
// Original: arm9/main @ 0x020A2BE8; symbol: func_020a2be8; size: 0x88.
extern "C" void ComputeObjectPositionOffsetFromIndexedObjectCenter(char* p){GameState* state=GameState::GetInstance();Vector3fix origin,delta;__clear(&origin,12);GameObject* obj=state->GetGameObjectByIndex(*(short*)(p+0x21c));if(obj){origin=obj->obj3D_.position_;origin.y+=obj->obj3D_.GetHeight()>>1;}Vector3fix_Subtract((Vector3fix*)(p+16),&origin,&delta);*(Vector3fix*)(p+0x22c)=delta;((unsigned char*)p)[0x245]|=0x11;}
