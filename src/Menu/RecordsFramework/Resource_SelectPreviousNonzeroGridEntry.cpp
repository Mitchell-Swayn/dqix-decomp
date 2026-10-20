#include <globaldefs.h>
ARM
extern "C" void Math_StoreSignedQuotientAndRemainder(void*,unsigned short);
extern "C" void MenuSelectionGrid_RefreshCursorAndSelectionCallback(void*,void*);
// Original: arm9/ov023 @ 0x021F9D14; symbol: Resource_SelectPreviousNonzeroGridEntry; size: 0x8c.
// Scans grid backward from current row/column until nonzero entry or origin and updates selection.
extern "C" void Resource_SelectPreviousNonzeroGridEntry(char* self,void* context) {
 int column=*(volatile unsigned short*)(self+0x2a),row=*(volatile unsigned short*)(self+0x28),width=*(volatile unsigned short*)(self+0x26);
 int index=row*width+column;
 while(!(*(volatile unsigned short**)(self+0x20))[index]) {
 if(column==0){if(row==0)break;column=width-1;--row;}else if(column>0)--column;
 index=row*width+column;
 }
 if(!(*(volatile unsigned short**)(self+0x20))[index])index=0;
 Math_StoreSignedQuotientAndRemainder(self,(unsigned short)index);MenuSelectionGrid_RefreshCursorAndSelectionCallback(self,context);
}
