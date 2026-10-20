#include <globaldefs.h>
ARM
extern "C" void Crypto_LoadBigEndianDigestWords(unsigned*,const void*,unsigned);
extern "C" unsigned Network_UpdateSha1ScheduleWord(unsigned,unsigned*);
#define ROT(x,n) (((x)<<(n))|((x)>>(32-(n))))
#define CH(b,c,d) ((d)^((b)&((c)^(d))))
#define PAR(b,c,d) ((d)^((b)^(c)))
#define MAJ(b,c,d) (((b)&((c)|(d)))|((c)&(d)))
#define STEP(a,b,c,d,e,w,f,k) e += ROT(a,5)+f(b,c,d)+(w)+(k);b=ROT(b,30)
// Original: arm9/ov031 @ 0x0220B218; symbol: Network_CompressSha1Block; size: 0x688.
// SHA-1 compression with a 16-word rolling schedule and five-step unrolled rounds.
extern "C" void Crypto_CompressSha1Block(unsigned* state,const void* input) {
 int third,second,first;
 unsigned a=state[0],b=state[1],c=state[2],d=state[3],e=state[4];unsigned words[16];Crypto_LoadBigEndianDigestWords(words,input,64);
 int index=0;for(int i=0;i<3;i++) {
 STEP(a,b,c,d,e,words[index],CH,0x5a827999u);
 STEP(e,a,b,c,d,words[index+1],CH,0x5a827999u);
 STEP(d,e,a,b,c,words[index+2],CH,0x5a827999u);
 STEP(c,d,e,a,b,words[index+3],CH,0x5a827999u);
 STEP(b,c,d,e,a,words[index+4],CH,0x5a827999u);index+=5;
 }
 STEP(a,b,c,d,e,words[15],CH,0x5a827999u);
 STEP(e,a,b,c,d,Network_UpdateSha1ScheduleWord(0,words),CH,0x5a827999u);
 STEP(d,e,a,b,c,Network_UpdateSha1ScheduleWord(1,words),CH,0x5a827999u);
 STEP(c,d,e,a,b,Network_UpdateSha1ScheduleWord(2,words),CH,0x5a827999u);
 STEP(b,c,d,e,a,Network_UpdateSha1ScheduleWord(3,words),CH,0x5a827999u);
 index=4;for(first=0;first<4;first++) {
 STEP(a,b,c,d,e,Network_UpdateSha1ScheduleWord(index,words),PAR,0x6ed9eba1u);
 STEP(e,a,b,c,d,Network_UpdateSha1ScheduleWord(index+1,words),PAR,0x6ed9eba1u);
 index=(index+2)&15;
 STEP(d,e,a,b,c,Network_UpdateSha1ScheduleWord(index,words),PAR,0x6ed9eba1u);
 STEP(c,d,e,a,b,Network_UpdateSha1ScheduleWord(index+1,words),PAR,0x6ed9eba1u);
 STEP(b,c,d,e,a,Network_UpdateSha1ScheduleWord(index+2,words),PAR,0x6ed9eba1u);index+=3;
 }
 for(second=0;second<4;second++) {
 STEP(a,b,c,d,e,Network_UpdateSha1ScheduleWord(index,words),MAJ,0x8f1bbcdcu);
 STEP(e,a,b,c,d,Network_UpdateSha1ScheduleWord(index+1,words),MAJ,0x8f1bbcdcu);
 STEP(d,e,a,b,c,Network_UpdateSha1ScheduleWord(index+2,words),MAJ,0x8f1bbcdcu);
 index=(index+3)&15;
 STEP(c,d,e,a,b,Network_UpdateSha1ScheduleWord(index,words),MAJ,0x8f1bbcdcu);
 STEP(b,c,d,e,a,Network_UpdateSha1ScheduleWord(index+1,words),MAJ,0x8f1bbcdcu);index+=2;
 }
 for(third=0;third<4;third++) {
 STEP(a,b,c,d,e,Network_UpdateSha1ScheduleWord(index,words),PAR,0xca62c1d6u);
 STEP(e,a,b,c,d,Network_UpdateSha1ScheduleWord(index+1,words),PAR,0xca62c1d6u);
 STEP(d,e,a,b,c,Network_UpdateSha1ScheduleWord(index+2,words),PAR,0xca62c1d6u);
 STEP(c,d,e,a,b,Network_UpdateSha1ScheduleWord(index+3,words),PAR,0xca62c1d6u);
 index=(index+4)&15;
 STEP(b,c,d,e,a,Network_UpdateSha1ScheduleWord(index,words),PAR,0xca62c1d6u);index++;
 }
 state[0]+=a;state[1]+=b;state[2]+=c;state[3]+=d;state[4]+=e;
}
