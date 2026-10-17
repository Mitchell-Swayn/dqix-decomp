#include <globaldefs.h>
ARM
struct Table{int pad;short* ids;unsigned char pad8[12];unsigned char count;};extern "C" {void func_0204f3bc(void*,int);
// Original: arm9/main @ 0x02081530; symbol: func_02081530; size: 0x44.
void ProcessEachTableIdentifier(void* unused,void* p,Table* table){if(!table)return;for(unsigned char i=0;i<table->count;i++)func_0204f3bc(p,table->ids[i]);}}
