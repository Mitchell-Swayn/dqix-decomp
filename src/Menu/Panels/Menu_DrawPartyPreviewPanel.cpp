#include <globaldefs.h>
extern "C" void Menu_DrawPartyPreviewSummary(void*);
extern "C" void Graphics_SubmitTwoMappedCursorPositions(void*);
extern "C" void Menu_DrawPartyPreviewMemberSwitchButton(void*);
extern "C" void Menu_DrawPartyPreviewCloseButton(void*);
extern "C" void EquipmentMenu_DrawController(void*);
// Original: arm9/ov023 @ 0x021E3134; symbol: func_ov023_021e3134; size: 0x50.
extern "C" void Menu_DrawPartyPreviewPanel(void* object) {
    signed char state = *(signed char*)((char*)object + 0x4e6);
    if (state == 0) return;
    if (state == -1) return;
    Menu_DrawPartyPreviewSummary(object);
    Graphics_SubmitTwoMappedCursorPositions(object);
    Menu_DrawPartyPreviewMemberSwitchButton(object);
    Menu_DrawPartyPreviewCloseButton(object);
    void* resource = *(void**)object;
    if (resource) EquipmentMenu_DrawController(resource);
}
