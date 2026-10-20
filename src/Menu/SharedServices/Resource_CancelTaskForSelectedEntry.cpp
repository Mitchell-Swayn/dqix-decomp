#include <globaldefs.h>
ARM
extern "C" int Resource_ReadIndexedNodeAndFlag(int, unsigned char*);
extern "C" void* QuestMenu_FindMessagePanelById(void*, int);
extern "C" void BackgroundLoader_CancelTaskAndSelectNewHalfwordId(char*, int, unsigned char);
// Original: arm9/ov004 @ 0x02166FA0; symbol: Resource_CancelTaskForSelectedEntry; size: 0x44.
// Reads the selected node ID and status, then cancels the task for entry 7 when that entry exists.
extern "C" int Resource_CancelTaskForSelectedEntry(void* input) {
    unsigned char flag;
    int id = Resource_ReadIndexedNodeAndFlag((int)input, (unsigned char*)&flag);
    unsigned char savedFlag = flag;
    void* owner = QuestMenu_FindMessagePanelById(input, 7);
    if (owner != 0)
        BackgroundLoader_CancelTaskAndSelectNewHalfwordId((char*)owner + 0x34, id, savedFlag);
    return 0;
}
