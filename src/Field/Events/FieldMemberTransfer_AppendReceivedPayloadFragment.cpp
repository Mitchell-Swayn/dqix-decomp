#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/ov017 @ 0x021A99DC; symbol: func_ov017_021a99dc; size: 0xC0.
extern "C" void FieldMemberTransfer_AppendReceivedPayloadFragment(char* self,const void* source,int kind,unsigned length,unsigned char finalize) {
char* buffer=*(char**)(self+0x20);
if(!buffer) return;
if(kind==0) {
memcpy(buffer+0xe04+*(unsigned char*)(self+0x25),source,length);
*(unsigned char*)(self+0x25)+=length;
} else if(kind==2) {
memcpy(buffer+0xdf0,source,length);
*(unsigned char*)(*(char**)(self+0x20)+0xe98)|=4;
} else {
*(unsigned char*)(buffer+0xe98)|=1;
memcpy(*(char**)(self+0x20)+0xe1c+*(unsigned char*)(self+0x26),source,length);
*(unsigned char*)(self+0x26)+=length;
}
if(finalize) *(unsigned char*)(*(char**)(self+0x20)+0xe98)|=2;
}
