#include <globaldefs.h>
ARM
extern "C" int rand();
extern "C" unsigned _fadd(unsigned,unsigned);
extern "C" unsigned _fsub(unsigned,unsigned);
extern "C" unsigned _fdiv(unsigned,unsigned);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" int _ffix(unsigned);
extern "C" unsigned _fflt(int);
extern "C" int ResourceTracks_GetPairedVectorSection(char*);
extern "C" unsigned** _ZN19SignedAllocatorList13GetNthElementEj(void*,unsigned);
// Original: arm9/main @ 0x020589B8; symbol: func_020589b8; size: 0x184.
extern "C" void Object_AdvanceRandomizedFloatKeyframe(char* self) {
 unsigned char* config=(unsigned char*)ResourceTracks_GetPairedVectorSection(*(char**)(self+0x28));
 if(config[9]<=1)return;
 if(config[9]<=*(unsigned short*)(self+0x68))return;
 unsigned** prev=_ZN19SignedAllocatorList13GetNthElementEj(*(char**)(self+0x28)+0xd4,*(unsigned short*)(self+0x68));
 if(!prev)return;
 if(**prev>=*(unsigned*)(self+4))return;
 ++*(unsigned short*)(self+0x68);
 if(*(unsigned short*)(self+0x68)>=config[9]) {
  *(unsigned*)(self+0x44)=0;*(unsigned*)(self+0x48)=0;return;
 }
 unsigned** next=_ZN19SignedAllocatorList13GetNthElementEj(*(char**)(self+0x28)+0xd4,*(unsigned short*)(self+0x68));
 if(!next)return;
 unsigned* record=*next;
 int random=rand();
 int scale=_ffix(record[3]);
 unsigned factor=_fdiv(_fflt((random&(scale<<1))-_ffix(record[3])),0x42c80000);
 unsigned oldX=*(unsigned*)(self+0x58);
 unsigned oldY=*(unsigned*)(self+0x5c);
 *(unsigned*)(self+0x58)=_fadd(record[1],_fmul(record[1],factor));
 record=*next;
 *(unsigned*)(self+0x5c)=_fadd(record[2],_fmul(record[2],factor));
 unsigned delta=_fsub(*(unsigned*)(self+0x58),oldX);
 *(unsigned*)(self+0x44)=_fdiv(delta,_fflt(**next-**prev));
 delta=_fsub(*(unsigned*)(self+0x5c),oldY);
 *(unsigned*)(self+0x48)=_fdiv(delta,_fflt(**next-**prev));
}
