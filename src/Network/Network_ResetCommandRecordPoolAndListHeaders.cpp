#include <globaldefs.h>
extern "C" {
    void LinkedQueue_InitializeWrapper(void *);
    void ClearThreeWordsIndirect(void *);
// Original: arm9/main @ 0x0202C814; symbol: func_0202c814; size: 0x34.
    void *Network_ResetCommandRecordPoolAndListHeaders(unsigned char *p){
        LinkedQueue_InitializeWrapper(p);
        ClearThreeWordsIndirect(p+5400);
        ClearThreeWordsIndirect(p+5388);
        ClearThreeWordsIndirect(p+5376);
        return p;
    }
}
