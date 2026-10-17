#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02161318; symbol: func_ov000_02161318; size: 0x68.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM char* FindFourSlotRecordByIndex(char* p, int id)
{
    int valid=(id>=0 && id<=3) ? 1 : 0;
    if(valid)
    {
        for(int i=0;i<4;++i) if(*(int*)(p+0x9a4+i*0x448)==id) return p+0x958+i*0x448;
    }
    return 0;
}
