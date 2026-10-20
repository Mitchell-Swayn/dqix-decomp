#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned MD5CompressBufferedBlock_UnknownRoleInitializedBytes_Variant2[];
extern "C" unsigned MD5CompressBufferedBlock_UnknownRoleInitializedBytes[];
struct Md5State { unsigned state[4]; unsigned count[2]; unsigned block[16]; };
#define ROT(x,s) (((x)<<(s))|((x)>>(32-(s))))
#define F(x,y,z) (((x)&(y))|(~(x)&(z)))
#define G(x,y,z) (((x)&(z))|((y)&~(z)))
#pragma always_inline on
inline unsigned Md5Xor(unsigned x,unsigned y,unsigned z){return z^(x^y);}
#define H(x,y,z) Md5Xor(x,y,z)
inline unsigned Md5Final(unsigned x,unsigned y,unsigned z){return y^(x|~z);}
#define I(x,y,z) Md5Final(x,y,z)
#define STEP(f,a,b,c,d,k,s) a=b+ROT(a+f(b,c,d)+x[k]+t[k],s)
#define STEPI(f,a,b,c,d,k,s) a=b+ROT(a+f(b,c,d)+x[q[k]]+t[k],s)
// Original: arm9/main @ 0x020C04E8; symbol: MD5_CompressBufferedBlock; size: 0x3B4.
// Applies all four MD5 rounds to the current 64-byte block and accumulates the state words.
extern "C" void MD5_CompressBufferedBlock(unsigned* ctx) {
const unsigned* q;
unsigned a=ctx[0],b=ctx[1],c=ctx[2],d=ctx[3];
unsigned* x=(ctx+6);
unsigned* p=x;
int i;
const unsigned* t=MD5CompressBufferedBlock_UnknownRoleInitializedBytes_Variant2;
i=0; do {
a=b+ROT(a+F(b,c,d)+p[0]+t[0],7);
d=a+ROT(d+F(a,b,c)+p[1]+t[1],12);
c=d+ROT(c+F(d,a,b)+p[2]+t[2],17);
unsigned constant=t[3],last=p[3];t+=4;p+=4;
b=c+ROT(b+F(c,d,a)+last+constant,22);
} while(++i<4);
q=MD5CompressBufferedBlock_UnknownRoleInitializedBytes;
i=0; do {
STEPI(G,a,b,c,d,0,5);
STEPI(G,d,a,b,c,1,9);
STEPI(G,c,d,a,b,2,14);
unsigned constant=t[3],last=x[q[3]];t+=4;q+=4;
b=c+ROT(b+G(c,d,a)+last+constant,20);
} while(++i<4);
i=0; do {
STEPI(H,a,b,c,d,0,4);
STEPI(H,d,a,b,c,1,11);
STEPI(H,c,d,a,b,2,16);
unsigned constant=t[3],last=x[q[3]];t+=4;q+=4;
b=c+ROT(b+H(c,d,a)+last+constant,23);
} while(++i<4);
i=0; do {
STEPI(I,a,b,c,d,0,6);
STEPI(I,d,a,b,c,1,10);
STEPI(I,c,d,a,b,2,15);
unsigned constant=t[3],last=x[q[3]];t+=4;q+=4;
b=c+ROT(b+I(c,d,a)+last+constant,21);
} while(++i<4);
ctx[0]+=a;
ctx[1]+=b;
ctx[2]+=c;
ctx[3]+=d;
}
