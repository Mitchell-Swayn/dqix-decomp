#include <globaldefs.h>
ARM
extern "C" void* ActorSprite_GetTurningTargetOrFacing(void*);extern "C" void* Object3D_ReadFlagSelectedPlaybackWord(void*);extern "C" void* Actor_GetFlagSelectedVerticalCoordinate(void*);
// Original: arm9/main @ 0x02040A90; symbol: func_02040a90; size: 0x4C.
extern "C" void* Actor_GetRepresentationEffectiveYawOrZero(unsigned char* p){void* a=*(void**)(p+20);if(a)return ActorSprite_GetTurningTargetOrFacing(a);void* b=*(void**)(p+24);if(b)return Object3D_ReadFlagSelectedPlaybackWord(b);void* c=*(void**)(p+28);if(!c)return 0;return Actor_GetFlagSelectedVerticalCoordinate(c);}
