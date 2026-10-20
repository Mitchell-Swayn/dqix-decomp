#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20ef078; symbol: data_020ef078.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25730000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3[];extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x0204887C; symbol: func_0204887c; size: 0x30.
extern "C" void GameObject_ReplaceNameRecordPreservingName(unsigned char* p,unsigned char* next) { unsigned char* old=*(unsigned char**)(p+0x148);*(unsigned char**)(p+0x148)=next;if(!old)return;sprintf((char*)*(unsigned char**)(p+0x148)+0x2c,UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3,(char*)old+0x2c); }
