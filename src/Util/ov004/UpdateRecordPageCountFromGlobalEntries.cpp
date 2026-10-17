#include <globaldefs.h>
ARM
struct State;
extern "C" {extern unsigned char* data_ov004_02171010;void* func_ov011_021849c8(State*);void* func_ov023_021f6880(void**,unsigned short);unsigned OV023_ReadHalfwordField04(void*);}
// Original: arm9/ov004 @ 0x02163530; symbol: func_ov004_02163530; size: 0xA0.
extern "C" void UpdateRecordPageCountFromGlobalEntries(State* owner){
*(short*)(data_ov004_02171010+0x18f8)=1;
while((*(short*)(data_ov004_02171010+0x18f8)<<3) < data_ov004_02171010[0x18f4])++*(short*)(data_ov004_02171010+0x18f8);
char* record=(char*)func_ov023_021f6880((void**)func_ov011_021849c8(owner),10);
if(!record)return;
if(OV023_ReadHalfwordField04(record)!=7)return;
*(short*)(data_ov004_02171010+0x18f6)=*(short*)(record+0x5c);
short pages=*(short*)(data_ov004_02171010+0x18f8);
short current=*(short*)(data_ov004_02171010+0x18f6);
*(short*)(record+0x5c)=current;*(short*)(record+0x5e)=pages;
}
