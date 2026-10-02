#include "CountMenu.h"

// Populate the count display for the selected secondary key.
extern "C" int func_ov004_02154618(CountMenuContext* menu)
{
    short category, primaryKey, secondaryKey;
    unsigned char availableCount, totalCount;
    func_ov004_02153978(menu, &category, &primaryKey, &secondaryKey);
    unsigned short label = (unsigned short)((unsigned short)secondaryKey + 25);
    func_ov023_021f645c(menu, 39, 4, 15);
    func_ov023_021f645c(menu, 40, label, 15);
    func_ov004_021546c0(data_ov004_021707c0, primaryKey, secondaryKey,
                       &availableCount, &totalCount);
    func_ov023_021f64a8(menu, 56, totalCount, 15);
    func_ov004_021536e0(menu, 56, 25);
    return 0;
}
