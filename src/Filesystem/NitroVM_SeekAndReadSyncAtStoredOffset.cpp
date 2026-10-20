#include <globaldefs.h>
#include <Filesystem/FileAccessor.h>
// Original: arm9/main @ 0x020C00C8; symbol: func_020c00c8; size: 0x38.
extern "C" ARM void NitroVM_SeekAndReadSyncAtStoredOffset(unsigned char* p,void* dst,int count,int offset){NitroVM_Seek((NitroVM*)(p+0x5c),*(int*)(p+0xa4)+offset,0);NitroVM_ReadSync((NitroVM*)(p+0x5c),dst,count);}
