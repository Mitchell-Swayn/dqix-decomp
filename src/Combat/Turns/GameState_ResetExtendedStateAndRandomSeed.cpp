#include <globaldefs.h>
ARM
extern "C" {
void Combat_ResetRecordPools(void*);
void* memset(void*,int,unsigned);
unsigned long long _Z19GetCurrentTimestampv();
void _Z10InitRandomP6RandomyPKch(void*,unsigned long long,const char*,unsigned char);
extern char GameState_ResetExtendedStateAndRandomSeed_TextBattle[];
}
#define W(o) (*(unsigned*)(p+(o)))
#define B(o) (*(unsigned char*)(p+(o)))
#define H(o) (*(short*)(p+(o)))
struct Bits {unsigned char a:4,b:2,c:2;};
struct Entry {unsigned char a,b;short c;unsigned d;};
struct Owner {char pad[0x81fc];Entry entries[4];};
// Original: arm9/ov000 @ 0x0215CE80; symbol: func_ov000_0215ce80; size: 0x210.
extern "C" void GameState_ResetExtendedStateAndRandomSeed(char* p){
Combat_ResetRecordPools(p);
W(0x8e18)=0;W(0x8e1c)=0;W(0x8e20)=0;B(0x8e47)=0;(*(signed char*)(p+0x8e48))=-1;
W(0x8e28)=0;W(0x8e2c)=0;W(0x8e30)=0;B(0x8e14)=0;W(0x8e34)=0;B(0x8e15)=0;
W(0x8e3c)=0x3f800000;W(0x8e40)=0x3f800000;B(0x8e49)=0;
memset(p+0x8e44,0,3);memset(p+0x8e84,0,16);
B(0x81b0)=0;((Bits*)(p+0x81b1))->a=0;((Bits*)(p+0x81b1))->b=0;((Bits*)(p+0x81b1))->c=0;
H(0x81b2)=0;
for(int i=0;i<3;i++)memset(p+0x81b4+i*24,0,24);
for(int i=0;i<4;i++){((Owner*)p)->entries[i].c=0;((Owner*)p)->entries[i].a=0;((Owner*)p)->entries[i].b=0;((Owner*)p)->entries[i].d=0;}
memset(p+0x8d5c,0,10);
B(0x8e07)=0;H(0x8e04)=-1;(*(signed char*)(p+0x8e06))=-1;H(0x8e4a)=0;H(0x8e4c)=0;H(0x8e4e)=0;B(0x8e97)=0;
for(int i=0;i<16;i++)memset(p+0x5c60+i*64,0,64);
for(int i=0;i<12;i++)memset(p+0x8d66+i*10,0,10);
B(0x8e94)=0;W(0x8eb0)=1;
unsigned long long time=_Z19GetCurrentTimestampv();
_Z10InitRandomP6RandomyPKch(p,time,GameState_ResetExtendedStateAndRandomSeed_TextBattle,1);
memset(p+0x8de0,-1,32);
}
