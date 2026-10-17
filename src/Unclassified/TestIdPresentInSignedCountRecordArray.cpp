#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0209497C; symbol: func_0209497c; size: 0x40.
extern "C" int TestIdPresentInSignedCountRecordArray(unsigned char* p,int id){for(int i=0;i<*(signed char*)(p+0x3cb);i++){short found=*(short*)(p+i*0x34+0x30);if(found==id)return 1;}return 0;}
