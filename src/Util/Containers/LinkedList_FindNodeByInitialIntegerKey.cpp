#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02057F8C; symbol: func_02057f8c; size: 0x28.
extern "C" unsigned char* LinkedList_FindNodeByInitialIntegerKey(unsigned char** list,int key) { unsigned char* p=*list; while (p) { if (key==*(int*)p) return p; p=*(unsigned char**)(p+0x1ec); } return 0; }
