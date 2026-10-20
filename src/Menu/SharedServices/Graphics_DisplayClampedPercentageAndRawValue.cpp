#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707c4; symbol: data_ov004_021707c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" { extern unsigned char* MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage; void NumericRecord_SetValueAndDisplayModeByKey(void*,int,int,int); void MenuTextCanvas_RedrawByKey(void*,int); }
// Original: arm9/ov004 @ 0x0215571C; symbol: func_ov004_0215571c; size: 0x90.
extern "C" int Graphics_DisplayClampedPercentageAndRawValue(void* output) {
 short current=*(short*)(MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage+14);
 short maximum=*(short*)(MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage+12);
 short percent=current*100/maximum;
 if(percent==0 && current==0) percent=0;
 if(percent==0 && current!=0) percent=1;
 if(percent>100) percent=100;
 if(percent<0) percent=0;
 NumericRecord_SetValueAndDisplayModeByKey(output,19,percent,15);
 NumericRecord_SetValueAndDisplayModeByKey(output,20,current,15);
 MenuTextCanvas_RedrawByKey(output,16);
 return 0;
}
