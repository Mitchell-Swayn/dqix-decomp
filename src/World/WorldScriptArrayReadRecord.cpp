#include "World/WorldScriptArrayList.h"
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" char data_020f1244[4];
extern "C" int func_020d2ff0(const char*);

extern "C" int func_0208d594(Script::Parameter* parameters, int)
{
    unsigned short mask = data_02108fc0.list->stringMask;
    WorldScriptArrayEntry entry;
    func_0208d51c(&entry);
    entry.key = (parameters++)->ToInt();
    {
        int found;
        const short* keys;
        int filterCount;
        short index;
        filterCount = data_02108fc0.list->capacityOverride;
        if (filterCount)
        {
            found = 0;
            index = 0;
            keys = data_02108fc0.list->keyFilter;
            for (; index < filterCount; ++keys, ++index)
            {
                short key = *keys;
                if (entry.key == key) found = 1;
            }
            if (!found) return 1;
        }
    }
    const char* text = (parameters++)->ToString();
    if (mask & 1)
    {
        int length = func_020d2ff0(text);
        if (length)
        {
            entry.unknown4 = (char*)data_02108fc0.allocator->Allocate(length + 1);
            entry.unknown4[length] = 0;
            sprintf(entry.unknown4, data_020f1244, text);
        }
    }
    text = (parameters++)->ToString();
    if (mask & 2)
    {
        int length = func_020d2ff0(text);
        if (length)
        {
            entry.unknown8 = (char*)data_02108fc0.allocator->Allocate(length + 1);
            entry.unknown8[length] = 0;
            sprintf(entry.unknown8, data_020f1244, text);
        }
    }
    if (mask & 0x3fc)
    {
        entry.values = (WorldScriptArrayValues*)data_02108fc0.allocator->Allocate(sizeof(WorldScriptArrayValues));
        for (unsigned char i = 0; i < 8; ++i) entry.values->values[i] = 0;
    }
    int bit = 4;
    unsigned char index = 0;
    for (; index < 8; bit <<= 1, ++index)
    {
        text = (parameters++)->ToString();
        if (mask & bit)
        {
            int length = func_020d2ff0(text);
            if (length)
            {
                entry.values->values[index] = (char*)data_02108fc0.allocator->Allocate(length + 1);
                char* destination = entry.values->values[index];
                destination[length] = 0;
                sprintf(destination, data_020f1244, text);
            }
        }
    }
    text = (parameters++)->ToString();
    if (mask & 0x400)
    {
        int length = func_020d2ff0(text);
        if (length)
        {
            entry.unknown10 = (char*)data_02108fc0.allocator->Allocate(length + 1);
            entry.unknown10[length] = 0;
            sprintf(entry.unknown10, data_020f1244, text);
        }
    }
    text = parameters->ToString();
    if (mask & 0x800)
    {
        int length = func_020d2ff0(text);
        if (length)
        {
            entry.unknown14 = (char*)data_02108fc0.allocator->Allocate(length + 1);
            entry.unknown14[length] = 0;
            sprintf(entry.unknown14, data_020f1244, text);
        }
    }
    func_0208d928(data_02108fc0.list, &entry);
    return 1;
}
