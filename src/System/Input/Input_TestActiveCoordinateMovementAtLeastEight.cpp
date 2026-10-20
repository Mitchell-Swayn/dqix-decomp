#include <globaldefs.h>
#include "System/Matrix.h"
ARM
struct InputCoordinateMovementState { char opaque[0x220]; unsigned char startX,startY,currentX,currentY,active; };
#define ROUND_COORD(value) ((int)((value)>0 ? 0.5f+(float)((value)<<12) : (float)((value)<<12)-0.5f))
// Original: arm9/main @ 0x020968D0; symbol: func_020968d0; size: 0x150.
// Tests active byte-coordinate movement for distance >= eight units (Q12).
// Neighbor 0x020966E0 captures ReadSelectedCoordinatePair into start/current bytes
// on press and updates current coordinates while active; inactive output is untouched.
// Proposed name: Input_TestActiveCoordinateMovementAtLeastEight; old ABI for proof.
extern "C" int Input_TestActiveCoordinateMovementAtLeastEight(const InputCoordinateMovementState* state,int* distanceOut) {
 if(!state->active) return 0;
 int x1=ROUND_COORD(state->startX);
 int y1=ROUND_COORD(state->startY);
 int x2=ROUND_COORD(state->currentX);
 int y2=ROUND_COORD(state->currentY);
 Vector3fix a={0};a.x=x1;a.y=y1;
 Vector3fix b={0};b.x=x2;b.y=y2;
 int distance=Vector3fix_Distance(&a,&b);
 if(distanceOut) *distanceOut=distance;
 if(distance<0x8000) return 0;
 return 1;
}
