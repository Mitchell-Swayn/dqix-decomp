#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size on
union Vector {struct {int x,y,z;};int v[3];};struct Flags {unsigned char value:2;unsigned char rest:6;};struct ShortVector {short x,y,z;};extern "C" void* Object_GetGlobalConnectionState();extern "C" void* GameResources_GetInstance();extern "C" int IsFirstWordNonzero(void*);extern "C" int TestInactiveOrPrimaryIndexState(void*);extern "C" char* GetRecordAtResolvedIndexWithStride116(void*,int);extern "C" int ReadIndexedSignedField1038(void*);extern "C" void _Z16Vector3fix16CopyP8Vector3sPKS_(ShortVector*,const ShortVector*);
// Original: arm9/main @ 0x02034104; symbol: func_02034104; size: 0xDC.
extern "C" void ReadContextOrLocalObjectPosition(Vector* out,unsigned char* p){void* state=Object_GetGlobalConnectionState();GameResources_GetInstance();ShortVector v;Vector result;if(!IsFirstWordNonzero(state)||!TestInactiveOrPrimaryIndexState(state)||!GetRecordAtResolvedIndexWithStride116(state,*(short*)(p+4)))goto local;{short id=*(short*)(p+4);int own=ReadIndexedSignedField1038(state);if(own==id || !(((Flags*)(p+0xc1))->value&1))goto local;} {char* record=GetRecordAtResolvedIndexWithStride116(state,*(short*)(p+4));_Z16Vector3fix16CopyP8Vector3sPKS_(&v,(ShortVector*)(record+8));result.x=v.x*128;result.y=v.y*128;result.z=v.z*128;*out=result;}goto done;local:*out=*(Vector*)(p+0x44);done:return;}
