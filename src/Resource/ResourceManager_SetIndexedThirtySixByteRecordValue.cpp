// ARM instruction behavior reviewed; fields retain known byte offsets.
struct Flags{unsigned int value:12;unsigned int rest:20;};extern "C" char data_0210f840[];
// Original: arm9/main @ 0x020BBF6C; symbol: func_020bbf6c; size: 0x18.
extern "C" void ResourceManager_SetIndexedThirtySixByteRecordValue(int i,int v){*(int*)(data_0210f840+i*36)=v;}
