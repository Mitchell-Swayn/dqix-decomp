#include <globaldefs.h>
#include <System/Memory.h>
ARM
extern "C" int ProcessContextWithDefaultOptions(void*,unsigned,unsigned);
extern "C" void Overlay_EnsureContextStateTwoUnlessAlreadySet(unsigned,int);
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022104E4; symbol: func_ov031_022104e4; size: 0x134.
// Reads a length-prefixed packet, bounds its length and validates its YSSD signature.
extern "C" int Network_ReadAndValidateLengthPrefixedPacket(char* buffer){
char* cursor=buffer;unsigned count=0;
if(!YssdClientRunWorker_UnknownRoleZeroInitializedStorage)return -28;
VectorizedMemset(buffer,0,0x414);
do{
int n=ProcessContextWithDefaultOptions(*(void**)(YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x1b8),(unsigned)cursor,4-count);
if(n>0){count+=n;cursor+=n;}
else {if((int)count>0 || n!=0)Overlay_EnsureContextStateTwoUnlessAlreadySet(6,-50);return count;}
}while(count<4);
unsigned length=*(unsigned*)buffer;
if(length>0x414){Overlay_EnsureContextStateTwoUnlessAlreadySet(6,-50);return -35;}
if(count<length){do{
int n=ProcessContextWithDefaultOptions(*(void**)(YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x1b8),(unsigned)cursor,length-count);
if(n>0){count+=n;cursor+=n;}
else {Overlay_EnsureContextStateTwoUnlessAlreadySet(6,-50);return count;}
}while(count<length);}
if(count<12 || *(unsigned*)(buffer+4)!=0x44535359){Overlay_EnsureContextStateTwoUnlessAlreadySet(6,-40);return 0;}
return count;
}
