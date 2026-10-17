extern "C" void __clear(void*,unsigned);
#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" char data_020ef7a0[];extern "C" char data_020fefec[];extern "C" void Text_CopyBoundedStringAndReturnSourceLength(void*,const void*,unsigned);extern "C" void Network_RefreshOrAppendMacAddressEntry(void*,void*);struct Owner {char pad[0x3c];unsigned short flag;char pad2[12];unsigned char kind;char pad3[5];char data[20];unsigned char count;};
// Original: arm9/main @ 0x0202AE4C; symbol: func_0202ae4c; size: 0x70.
extern "C" void Object_PrepareNameAndSubmitConnectionRecord(Owner* self) {char buffer[21];__clear(buffer,21);if(self->flag && self->kind==36)memcpy(buffer,self->data,self->count);else Text_CopyBoundedStringAndReturnSourceLength(buffer,data_020ef7a0,21);Network_RefreshOrAppendMacAddressEntry(data_020fefec,self); }
