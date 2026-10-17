#include <globaldefs.h>
struct Object{char pad[0xbd0];short* arrays[8];signed char* rates[8];short counts[8];unsigned char ids[8];};
// Original: arm9/main @ 0x0207CB38; symbol: func_0207cb38; size: 0xB0.
extern "C" ARM int SetBoundedGroupedValueAndPercentRate(Object* p,int index,unsigned id,int value,signed char rate){if(value<0)return 0;if(rate<0||rate>99)return 0;int found=-1;for(int i=0;i<8;i++)if(p->ids[i]==id){found=i;break;}if(found==-1)return 0;short count=p->counts[found];if(index<0||index>=count)return 0;signed char* rates=p->rates[found];short* values=p->arrays[found];values[index]=value;rates[index]=rate;return 1;}
