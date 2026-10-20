#include <globaldefs.h>
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct List {char pad[8];unsigned char count;};struct Owner {char pad[16];List* list;signed char index,selected;unsigned char unknown,active;};extern "C" char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;extern "C" int Input_ResolveCoordinateHitIndexOrNegativeStatus();extern "C" int Input_IsKeyMaskNewlyPressed(void*,unsigned);
// Original: arm9/main @ 0x020E269C; symbol: func_020e269c; size: 0xF8.
extern "C" void Input_UpdateSelectionFromPointerOrDirectionalKeys(Owner* self) {unsigned char count=self->list->count;int index=Input_ResolveCoordinateHitIndexOrNegativeStatus();if(index>=0) {if(self->index==index&&self->active)self->selected=self->index;self->active=1;self->index=index;return;}if(Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x80)) {self->index=(self->index+1)%count;self->active=0;return;}if(Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x40)) {self->index=self->index>0?self->index-1:count-1;self->active=0;return;}if(Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1)||Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x400)||Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200))self->selected=self->index;}
