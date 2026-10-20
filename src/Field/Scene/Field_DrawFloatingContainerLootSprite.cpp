#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
struct Vector {int x,y,z;};
extern "C" unsigned GameState_ReadUnknownB0(...);
extern "C" unsigned Graphics_ConvertCopiedWorldVectorToScreenCoordinates(...);
extern "C" unsigned Graphics_DrawSelectedResource(...);
extern "C" unsigned _Z8fix32sini(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZNK9GameState12GetTickCountEv(...);
// Original: arm9/ov017 @ 0x021b6090; symbol: Graphics_DrawSineOffsetResourceAtProjectedPosition; size: 0xe4.
extern "C" void Field_DrawFloatingContainerLootSprite(unsigned self){
unsigned game=_ZN9GameState11GetInstanceEv(),camera=GameState_ReadUnknownB0(game);Vector position=*(Vector*)(self+0x2c);if((int)U32(self+0x38)<0x191e)U32(self+0x38)+=_ZNK9GameState12GetTickCountEv(game)*0x199;position.y+=_Z8fix32sini(U32(self+0x38));int x,y;if(camera)Graphics_ConvertCopiedWorldVectorToScreenCoordinates(camera,D(&position),D(&x),D(&y));unsigned resource=U32(self+0x20);if(resource){int screenX=(x-12)<<12;int screenY=(y-40)<<12;U32(resource+0x1c)=screenX;U32(resource+0x20)=screenY;U32(resource+0x24)=0;Graphics_DrawSelectedResource(resource,1);unsigned alpha=U8(self+0x16);if(alpha>31)alpha=31;U16(resource+0x82)=alpha;}
}