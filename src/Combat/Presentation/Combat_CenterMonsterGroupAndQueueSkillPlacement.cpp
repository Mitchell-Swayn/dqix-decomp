#include <globaldefs.h>
#include <System/Matrix.h>
ARM
typedef Vector3fix Vec;struct Placement {unsigned zero,duration;short index,shortDuration;Vec offset;unsigned tail;};
extern "C" {void* __clear(void*,unsigned);void* _ZN9GameState11GetInstanceEv();void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);void _Z22Vector3fixDivideScalarPK8Vector3iiPS_(const Vec*,int,Vec*);void* _ZN8Vector3iaSERKS_(void*,const void*);void Combat_ResetQueuedMotionCommand(unsigned*);void Combat_QueueMovementOrTurnTask(void*,Placement*);void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);extern char Combat_CenterMonsterGroupAndQueueSkillPlacement_TextSkill1In[];}
// Original: arm9/ov025 @ 0x021E75A4; symbol: func_ov025_021e75a4; size: 0x178.
// Centers the eight indexed objects horizontally and queues 300-frame placement records.
extern "C" int Combat_CenterMonsterGroupAndQueueSkillPlacement(void* unused0,void* unused1,void* queue) {
 void* game=_ZN9GameState11GetInstanceEv();char* objects[8];Vec center;
 int count=0;char** objectSlot=objects;__clear(&center,12);
 for(int i=0;i<8;objectSlot++,i++){
 char* object=(char*)_ZN9GameState20GetGameObjectByIndexEi(game,i+192);*objectSlot=object;
 if(object){Vec temp=*(Vec*)(object+0x44);Vector3fix_Add(&center,&temp,&center);count++;}
 }
 _Z22Vector3fixDivideScalarPK8Vector3iiPS_(&center,count<<12,&center);
 objectSlot=objects;
 for(int i=0;i<count;objectSlot++,i++){char* object=*objectSlot;if(object){Vec position=*(Vec*)(object+0x44);position.x-=center.x;_ZN8Vector3iaSERKS_(object+0x44,&position);}}
 center.x=0;
 for(int i=0;i<8;i++){
 short id=(short)(i+192);void* object=_ZN9GameState20GetGameObjectByIndexEi(game,id);if(object){Placement placement;Combat_ResetQueuedMotionCommand((unsigned*)&placement);placement.index=id;placement.zero=0;placement.duration=300;placement.shortDuration=300;_ZN8Vector3iaSERKS_(&placement.offset,&center);Combat_QueueMovementOrTurnTask(queue,&placement);_ZN8Object3D18SetAnimationByNameEPKci(object,Combat_CenterMonsterGroupAndQueueSkillPlacement_TextSkill1In,0);}
 }
 return 1;
}
