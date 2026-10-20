#include <globaldefs.h>
ARM
extern "C" void Menu_GetCatalogueCategoryFilters(void*,short*,short*,short*);
extern "C" void MotionRecord_SetSelectionParameterAndRefreshByKey(void*,unsigned short,unsigned short,unsigned);
// Original data: arm9/ov004 @ 0x21707c0; symbol: data_ov004_021707c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void* SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;
extern "C" void Menu_GetCategoryCompletionCounts(void*,int,int,unsigned char*,unsigned char*);
extern "C" void NumericRecord_SetValueAndDisplayModeByKey(void*,unsigned short,void*,void*);
extern "C" void Menu_CopyPositionUnlessSourceDescriptorIsActive(void*,int,int);
// Original: arm9/ov004 @ 0x02154748; symbol: Resource_ConfigureType37RecordKeysAndVirtualValue; size: 0xb4.
// Configures keys39/40/56 from signed record values and resolves type15 value before virtual copy.
extern "C" int Menu_DisplayCatalogueKindCompletion(void* self) {
 short a,b,c;unsigned char first,second;Menu_GetCatalogueCategoryFilters(self,&a,&b,&c);unsigned short key=(unsigned short)((unsigned short)(b-1)+37);
 MotionRecord_SetSelectionParameterAndRefreshByKey(self,39,5,15);MotionRecord_SetSelectionParameterAndRefreshByKey(self,40,key,15);Menu_GetCategoryCompletionCounts(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage,b,-1,&first,&second);
 NumericRecord_SetValueAndDisplayModeByKey(self,56,(void*)second,(void*)15);Menu_CopyPositionUnlessSourceDescriptorIsActive(self,56,25);return 0;
}
