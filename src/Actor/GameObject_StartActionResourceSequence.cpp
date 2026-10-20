#include <globaldefs.h>
#pragma opt_propagation off
#include <GameState/GameState.h>
ARM
extern "C" void* SystemState_GetGlobalFlags();
extern "C" bool SystemState_TestAnyFlags(const unsigned int* word, unsigned int mask);
extern "C" void BackgroundLoader_QueueIndexedObjectResources(char* p,int index);
extern "C" void QueueFirstObjectBytePayload(int index,const char* payload,int count,int value);
extern "C" unsigned char GameState_ReadFirstObjectIndex(GameState* state);
extern "C" void* GameState_GetFieldOrbitCamera(GameState* state);
extern "C" int Camera_BeginLoadingFocusBlend(unsigned char *p);
struct SequenceFlags { unsigned char mode:2;unsigned char rest:6; };
// Original: arm9/main @ 0x02052F44; symbol: GameObject_StartActionResourceSequence; size: 0x148.
// Keeps up to four action resource IDs in 1..32, resets the sequence state, queues the
// first resource and its network payload, and starts a camera focus blend for the first object.
extern "C" int GameObject_StartActionResourceSequence(char* self,const char* ids,int count) {
 if(SystemState_TestAnyFlags((const unsigned int*)SystemState_GetGlobalFlags(),2))return 0;
 if(count>4)return 0;
 bool active=self[0x17c]>0;
 if(active)return 0;
 int validCount=0;
 int i=0;
 while(i<count) {
  int id=ids[i];
  if(id>0 && id<0x21){(self+validCount)[0x178]=id;++validCount;}
  ++i;
 }
 if(!validCount)return 0;
 self[0x17c]=validCount;self[0x17d]=0;
 *(int*)(self+0x180)=-1;self[0x17e]=0;self[0x184]=0;
 *(int*)(self+0x190)=0;*(int*)(self+0x194)=-1;self[0x185]=0;self[0x186]=0;
 BackgroundLoader_QueueIndexedObjectResources(self,(self+self[0x17d])[0x178]);
 QueueFirstObjectBytePayload(*(short*)(self+4),ids,count,0);
 ((SequenceFlags*)(self+0xc1))->mode|=2;
 GameState* state=GameState::GetInstance();
 int index=*(short*)(self+4);
 int currentIndex=GameState_ReadFirstObjectIndex(state);
 if(currentIndex==index) {
  void* camera=GameState_GetFieldOrbitCamera(state);
  if(camera)Camera_BeginLoadingFocusBlend((unsigned char*)camera);
 }
 return 1;
}
