#include <globaldefs.h>
ARM
extern "C" {void ActorSprite_SelectCameraRelativeDirectionalAnimation(void*);void ActorSprite_DrawBillboardFrame(void*,int,int);
// Original: arm9/main @ 0x0203CD64; symbol: func_0203cd64; size: 0x44.
void ActorSprite_DrawWithDirectionalAnimation(unsigned char* p,int value){unsigned int flags=*(unsigned int*)(p+0x5c);if(!(flags&0x10)&&!(flags&0x20))ActorSprite_SelectCameraRelativeDirectionalAnimation(p);ActorSprite_DrawBillboardFrame(p,value,p[0x95]?0xe40:0x1000);}}
