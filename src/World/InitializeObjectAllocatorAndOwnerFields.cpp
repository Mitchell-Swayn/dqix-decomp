#include <globaldefs.h>
#include <World/Object3D.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original: arm9/main @ 0x02046E08; symbol: func_02046e08; size: 0x68.
void InitializeObjectAllocatorAndOwnerFields(char *p){*(int *)p=0;*(int *)(p+4)=0;*(int *)(p+32)=0;*(int *)(p+8)=0;*(float *)(p+12)=15.0f;*(int *)(p+0xec)=-1;p[28]=1;p[29]=1;((Object3D *)(p+60))->Initialize();((SafeAllocator *)(p+36))->ResetAllocatorPointer();*(int *)(p+56)=0;*(int *)(p+0xe8)=0;*(int *)(p+16)=0;*(int *)(p+20)=0;*(int *)(p+24)=0;}
}
