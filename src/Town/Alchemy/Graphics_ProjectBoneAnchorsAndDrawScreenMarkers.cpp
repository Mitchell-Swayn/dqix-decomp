#include <globaldefs.h>
ARM
#pragma always_inline on
struct Vec {int x,y,z;};
extern "C" {
void TextCanvas_ClearDisplayLayerBuffers(unsigned char*);
void Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(void*);
void Graphics_ResetGeometryMatrixStackState();
void _ZN12RenderConfig12SubmitToFifoEv();
void _ZN8Object3D25UpdateTrackedBoneMatricesEv(void*);
void* _ZN9GameState11GetInstanceEv();
void* GameState_ReadUnknownB0(void*);
Vec _ZNK8Object3D8GetScaleEv(const void*);
void Vector3fix_Add(const void*,const void*,void*);
int Graphics_ConvertCopiedWorldVectorToScreenCoordinates(void*,const void*,int*,int*);
void* Graphics_GetGlobalOamTransferState();
char* Graphics_GetMainOamStagingBuffer();
int _ZNK8Object3D19HasAnimationStoppedEv(const void*);
void Sprite_SetScaleFactors(void*,int,int);
int Sprite_DrawSelectedAnimationCell(void*,int,int);
// Original data: arm9/ov006 @ 0x216038c; symbol: data_ov006_0216038c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern void* GraphicsCaptureMatchingSlotMatrices_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x210a00c; symbol: data_0210a00c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned GraphicsProjectBoneAnchorsAndDrawScreenMarkers_UnknownRoleZeroInitializedStorage;
}
struct Matrix {int v[12];};
struct Mapping {unsigned char v[4][4];};
struct Bits {unsigned char a:1,b:1,c:6;};
// Original data: arm9/ov006 @ 0x215ff6c; symbol: data_ov006_0215ff6c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000000001020000000102.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern "C" Mapping GraphicsProjectBoneAnchorsAndDrawScreenMarkers_UnknownRoleInitializedBytes;
static inline int MultiplyRounded(int a,int b) { return (int)(((long long)a*b+0x800LL)>>12); }
// Original: arm9/ov006 @ 0x02154A60; symbol: func_ov006_02154a60; size: 0x3F8.
extern "C" void Graphics_ProjectBoneAnchorsAndDrawScreenMarkers(unsigned char* self) {
if(((Bits*)(self+0x127f))->b || !self[0xadc]) return;
unsigned char* transfer=*(unsigned char**)(self+0x1d4);
TextCanvas_ClearDisplayLayerBuffers(transfer);
Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(transfer);
if(*(unsigned short*)(self+0xae2)&8) return;
Matrix matrices[3];
for(int i=0;i<3;i++) GraphicsCaptureMatchingSlotMatrices_UnknownRoleZeroInitializedStorage[i]=&matrices[i];
Graphics_ResetGeometryMatrixStackState();_ZN12RenderConfig12SubmitToFifoEv();
_ZN8Object3D25UpdateTrackedBoneMatricesEv(self+0x4e8);
for(int i=0;i<3;i++) GraphicsCaptureMatchingSlotMatrices_UnknownRoleZeroInitializedStorage[i]=0;
Vec positions[3];
positions[0].x=matrices[0].v[9];positions[0].y=matrices[0].v[10];positions[0].z=matrices[0].v[11];
positions[1].x=matrices[1].v[9];positions[1].y=matrices[1].v[10];positions[1].z=matrices[1].v[11];
positions[2].x=matrices[2].v[9];positions[2].y=matrices[2].v[10];positions[2].z=matrices[2].v[11];
int widths[3];widths[0]=matrices[0].v[0];widths[1]=matrices[1].v[0];widths[2]=matrices[2].v[0];
int heights[3];heights[0]=matrices[0].v[4];heights[1]=matrices[1].v[4];heights[2]=matrices[2].v[4];
for(int i=0;i<3;i++) {if(widths[i]<40) widths[i]=40;if(heights[i]<40) heights[i]=40;}
unsigned group=self[0x12bb];
Mapping mapping=GraphicsProjectBoneAnchorsAndDrawScreenMarkers_UnknownRoleInitializedBytes;
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
Graphics_GetGlobalOamTransferState();char* records=Graphics_GetMainOamStagingBuffer();
unsigned char* marker;unsigned char i;int value=*(int*)(self+0x308);
if((*(unsigned short*)(self+0xae2)&0x2000 || *(unsigned short*)(self+0xae2)&0x80) && !_ZNK8Object3D19HasAnimationStoppedEv(self+0x4e8)) {
marker=self+0x910;
for(i=1;i<4;marker+=124,i++) {
unsigned index=mapping.v[group][i];
*(unsigned*)(marker+0x4c)=0x300;
*(void**)(marker+0x14)=records+8*(32+i*4);
*(int*)(marker+0x44)=(32+i*4)/4;
Sprite_SetScaleFactors(marker,widths[index],heights[index]);
Sprite_DrawSelectedAnimationCell(marker,*(short*)(marker+0x76),*(short*)(marker+0x78));
}}
if(*(unsigned short*)(self+0xae2)&0x200) {
GraphicsProjectBoneAnchorsAndDrawScreenMarkers_UnknownRoleZeroInitializedStorage=0;
unsigned char* marker=self+0x894;
if(value>983 && *(short*)(marker+0x78)<192) {
*(unsigned*)(marker+0x4c)=0x300;
*(void**)(marker+0x14)=records+0x120;
*(int*)(marker+0x44)=9;
Sprite_SetScaleFactors(marker,widths[0],heights[0]);
Sprite_DrawSelectedAnimationCell(marker,*(short*)(marker+0x76),*(short*)(marker+0x78));
}}
}
