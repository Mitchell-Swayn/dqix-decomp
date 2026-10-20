#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" int _ffix(unsigned);
extern "C" unsigned _ffltu(unsigned);
extern "C" int _fleq(unsigned,unsigned);
// Original: arm9/ov024 @ 0x021F8D80; symbol: func_ov024_021f8d80; size: 0x1A0.
extern "C" int Combat_SelectHighestPriorityCandidate(void* unused,int* selected,char* flags,char** candidates,int count,unsigned* damages,unsigned* limits,int multiplier) {
 int rank[8];
 __clear(rank,32);
 for(int i=0;i<count;i++) {
  char* detail=*(char**)(candidates[i]+0x138);
  unsigned state=*(unsigned*)(detail+0x14);
  if((*(unsigned*)(flags+0x10)&0x400)&&(state&0x200))rank[i]=-1;
  else if(state&8)rank[i]=1;
  else if(state&0x20)rank[i]=2;
  else if(state&0x10)rank[i]=3;
  else if((float)(unsigned)*(unsigned short*)detail<=((float*)limits)[i])rank[i]=5;
  else rank[i]=4;
 }
 int best=0;
 for(int i=1;i<count;i++) {
  if(rank[i]>rank[best])best=i;
  else if(rank[i]==rank[best]) {
   int hp=*(unsigned short*)(*(char**)(candidates[i]+0x138));
   int bestHp=*(unsigned short*)(*(char**)(candidates[best]+0x138));
   int replace=0;
   int remaining=hp-multiplier*_ffix(damages[i]);
   int bestRemaining=bestHp-multiplier*_ffix(damages[best]);
   if(remaining<=0) {
    if(bestRemaining>0)replace=1;
    else if(hp>bestHp)replace=1;
   } else if(remaining<bestRemaining)replace=1;
   if(replace)best=i;
  }
 }
 *selected=best;
 return rank[best]>=0;
}
