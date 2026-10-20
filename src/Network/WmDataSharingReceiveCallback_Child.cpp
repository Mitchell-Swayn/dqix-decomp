#include <globaldefs.h>
ARM
struct Buffer {unsigned char blocks[4][512];unsigned short lengths[4],index;char pad80a[10];unsigned short packetSize;char pad816[6];unsigned short status;};
struct Packet {unsigned short unknown,error,kind;char pad6[6];const unsigned short* data;unsigned short size;char pad12[8];unsigned short length;Buffer* target;};
extern "C" unsigned char ReadOptionalSharedHalfwordStatusUnderIRQGuard();extern "C" void MIi_CpuCopy16(const void*,void*,unsigned);
// Original: arm9/main @ 0x020D651C; symbol: func_020d651c; size: 0xF4.
extern "C" void WmDataSharingReceiveCallback_Child(Packet* p){Buffer* b=p->target;if(!b)return;if(!p->error){
 switch(p->kind){case 7:case 9:case 25:case 26:return;case 21:break;default:return;}
 unsigned short size,mask;const unsigned short* data;data=p->data;size=p->size;mask=*data;unsigned char channel=ReadOptionalSharedHalfwordStatusUnderIRQGuard();
 if(size!=b->packetSize&&size>512)size=512;if(size<4)return;if(!(mask&(1u<<channel)))return;
 MIi_CpuCopy16(data,b->blocks[b->index],size);b->lengths[b->index]=p->length>>1;b->index=(b->index+1)&3;}else b->status=5;
}
