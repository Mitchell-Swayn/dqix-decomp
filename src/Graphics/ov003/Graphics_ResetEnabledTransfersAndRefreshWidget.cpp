#include <globaldefs.h>
ARM
extern "C" { void Graphics_ResetCountedTransferEntriesWithModeZero(void*); void Window_SetWidgetPositionAndToggleTwoOptions(void*); unsigned ReadBit(void*); void RegisterBit_UpdateSelectedBankWhenValueChanges(void*,unsigned); void WriteWordPairAtOffsets4And8(void*,unsigned,unsigned); void func_ov003_0216720c(void*); void ResetCountedTransferEntriesIfEnabledAndPresent(void*); }
// Original: arm9/ov003 @ 0x02160240; symbol: func_ov003_02160240; size: 0x7C.
extern "C" void Graphics_ResetEnabledTransfersAndRefreshWidget(unsigned char* object) {
 if(!object[0x4a3]) return;
 if(*(void**)(object+0x324)) Graphics_ResetCountedTransferEntriesWithModeZero(*(void**)(object+0x324));
 func_ov003_0216720c(object);
 if(*(void**)(object+0x318)) ResetCountedTransferEntriesIfEnabledAndPresent(*(void**)(object+0x318));
 if(*(void**)(object+0x390)) {
  unsigned char* widget=*(unsigned char**)(*(unsigned char**)(object+0x390)+0x10);
  WriteWordPairAtOffsets4And8(widget+0x28,25,1);
  RegisterBit_UpdateSelectedBankWhenValueChanges(widget+0x28,ReadBit(*(void**)(object+0x390)));
  Window_SetWidgetPositionAndToggleTwoOptions(*(void**)(object+0x390));
 }
}
