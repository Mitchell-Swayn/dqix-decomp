#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" char* ReadGlobalAt02109928();
extern "C" void Graphics_CopySixteenBytesToEdgeColorRegisters(const void*);
extern "C" void* _Z17GetModel3DContextP7Model3D(void*);
extern "C" int _ZN7Model3D12GetBoneIndexEPKc(void*,const char*);
extern "C" void _Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(void*,void*,void*,unsigned);
extern "C" void _ZN8Object3D10EnableFlagEi(void*,int);
extern "C" void _ZN8Object3D15ApplyAnimationsEPS_(void*,void*);
extern "C" void _ZN8Object3D4DrawEb(void*,bool);
struct Names { char names[9][20]; };
struct Flags { int flags[9]; };
extern "C" Names data_ov015_02193ee8;
extern "C" Flags data_ov015_02193d9c;
// Original: arm9/ov015 @ 0x0218EB04; symbol: func_ov015_0218eb04; size: 0x1D4.
extern "C" void Graphics_DrawBoneAttachedObjectParts(char* self) {
 unsigned short color=*(unsigned short*)(ReadGlobalAt02109928()+0x128);
 unsigned short edge[8];
 edge[0]=color;edge[1]=color;edge[2]=color;edge[3]=color;
 edge[4]=color;edge[5]=color;edge[6]=color;edge[7]=color;
 Graphics_CopySixteenBytesToEdgeColorRegisters(edge);
 *(short*)(self+0x36)=0;
 *(short*)(self+0x34)=0;
 void* model=*(void**)(*(char**)(self+0x24)+8);
 if(model) {
 void* context=_Z17GetModel3DContextP7Model3D(model);
 if(context) {
 char* objects[10]={0};
 objects[0]=*(char**)(self+0x24);
 objects[1]=*(char**)(self+0x24)+0x158;
 objects[2]=*(char**)(self+0x24)+0x204;
 objects[3]=*(char**)(self+0x24)+0x4b4;
 objects[4]=*(char**)(self+0x24)+0x560;
 objects[5]=*(char**)(self+0x24)+0x60c;
 objects[6]=*(char**)(self+0x24)+0x408;
 objects[7]=*(char**)(self+0x24)+0x35c;
 objects[8]=*(char**)(self+0x24)+0xac;
 Names names=data_ov015_02193ee8;
 Flags flags=data_ov015_02193d9c;
 for(int i=0;objects[i];i++) {
 char* object=objects[i];
 if(*(short*)(object+2)>=0) {
 if(strlen(names.names[i])) {
 int bone=_ZN7Model3D12GetBoneIndexEPKc(model,names.names[i]);
 _Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(context,0,0,bone);
 _ZN8Object3D10EnableFlagEi(object,0x4000);
 }
 if(flags.flags[i]) _ZN8Object3D15ApplyAnimationsEPS_(*(void**)(self+0x24),object);
 _ZN8Object3D4DrawEb(object,true);
 }
 }
 }
 }
}
