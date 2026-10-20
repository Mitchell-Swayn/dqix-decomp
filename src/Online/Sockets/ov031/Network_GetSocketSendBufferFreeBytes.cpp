#include <globaldefs.h>
ARM
struct RingIndices {volatile unsigned short begin,end;};
struct Ring {char unknown[0xf8];int capacity;unsigned unknownFC;RingIndices indices;};
struct Owner {char unknown[0x68];Ring* ring;};
// Original: arm9/ov031 @ 0x022063EC; symbol: Network_GetSocketSendBufferFreeBytes; size: 0x24.
// Counts slots between the ring indices, retaining one reserved slot.
// The indices are read in sequence; WaitForMinimumAvailableCount protects this
// shared state with IRQ exclusion and waits on the adjacent context list.
extern "C" int Network_GetSocketSendBufferFreeBytes(Owner* self) {
 int begin;
 Ring* ring=self->ring;
 RingIndices* indices=&ring->indices;
 int capacity=ring->capacity;
 int end;
 begin=indices->begin;
 end=indices->end;
 int distance=end-begin-1;
 if(distance<0)distance+=capacity;
 return distance;
}
