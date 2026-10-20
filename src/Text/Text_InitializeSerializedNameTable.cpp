#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Header{unsigned data:31;unsigned ready:1;};struct Object{Header header;unsigned char*data;unsigned char*end;};extern "C" void* memcpy(void*,const void*,unsigned);extern "C" int Text_GetNameTableEntryDataSize(Object*);extern "C" void Text_VisitNameTableEntries(Object*,int);
// Original: arm9/main @ 0x020E53BC; symbol: func_020e53bc; size: 0x90.
extern "C" int Text_InitializeSerializedNameTable(Object*p,Header*source,unsigned char*ready,int mode){*ready=0;if(!source)return 0;memcpy(p,source,4);p->data=(unsigned char*)(source+1);p->end=(unsigned char*)source+(Text_GetNameTableEntryDataSize(p)+4);if(p->header.ready){*ready=1;return 1;}Text_VisitNameTableEntries(p,mode);p->header.ready=1;source->ready=1;return 1;}
