#include <globaldefs.h>
struct Node{unsigned char pad[0x2c];unsigned char kind;};extern "C" void NNSi_SndFaderSet(void*,unsigned,unsigned,Node*);
// Original: arm9/main @ 0x020BC180; symbol: func_020bc180; size: 0x2C.
extern "C" ARM void NNS_SndPlayerMoveVolume(Node* volatile* p,unsigned a,unsigned b){Node* node;if(*p&&(node=*p)->kind!=2){NNSi_SndFaderSet((char*)node+0x1c,a<<8,b,node);}}
