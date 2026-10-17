#include <globaldefs.h>
ARM
extern "C" int strncmp(const char*,const char*,unsigned);
extern "C" unsigned char* data_ov031_0224e5c4[];
// Original: arm9/ov031 @ 0x022135F4; symbol: func_ov031_022135f4; size: 0xA0.
extern "C" int Util_TestSelectedStringAgainstEligibleRecords(){
 char* records;unsigned char i;unsigned char selected;
 unsigned char* p=data_ov031_0224e5c4[4];
 selected=p[0xd13];
 records=(char*)p+0x474;
 int offset=(short)192*(short)selected;
 if(p[0xd0d]>=6)return 1;
 unsigned char count=p[0xd12];
 for(i=0;i<count;i++){
 if(i==selected)continue;
 if(*(unsigned char*)(p+i*4+0x445)>=6)continue;
 int other=i*192;
 if(!strncmp(records+offset,records+other,*(unsigned short*)(p+other+0x47a)))return 2;
 }
 return 1;
}
