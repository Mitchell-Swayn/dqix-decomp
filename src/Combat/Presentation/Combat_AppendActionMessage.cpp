#include <globaldefs.h>
ARM

// Original: arm9/ov025 @ 0x021ED380; symbol: AppendBoundedPresentationEntry; size: 0xc4.
// Appends one of16 presentation entries, advances wrapping sequence and stores owner/target/flags.
extern "C" int Combat_AppendActionMessage(char* self,unsigned short key,short value,int kind,void* owner,short target,unsigned short flags){if(kind>=6)return -1;int result=-1;if(key&&(unsigned char)self[0x150]<16){*(unsigned short*)(self+2*(unsigned char)self[0x150])=key;*(short*)(self+0x20+2*(unsigned char)self[0x150])=value;*(char*)((self+(unsigned char)self[0x150])+0xa0)=kind;*(void**)(self+0xb0+4*(unsigned char)self[0x150])=owner;if(*(short*)(self+0x152)==32767)*(short*)(self+0x152)=0;++*(short*)(self+0x152);result=*(short*)(self+0x152);*(short*)(self+0x60+2*(unsigned char)self[0x150])=result;*(short*)(self+0x40+2*(unsigned char)self[0x150])=target;*(unsigned short*)(self+0x80+2*(unsigned char)self[0x150])=flags;++*(unsigned char*)(self+0x150);}return result;}
