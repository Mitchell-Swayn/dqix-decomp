#include <globaldefs.h>
#include <System/Interrupts.h>
ARM
struct Link { Link* previous; Link* next; };
// Original: arm9/ov031 @ 0x0223D8D8; symbol: WfcUtility_InsertListNodeBefore; size: 0x30.
// Inserts a node before the supplied link while VBlank interrupts are masked.
extern "C" void WfcUtility_InsertListNodeBefore(Link* position,Link* node) {
 unsigned mask=DisableSpecificInterrupts(1);
 position->previous->next=node;
 node->previous=position->previous;
 node->next=position;
 position->previous=node;
 EnableSpecificInterrupts(mask);
}
