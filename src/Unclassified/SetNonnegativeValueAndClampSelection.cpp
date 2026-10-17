#include <globaldefs.h>
extern "C" {
    int Grid_ComputeSelectedLinearIndex(void *);
    void ComputePageRowAndColumn(void *,int);
// Original: arm9/main @ 0x0205BACC; symbol: func_0205bacc; size: 0x30.
    void SetNonnegativeValueAndClampSelection(int *p,int value){
        if(value<0)return;
        *p=value;
        if(Grid_ComputeSelectedLinearIndex(p)<value)return;
        ComputePageRowAndColumn(p,value-1);
    }
}
