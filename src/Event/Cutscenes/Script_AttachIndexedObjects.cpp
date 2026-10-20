#include <globaldefs.h>
ARM
struct IntegerParameterView;struct Record {int type;int pad[2];void* object;};
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" {int Script_ReadParameterAsInteger(IntegerParameterView*);const char* Script_ReadParameterString(void*);void _ZN8Object3D6AttachEPS_PKc(void*,void*,const char*);extern unsigned EventGetObjectSession_UnknownRoleZeroInitializedStorage[];}
// Original: arm9/ov001 @ 0x0215CD50; symbol: func_ov001_0215cd50; size: 0xA8.
extern "C" int Script_AttachIndexedObjects(char* parameters,int count){
int first=Script_ReadParameterAsInteger((IntegerParameterView*)parameters);
int second=Script_ReadParameterAsInteger((IntegerParameterView*)(parameters+8));
const char* name=0;if(count>=3)name=Script_ReadParameterString(parameters+16);
void* a=0;void* b=0;Record* records=(Record*)EventGetObjectSession_UnknownRoleZeroInitializedStorage[1];
int type=records[first].type;
if(type==0||type==4||type==5||type==1||type==6)a=records[first].object;
type=records[second].type;
if(type==0||type==4||type==5||type==1||type==6)b=records[second].object;
if(!a||!b)return 0;
_ZN8Object3D6AttachEPS_PKc(a,b,name);return 1;
}
