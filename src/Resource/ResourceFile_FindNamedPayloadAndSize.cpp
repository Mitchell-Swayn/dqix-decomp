#include <globaldefs.h>
ARM
extern "C" unsigned char* ResourceFile_FindEntryByBasename(void*,const char*);
// Original: arm9/main @ 0x020467C0; symbol: func_020467c0; size: 0x30.
extern "C" void* ResourceFile_FindNamedPayloadAndSize(void* p,const char* name,unsigned* size){unsigned char* f=ResourceFile_FindEntryByBasename(p,name);if(!f)return 0;if(size)*size=*(unsigned*)(f+68);return f+*(unsigned*)(f+64);}
