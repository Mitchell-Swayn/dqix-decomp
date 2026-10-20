#include <globaldefs.h>
ARM
extern "C" int strncmp(const char*,const char*,unsigned);
// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022135F4; symbol: func_ov031_022135f4; size: 0xA0.
extern "C" int Util_TestSelectedStringAgainstEligibleRecords(){
 char* records;unsigned char i;unsigned char selected;
 unsigned char* p=NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[4];
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
