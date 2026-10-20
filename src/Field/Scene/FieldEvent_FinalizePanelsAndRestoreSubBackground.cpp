#include <globaldefs.h>
extern "C" void StaffRoll_UploadTilesAndApplyScroll(void *);
extern "C" void QuestMessagePanel_FinalizePresentation(void *);
extern "C" int _Z13IsSceneLoadedj(unsigned);
extern "C" void Graphics_PrepareSubBackgroundAtBrightnessLimit();
// Original: arm9/ov017 @ 0x021BB8F0; symbol: func_ov017_021bb8f0; size: 0x40.
extern "C" void FieldEvent_FinalizePanelsAndRestoreSubBackground(void *state) {
    if (*(void **)((char *)state + 0x160)) StaffRoll_UploadTilesAndApplyScroll(*(void **)((char *)state + 0x160));
    if (*(void **)((char *)state + 0x120)) QuestMessagePanel_FinalizePresentation(*(void **)((char *)state + 0x120));
    if (_Z13IsSceneLoadedj(1)) Graphics_PrepareSubBackgroundAtBrightnessLimit();
}
