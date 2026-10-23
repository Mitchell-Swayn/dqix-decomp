#include <globaldefs.h>
ARM
extern "C" void *QuestMenu_FindMessagePanelById(void *, unsigned short);
extern "C" void BackgroundLoader_UpdateIdentifierAndCancelPreviousTask(char *, int, unsigned char);
// Original: arm9/ov004 @ 0x02167648; symbol: Resource_CancelBackgroundTaskForEntry7; size: 0x30.
// Looks up entry 7 and cancels its background task using the task identifier at entry+0x34.
extern "C" int Resource_CancelBackgroundTaskForEntry7(void *self) {
    void *value = QuestMenu_FindMessagePanelById(self, 7);
    if (value) BackgroundLoader_UpdateIdentifierAndCancelPreviousTask((char *)value + 0x34, 0x270f, 0);
    return 0;
}
