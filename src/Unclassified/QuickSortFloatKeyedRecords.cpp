#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct Pair{unsigned data;float value;};
// Original: arm9/main @ 0x02056C3C; symbol: func_02056c3c; size: 0xD4.
extern "C" void QuickSortFloatKeyedRecords(unsigned context,Pair* array,int low,int high){int i=low,j=high;float pivot=array[i].value;for(;;){while(array[i].value<pivot)++i;while(array[j].value>pivot)--j;if(i>=j)break;float value=array[i].value;unsigned data=array[i].data;array[i].value=array[j].value;array[i].data=array[j].data;array[j].value=value;array[j].data=data;++i;--j;}if(low<i-1)QuickSortFloatKeyedRecords(context,array,low,i-1);if(j+1<high)QuickSortFloatKeyedRecords(context,array,j+1,high);}
