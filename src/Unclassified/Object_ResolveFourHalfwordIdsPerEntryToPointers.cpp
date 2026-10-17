#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
char *GetFortyEightByteRecordByBoundedIndex(void *,int);void *FindNonnegativeKeyInEntryArray(void *,int);
// Original: arm9/main @ 0x0207F72C; symbol: func_0207f72c; size: 0x80.
void Object_ResolveFourHalfwordIdsPerEntryToPointers(char *p){short count=*(short *)(p+4);for(short i=0;i<count;i++){char *q=GetFortyEightByteRecordByBoundedIndex(p,i);if(q){*(void **)(q+24)=FindNonnegativeKeyInEntryArray(p,*(short *)(q+24));*(void **)(q+28)=FindNonnegativeKeyInEntryArray(p,*(short *)(q+28));*(void **)(q+32)=FindNonnegativeKeyInEntryArray(p,*(short *)(q+32));*(void **)(q+36)=FindNonnegativeKeyInEntryArray(p,*(short *)(q+36));}}}
}
