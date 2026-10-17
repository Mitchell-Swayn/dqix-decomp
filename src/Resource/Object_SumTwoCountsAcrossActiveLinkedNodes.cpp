#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void ReadIndirectHalfwordPair(void*,unsigned short*,unsigned short*);
// Original: arm9/main @ 0x020577CC; symbol: func_020577cc; size: 0x88.
extern "C" void Object_SumTwoCountsAcrossActiveLinkedNodes(unsigned char* p,unsigned short* outa,unsigned short* outb){unsigned short a=0,b=0;unsigned char* node=*(unsigned char**)(p+52);while(node){if(!node[44]){node=*(unsigned char**)(node+328);continue;}unsigned short x=0,y=0;ReadIndirectHalfwordPair(node,&x,&y);node=*(unsigned char**)(node+328);a+=x;b+=y;}*outa=a;*outb=b;}
