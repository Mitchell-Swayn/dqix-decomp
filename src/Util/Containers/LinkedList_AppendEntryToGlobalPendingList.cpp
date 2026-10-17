#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* data_02111800;extern "C" void AppendSinglyLinkedNode(void**,void*);
// Original: arm9/main @ 0x020CEF4C; symbol: func_020cef4c; size: 0x18.
extern "C" void LinkedList_AppendEntryToGlobalPendingList(void* entry){AppendSinglyLinkedNode(&data_02111800,entry);}
