#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov004 @ 0x0216F8C0; symbol: Resource_MapThousandRangeIdToLocalCode; size: 0xd0.
// Maps IDs1000 through1013 to codes69 through82 using independent equality tests.
extern "C" unsigned short Resource_MapThousandRangeIdToLocalCode(unsigned id){unsigned result=0;if(id==1000)result=69;if(id==1001)result=70;if(id==1002)result=71;if(id==1003)result=72;if(id==1004)result=73;if(id==1005)result=74;if(id==1006)result=75;if(id==1007)result=76;if(id==1008)result=77;if(id==1009)result=78;if(id==1010)result=79;if(id==1011)result=80;if(id==1012)result=81;if(id==1013)result=82;return result;}
