#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void _ZN8Vector3iaSERKS_(void*,const void*);
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(char*,int);
extern "C" unsigned char* ActorPool_FindActiveActorById(void*,unsigned);
extern "C" unsigned short* Actor_GetPlacementDescriptor(void*);
extern "C" char* Actor_GetMotionDescriptor(void*);
extern "C" void Actor_SetRepresentationPosition(unsigned char*,unsigned,unsigned,unsigned);
extern "C" void Actor_SetRepresentationTargetYaw(void*,unsigned);
extern "C" void Actor_SetRepresentationCurrentAndTargetYaw(void*,unsigned);
struct Command { short x,y,z,angle; unsigned short id:9,flag:1,remaining:5,mode:1; };
struct Vec { int x,y,z; };
// Original: arm9/main @ 0x0203E2C4; symbol: func_0203e2c4; size: 0x260.
extern "C" void ApplyQueuedEntryTransformsAndSavedPosition(char* self,unsigned expected) {
 if(*(unsigned short*)(self+0x1de)==expected) {
 Command* cmd=(Command*)(self+0x9e);
 for(int i=0;i<*(unsigned short*)(self+0x1e0);cmd++,i++) {
 char** entries=(char**)(self+0xc);
 for(unsigned j=0;j<*(unsigned*)(self+0x8c);entries++,j++) {
 char* entry=*entries;
 unsigned short* key=Actor_GetPlacementDescriptor(entry);
 char* data=Actor_GetMotionDescriptor(entry);
 if(!key || !data || *key!=cmd->id) continue;
 Vec pos;pos.x=cmd->x<<4;pos.y=cmd->y<<4;pos.z=cmd->z<<4;
 int angle=cmd->angle;
 if(*(char**)(entry+0x14)) _ZN8Vector3iaSERKS_(*(char**)(entry+0x14)+4,&pos);
 else if(*(char**)(entry+0x18)) _ZN8Vector3iaSERKS_(*(char**)(entry+0x18)+0x44,&pos);
 else if(*(char**)(entry+0x1c)) {
 _ZN8Vector3iaSERKS_(*(char**)(entry+0x1c)+0x44,&pos);
 Object3D_SetNormalizedAngleAndUpdatePosition(*(char**)(entry+0x1c),angle);
 }
 Actor_SetRepresentationCurrentAndTargetYaw(entry,angle);
 Actor_SetRepresentationTargetYaw(entry,angle);
 if(cmd->flag) *(unsigned*)entry|=0x8000;
 data=Actor_GetMotionDescriptor(entry);
 if(data) {
 char* node=*(char**)(data+0x34);
 while(node) {
 if(cmd->remaining==0) *(int*)(node+0xc)=1; else *(int*)(node+0xc)=0;
 cmd->remaining--;
 node=*(char**)(node+0x10);
 if(node==*(char**)(data+0x34)) break;
 }
 }
 if(cmd->mode) *(unsigned char*)(data+0xa)=(*(unsigned char*)(data+0xa)&~0x38)|0x18;
 if(*(unsigned*)(self+0x1e4)&(1<<j)) *(unsigned*)entry|=0x40000;
 break;
 }
 }
 }
 *(unsigned short*)(self+0x1de)=0;*(unsigned*)(self+0x1e4)=0;
 char* saved=(char*)_ZN9GameState11GetInstanceEv()+0x7e78;
 unsigned id=*(unsigned char*)(saved+6);
 if(id!=255) {
 unsigned char* entry=ActorPool_FindActiveActorById(self,id);
 if(entry) Actor_SetRepresentationPosition(entry,*(short*)saved<<4,*(short*)(saved+2)<<4,*(short*)(saved+4)<<4);
 *(unsigned char*)(saved+6)=255;
 }
}
