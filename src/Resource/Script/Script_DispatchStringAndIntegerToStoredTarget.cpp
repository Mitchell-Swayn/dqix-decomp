#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned char data_020fdc4c[];extern "C" void Object_CopyChangedNameAndClearRelatedFlags(void*,const char*);extern "C" void Object_AppendAllocatedNamedRecord(void*,int,const char*,void*);
// Original: arm9/main @ 0x0201F528; symbol: func_0201f528; size: 0x58.
extern "C" int Script_DispatchStringAndIntegerToStoredTarget(Script::Parameter* p){int n=p[0].ToInt();const char* text=p[1].ToString();if(!text)return 0;Object_CopyChangedNameAndClearRelatedFlags(*(void**)(data_020fdc4c+16),text);Object_AppendAllocatedNamedRecord(*(void**)(data_020fdc4c+16),n,text,*(void**)(data_020fdc4c+8));return 1;}
