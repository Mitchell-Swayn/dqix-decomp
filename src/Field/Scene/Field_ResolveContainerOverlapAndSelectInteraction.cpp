#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
ARM
struct InteractionCandidate { unsigned char type,unknown1;unsigned short index;unsigned unknown4;void* object;unsigned unknownC;short angle;short unknown12; };
extern "C" {
Zone3D* Zone3D_GetMainInstance();
int GameObject_GetCollisionDisplacementBypassMask(GameObject*);
void Vector3fix_Subtract(const Vector3fix*,const Vector3fix*,Vector3fix*);
void Vector3fix_Add(const Vector3fix*,const Vector3fix*,Vector3fix*);
void Vector3fix_Normalize(const Vector3fix*,Vector3fix*);
int Vector3fix_Distance(const Vector3fix*,const Vector3fix*);
short GetAbsoluteSignedAngleToTargetVector(void*,int,void*);
bool LinkedQueue_IsEmpty(void*);
bool GameObject_HasQueuedActions(GameObject*);
void Field_InitializeInteractionCandidate(InteractionCandidate*);
void Field_SelectBetterInteractionCandidate(void*,const InteractionCandidate*);
}
#pragma force_active on
// Original: arm9/ov017 @ 0x0218DFD8; symbol: func_ov017_0218dfd8; size: 0x238.
// Pushes an actor outside active container collision circles and selects the closest facing interaction.
extern "C" bool Field_ResolveContainerOverlapAndSelectInteraction(GameObject* object) {
    char* resources=(char*)GameResources_GetInstance();
    if(*((unsigned char*)*(void**)(resources+0x370c)+3)) return false;
    Vector3fix position=object->obj3D_.position_;
    bool displaced=false;
    Zone3D* zone=Zone3D_GetMainInstance();
    ZoneContainerRenderEntry* container=zone->GetContainerRenderEntry(0);
    if(!container) return false;
    int radius=object->obj3D_.GetRadius()/2+0x800;
    int bestAngle=0x3244;
    int bestIndex=-1;
    ZoneContainerRenderEntry* best=0;
    for(int i=0;i<zone->unknown_476_;++container,++i) {
        if(container->state) continue;
        Vector3fix actorPosition=position;
        Vector3fix containerPosition=container->mainPart.position;
        if(fix32abs(actorPosition.y-containerPosition.y)>=0x1000) continue;
        actorPosition.y=0;containerPosition.y=0;
        int distance=Vector3fix_Distance(&actorPosition,&containerPosition);
        if(distance<radius) {
            if(!GameObject_GetCollisionDisplacementBypassMask(object)) {
                Vector3fix delta;
                Vector3fix_Subtract(&actorPosition,&containerPosition,&delta);
                Vector3fix_Normalize(&delta,&delta);
                Vector3fixMultiplyScalar(&delta,radius,&delta);
                Vector3fix_Add(&containerPosition,&delta,&actorPosition);
                position.x=actorPosition.x;position.z=actorPosition.z;
                object->obj3D_.position_=position;
            }
            displaced=true;
        }
        if(distance<radius+0x400) {
            int angle=GetAbsoluteSignedAngleToTargetVector(&position,(short)object->obj3D_.rotation_.y,&containerPosition);
            if(angle<bestAngle) {bestAngle=angle;bestIndex=i;best=container;}
        }
    }
    void* queue=*(void**)(resources+0x36fc);
    if(best && LinkedQueue_IsEmpty(queue) && !GameObject_HasQueuedActions(object) && !(*(unsigned*)((char*)object+0x18c)&0x40) && bestAngle<0xc91) {
        InteractionCandidate candidate;
        Field_InitializeInteractionCandidate(&candidate);
        candidate.type=5;candidate.angle=bestAngle;candidate.object=best;candidate.index=bestIndex;
        Field_SelectBetterInteractionCandidate(resources,&candidate);
    }
    return displaced;
}
#pragma force_active off
