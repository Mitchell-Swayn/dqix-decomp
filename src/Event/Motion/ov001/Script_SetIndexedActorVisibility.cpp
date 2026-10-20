#include <globaldefs.h>
struct IntegerParameterView {unsigned type;union {int integer;float real;} value;};
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void Object3D_MakeFirstAvailableRepresentationVisible(char*);
extern "C" void Object_HideFirstAvailableRenderTarget(unsigned char*);
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
struct IndexedObject {int kind;int unknown4,unknown8;void* object;};
// Original: arm9/ov001 @ 0x0215C730; symbol: Script_SetIndexedActorVisibility; size: 0x58 (88).
// Kind2 object visibility is controlled by the second eight-byte script parameter.
extern "C" ARM int Script_SetIndexedActorVisibility(IntegerParameterView* parameters){
 int index=Script_ReadParameterAsInteger(parameters);int visible=Script_ReadParameterAsInteger(parameters+1);
 IndexedObject* entries=*(IndexedObject**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4);
 if(entries[index].kind!=2)return 1;
 if(visible)Object3D_MakeFirstAvailableRepresentationVisible((char*)entries[index].object);
 else Object_HideFirstAvailableRenderTarget((unsigned char*)entries[index].object);
 return 1;
}
