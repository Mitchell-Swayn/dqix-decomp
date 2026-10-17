#include <globaldefs.h>
extern "C" void Resource_CopySelectedRecordsWithOwnedStrings(void*,void*,const void*,unsigned,const short*,int,void*,void*);
// Original: arm9/main @ 0x0206F200; symbol: func_0206f200; size: 0x30.
extern "C" ARM void ProcessSingleHalfwordIDThroughArrayInterface(void* owner,void* allocator,const void* source,unsigned unused,short id){Resource_CopySelectedRecordsWithOwnedStrings(owner,allocator,source,unused,&id,1,0,0);}
