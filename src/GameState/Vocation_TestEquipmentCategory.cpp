#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x20ee700; symbol: data_020ee700.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000102030405060708090a0b0c0d0e00.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
unsigned int Vocation_GetSkillLineId(void *,int);extern unsigned char VocationTestEquipmentCategory_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020DD19C; symbol: func_020dd19c; size: 0x64.
bool Vocation_TestEquipmentCategory(void *p,int v){bool result=false;for(unsigned char i=0;i<4;i++){unsigned int n=Vocation_GetSkillLineId(p,i);if(n&&n<=14&&VocationTestEquipmentCategory_UnknownRoleInitializedBytes[n]==v){result=true;break;}}return result;}
}
