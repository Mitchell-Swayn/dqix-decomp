#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct CatchList { unsigned count; unsigned pad[2]; const unsigned char* entries; };
extern "C" int __throw_catch_compare(void*,unsigned,int*);
// Original: arm9/main @ 0x0200E984; symbol: func_0200e984; size: 0x84.
extern "C" int System_ExceptionMatchesCatchList(void* type,CatchList* list) {
 const unsigned char* p=list->entries;
 for(unsigned i=0;i<list->count;++i) {
  struct Locals { int adjustment; unsigned entry; } locals;
  locals.entry=p[0]|(p[1]<<8)|(p[2]<<16)|(p[3]<<24);
  if(__throw_catch_compare(type,locals.entry,&locals.adjustment)) return 1;
  p+=4;
 }
 return 0;
}
