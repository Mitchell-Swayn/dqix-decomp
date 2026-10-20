#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d76d8; symbol: data_ov017_021d76d8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ff00ffff.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern unsigned char FieldInteractionUpdateActorAndMemberTargets_UnknownRoleInitializedBytes[];
extern "C" void Field_InitializeOverlayEightActivityRequest(void *);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int *, unsigned int);
// Original: arm9/ov017 @ 0x021A4DD0; symbol: func_ov017_021a4dd0; size: 0x3C.
extern "C" void FieldInteraction_QueueSelectedMemberFragmentTransfer(void *self) {
    unsigned int *list = *(unsigned int **)((char *)self + 0x36FC);
    unsigned int node = *(unsigned int *)((char *)self + 0x3B84);
    if (*(signed char *)FieldInteractionUpdateActorAndMemberTargets_UnknownRoleInitializedBytes < 0) return;
    Field_InitializeOverlayEightActivityRequest((void *)node);
    LinkedQueue_AppendAndMarkActive(list, node);
}
