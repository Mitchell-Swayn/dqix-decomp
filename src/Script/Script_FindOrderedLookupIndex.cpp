// Original data: arm9/main @ 0x20e87c0; symbol: data_020e87c0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000030002000400050006000700080009000a000b0012000c000d000e000f0010001100130001001400150016001700180019001a001b001c001d001e001f00 ...; full span in module reference.
// Observed span: 68 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" short ScriptGetOrderedLookupId_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x0206E3E8; symbol: func_0206e3e8; size: 0x3C.
extern "C" int Script_FindOrderedLookupIndex(int unused,int key){short result=0;short* p=ScriptGetOrderedLookupId_UnknownRoleInitializedBytes;for(int i=0;i<32;++i,++p){if(*p==key){result=i;break;}}return result;}
