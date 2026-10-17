#include <globaldefs.h>
ARM
#pragma always_inline on
struct Vec {int x,y,z;};struct Directions {Vec vectors[4];};
extern "C" const Directions data_020e7a20;
extern "C" int rand();
extern "C" int _Z8fix32sini(int);
extern "C" int _Z8fix32cosi(int);
extern "C" void _ZN8Vector3iaSERKS_(Vec*,const Vec*);
extern "C" void Vector3fix_Add(const Vec*,const Vec*,Vec*);
extern "C" void DispatchVectorToFirstAvailableSource(void*,Vec*);
struct Configuration {char pad[0x1f];unsigned char mode;char gap[2];short angle;int maxX,maxZ,minX,minZ;};
struct Object {char pad[12];Configuration* config;};
// Original: arm9/main @ 0x02040F48; symbol: func_02040f48; size: 0x234.
extern "C" void Object_DispatchRandomStepWithinBounds(Object* p,const Vec* input) {
 Directions directions=data_020e7a20;
 Vec position=*input;
 Vec candidates[4];
 if(p->config->mode==8) {
  int sine=_Z8fix32sini(p->config->angle);
  int cosine=_Z8fix32cosi(p->config->angle);
  if(sine<0)sine=-sine;
  if(cosine<0)cosine=-cosine;
  int angle=p->config->angle;
  if(angle<0x191e || (angle>0x323d && angle<0x4b5c)) {
   directions.vectors[0].x=sine;directions.vectors[0].z=cosine;
   directions.vectors[1].x=sine;directions.vectors[1].z=cosine;
   directions.vectors[2].x=-sine;directions.vectors[2].z=-cosine;
   directions.vectors[3].x=-sine;directions.vectors[3].z=-cosine;
  }else {
   directions.vectors[0].x=sine;directions.vectors[0].z=-cosine;
   directions.vectors[1].x=sine;directions.vectors[1].z=-cosine;
   directions.vectors[2].x=-sine;directions.vectors[2].z=cosine;
   directions.vectors[3].x=-sine;directions.vectors[3].z=cosine;
  }
 }
 int count=0;
 if(position.x<p->config->maxX) {_ZN8Vector3iaSERKS_(candidates+count,&directions.vectors[0]);++count;}
 if(position.z<p->config->maxZ) {_ZN8Vector3iaSERKS_(candidates+count,&directions.vectors[1]);++count;}
 if(position.x>p->config->minX) {_ZN8Vector3iaSERKS_(candidates+count,&directions.vectors[2]);++count;}
 if(position.z>p->config->minZ) {_ZN8Vector3iaSERKS_(candidates+count,&directions.vectors[3]);++count;}
 if(position.x>p->config->maxX)position.x=p->config->maxX;
 if(position.z>p->config->maxZ)position.z=p->config->maxZ;
 if(position.x<p->config->minX)position.x=p->config->minX;
 if(position.z<p->config->minZ)position.z=p->config->minZ;
 Vector3fix_Add(&position,&candidates[rand()%count],&position);
 DispatchVectorToFirstAvailableSource(p,&position);
}
