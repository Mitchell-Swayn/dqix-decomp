#include <globaldefs.h>
ARM
struct StateInner { char pad[0x6fc]; unsigned *node; char gap[0x38]; unsigned char *bytes; };
struct StateOuter { char pad[0x3000]; StateInner inner; };
extern "C" void FieldFacilityMenu_InitializeOverlayCommand(unsigned char *p);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned *, unsigned);
// Original: arm9/ov017 @ 0x021B2C24; symbol: Object_ApplyInnerValueAndAppendNode; size: 0x28.
// Applies the embedded byte buffer, then appends the associated node using that same buffer pointer.
extern "C" void FieldFacilityMenu_QueueOverlayCommand(StateOuter *object) {
    FieldFacilityMenu_InitializeOverlayCommand(object->inner.bytes);
    LinkedQueue_AppendAndMarkActive(object->inner.node, (unsigned)object->inner.bytes);
}
