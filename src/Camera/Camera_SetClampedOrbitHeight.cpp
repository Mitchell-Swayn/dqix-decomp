// Clamp the stored orbit height inside the current orbit radius, then rebuild the endpoint.
#include <globaldefs.h>
struct Orbit {char pad[0x70];int angle,height,length;};
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(char*,int,int,int);
// Original: arm9/main @ 0x0202E6C0; symbol: func_0202e6c0; size: 0x5C.
extern "C" ARM void Camera_SetClampedOrbitHeight(void* object,int height){
 Orbit* self=(Orbit*)object;
 self->height=height;
 if(0.0f<(float)self->height){int limit=self->length-4096;if(limit<self->height)self->height=limit;}
 else {int limit=4096-self->length;if(self->height<limit)self->height=limit;}
 ComputeRotatedEndpointFromAngleHeightAndLength((char*)self,self->angle,self->height,self->length);
}
