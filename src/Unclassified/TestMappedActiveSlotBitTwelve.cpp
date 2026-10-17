extern "C" signed char data_020e8b24[],data_020e8b25[];
// Original: arm9/main @ 0x02085230; symbol: func_02085230; size: 0x74.
 extern "C" int TestMappedActiveSlotBitTwelve(unsigned char *self) { int i=0; while(data_020e8b24[i*2]!=-1) { int slot=data_020e8b24[i*2]; if(*(short *)(self+data_020e8b25[i*2]*32+0x1ac)>0 && ((*(unsigned int *)(self+slot*44+0x2f4)<<19)>>31)!=0) return 1; ++i; } return 0; }
