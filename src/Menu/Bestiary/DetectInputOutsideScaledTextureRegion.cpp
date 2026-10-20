#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); }; struct Object3D { void SetScale(const Vector3i*); };
extern "C" {
struct Table {unsigned short first,count,n,m;unsigned flags;unsigned* base;unsigned char* relocBase;};
struct Stream { unsigned char data[0x14]; short index,active; int handle; void* source; };
struct Owner { unsigned char pad[0x3c]; SafeAllocator* allocators; Object3D* object; unsigned word;void* current;unsigned char pad2[0x20];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags,f82,gap[3];short tasks[5];unsigned char gap2[0x14];unsigned char list[0x10];SafeAllocator* arrays;void* head;void* node;void* service;unsigned words[7];unsigned char nested[0x7c];unsigned a,b,c;int handle;unsigned extra;short pane,index,extra2,page,last;unsigned char state,phase,other[2],options,closed;unsigned short field;short values[8]; };
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];int Input_IsKeyMaskNewlyPressed(void*,int);void ReadSelectedCoordinatePair(void*,int*,int*);int Geometry_TestPointWithinScaledTextureRectangle(void*,int,int,int);
// Original: arm9/ov014 @ 0x02186FF0; symbol: func_ov014_02186ff0; size: 0x84.
int DetectInputOutsideScaledTextureRegion(Owner* p){int found=0;if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2))found=1;if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]){int y,x;ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&y,&x);if(!Geometry_TestPointWithinScaledTextureRectangle(p->service,p->pane,(short)y,(short)x))found=1;}return found;}
}
