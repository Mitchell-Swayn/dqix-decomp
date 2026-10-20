#include <globaldefs.h>
ARM
// Original data: arm9/ov006 @ 0x2160030; symbol: data_ov006_02160030.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000100000004000000020000000500000003000000060000000700000008000000.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern "C" int KrakPotRefreshSelectedIngredientPreview_UnknownRoleInitializedBytes[9];
extern "C" short* KrakPot_GetSelectedCategoryItemIds(void*);
extern "C" void KrakPot_RequestIngredientPreview(int,int,int);
// Original: arm9/ov006 @ 0x0215F740; symbol: UpdateMappedHalfwordWithClampedRowParameter; size: 0xa8.
extern "C" void KrakPot_RefreshSelectedIngredientPreview(char* self) {
 short* values=KrakPot_GetSelectedCategoryItemIds(self);if(!values)return;
 unsigned short index=(unsigned short)(*(unsigned char*)(self+0x388)<<3)+(*(short*)(self+0x364)-100);
 struct Table{int values[9];};Table local=*(Table*)KrakPotRefreshSelectedIngredientPreview_UnknownRoleInitializedBytes;
 short row=*(short*)(self+0x362)-91;int clamped=row;if(clamped<0)clamped=0;if(clamped>8)clamped=8;KrakPot_RequestIngredientPreview(*(int*)(self+16),values[index],(signed char)local.values[clamped]);
}
