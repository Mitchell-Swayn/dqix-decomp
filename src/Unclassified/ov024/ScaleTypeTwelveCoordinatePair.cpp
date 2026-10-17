#include <globaldefs.h>
struct TypeDescriptorView { unsigned short pad[5]; unsigned short low:7; unsigned short type:4; unsigned short high:5; };
struct CoordinateScaleView { char pad[8]; struct TypeDescriptorView* descriptor; unsigned unused[2]; float sourceX,sourceY,destinationX,destinationY; };
// Original: arm9/ov024 @ 0x021F6F10; symbol: func_ov024_021f6f10; size: 0x50.
extern "C" ARM int ScaleTypeTwelveCoordinatePair(CoordinateScaleView* self) { if(self->descriptor && self->descriptor->type == 12) { self->destinationX=1.5f*self->sourceX; self->destinationY=1.5f*self->sourceY; } return 1; }
