#include <globaldefs.h>
ARM
struct Selection { unsigned char pad[0xBE]; unsigned char row, padBF, column; };
// Original data: arm9/main @ 0x20ef9c4; symbol: data_020ef9c4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000504050000000000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char GameObjectSelectAnimationForMotionState_UnknownRoleInitializedBytes[9][13];
extern "C" void Object_SelectRegularAnimationAndStoreIndex(Selection*, int);
// Original: arm9/main @ 0x02033DD4; symbol: func_02033dd4; size: 0x44.
extern "C" void GameObject_SelectAnimationForMotionState(Selection* self) {
 if (self->row >= 9) return;
 if (self->column >= 12) self->column = 0;
 Object_SelectRegularAnimationAndStoreIndex(self, GameObjectSelectAnimationForMotionState_UnknownRoleInitializedBytes[self->row][self->column]);
}
