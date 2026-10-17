#include <globaldefs.h>
#include <System/Matrix.h>
ARM
struct GameState;struct IntegerParameterView;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetField3B0ObjectWithFlag4(GameState*);
extern "C" void ComputeOutputVectorsWhileRestoringObjectState(unsigned char*,Vector3i*,Vector3i*,Vector3i*);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" void func_ov001_02158f64(void*,Vector3i,Vector3i,int,int,int);
extern "C" unsigned char data_ov001_02165880[];
// Original: arm9/ov001 @ 0x0215E14C; symbol: func_ov001_0215e14c; size: 0x80.
extern "C" int Resource_ScriptInitializePoolFromObjectVectors(IntegerParameterView* p){
 Vector3i a,b,c;
 unsigned char* object=(unsigned char*)GameState_GetField3B0ObjectWithFlag4((GameState*)_ZN9GameState11GetInstanceEv());
 if(!object)return 0;
 ComputeOutputVectorsWhileRestoringObjectState(object,&a,&b,&c);
 int mode=ReadScriptParameterAsInteger(p);
 func_ov001_02158f64(*(void**)(data_ov001_02165880+0x24),a,b,mode,0,0);
 return 1;
}
