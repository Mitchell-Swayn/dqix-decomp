#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" void Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(void*,unsigned,int);
struct Object {char pad[0x13c];unsigned char* data;};
// Original: arm9/main @ 0x020494C0; symbol: func_020494c0; size: 0x38.
extern "C" ARM void ApplyPrimaryOrFallbackComponentByte(Object* p){if(!p->data)return;GameState::GetInstance();unsigned char value=p->data[0x4c];if(value==255)value=p->data[0x4d];Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(p,value,0);}
