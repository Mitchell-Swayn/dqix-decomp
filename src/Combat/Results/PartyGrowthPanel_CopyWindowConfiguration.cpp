#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
struct Block80{unsigned w[20];};struct Block64{unsigned w[16];};
// Original: arm9/ov023 @ 0x021d8cb4; symbol: Object_CopyExtendedSnapshot.
extern "C" void PartyGrowthPanel_CopyWindowConfiguration(unsigned char* dst,unsigned char* src){
if(!src)return;unsigned char* owner=src+0x188;
*(Block80*)(dst+0x24)=*(Block80*)(owner+4);
*(Block64*)(dst+0x74)=*(Block64*)(owner+0x54);
dst[0xb4]=owner[0x94];
dst[0xb5]=owner[0x95];
dst[0xb6]=owner[0x96];
dst[0xb7]=owner[0x97];
W(dst,0xb8)=W(owner,0x98);W(dst,0xbc)=W(owner,0x9c);
*(short*)(dst+0xc0)=*(short*)(owner+0xa0);
*(short*)(dst+0xc2)=*(short*)(owner+0xa2);
*(short*)(dst+0xc4)=*(short*)(owner+0xa4);
*(short*)(dst+0xc6)=*(short*)(owner+0xa6);
*(short*)(dst+0xc8)=*(short*)(owner+0xa8);
*(short*)(dst+0xca)=*(short*)(owner+0xaa);
*(short*)(dst+0xcc)=*(short*)(owner+0xac);
*(short*)(dst+0xce)=*(short*)(owner+0xae);
dst[0xd0]=owner[0xb0];
dst[0xd1]=owner[0xb1];
dst[0xd2]=owner[0xb2];
dst[0xd3]=owner[0xb3];
dst[0xd4]=owner[0xb4];
dst[0xd5]=owner[0xb5];
dst[0xd6]=owner[0xb6];
dst[0xd7]=owner[0xb7];
dst[0xd8]=owner[0xb8];
dst[0xd9]=owner[0xb9];
dst[0xda]=owner[0xba];
dst[0xdb]=owner[0xbb];
P(dst,0)=src+0xb8;
}
