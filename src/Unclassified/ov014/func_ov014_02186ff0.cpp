#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); }; struct Object3D { void SetScale(const Vector3i*); };
extern "C" {
struct Table {unsigned short first,count,n,m;unsigned flags;unsigned* base;unsigned char* relocBase;};
struct Stream { unsigned char data[0x14]; short index,active; int handle; void* source; };
struct Owner { unsigned char pad[0x3c]; SafeAllocator* allocators; Object3D* object; unsigned word;void* current;unsigned char pad2[0x20];int task,load,frame,otherTask;unsigned char f7c,f7d,count,active,selected,flags,f82,gap[3];short tasks[5];unsigned char gap2[0x14];unsigned char list[0x10];SafeAllocator* arrays;void* head;void* node;void* service;unsigned words[7];unsigned char nested[0x7c];unsigned a,b,c;int handle;unsigned extra;short pane,index,extra2,page,last;unsigned char state,phase,other[2],options,closed;unsigned short field;short values[8]; };
extern unsigned char data_02114e30[];extern unsigned char data_02114e54[];int Object_TestNewlySetHalfwordMask(void*,int);void ReadSelectedCoordinatePair(void*,int*,int*);int Geometry_TestPointWithinScaledTextureRectangle(void*,int,int,int);
// Original: arm9/ov014 @ 0x02186FF0; symbol: func_ov014_02186ff0; size: 0x84.
int func_ov014_02186ff0(Owner* p){int found=0;if(Object_TestNewlySetHalfwordMask(data_02114e30,2))found=1;if(data_02114e54[0x55]){int y,x;ReadSelectedCoordinatePair(data_02114e54,&y,&x);if(!Geometry_TestPointWithinScaledTextureRectangle(p->service,p->pane,(short)y,(short)x))found=1;}return found;}
}
