#include <globaldefs.h>
ARM
extern "C" void QuestMenu_PopulateVisibleQuestRows(void);
extern "C" unsigned int Resource_ReadIndexedNodeAndFlag(void *, unsigned char *);
extern "C" void *QuestMenu_FindMessagePanelById(void *, unsigned int);
extern "C" void BackgroundLoader_UpdateIdentifierAndCancelPreviousTask(char *, int, unsigned char);
// Original: arm9/ov004 @ 0x021675FC; symbol: func_ov004_021675fc; size: 0x4C.
extern "C" int QuestMenu_RefreshRowsAndQueueSelectedPreview(void *owner) {
    unsigned char value;
    QuestMenu_PopulateVisibleQuestRows();
    unsigned int identifier = Resource_ReadIndexedNodeAndFlag(owner, &value);
    unsigned char savedValue = value;
    void *task = QuestMenu_FindMessagePanelById(owner, 7);
    if (task != 0) BackgroundLoader_UpdateIdentifierAndCancelPreviousTask((char *)task + 0x34, identifier, savedValue);
    return 0;
}
