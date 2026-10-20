#include <globaldefs.h>
ARM
extern "C" {
void __clear(void*,unsigned);
void* _ZN9GameState11GetInstanceEv();
void* _ZN9GameState20GetUnknownGameObjectEv(void*);
void* GameState_GetFieldVisualObject(void*);
int Input_TestKeyMask(unsigned short*,unsigned short);
int ReadSelectedCoordinatePair(void*,int*,int*);
void* Zone3D_GetMainInstance();
bool GameObject_IsMovementPauseActive(char*);
void GameObject_RequestMovementInputEnable(void*);
void GameObject_DisableMovementInput(void*,int);
int GameObject_GetLadderTraversalActive(void*);
unsigned TextContext_GetSharedInstance();
bool SystemState_TestAnyFlags(const unsigned*,unsigned);
bool LinkedQueue_IsEmpty(const int*);
int LinkedQueue_GetFrontKindOrInvalid(char**);
bool GameObject_HasQueuedActions(signed char*);
void FieldVisualActor_EnableMovementInput(void*);
void FieldVisualActor_DisableMovementInput(void*);
void* SystemState_GetGlobalFlags();
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
}
// Original: arm9/ov017 @ 0x0219A6B8; symbol: func_ov017_0219a6b8; size: 0x3A4.
extern "C" void Input_UpdateTouchRectangleDrag(unsigned char* self) {
 unsigned char *modes, *ys, *xs;
 void* linked;
 unsigned id;
 int i;
 void* state=_ZN9GameState11GetInstanceEv();
 TextContext_GetSharedInstance();
 id=*(unsigned short*)Zone3D_GetMainInstance();
 unsigned* flags=(unsigned*)SystemState_GetGlobalFlags();
 if(!LinkedQueue_IsEmpty(*(int**)(self+0x36fc)))return;
 if(LinkedQueue_GetFrontKindOrInvalid(*(char***)(self+0x36fc))==2)return;
 if(SystemState_TestAnyFlags(flags,0x800))return;
 void* object=_ZN9GameState20GetUnknownGameObjectEv(state);
 if(!object)return;
 linked=GameState_GetFieldVisualObject(state);
 if(GameObject_HasQueuedActions((signed char*)object))return;
 if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2) && !self[0x3658])return;
 if(GameObject_IsMovementPauseActive((char*)object))return;
 if(GameObject_GetLadderTraversalActive(object))return;
 if(id==0x2774)return;
 int indices[1]={0};
 i=0;
 for(;i<1;i++) {
   ys=self+0x3646;xs=self+0x3634;modes=self+0x3658;
   int index=indices[i];
   int w=24,h=24;
   if(index==0){w=32;h=32;}
   if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]) {
     int x,y;
     ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
     if(xs[index]<x && x<xs[index]+w && ys[index]<y && y<ys[index]+h){
       GameObject_DisableMovementInput(object,1);
       if(linked && id==0x2710)FieldVisualActor_DisableMovementInput(linked);
       (self+index)[0x3658]=1;
     }
   } else if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x5f] && *(unsigned short*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x24)) {
     int x,y;
     ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
     if(modes[index]==1){
       if(!(xs[index]<x && x<xs[index]+w && ys[index]<y && y<ys[index]+h))modes[index]=2;
     } else if(modes[index]==2){
       int nx=(x-12+xs[index])/2,ny=(y-12+ys[index])/2;
       if(nx<0)nx=0;
       if(256-w<nx)nx=256-w;
       if(ny<0)ny=0;
       if(192-h<ny)ny=192-h;
       xs[index]=nx;ys[index]=ny;
     }
   } else if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x54]) {
     if(modes[index]){
       GameObject_RequestMovementInputEnable(object);
       if(linked && id==0x2710)FieldVisualActor_EnableMovementInput(linked);
     }
     if(modes[index]==1){
       self[0x42e4]=1;
       GameObject_RequestMovementInputEnable(object);
       if(linked && id==0x2710)FieldVisualActor_EnableMovementInput(linked);
     }
     modes[index]=0;
   } else if(modes[index]){
     GameObject_RequestMovementInputEnable(object);
     if(linked && id==0x2710)FieldVisualActor_EnableMovementInput(linked);
     modes[index]=0;
   }
   if((self+index)[0x3658])break;
 }
}
