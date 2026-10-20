#include <globaldefs.h>
ARM
typedef void (*Callback)(void*,void*);
// Original: arm9/main @ 0x02097000; symbol: func_02097000; size: 0x54.
extern "C" int BestiaryInfo_ForEachRecord(char* p,Callback cb){unsigned short count;char* list=*(char**)(p+8);if(!list||!(count=*(unsigned short*)p)||!cb)return 0;int i=0;while(i<count){cb(p,list);++i;list+=48;}return 1;}
