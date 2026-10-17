// Reviewed original instruction stream; opaque fields require later semantic naming.
extern "C" unsigned int data_0214e4a0[];unsigned int DisableSpecificInterrupts(unsigned int);
// Original: arm9/main @ 0x020D8654; symbol: func_020d8654; size: 0x40.
extern "C" void System_PushInterruptFourEnabledStateAndDisable(){data_0214e4a0[1]<<=1;unsigned int old=DisableSpecificInterrupts(4);unsigned int flag=(old&4)!=0;data_0214e4a0[1]|=flag;}
