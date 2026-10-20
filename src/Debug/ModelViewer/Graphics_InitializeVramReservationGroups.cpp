#include <globaldefs.h>
ARM
struct AllocatorUnion;struct State;
struct Descriptor {unsigned image0,palette0,image1,palette1;};struct Descriptors {Descriptor entries[10];};
struct StateSlot {State* state;unsigned other;};struct Owner {unsigned char prefix[0xc4];StateSlot first[4],second[4],third[4];unsigned char tail[0x70];};
extern "C" {
// Original data: arm9/ov015 @ 0x2193e48; symbol: data_ov015_02193e48.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000c0000000200000044000020020000000400004000000000100000400000000008000040000000001000004000000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 160 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Descriptors GraphicsInitializeVramReservationGroups_UnknownRoleInitializedBytes;extern char Main_UnknownRoleZeroInitializedStorage_Variant3[];
void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
void VRAM_SaveStateAndReserveImagePaletteBytes(State*,unsigned,unsigned);
}
// Original: arm9/ov015 @ 0x02192600; symbol: func_ov015_02192600; size: 0x100.
// Creates four groups of ten image/palette reservation states and one auxiliary reservation per group.
extern "C" void Graphics_InitializeVramReservationGroups(Owner* self) {
 Descriptors descriptors=GraphicsInitializeVramReservationGroups_UnknownRoleInitializedBytes;
 for(int group=0;group<4;++group) {
 self->first[group].state=(State*)AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,0x460);
 self->second[group].state=(State*)AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,0x460);
 self->third[group].state=(State*)AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,0x70);
 for(int i=0;i<10;++i) {
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)((unsigned char*)self->first[group].state+i*0x70),descriptors.entries[i].image0,descriptors.entries[i].palette0);
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)((unsigned char*)self->second[group].state+i*0x70),descriptors.entries[i].image1,descriptors.entries[i].palette1);
 }
 VRAM_SaveStateAndReserveImagePaletteBytes(self->third[group].state,0x4000,0x400);
 }
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)self->tail,0x4000,0x40);
}
