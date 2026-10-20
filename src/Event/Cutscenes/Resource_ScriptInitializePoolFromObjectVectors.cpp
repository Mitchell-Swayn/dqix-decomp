#include <globaldefs.h>
#include <System/Matrix.h>
ARM
struct GameState;struct IntegerParameterView;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetFieldOrbitCamera(GameState*);
extern "C" void ComputeOutputVectorsWhileRestoringObjectState(unsigned char*,Vector3i*,Vector3i*,Vector3i*);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void Resource_ScriptEnqueueTypeThreeArgumentRecord(void*,Vector3i,Vector3i,int,int,int);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215E14C; symbol: func_ov001_0215e14c; size: 0x80.
extern "C" int Resource_ScriptInitializePoolFromObjectVectors(IntegerParameterView* p){
 Vector3i a,b,c;
 unsigned char* object=(unsigned char*)GameState_GetFieldOrbitCamera((GameState*)_ZN9GameState11GetInstanceEv());
 if(!object)return 0;
 ComputeOutputVectorsWhileRestoringObjectState(object,&a,&b,&c);
 int mode=Script_ReadParameterAsInteger(p);
 Resource_ScriptEnqueueTypeThreeArgumentRecord(*(void**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+0x24),a,b,mode,0,0);
 return 1;
}
