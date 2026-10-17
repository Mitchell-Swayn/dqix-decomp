#include <globaldefs.h>
ARM
extern "C" void Ov031_SetCurrentObject(unsigned int);
extern "C" unsigned int data_ov031_02249a14[];
extern "C" unsigned int data_ov031_02249a3c[];
extern "C" unsigned int data_ov031_02249a60[];
// Original: arm9/ov031 @ 0x02211C50; symbol: func_ov031_02211c50; size: 0x50.
extern "C" void SetCurrentObjectFromCategory(int category) {
    switch (category) {
    case 0: Ov031_SetCurrentObject((unsigned)data_ov031_02249a14); break;
    case 1: Ov031_SetCurrentObject((unsigned)data_ov031_02249a3c); break;
    case 2: Ov031_SetCurrentObject((unsigned)data_ov031_02249a60); break;
    }
}
