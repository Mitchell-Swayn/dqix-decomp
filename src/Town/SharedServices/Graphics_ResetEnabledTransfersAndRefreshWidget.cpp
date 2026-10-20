#include <globaldefs.h>
ARM
extern "C" { void Graphics_ResetCountedTransferEntriesWithModeZero(void*); void Window_SetWidgetPositionAndToggleTwoOptions(void*); unsigned Window_IsVisible(void*); void WindowControl_SetEnabled(void*,unsigned); void WindowControl_SetInsideMaskWithEffect(void*,unsigned,unsigned); void Graphics_ResetFlaggedObjectResource(void*); void ResetCountedTransferEntriesIfEnabledAndPresent(void*); }
// Original: arm9/ov003 @ 0x02160240; symbol: func_ov003_02160240; size: 0x7C.
extern "C" void Graphics_ResetEnabledTransfersAndRefreshWidget(unsigned char* object) {
 if(!object[0x4a3]) return;
 if(*(void**)(object+0x324)) Graphics_ResetCountedTransferEntriesWithModeZero(*(void**)(object+0x324));
 Graphics_ResetFlaggedObjectResource(object);
 if(*(void**)(object+0x318)) ResetCountedTransferEntriesIfEnabledAndPresent(*(void**)(object+0x318));
 if(*(void**)(object+0x390)) {
  unsigned char* widget=*(unsigned char**)(*(unsigned char**)(object+0x390)+0x10);
  WindowControl_SetInsideMaskWithEffect(widget+0x28,25,1);
  WindowControl_SetEnabled(widget+0x28,Window_IsVisible(*(void**)(object+0x390)));
  Window_SetWidgetPositionAndToggleTwoOptions(*(void**)(object+0x390));
 }
}
