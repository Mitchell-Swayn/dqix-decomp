#include "World/Object3D.h"
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
struct IndexedObject {int kind;int unknown4,unknown8;Object3D* object;};
// Original: arm9/ov001 @ 0x0215CDF8; symbol: Script_DetachBoundObject; size: 0x54 (84).
// Supported kinds0,4,5,1,6 expose their object pointer; others report failure.
extern "C" ARM int Script_DetachBoundObject(IntegerParameterView* parameter){
 int index=Script_ReadParameterAsInteger(parameter);Object3D* object=0;
 IndexedObject* entries=*(IndexedObject**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4);
 int kind=entries[index].kind;
 if(kind==0||kind==4||kind==5||kind==1||kind==6)object=entries[index].object;
 if(!object)return 0;
 object->Detach();return 1;
}
