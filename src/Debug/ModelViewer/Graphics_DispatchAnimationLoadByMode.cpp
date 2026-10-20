#include <globaldefs.h>
ARM
extern "C" void CharacterViewer_ReloadPlayerAnimationArchives(void* owner, int fileId);
extern "C" void Graphics_LoadAnimationArchiveById(void* owner, int fileId);
// Original: arm9/ov015 @ 0x0218F308; symbol: func_ov015_0218f308; size: 0x3C.
// Dispatches animation loading by the owner mode byte, forwarding the selected file identifier.
extern "C" void Graphics_DispatchAnimationLoadByMode(void* owner, int fileId) {
    unsigned char mode = *((unsigned char*)owner + 0x1c);
    if (mode == 0) goto loadPackages;
    if (mode == 2) goto loadArchiveForMode2;
    if (mode == 3) goto loadArchiveForMode3;
    return;
loadPackages:
    CharacterViewer_ReloadPlayerAnimationArchives(owner, fileId);
    return;
loadArchiveForMode2:
    Graphics_LoadAnimationArchiveById(owner, fileId);
    return;
loadArchiveForMode3:
    Graphics_LoadAnimationArchiveById(owner, fileId);
}
