#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned char data_020fdc4c[];extern "C" void AllocateThirtySixByteRecordArray(void*,unsigned,void*);
// Original: arm9/main @ 0x0201F500; symbol: func_0201f500; size: 0x28.
extern "C" int Script_InvokeOwnerWithIntegerParameter(Script::Parameter* p){unsigned n=p->ToInt();AllocateThirtySixByteRecordArray(*(void**)(data_020fdc4c+16),n,*(void**)(data_020fdc4c+8));return 1;}
