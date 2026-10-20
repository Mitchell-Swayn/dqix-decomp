#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size on
union Vector {struct {int x,y,z;};int v[3];};struct Flags {unsigned char value:2;unsigned char rest:6;};struct ShortVector {short x,y,z;};extern "C" void* Network_GetConnectionManager();extern "C" void* GameResources_GetInstance();extern "C" int Network_IsSessionActive(void*);extern "C" int Network_IsParentOrOffline(void*);extern "C" char* Network_GetReceivedMemberPacket(void*,int);extern "C" int Network_GetLocalMemberId(void*);extern "C" void _Z16Vector3fix16CopyP8Vector3sPKS_(ShortVector*,const ShortVector*);
// Original: arm9/main @ 0x02034104; symbol: func_02034104; size: 0xDC.
extern "C" void GameObject_GetAuthorityPosition(Vector* out,unsigned char* p){void* state=Network_GetConnectionManager();GameResources_GetInstance();ShortVector v;Vector result;if(!Network_IsSessionActive(state)||!Network_IsParentOrOffline(state)||!Network_GetReceivedMemberPacket(state,*(short*)(p+4)))goto local;{short id=*(short*)(p+4);int own=Network_GetLocalMemberId(state);if(own==id || !(((Flags*)(p+0xc1))->value&1))goto local;} {char* record=Network_GetReceivedMemberPacket(state,*(short*)(p+4));_Z16Vector3fix16CopyP8Vector3sPKS_(&v,(ShortVector*)(record+8));result.x=v.x*128;result.y=v.y*128;result.z=v.z*128;*out=result;}goto done;local:*out=*(Vector*)(p+0x44);done:return;}
