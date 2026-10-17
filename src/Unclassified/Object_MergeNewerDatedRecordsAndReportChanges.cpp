#include <globaldefs.h>
#pragma always_inline on
#include <std_library_functions.h>
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
struct Record {unsigned char year,month,day;unsigned char a[4];unsigned short b[4];unsigned char c[4];unsigned short d[4];};
// Original: arm9/main @ 0x0206E558; symbol: func_0206e558; size: 0x1B4.
extern "C" int Object_MergeNewerDatedRecordsAndReportChanges(char *state){int changed=0;if(*(int*)(state+0x404)||*(int*)(state+0x408)){
for(int i=0;i<5;i++){Record *old=(Record*)(state+i*28);Record *next=(Record*)(state+0x334+i*28);
unsigned dateOld=old->year*10000+(short)old->month*100+old->day;unsigned dateNext=next->year*10000+(short)next->month*100+next->day;
if(dateOld<=dateNext){if(!changed&&RuntimeMemory_CompareByteRanges(old,next,28))changed=1;*old=*next;}}
if(!changed&&RuntimeMemory_CompareByteRanges(state+0x8c,state+0x3c0,0x42))changed=*(int*)(state+0x404);memcpy(state+0x8c,state+0x3c0,0x42);
if(!changed&&RuntimeMemory_CompareByteRanges(state+0x323,state+0x40c,15))changed=1;memcpy(state+0x323,state+0x40c,15);*(int*)(state+0x404)=0;*(int*)(state+0x408)=0;}return changed;}
