#pragma optimize_for_size off
extern "C" char* data_ov031_02290d2c[];
extern "C" void MIi_CpuClear32(unsigned,void*,unsigned);
extern "C" void MIi_CpuCopy16(const void*,void*,unsigned);
extern "C" void MIi_CpuCopy32(const void*,void*,unsigned);

// Original: arm9/ov031 @ 0x0223BDB0; symbol: func_ov031_0223bdb0; size: 0x94.
extern "C" void ExpandPackedSixByteEntriesToEight(unsigned table,unsigned index,void* output) {
char* base=data_ov031_02290d2c[table];
unsigned offset=*(unsigned*)(base+index*8+4);
unsigned short count=*(unsigned short*)(base+index*8);
char* out=(char*)output;
char* in=base+offset;
unsigned temp[2];
MIi_CpuClear32(0,temp,8);
int i=0;
if(i>=count)return;
do {
MIi_CpuCopy16(in,temp,6);
MIi_CpuCopy32(temp,out,8);
++i;
in+=6;
out+=8;

}
while(i<count);

}
