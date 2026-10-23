// Keep orbit distance outside the stored height and at least one fixed-point unit, then rebuild the endpoint.
#include <globaldefs.h>
struct Orbit {char pad[0x70];int angle,height,length;};
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(char*,int,int,int);
// Original: arm9/main @ 0x0202E71C; symbol: func_0202e71c; size: 0x68.
extern "C" ARM void Camera_SetClampedOrbitDistance(void* object,int length){
 Orbit* self=(Orbit*)object;
 self->length=length;
 if(0.0f<(float)self->height){if(self->length<self->height+4096)self->length=self->height+4096;}else{if(self->length<4096-self->height)self->length=4096-self->height;}
 if(self->length<4096)self->length=4096;
 ComputeRotatedEndpointFromAngleHeightAndLength((char*)self,self->angle,self->height,self->length);
}
