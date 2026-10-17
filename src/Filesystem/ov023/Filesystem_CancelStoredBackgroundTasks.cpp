#include <globaldefs.h>
ARM
extern "C" void RemoveNonnegativeStoredBackgroundTask(int* task);
// Original: arm9/ov023 @ 0x021DCA88; symbol: func_ov023_021dca88; size: 0x58.
extern "C" void Filesystem_CancelStoredBackgroundTasks(char* loader) {
    if ((unsigned char)loader[0x776] == 2)
        return;
    RemoveNonnegativeStoredBackgroundTask((int*)(loader + 0x734));
    for (int i = 0; i < 7; i++)
        RemoveNonnegativeStoredBackgroundTask((int*)(loader + 0x738 + i * 4));
    loader[0x776] = 2;
    loader[0x777] = 0;
}
