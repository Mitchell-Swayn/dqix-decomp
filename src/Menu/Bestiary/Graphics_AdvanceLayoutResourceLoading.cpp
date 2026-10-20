#include <globaldefs.h>
ARM
struct Camera;struct Record;struct GameState;struct GameResources;struct Catalog;struct Item;struct Layout;struct Input;
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void _ZN13SafeAllocator5ResetEv(void*);
void Menu_ResetLayout(char*);int LoadRelativeLayoutRecords(Layout*,unsigned,Input*,void*);
Item* BestiaryDetail_FindLayoutEntryByKey(Catalog*,int);
int ResourceFile_CountActiveStrideRecords(Record*);
char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
int Graphics_DispatchDataByResourceMagic(int,void*,int,int);
void Object_ConvertMappedKeyToTwoHalfwords(void*,int,short*,short*);
void* _ZN9GameState11GetInstanceEv();void* GameState_GetFieldOrbitCamera(GameState*);void GameState_SetUnknown3b0(GameState*,void*);
void Camera_InitializeTargetFollowingState(char*);void Camera_SetTargetCoordinates(int,unsigned,unsigned,unsigned);
void ComputeRotatedEndpointFromAngleHeightAndLength(char*,int,int,int);void Camera_UpdateRenderView(Camera*);void Camera_DisableTargetFollowing(int);
GameResources* GameResources_GetInstance();void GameResources_SetSecondaryFlags(int,unsigned);void GameResources_ClearSecondaryFlags(int,unsigned);
void Graphics_WriteHalfwordRegister35CAndDisplayControl(int,int,int,unsigned short);void G3X_SetClearColor(unsigned,unsigned,unsigned short,unsigned,int);
char* _ZN15LightingManager11GetInstanceEv();
// Original data: arm9/ov014 @ 0x2189800; symbol: data_ov014_02189800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern const char Graphics_AdvanceLayoutResourceLoading_PathDataAniLaySmlLia[],Graphics_AdvanceLayoutResourceLoading_PathDataAniObjSmiPac[];extern void* BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[];
}
#define F(t,o) (*(t*)(p+(o)))
static inline void SetPriority(volatile unsigned short* reg,unsigned priority) { *reg=(*reg&~3)|priority; }
// Original: arm9/ov014 @ 0x0218580C; symbol: func_ov014_0218580c; size: 0x430.
// Advances asynchronous layout/resource loading, initializes three positioned records and configures the display camera.
extern "C" void Graphics_AdvanceLayoutResourceLoading(unsigned char* p) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(p[0x7d]==0) {
  volatile unsigned short* reg=(volatile unsigned short*)0x0400000a;
  *reg=(*reg&0x43)|0x1f00;
  p[0x81]|=0x10;++p[0x7d];
 }
 if(p[0x7d]==1) {
  Menu_ResetLayout(F(char*,0x58));
  F(int,0x6c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Graphics_AdvanceLayoutResourceLoading_PathDataAniLaySmlLia,0);
  ++p[0x7d];
 }
 if(p[0x7d]==2 && _ZN16BackgroundLoader13GetTaskStatusEi(loader,F(int,0x6c))) {
  void* data;unsigned size;
  _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,F(int,0x6c),&data,&size);
  if(data) {
   unsigned char* alloc=F(unsigned char*,0x3c);
   _ZN13SafeAllocator5ResetEv(alloc+0x3c);
   LoadRelativeLayoutRecords(F(Layout*,0x58),(unsigned)(alloc+0x3c),(Input*)data,(void*)size);
   unsigned char* item=(unsigned char*)BestiaryDetail_FindLayoutEntryByKey(F(Catalog*,0x58),1);
   if(item)item[0x16]&=~1;
  }
  _ZN16BackgroundLoader10RemoveTaskEi(loader,F(int,0x6c));F(int,0x6c)=-1;
  F(int,0x6c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Graphics_AdvanceLayoutResourceLoading_PathDataAniObjSmiPac,0);
  ++p[0x7d];
 }
 if(p[0x7d]==3 && _ZN16BackgroundLoader13GetTaskStatusEi(loader,F(int,0x6c))) {
  char* block;char* data;unsigned size;unsigned blockSize;
  _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,F(int,0x6c),(void**)&data,&size);
  int count=ResourceFile_CountActiveStrideRecords((Record*)data);
  _ZN13SafeAllocator5ResetEv(F(unsigned char*,0x3c)+0x64);
  for(int i=0;i<count;i++) {
   char* entry=ResourceFile_GetPayloadByIndex(data,i,&block,&blockSize);
   if(entry) Graphics_DispatchDataByResourceMagic(F(int,4),entry,blockSize,(int)(F(unsigned char*,0x3c)+0x64));
  }
  short x=0,y=0;
  unsigned char* item=(unsigned char*)BestiaryDetail_FindLayoutEntryByKey(F(Catalog*,0x58),0x1a);
  if(item)item[0x16]&=~1;
  Object_ConvertMappedKeyToTwoHalfwords(F(void*,0x58),0x1a,&x,&y);
  unsigned char* record=F(unsigned char*,8);
  *(int*)(record+0x14)=x<<12;*(int*)(record+0x18)=y<<12;record[0x22]=0x21;record[0x26]=0;
  item=(unsigned char*)BestiaryDetail_FindLayoutEntryByKey(F(Catalog*,0x58),0x1b);
  if(item)item[0x16]&=~1;
  Object_ConvertMappedKeyToTwoHalfwords(F(void*,0x58),0x1b,&x,&y);
  record=F(unsigned char*,8);
  *(int*)(record+0x3c)=x<<12;*(int*)(record+0x40)=y<<12;record[0x4a]=0x22;record[0x4e]=0;
  Object_ConvertMappedKeyToTwoHalfwords(F(void*,0x58),0x14,&x,&y);
  record=F(unsigned char*,8);
  *(int*)(record+0x64)=x<<12;*(int*)(record+0x68)=y<<12;record[0x72]=0x20;record[0x76]=0;
  _ZN16BackgroundLoader10RemoveTaskEi(loader,F(int,0x6c));F(int,0x6c)=-1;++p[0x7d];
 }
 if(p[0x7d]==4) {
  volatile unsigned* display=(volatile unsigned*)0x04000000;
  volatile unsigned short* regs=(volatile unsigned short*)0x04000008;
  SetPriority(regs,0);SetPriority(regs+1,1);SetPriority(regs+2,2);SetPriority(regs+3,3);
  *display=(*display&~0x1f00)|0x1300;
  GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
  BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[3]=GameState_GetFieldOrbitCamera(game);
  Camera_InitializeTargetFollowingState(F(char*,0x44));
  Camera_SetTargetCoordinates(F(int,0x44),0,0,0);
  ComputeRotatedEndpointFromAngleHeightAndLength(F(char*,0x44),0,0,0xa000);
  Camera_UpdateRenderView((Camera*)F(void*,0x44));Camera_DisableTargetFollowing(F(int,0x44));GameState_SetUnknown3b0(game,F(void*,0x44));
  GameResources* resources=GameResources_GetInstance();
  GameResources_SetSecondaryFlags((int)resources,0x6093e);GameResources_ClearSecondaryFlags((int)resources,0x20);
  Graphics_WriteHalfwordRegister35CAndDisplayControl(0,0,0,0);G3X_SetClearColor(0,0,0x7fff,0,0);
  _ZN15LightingManager11GetInstanceEv()[0x85]=0;
  p[0x7c]=1;p[0x7d]=0;
 }
}
