#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20e80cc; symbol: data_020e80cc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 414354494f4e0000000000004143544f5200000000000000434f4e534f4e414e54000000454c53450000000000000000454e4449460000000000000046000000 ...; full span in module reference.
// Observed span: 624 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f08f8; symbol: data_020f08f8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 5f00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void __clear(void*,unsigned);extern "C" char* strcat(char*,const char*);extern "C" int sprintf(char*,const char*,...);extern "C" char TextFormatUpToFourIndexedStringFragments_UnknownRoleInitializedBytes_Variant2[];extern "C" char TextFormatUpToFourIndexedStringFragments_UnknownRoleInitializedBytes[][12];extern "C" char Text_FormatUpToFourIndexedStringFragments_FormatS[];
// Original: arm9/main @ 0x02068EA0; symbol: func_02068ea0; size: 0xA0.
extern "C" void Text_FormatUpToFourIndexedStringFragments(signed char* values,char* output){if(values[0]<0)return;char buffer[48];__clear(buffer,48);for(int i=0;i<4;i++){if(*values<0)break;if(i)strcat(buffer,TextFormatUpToFourIndexedStringFragments_UnknownRoleInitializedBytes_Variant2);strcat(buffer,TextFormatUpToFourIndexedStringFragments_UnknownRoleInitializedBytes[*values++]);}sprintf(output,Text_FormatUpToFourIndexedStringFragments_FormatS,buffer);}
