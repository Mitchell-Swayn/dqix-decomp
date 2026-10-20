#include <globaldefs.h>
ARM
#include <World/WorldObjectInstanceList.h>
#include <World/WorldPlacementSource.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState21GetEffectiveDeltaTimeEv(void*);
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsClientSession(unsigned*);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" unsigned BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
extern "C" void World_QueueTypeB7PlacementRecord(int,int,unsigned char,int,WorldPlacementSource::PersistentState*);
// Original: arm9/main @ 0x0208EC78; symbol: func_0208ec78; size: 0x3D0.
extern "C" void World_UpdatePlacementInstances(WorldObjectInstanceList* self) {
unsigned char* gs=(unsigned char*)_ZN9GameState11GetInstanceEv();
WorldPlacementSource::GetInstance();
unsigned* connection;
BCFG::AnimationRecord* record;
WorldPlacementSource::PersistentState* states=(WorldPlacementSource::PersistentState*)(gs+0x5cdc);
connection=(unsigned*)Network_GetConnectionManager();
if(self->object) {
BCFG* config=self->object->GetCurrentAnimationConfig();
if(config) {
record=config->GetAnimationRecord(0);
if(record) {
int frame=(int)(4096.0f*((float)_ZNK9GameState21GetEffectiveDeltaTimeEv(gs)/16.666666f));
int increment=(int)(((long long)record->frameRate*frame+0x800)>>12);
WorldObjectInstanceList::Instance* instance=self->head;
while(instance) {
instance->animationTime+=increment;
if(record->endTime<instance->animationTime) instance->animationTime=record->startTime;
instance=instance->next;
}
}
}
}
if(!Network_IsClientSession(connection)) {
self->unknown4+=(float)_ZNK9GameState21GetEffectiveDeltaTimeEv(gs)/1000.0f;
if(self->unknown4<60.0f && self->unknown0==0) return;
{
if(self->unknown4>=60.0f) self->unknown4=0.0f;
WorldPlacementSource::PersistentState* state=&states[self->unknown0];
bool skip=false;
if(!state->available) skip=true;
if(state->unknown29!=1) {
unsigned char* global=(unsigned char*)GameState_GetSerializedProgressState();
if(state->unknown29==2 && !BitArray_ReadNonnegativeIndexMask(global,global+0x8c,0x798)) skip=true;
else if(state->unknown29==3 && !BitArray_ReadNonnegativeIndexMask(global,global+0x8c,0x796)) skip=true;
}
if(skip) {self->unknown0=(self->unknown0+1)%100;return;}
unsigned char count=0;
for(int i=0;i<8;i++) if(state->flags&(1<<i)) count++;
if(state->unknown0==0) {
unsigned char additional=0;
if(count==0) {
additional=(unsigned)rand()%(state->count+1);
if(additional<state->unknown13) additional=state->unknown13;
} else if(count<state->count) additional=(unsigned)rand()%(state->count-count+1);
if(self->unknown0<98) {
count+=additional;
unsigned next=(unsigned)rand()%state->count;
while(additional) {
if(!(state->flags&(1<<next))) {
state->flags|=1<<next;
additional--;
}
next++;
if(next>=state->count) next=0;
}
World_QueueTypeB7PlacementRecord(0,0,(unsigned char)state->flags,self->unknown0,state);
} else self->UpdatePersistentPlacementFlags();
state->unknown0=state->unknown25*30;
}
if(count!=state->count || self->unknown0>=98) state->unknown0--;
self->unknown0=(self->unknown0+1)%100;
}
}
}
