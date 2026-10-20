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
// Original data: arm9/main @ 0x20e73cc; symbol: data_020e73cc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 04ef02020000000038e902020000000094e6020200000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e73e4; symbol: data_020e73e4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 04ef0202000000005cec02020000000094e6020200000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern MotionMethods MotionOwnerAdvanceThreeTracksPositionAndAngle_UnknownRoleProcedureReferenceRecords_Variant2,MotionOwnerAdvanceThreeTracksPositionAndAngle_UnknownRoleProcedureReferenceRecords;
bool VectorTransition_IsActive(Track*);
void VectorTransition_Advance(Track*);
void Camera_RotateTargetAroundEye(MotionOwner*,int);
}
// Original: arm9/main @ 0x0202EF14; symbol: func_0202ef14; size: 0x1B0.
extern "C" void MotionOwner_AdvanceThreeTracksPositionAndAngle(MotionOwner* owner)
{
    Track* tracks[3]={&owner->tracks[0],&owner->tracks[1],&owner->tracks[2]};
    if(owner->flags&2) {
        MotionMethods methods=MotionOwnerAdvanceThreeTracksPositionAndAngle_UnknownRoleProcedureReferenceRecords_Variant2;
        for(int i=0;i<3;i++) {
            if(VectorTransition_IsActive(tracks[i])) {
                Track* track=tracks[i];VectorTransition_Advance(track);
                (owner->*methods.methods[i])(track->value);
            }
        }
    } else {
        MotionMethods methods=MotionOwnerAdvanceThreeTracksPositionAndAngle_UnknownRoleProcedureReferenceRecords;
        for(int i=0;i<3;i++) {
            if(VectorTransition_IsActive(tracks[i])) {
                Track* track=tracks[i];VectorTransition_Advance(track);
                (owner->*methods.methods[i])(track->value);
            }
        }
    }
    if(owner->positionTicks) { --owner->positionTicks;owner->position+=owner->velocity; }
    if(owner->moveTicks) { --owner->moveTicks;Camera_RotateTargetAroundEye(owner,owner->moveStep); }
    if(owner->angularTicks) { --owner->angularTicks;owner->angle=fix32ReduceAngle0To2Pi(owner->angle+owner->angularStep); }
}
