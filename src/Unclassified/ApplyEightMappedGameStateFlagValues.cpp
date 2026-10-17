#include <globaldefs.h>
extern "C" {
    extern unsigned short data_020e9138[];
    unsigned char *ReadGlobalValueAt02108844();
    int ReadNonnegativeIndexedBit(void *,void *,unsigned short);
    void Zone3D_UpdateThreeIndexedInstancesInMatchingZone(unsigned char,unsigned char);
// Original: arm9/main @ 0x020AE9F0; symbol: func_020ae9f0; size: 0x50.
    void ApplyEightMappedGameStateFlagValues(){
        unsigned char *p=ReadGlobalValueAt02108844();
        for(int i=0;i<8;i++)Zone3D_UpdateThreeIndexedInstancesInMatchingZone(i,ReadNonnegativeIndexedBit(p,p+140,data_020e9138[i]));
    }
}
