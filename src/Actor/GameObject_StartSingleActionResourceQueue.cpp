#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" void* SystemState_GetGlobalFlags();
extern "C" bool SystemState_TestAnyFlags(const unsigned*,unsigned);
extern "C" void BackgroundLoader_QueueIndexedObjectResources(char*,int);
extern "C" void QueueFirstObjectBytePayload(int,void*,int,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadFirstObjectIndex(void*);
extern "C" void* GameState_GetFieldOrbitCamera(void*);
extern "C" int Camera_BeginLoadingFocusBlend(void*);

inline int IsQueueBusy(char* p){return *(signed char*)(p+0x17c)>0;}
inline bool EqualIndex(int actual,int expected){return actual==expected;}
// Original: arm9/main @ 0x02052E44; symbol: GameState_StartBoundedIndexedResourceQueue; size: 0x100.
extern "C" int GameObject_StartSingleActionResourceQueue(char* self,signed char value,...){

 if(SystemState_TestAnyFlags((const unsigned*)SystemState_GetGlobalFlags(),2))return 0;
 int busy=IsQueueBusy(self);if(busy)return 0;if(value<=0||value>=33)return 0;
 self[0x178]=value;self[0x17c]=1;self[0x17d]=0;*(int*)(self+0x180)=-1;self[0x17e]=0;self[0x184]=0;*(int*)(self+0x190)=0;*(int*)(self+0x194)=-1;self[0x185]=0;self[0x186]=0;
 BackgroundLoader_QueueIndexedObjectResources(self,*(signed char*)(self+*(signed char*)(self+0x17d)+0x178));QueueFirstObjectBytePayload(*(short*)(self+4),&value,1,0);
 void *game=_ZN9GameState11GetInstanceEv();int index=*(short*)(self+4);int current=GameState_ReadFirstObjectIndex(game);if(EqualIndex(current,index)){void *object=GameState_GetFieldOrbitCamera(game);if(object)Camera_BeginLoadingFocusBlend(object);}return 1;
}
