#pragma optimize_for_size off
#include <globaldefs.h>
ARM
#include "std_library_functions.h"
// Original data: arm9/main @ 0x20ef6d0; symbol: data_020ef6d0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 256400.
// Observed span: 3 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const char FormatThreeIndexedTextAndValueSlots_UnknownRoleInitializedBytes[];
struct Object { unsigned char pad[0x6ec]; char text[0x7a]; unsigned short value; };
// Original: arm9/main @ 0x0202656C; symbol: func_0202656c; size: 0x3C.
extern "C" void TreasureMapPanel_SetMinimumTurnCount(Object* object,unsigned value) {object->value=value;if(object->value==0)return;if(object->value>=1000)return;sprintf(object->text,FormatThreeIndexedTextAndValueSlots_UnknownRoleInitializedBytes,value);}
