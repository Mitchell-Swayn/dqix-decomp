#include <globaldefs.h>
extern "C" {
    void *ReadGlobalValueAt020FB3F0();
    void ShiftCurrentByteValueToPreviousAndRefresh(void *,int);
// Original: arm9/main @ 0x02076D34; symbol: func_02076d34; size: 0x28.
    bool ClearFieldB2AndSetObjectModeFive(unsigned char *p){
        ReadGlobalValueAt020FB3F0();
        *(short *)(p+178)=0;
        ShiftCurrentByteValueToPreviousAndRefresh(p,5);
        return true;
    }
}
