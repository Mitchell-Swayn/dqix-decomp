#include <globaldefs.h>
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void *memset(void *, int, unsigned);
extern "C" void Text_AppendSixAlternatingWidthAlignedLabels(void *, void *);
extern "C" int Window_ReplaceCanvasTextById(void *, unsigned, void *, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x02177A7C; symbol: func_ov000_02177a7c; size: 0x4C.
extern "C" void BattleMenu_RefreshTacticsPanelText(void *owner) {
    unsigned char *buffer = (unsigned char *)(*(unsigned *)(TextContext_GetSharedInstance() + 0x5c));
    memset(buffer, 0, 0x960);
    Text_AppendSixAlternatingWidthAlignedLabels(owner, buffer);
    Window_ReplaceCanvasTextById((char *)owner + 0x188, 4, buffer, 1, 0);
}
