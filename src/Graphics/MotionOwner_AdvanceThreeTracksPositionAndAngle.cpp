#include <globaldefs.h>
#pragma opt_common_subs off
#include "Graphics/Vector.h"
struct Track { unsigned state;unsigned char value[36]; };
struct MotionOwner {
    unsigned char reserved[0x7c];short position;unsigned char reserved7E[0xea];
    unsigned flags;Track tracks[3];unsigned char reserved1E4[8];
    short velocity;unsigned short positionTicks;unsigned char reserved1F0[30];
    short moveStep;unsigned short moveTicks;short angle,angularStep;unsigned short angularTicks;
};
typedef void (MotionOwner::*MotionMethod)(const void*);
struct MotionMethods { MotionMethod methods[3]; };
extern "C" {
extern MotionMethods data_020e73e4,data_020e73cc;
bool IsFirstValueNonzero(Track*);
void Object_InvokeIndexedMemberMethod(Track*);
void RotateEndpointAroundOriginOnYAxis(MotionOwner*,int);
}
// Original: arm9/main @ 0x0202EF14; symbol: func_0202ef14; size: 0x1B0.
extern "C" void MotionOwner_AdvanceThreeTracksPositionAndAngle(MotionOwner* owner)
{
    Track* tracks[3]={&owner->tracks[0],&owner->tracks[1],&owner->tracks[2]};
    if(owner->flags&2) {
        MotionMethods methods=data_020e73e4;
        for(int i=0;i<3;i++) {
            if(IsFirstValueNonzero(tracks[i])) {
                Track* track=tracks[i];Object_InvokeIndexedMemberMethod(track);
                (owner->*methods.methods[i])(track->value);
            }
        }
    } else {
        MotionMethods methods=data_020e73cc;
        for(int i=0;i<3;i++) {
            if(IsFirstValueNonzero(tracks[i])) {
                Track* track=tracks[i];Object_InvokeIndexedMemberMethod(track);
                (owner->*methods.methods[i])(track->value);
            }
        }
    }
    if(owner->positionTicks) { --owner->positionTicks;owner->position+=owner->velocity; }
    if(owner->moveTicks) { --owner->moveTicks;RotateEndpointAroundOriginOnYAxis(owner,owner->moveStep); }
    if(owner->angularTicks) { --owner->angularTicks;owner->angle=fix32ReduceAngle0To2Pi(owner->angle+owner->angularStep); }
}
