#pragma opt_propagation off
#pragma opt_arithtransformation off
#include <globaldefs.h>
struct Flags { unsigned char low:4; unsigned char high:4; };
struct Owner {char pad[0x1c];Flags flags;};
// Original data: arm9/main @ 0x20f01d8; symbol: data_020f01d8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex d0a60402b4a6040298a604027ca6040260a6040244a6040228a604020ca60402.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void (*GraphicsSetBackgroundColorMode_UnknownRoleProcedureReferenceRecords[4][4])(unsigned int);
// Original: arm9/main @ 0x0204B5B4; symbol: func_0204b5b4; size: 0x34.
extern "C" ARM void Graphics_SetBackgroundColorMode(Owner* self,unsigned int mode) {
 Flags* flags=&self->flags;
 void (*function)(unsigned int)=GraphicsSetBackgroundColorMode_UnknownRoleProcedureReferenceRecords[flags->low][flags->high];
 mode &= 3;
 function(mode);
}
