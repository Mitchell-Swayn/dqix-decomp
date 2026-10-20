#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned TextContext_GetSharedInstance(...);
extern "C" unsigned KrakPot_ReleaseRecipeInventoryContext(...);
extern "C" unsigned _ZN13SafeAllocator7DestroyEv(...);
extern "C" unsigned _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" unsigned _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" unsigned _ZNK13SafeAllocator18GetSignedAllocatorEv(...);
extern "C" unsigned DestroySceneResourceOwnerAndReset(...);
// Original: arm9/ov006 @ 0x02157CC0; symbol: DestroyLoadedObjectTasksAndTenAllocators; size: 0xbc.
// Destroys loaded object and two tasks, clears owner state, destroys ten present allocators.
extern "C" void KrakPot_DestroyMenuResources(char* p){
 if(U(p,16)){DestroySceneResourceOwnerAndReset(U(p,16));U(p,16)=0;}unsigned loader=_ZN16BackgroundLoader11GetInstanceEv();
 if((int)U(p,0x354)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,U(p,0x354));U(p,0x354)=-1;}
 if((int)U(p,0x358)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,U(p,0x358));U(p,0x358)=-1;}
 KrakPot_ReleaseRecipeInventoryContext(p+0x74);U(TextContext_GetSharedInstance(),0x2d8)=0;
 if(U(p,12))for(unsigned char i=0;i<10;i++){unsigned offset=i*20;if(_ZNK13SafeAllocator18GetSignedAllocatorEv(U(p,12)+offset))_ZN13SafeAllocator7DestroyEv(U(p,12)+offset);}
}
