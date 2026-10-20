#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned*,unsigned);
extern "C" void Network_QueueSavedPartyMemberMode(int);
extern "C" void FieldScreen_InitializeOverlayThreeSession(unsigned char*,unsigned char,unsigned char);
struct OwnerTail {unsigned char pad[0x6fc];unsigned* list;unsigned char gap[0x450];unsigned char* record;};
struct Owner {unsigned char pad[0x3000];OwnerTail tail;};
// Original: arm9/ov017 @ 0x021C12FC; symbol: func_ov017_021c12fc; size: 0x54.
// Initializes and appends an idle type-2E record; optionally applies value one to the saved party member.
extern "C" void FieldScreen_QueueOverlayThreeSession(Owner* owner,unsigned char first,unsigned char second) {
 unsigned char* record=owner->tail.record;
 if(record[2])return;
 FieldScreen_InitializeOverlayThreeSession(record,first,second);
 LinkedQueue_AppendAndMarkActive(owner->tail.list,(unsigned)owner->tail.record);
 if(first && !second) Network_QueueSavedPartyMemberMode(1);
}
