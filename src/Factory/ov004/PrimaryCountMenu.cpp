#include "CountMenu.h"

#pragma dont_inline on
extern "C" int func_ov004_02154718(CountMenuContext* menu)
{
    func_ov004_02154618(menu);
    CountMenuEntry* entry = func_ov004_02153944(menu, 55);
    if (entry)
        func_ov023_021f809c(entry, menu);
    return 0;
}

extern "C" int func_ov004_02154748(CountMenuContext* menu)
{
    short category, primaryKey, secondaryKey;
    unsigned char availableCount, totalCount;
    func_ov004_02153978(menu, &category, &primaryKey, &secondaryKey);
    unsigned short label = (unsigned short)((unsigned short)(primaryKey - 1) + 37);
    func_ov023_021f645c(menu, 39, 5, 15);
    func_ov023_021f645c(menu, 40, label, 15);
    func_ov004_021546c0(data_ov004_021707c0, primaryKey, -1,
                       &availableCount, &totalCount);
    func_ov023_021f64a8(menu, 56, totalCount, 15);
    func_ov004_021536e0(menu, 56, 25);
    return 0;
}

extern "C" int func_ov004_021547fc(CountMenuContext* menu)
{
    func_ov004_02154748(menu);
    CountMenuEntry* entry = func_ov004_02153944(menu, 55);
    if (entry)
        func_ov023_021f809c(entry, menu);
    return 0;
}
