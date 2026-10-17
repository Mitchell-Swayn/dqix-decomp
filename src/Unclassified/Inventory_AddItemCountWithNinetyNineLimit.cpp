#include <globaldefs.h>
struct Inventory {short* ids;signed char* counts;short capacity;};extern "C" int FindNonnegativeHalfwordKeyIndex(Inventory*,int);
// Original: arm9/main @ 0x020A095C; symbol: func_020a095c; size: 0xAC.
extern "C" int Inventory_AddItemCountWithNinetyNineLimit(Inventory* self,int id,int count) {short* ids=self->ids;signed char* counts=self->counts;short capacity=self->capacity;if(id<0)return 0;if(count<=0)return 0;int result=0;int index=FindNonnegativeHalfwordKeyIndex(self,id);if(index>=0) {result=1;if(counts[index]<99) {signed char available=99-counts[index];if(available<count)count=available;counts[index]+=count;}}else for(short i=0;i<capacity;++i)if(ids[i]<0) {ids[i]=id;counts[i]=count;result=1;break;}return result;}
