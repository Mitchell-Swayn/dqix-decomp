#include <globaldefs.h>
ARM
extern "C" char* GameResources_GetInstance();
extern "C" void* Field_GetSharedSubscreenInstance(void*);
extern "C" void Object_SetTwoFixedPointRecordPositions(void*,int,int,int,short);
// Original: arm9/ov005 @ 0x0215A2C8; symbol: Graphics_AdjustTwoRecordPositionsForPendingFlags; size: 0xb4.
// Consumes pending adjustment flags20000/40000 and updates two fixed point record positions.
extern "C" void Graphics_AdjustTwoRecordPositionsForPendingFlags(unsigned char* self) {
 if(*(unsigned char*)(self+self[0x3dbc]+0x3df4)==1)return;short x=142,y=160;
 if(*(unsigned*)(self+0x3dcc)&0x20000){--x;++y;*(unsigned*)(self+0x3dcc)&=~0x20000;}
 short z=235,w=160;if(*(unsigned*)(self+0x3dcc)&0x40000){++z;++w;*(unsigned*)(self+0x3dcc)&=~0x40000;}
 Object_SetTwoFixedPointRecordPositions(Field_GetSharedSubscreenInstance(*(void**)(GameResources_GetInstance()+0x3708)),x,y,z,w);
}
