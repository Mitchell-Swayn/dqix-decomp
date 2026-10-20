#include <globaldefs.h>
extern "C" {
    int Grid_ComputeSelectedLinearIndex(void *);
    void Grid_SelectIndexAndComputePageCoordinates(void *,int);
// Original: arm9/main @ 0x0205BACC; symbol: func_0205bacc; size: 0x30.
    void Grid_SetEntryCountAndClampSelection(int *p,int value){
        if(value<0)return;
        *p=value;
        if(Grid_ComputeSelectedLinearIndex(p)<value)return;
        Grid_SelectIndexAndComputePageCoordinates(p,value-1);
    }
}
