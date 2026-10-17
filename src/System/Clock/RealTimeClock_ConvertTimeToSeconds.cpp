// Original ARM range reviewed.
extern "C" char* ReadSignedWordAtOffset4(char*);extern "C" unsigned int data_02107800[];
// Original: arm9/main @ 0x020CF978; symbol: func_020cf978; size: 0x18.
extern "C" int RealTimeClock_ConvertTimeToSeconds(int* p){return (p[0]*60+p[1])*60+p[2];}
