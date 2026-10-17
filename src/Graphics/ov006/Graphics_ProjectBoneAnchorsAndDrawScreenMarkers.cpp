#include <globaldefs.h>
ARM
#pragma always_inline on
struct Vec {int x,y,z;};
extern "C" {
void Graphics_ResetCountedTransferRecordsAtOffset2C(unsigned char*);
void SetValueZeroForEachThirtyTwoByteEntry(void*);
void Graphics_ResetGeometryMatrixStackState();
void _ZN12RenderConfig12SubmitToFifoEv();
void _ZN8Object3D24MaybeUpdateBonePositionsEv(void*);
void* _ZN9GameState11GetInstanceEv();
void* GameState_ReadUnknownB0(void*);
Vec _ZNK8Object3D8GetScaleEv(const void*);
void Vector3fix_Add(const void*,const void*,void*);
int Graphics_ConvertCopiedWorldVectorToScreenCoordinates(void*,const void*,int*,int*);
void* ReadGlobalAt02105AB4();
char* ReadGlobalAt021052B4();
int _ZNK8Object3D19HasAnimationStoppedEv(const void*);
void SetWordFieldsAtOffsets28And2C(void*,int,int);
int DispatchSelectedTwoDimensionalTableEntryWhenEnabled(void*,int,int);
extern void* data_ov006_0216038c[];
extern unsigned data_0210a00c;
}
struct Matrix {int v[12];};
struct Mapping {unsigned char v[4][4];};
struct Bits {unsigned char a:1,b:1,c:6;};
extern "C" Mapping data_ov006_0215ff6c;
static inline int MultiplyRounded(int a,int b) { return (int)(((long long)a*b+0x800LL)>>12); }
// Original: arm9/ov006 @ 0x02154A60; symbol: func_ov006_02154a60; size: 0x3F8.
extern "C" void Graphics_ProjectBoneAnchorsAndDrawScreenMarkers(unsigned char* self) {
if(((Bits*)(self+0x127f))->b || !self[0xadc]) return;
unsigned char* transfer=*(unsigned char**)(self+0x1d4);
Graphics_ResetCountedTransferRecordsAtOffset2C(transfer);
SetValueZeroForEachThirtyTwoByteEntry(transfer);
if(*(unsigned short*)(self+0xae2)&8) return;
Matrix matrices[3];
for(int i=0;i<3;i++) data_ov006_0216038c[i]=&matrices[i];
Graphics_ResetGeometryMatrixStackState();_ZN12RenderConfig12SubmitToFifoEv();
_ZN8Object3D24MaybeUpdateBonePositionsEv(self+0x4e8);
for(int i=0;i<3;i++) data_ov006_0216038c[i]=0;
Vec positions[3];
positions[0].x=matrices[0].v[9];positions[0].y=matrices[0].v[10];positions[0].z=matrices[0].v[11];
positions[1].x=matrices[1].v[9];positions[1].y=matrices[1].v[10];positions[1].z=matrices[1].v[11];
positions[2].x=matrices[2].v[9];positions[2].y=matrices[2].v[10];positions[2].z=matrices[2].v[11];
int widths[3];widths[0]=matrices[0].v[0];widths[1]=matrices[1].v[0];widths[2]=matrices[2].v[0];
int heights[3];heights[0]=matrices[0].v[4];heights[1]=matrices[1].v[4];heights[2]=matrices[2].v[4];
for(int i=0;i<3;i++) {if(widths[i]<40) widths[i]=40;if(heights[i]<40) heights[i]=40;}
unsigned group=self[0x12bb];
Mapping mapping=data_ov006_0215ff6c;
void* camera=GameState_ReadUnknownB0(_ZN9GameState11GetInstanceEv());
if(camera) {
unsigned char* marker=self+0x894;
for(unsigned char i=0;i<4;i++,marker+=124) {
Vec v=positions[mapping.v[group][i]];
Vec world;
v.x=MultiplyRounded(v.x,_ZNK8Object3D8GetScaleEv(self+0x2e4).x);
v.y=MultiplyRounded(v.y,_ZNK8Object3D8GetScaleEv(self+0x2e4).y);
v.z=MultiplyRounded(v.z,_ZNK8Object3D8GetScaleEv(self+0x2e4).z);
Vec pos=*(Vec*)(self+0x328);Vector3fix_Add(&v,&pos,&world);
int x,y;Graphics_ConvertCopiedWorldVectorToScreenCoordinates(camera,&world,&x,&y);
*(short*)(marker+0x76)=x-18;
*(short*)(marker+0x78)=y-12;
}}
ReadGlobalAt02105AB4();char* records=ReadGlobalAt021052B4();
unsigned char* marker;unsigned char i;int value=*(int*)(self+0x308);
if((*(unsigned short*)(self+0xae2)&0x2000 || *(unsigned short*)(self+0xae2)&0x80) && !_ZNK8Object3D19HasAnimationStoppedEv(self+0x4e8)) {
marker=self+0x910;
for(i=1;i<4;marker+=124,i++) {
unsigned index=mapping.v[group][i];
*(unsigned*)(marker+0x4c)=0x300;
*(void**)(marker+0x14)=records+8*(32+i*4);
*(int*)(marker+0x44)=(32+i*4)/4;
SetWordFieldsAtOffsets28And2C(marker,widths[index],heights[index]);
DispatchSelectedTwoDimensionalTableEntryWhenEnabled(marker,*(short*)(marker+0x76),*(short*)(marker+0x78));
}}
if(*(unsigned short*)(self+0xae2)&0x200) {
data_0210a00c=0;
unsigned char* marker=self+0x894;
if(value>983 && *(short*)(marker+0x78)<192) {
*(unsigned*)(marker+0x4c)=0x300;
*(void**)(marker+0x14)=records+0x120;
*(int*)(marker+0x44)=9;
SetWordFieldsAtOffsets28And2C(marker,widths[0],heights[0]);
DispatchSelectedTwoDimensionalTableEntryWhenEnabled(marker,*(short*)(marker+0x76),*(short*)(marker+0x78));
}}
}
