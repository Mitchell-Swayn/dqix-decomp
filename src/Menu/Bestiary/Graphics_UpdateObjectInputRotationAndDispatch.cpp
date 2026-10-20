#include <globaldefs.h>
ARM
struct Bits { unsigned char active:1; unsigned char rest:7; };
struct Owner { char pre[12]; char list[0x34]; unsigned char* object; unsigned pad44; unsigned char* record; char gap[0x30]; unsigned char index; char pad7d[5]; Bits flags; char pad83[13]; unsigned char left,right,changed; };
typedef void (Owner::*Action)();
struct Vector {int x,y,z;};
struct GameState;
extern "C" {
int strcmp(const char*,const char*);
void* _ZN9GameState11GetInstanceEv();
unsigned _ZNK9GameState12GetTickCountEv(GameState*);
int Input_TestKeyMask(unsigned short*,unsigned short);
int Input_IsKeyMaskReleased(unsigned short*,unsigned int);
Vector* _ZN8Vector3iaSERKS_(Vector*,const Vector*);
void _ZN8Object3D14AdvanceEffectsEv(void*);
void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);
bool _ZNK8Object3D19HasAnimationStoppedEv(void*);
bool _ZNK8Object3D22HasAnimationReachedEndEv(void*);
void* BestiaryInfo_FindMonsterRecord(void*,int);
void BestiaryDetail_QueueDefaultBackgroundLoad(Owner*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov014 @ 0x21895ce; symbol: data_ov014_021895ce.
// Source-defined character literal. Text: "run". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "run".
// Observed span: 7 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern char BestiaryDetail_PlayNextMonsterAnimation_TextStand[],BestiaryDetailPlayNextMonsterAnimation_TextRunWithAdjacentText[];
// Original data: arm9/ov014 @ 0x2189800; symbol: data_ov014_02189800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern unsigned BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Action ShopUpdateInterface_UnknownRoleInitializedBytes;
// Original data: arm9/ov014 @ 0x21895a0; symbol: data_ov014_021895a0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000f0410000f0410000344300003443.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern Action GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleInitializedBytes[];
// Original data: arm9/ov014 @ 0x21895b0; symbol: data_ov014_021895b0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0c581802000000003c5c1802000000000000000000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern Action GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleProcedureReferenceRecords[];
}
// Original: arm9/ov014 @ 0x02184700; symbol: func_ov014_02184700; size: 0x364.
// Updates input rotation relative to a mapped record and dispatches the indexed member handler.
extern "C" void Graphics_UpdateObjectInputRotationAndDispatch(Owner* self) {
Vector updatedRotation,returningRotation;
int base; unsigned char* obj; int current; int delta; int next; int changed;
BestiaryDetail_QueueDefaultBackgroundLoad(self);
if(self->object) {
_ZN8Object3D14AdvanceEffectsEv(self->object);
base=0;
unsigned char* record=self->record;
if(record) {
unsigned char* found=(unsigned char*)BestiaryInfo_FindMonsterRecord(self->list,*(short*)(record+12));
if(found) base=(int)(4096.0f**(float*)(found+0x1c));
}
obj=self->object;
current=self->flags.active;
if(!obj) next=0;
else {
changed=0;
self->left=0;
next=current;
delta=0;
self->right=0;
if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200) && Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100)) {
if(!current) {next=1;self->left=1;self->right=1;}
} else if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200) && !Input_IsKeyMaskReleased(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100)) {
changed=1;self->left=1;delta=204;
} else if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100) && !Input_IsKeyMaskReleased(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200)) {
changed=1;self->right=1;delta=-204;
}
if(current) {
_ZN8Vector3iaSERKS_(&returningRotation,(Vector*)(obj+0x50));
int distance=base-returningRotation.y;
if(returningRotation.y>=base+0x3243) distance=base+0x6487-returningRotation.y;
delta=distance;
delta/=5;
if(!Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100) && !Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200) && returningRotation.y==base) next=0;
}
if(changed || current) {
delta=delta*_ZNK9GameState12GetTickCountEv((GameState*)_ZN9GameState11GetInstanceEv());
_ZN8Vector3iaSERKS_(&updatedRotation,(Vector*)(obj+0x50));
updatedRotation.y+=delta;
if(current) {
if(updatedRotation.y<base+204 || updatedRotation.y>base+0x63bb) updatedRotation.y=base;
if(!self->left || !self->right || updatedRotation.y==base) {self->left=0;self->right=0;}
}
if(updatedRotation.y<0) updatedRotation.y+=0x6487;
if(updatedRotation.y>=0x6487) updatedRotation.y-=0x6487;
_ZN8Vector3iaSERKS_((Vector*)(obj+0x50),&updatedRotation);
}}
*(unsigned char*)&self->flags=(*(unsigned char*)&self->flags&~1)|(next&1);
if(_ZNK8Object3D19HasAnimationStoppedEv(self->object) || _ZNK8Object3D22HasAnimationReachedEndEv(self->object)) {
obj=self->object;
char* name=*(char**)(obj+0x14);
if(name && strcmp(BestiaryDetail_PlayNextMonsterAnimation_TextStand,name) && strcmp(BestiaryDetailPlayNextMonsterAnimation_TextRunWithAdjacentText,name)) _ZN8Object3D18SetAnimationByNameEPKci(obj,BestiaryDetail_PlayNextMonsterAnimation_TextStand,0);
}
}
self->changed=0;
unsigned flags=BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[1];
if(!(flags&1)) {
GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleInitializedBytes[4]=ShopUpdateInterface_UnknownRoleInitializedBytes;
BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[1]=flags|1;
}
if(GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleProcedureReferenceRecords[self->index]) (self->*GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleProcedureReferenceRecords[self->index])();
}
