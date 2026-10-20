#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
struct Motion {unsigned short id;unsigned char pad,state;int speed,accel,max;Vec position,target;};
struct Object {void (**vtable)();};
extern "C" void Vector3fix_Subtract(const Vec*,const Vec*,Vec*);
extern "C" void Vector3fix_Normalize(const Vec*,Vec*);
extern "C" void Vector3fix_Add(const Vec*,const Vec*,Vec*);
extern "C" int Vector3fix_Distance(const Vec*,const Vec*);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vec*,int,Vec*);
extern "C" void _ZN8Vector3iaSERKS_(Vec*,const Vec*);
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" Object* MenuRecordList_LocateByKey(void*,unsigned short);
extern "C" void Menu_ResetMotionQueueEntry(void*);
// Original: arm9/ov023 @ 0x021FA108; symbol: func_ov023_021fa108; size: 0x190.
extern "C" void World_UpdateAcceleratingMotionToTarget(void* unused,void* context,Motion* motion) {
 Vec direction;
 Vector3fix_Subtract(&motion->target,&motion->position,&direction);
 Vector3fix_Normalize(&direction,&direction);
 int complete=0;
 if(motion->state==0) {
 motion->speed+=motion->accel;
 if(motion->max<motion->speed)motion->speed=motion->max;
 Vec step;
 _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&direction,motion->speed,&step);
 Vector3fix_Add(&motion->position,&step,&motion->position);
 int distance=Vector3fix_Distance(&motion->target,&motion->position);
 float speed=(float)motion->speed/4096.0f;
 float square=speed*speed;
 int stopping=(int)(4096.0f*(square/(2.0f*((float)motion->accel/4096.0f))));
 if(distance<stopping)motion->state=1;
 } else if(motion->state==1) {
 int distance=Vector3fix_Distance(&motion->target,&motion->position);
 if(motion->accel<motion->speed&&motion->speed-motion->accel<distance) {
 Vec step;
 motion->speed-=motion->accel;
 _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&direction,motion->speed,&step);
 Vector3fix_Add(&motion->position,&step,&motion->position);
 } else {
 _ZN8Vector3iaSERKS_(&motion->position,&motion->target);
 complete=1;
 }
 }
 Object* object=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(context),motion->id);
 if(object)((void(*)(Object*,Vec*))object->vtable[7])(object,&motion->position);
 if(complete)Menu_ResetMotionQueueEntry(motion);
}
