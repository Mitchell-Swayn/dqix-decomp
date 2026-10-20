#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* YssdClientRunWorker_UnknownRoleZeroInitializedStorage;
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
extern "C" int Network_ResolveHostnameToBigEndianAddress(unsigned,unsigned*);
extern "C" char* NetworkSocket_GetHostByName(unsigned);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
// Original: arm9/ov031 @ 0x02210F78; symbol: Network_BuildTypeEightPacketFromHandle; size: 0xa0.
// Builds type8/subtype2 packet and falls back to copying resolved handle payload under mutex.
extern "C" bool Network_BuildTypeEightPacketFromHandle(unsigned handle,int id,unsigned char* packet) {
 packet[0]=8;packet[1]=2;*(unsigned short*)(packet+2)=((id>>8)&255)|((id<<8)&0xff00);
 if(!Network_ResolveHostnameToBigEndianAddress(handle,(unsigned*)(packet+4))){_Z9LockMutexP5Mutex(YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x1bc);char* record=NetworkSocket_GetHostByName(handle);if(record)MI_CpuCopy8(**(void***)(record+12),packet+4,*(short*)(record+10));_Z11UnlockMutexP5Mutex(YssdClientRunWorker_UnknownRoleZeroInitializedStorage+0x1bc);if(!record)return false;}return true;
}
