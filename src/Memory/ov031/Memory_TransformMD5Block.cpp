#include <globaldefs.h>
ARM
extern "C" void func_ov031_0220abac(const void*,void*,unsigned);
extern "C" unsigned char data_ov031_02249764[];
extern "C" unsigned data_ov031_022497e4[];
#define ROTATE(x,s) (((x)<<(s))|((x)>>(32-(s))))
#define F(b,c,d) ((d)^((b)&((c)^(d))))
#define G(b,c,d) ((c)^((d)&((b)^(c))))
#define H(b,c,d) ((d)^((b)^(c)))
#define I(b,c,d) ((c)^((b)|~(d)))
#define STEP(f,a,b,c,d,s,n) a += f(b,c,d) + words[data_ov031_02249764[k+n]] + data_ov031_022497e4[k+n]; a = b + ROTATE(a,s)
// Original: arm9/ov031 @ 0x0220ABC4; symbol: func_ov031_0220abc4; size: 0x41C.
extern "C" void Memory_TransformMD5Block(unsigned* state,void* block) {
 unsigned a=state[0],b=state[1],c=state[2],d=state[3];
 unsigned words[16];
 func_ov031_0220abac(words,block,64);
 int k=0,j;
 for(j=0;j<4;j++) {
  STEP(F,a,b,c,d,7,0);
  STEP(F,d,a,b,c,12,1);
  STEP(F,c,d,a,b,17,2);
  STEP(F,b,c,d,a,22,3);
  k+=4;
 }
 for(j=0;j<4;j++) {
  STEP(G,a,b,c,d,5,0);
  STEP(G,d,a,b,c,9,1);
  STEP(G,c,d,a,b,14,2);
  STEP(G,b,c,d,a,20,3);
  k+=4;
 }
 for(j=0;j<4;j++) {
  STEP(H,a,b,c,d,4,0);
  STEP(H,d,a,b,c,11,1);
  STEP(H,c,d,a,b,16,2);
  STEP(H,b,c,d,a,23,3);
  k+=4;
 }
 for(j=0;j<4;j++) {
  STEP(I,a,b,c,d,6,0);
  STEP(I,d,a,b,c,10,1);
  STEP(I,c,d,a,b,15,2);
  STEP(I,b,c,d,a,21,3);
  k+=4;
 }
 state[0]+=a;state[1]+=b;state[2]+=c;state[3]+=d;
}
