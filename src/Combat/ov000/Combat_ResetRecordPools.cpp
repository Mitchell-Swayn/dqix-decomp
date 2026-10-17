#include <globaldefs.h>
ARM
extern "C" {void* memset(void*,int,unsigned);void func_ov000_02157d14(void*);void InitializeInvalidHalfwordRecord(void*);void InitializeInvalidIndexRecord(unsigned char*);}
// Original: arm9/ov000 @ 0x0215D090; symbol: func_ov000_0215d090; size: 0x384.
extern "C" void Combat_ResetRecordPools(unsigned char* p){
p[0x8e00]=0;
p[0x8e01]=0;
p[0x8e02]=0;
p[0x8e03]=0;
p[0x8e82]=0;
*(short*)(p+0x8e52)=0;*(short*)(p+0x8e50)=-1;p[0x8e83]=0;*(unsigned*)(p+0x8e58)=0;
p[0x8e0c]=0;
p[0x8e0d]=0;
p[0x8e0e]=0;
p[0x8e0b]=0;
p[0x8e08]=0;
p[0x8e09]=0;
p[0x8e0a]=0;
p[0x8e0f]=0;
p[0x8e11]=0;
p[0x8e12]=0;
p[0x8e10]=0;
p[0x8e13]=0;
p[0x8e96]=0;
*(unsigned*)(p+0x8e24)=0;*(short*)(p+0x8e6e)=0;
for(int i=0;i<72;i++)func_ov000_02157d14(p+0x20+i*52);
for(int i=0;i<136;i++)InitializeInvalidHalfwordRecord(p+0xec0+i*36);
for(int i=0;i<360;i++){memset(p+0x21e0+i*36,0,32);*(int*)(p+0x2200+i*36)=0;}
for(int i=0;i<252;i++){*(short*)(p+0x5480+i*8)=0;*(int*)(p+0x5484+i*8)=0;}
for(int i=0;i<72;i++)InitializeInvalidIndexRecord(p+0x821c+i*40);
for(int i=0;i<20;i++)func_ov000_02157d14(p+0x6380+i*52);
for(int i=0;i<20;i++)InitializeInvalidHalfwordRecord(p+0x6790+i*36);
for(int i=0;i<20;i++){memset(p+0x6a60+i*36,0,32);*(int*)(p+0x6a80+i*36)=0;}
for(int i=0;i<20;i++)InitializeInvalidIndexRecord(p+0x6060+i*40);
for(int i=0;i<16;i++)func_ov000_02157d14(p+0x6fb0+i*52);
for(int i=0;i<16;i++)InitializeInvalidHalfwordRecord(p+0x72f0+i*36);
for(int i=0;i<16;i++){memset(p+0x7530+i*36,0,32);*(int*)(p+0x7550+i*36)=0;}
for(int i=0;i<16;i++)InitializeInvalidIndexRecord(p+0x6d30+i*40);
for(int i=0;i<16;i++){InitializeInvalidIndexRecord(p+0x7770+i*40);func_ov000_02157d14(p+0x79f0+i*52);InitializeInvalidHalfwordRecord(p+0x7d30+i*36);memset(p+0x7f70+i*36,0,32);*(int*)(p+0x7f90+i*36)=0;}
*(unsigned*)(p+0x8e70)=0;
*(unsigned char*)(p+0x8e80)=0;
*(unsigned*)(p+0x8e74)=0;
*(unsigned char*)(p+0x8e81)=0;
*(unsigned*)(p+0x8e78)=0;
*(unsigned*)(p+0x8e7c)=0;
}
