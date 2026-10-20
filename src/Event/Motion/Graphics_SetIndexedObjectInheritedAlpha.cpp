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
extern "C" unsigned ActorSprite_SetAlpha(...);
extern "C" unsigned _ZN8Object3D17SetInheritedAlphaEi(...);
// Original: arm9/ov001 @ 0x02164908; symbol: Graphics_SetIndexedObjectInheritedAlpha; size: 0xcc.
extern "C" int Graphics_SetIndexedObjectInheritedAlpha(unsigned self,int index,int alpha){
if(index<0||index>=32)return 0;unsigned entry=self+index*16;switch(U32(entry)){
case 0:case 1:case 4:case 5:{unsigned object=U32(entry+12);if(!object)return 0;_ZN8Object3D17SetInheritedAlphaEi(object,alpha);return 1;}
case 6:{unsigned object=U32(entry+12);if(!object)return 0;object=U32(object+0x18);if(!object)return 0;_ZN8Object3D17SetInheritedAlphaEi(object,alpha);return 1;}
case 2:{unsigned object=U32(entry+12);if(!object)return 0;object=U32(object+0x14);if(!object)return 0;ActorSprite_SetAlpha(object,alpha);break;}
}return 0;
}