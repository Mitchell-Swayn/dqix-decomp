#include <globaldefs.h>
ARM
extern "C" char data_ov031_02290c8c[];
extern "C" unsigned char data_ov031_02248eac[],data_ov031_02248eb0[];
extern "C" void* Resource_ExpandPackedTableToAllocatedBuffer(unsigned,unsigned);
extern "C" void ExpandPackedSixByteEntriesToEight(unsigned,unsigned,void*);
// Original: arm9/ov031 @ 0x0222B918; symbol: func_ov031_0222b918; size: 0x174.
extern "C" void Graphics_InitializePairedSpriteEntryArrays() {
 int count=*(unsigned char*)(*(char**)(data_ov031_02290c8c+4)+0x51);
 if(count>5)count=5;
 int i=0;
 if(count>0)do {
  *(void**)(*(char**)(data_ov031_02290c8c+4)+0x10+i*4)=Resource_ExpandPackedTableToAllocatedBuffer(0,0x2e);
  *(void**)(*(char**)(data_ov031_02290c8c+4)+0x24+i*4)=Resource_ExpandPackedTableToAllocatedBuffer(0,0x18);
  i++;
 } while(i<count);
 {unsigned table=0;unsigned char* pattern=data_ov031_02248eac;unsigned i=0;
 do {
  ExpandPackedSixByteEntriesToEight(table,*pattern,*(void**)(*(char**)(data_ov031_02290c8c+4)+0x10));
  char* state=*(char**)(data_ov031_02290c8c+4);
  *(unsigned short*)(state+0x42+i*2)=*(unsigned short*)(*(char**)(state+0x10)+4)&0x3ff;
 pattern++;i++;
 } while(i<3); }
 {unsigned table=0;unsigned char* pattern=data_ov031_02248eb0;unsigned i=0;
 do {
  ExpandPackedSixByteEntriesToEight(table,*pattern,*(void**)(*(char**)(data_ov031_02290c8c+4)+0x24));
  char* state=*(char**)(data_ov031_02290c8c+4);
  *(unsigned short*)(state+0x48+i*2)=*(unsigned short*)(*(char**)(state+0x24)+4)&0x3ff;
 pattern++;i++;
 } while(i<4); }
 int j=0;
 if(count<=0)return;
 do {
  unsigned short* first=*(unsigned short**)(*(char**)(data_ov031_02290c8c+4)+0x10+j*4);
  first[2]=(first[2]&~0xc00)|0xc00;
  unsigned short* second=*(unsigned short**)(*(char**)(data_ov031_02290c8c+4)+0x24+j*4);
  second[2]=(second[2]&~0xc00)|0xc00;
 j++;
 } while(j<count);
}
