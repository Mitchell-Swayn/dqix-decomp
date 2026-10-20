#include <globaldefs.h>
ARM
extern "C" void Ov031_SetCurrentObject(unsigned int);
extern "C" unsigned int SetCurrentObjectFromCategory_PathHttpsNasTestNintendowifiNetAc[];
extern "C" unsigned int SetCurrentObjectFromCategory_PathHttpsNasDevNintendowifiNetAc[];
extern "C" unsigned int SetCurrentObjectFromCategory_PathHttpsNasNintendowifiNetAc[];
// Original: arm9/ov031 @ 0x02211C50; symbol: func_ov031_02211c50; size: 0x50.
extern "C" void SetCurrentObjectFromCategory(int category) {
    switch (category) {
    case 0: Ov031_SetCurrentObject((unsigned)SetCurrentObjectFromCategory_PathHttpsNasTestNintendowifiNetAc); break;
    case 1: Ov031_SetCurrentObject((unsigned)SetCurrentObjectFromCategory_PathHttpsNasDevNintendowifiNetAc); break;
    case 2: Ov031_SetCurrentObject((unsigned)SetCurrentObjectFromCategory_PathHttpsNasNintendowifiNetAc); break;
    }
}
