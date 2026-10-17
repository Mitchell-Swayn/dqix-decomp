#include <globaldefs.h>

extern "C" void* ReadGlobalAt020FDD44(); extern "C" char* GetBoundedEntryAtStride318(void*,int);
// Original: arm9/main @ 0x02090294; symbol: func_02090294; size: 0xA8.
extern "C" ARM int Object_SelectUnusedByteOrdinalAmongFourRecords(char* p) { void* table=ReadGlobalAt020FDD44(); for(;;) { if(p[0x276]>4)p[0x276]=0; int i; for(i=0;i<4;i++) { char* entry=GetBoundedEntryAtStride318(table,i); if(entry && entry[13]==p[0x276]) { ++p[0x276]; goto retry; } } break; retry:; } for(int j=0;j<4;j++)GetBoundedEntryAtStride318(table,j); char* end=p+0x200; char next=end[0x76]; p[0x276]=next+1; return next; }
