#include <globaldefs.h>
ARM
struct IntegerParameterView;struct Record {int type;int pad[2];void* object;};
extern "C" {int ReadScriptParameterAsInteger(IntegerParameterView*);const char* OV017_ReadWordField04(void*);void _ZN8Object3D6AttachEPS_PKc(void*,void*,const char*);extern unsigned data_ov001_02165880[];}
// Original: arm9/ov001 @ 0x0215CD50; symbol: func_ov001_0215cd50; size: 0xA8.
extern "C" int Script_AttachIndexedObjects(char* parameters,int count){
int first=ReadScriptParameterAsInteger((IntegerParameterView*)parameters);
int second=ReadScriptParameterAsInteger((IntegerParameterView*)(parameters+8));
const char* name=0;if(count>=3)name=OV017_ReadWordField04(parameters+16);
void* a=0;void* b=0;Record* records=(Record*)data_ov001_02165880[1];
int type=records[first].type;
if(type==0||type==4||type==5||type==1||type==6)a=records[first].object;
type=records[second].type;
if(type==0||type==4||type==5||type==1||type==6)b=records[second].object;
if(!a||!b)return 0;
_ZN8Object3D6AttachEPS_PKc(a,b,name);return 1;
}
