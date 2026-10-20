#include <globaldefs.h>
ARM
extern "C" void* Zone3D_GetMainInstance();
extern "C" char* _ZN15LightingManager11GetInstanceEv();
extern "C" char* _ZN17Zone3D_BMDJStruct10ScriptData15GetStruct20ByIDEi(void*,int);
extern "C" char* _ZN17Zone3D_BMDJStruct10ScriptData14GetStructCByIDEi(void*,int);
extern "C" void _ZN15LightingManager36ModelTransformTintBrightnessContrastEP18NSBXXInternalModel(char*,void*);
struct Node {unsigned short id; char pad[0x22]; char* model; char pad28[4]; Node *child,*sibling;};
// Original: arm9/ov001 @ 0x021601F8; symbol: func_ov001_021601f8; size: 0x140.
extern "C" void Lighting_ApplyTintToModelTree(Node* self,void* script) {
 Zone3D_GetMainInstance();
 char* lighting=_ZN15LightingManager11GetInstanceEv();
 char* model=self->model;
 int lightingId=*(int*)(lighting+0x98);
 char* record=_ZN17Zone3D_BMDJStruct10ScriptData15GetStruct20ByIDEi(script,self->id);
 record=_ZN17Zone3D_BMDJStruct10ScriptData14GetStructCByIDEi(script,*(short*)(record+2));
 for(char* node=*(char**)(record+8);node;node=*(char**)(node+8)) {
  if(*(short*)node==lightingId){record=node;break;}
 }
 if(model) {
  int kind=*(short*)model;
  if(kind==0 && *(char**)(model+4) && *(void**)(*(char**)(model+4)+0x54) && !(*(unsigned short*)(model+2)&1)) {
   if(record && !(*(unsigned char*)(record+2)&0x20)) {
    _ZN15LightingManager36ModelTransformTintBrightnessContrastEP18NSBXXInternalModel(lighting,*(void**)(*(char**)(model+4)+0x54));
    *(unsigned short*)(model+2)|=1;
   }
  } else if(kind==2 && *(char**)(model+4) && *(char**)(*(char**)(model+4)+8) && *(void**)(*(char**)(*(char**)(model+4)+8)+0x54) && !(*(unsigned short*)(model+2)&1)) {
   if(record && !(*(unsigned char*)(record+2)&0x20)) {
    _ZN15LightingManager36ModelTransformTintBrightnessContrastEP18NSBXXInternalModel(lighting,*(void**)(*(char**)(*(char**)(model+4)+8)+0x54));
    *(unsigned short*)(model+2)|=1;
   }
  }
 }
 if(self->child)Lighting_ApplyTintToModelTree(self->child,script);
 if(self->sibling)Lighting_ApplyTintToModelTree(self->sibling,script);
}
