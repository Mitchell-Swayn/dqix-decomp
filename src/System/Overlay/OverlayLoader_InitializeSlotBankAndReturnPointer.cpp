#include <globaldefs.h>
extern "C" {
void OverlayLoader_ClearSixSlotEntries(void *);
// Original: arm9/main @ 0x020A1FFC; symbol: func_020a1ffc; size: 0x14.
void *OverlayLoader_InitializeSlotBankAndReturnPointer(void *p){OverlayLoader_ClearSixSlotEntries(p);return p;}
}
