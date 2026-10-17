// Original instruction control flow and relocations reviewed.
extern "C" char* data_02110370[];extern "C" unsigned short data_02108d70[];extern "C" unsigned int data_0210f3c0[];struct Flag{unsigned char enabled:1;unsigned char rest:7;};
// Original: arm9/main @ 0x02088B64; symbol: func_02088b64; size: 0x20.
extern "C" void Object_SetByte68ToSixAndFlag40000000(char* p){p[0x68]=6;p[0x8b]=0;*(unsigned int*)(p+20)|=0x40000000;}
