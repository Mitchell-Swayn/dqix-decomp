#include "MenuText.h"

extern "C" Ov013DisplayEntry* func_ov013_02184338(Ov013Display* display, unsigned short index)
{
    Ov013DisplayEntry* entry = 0;
    if (display->entries != 0 && index < display->entryCount)
        entry = &display->entries[index];
    return entry;
}
