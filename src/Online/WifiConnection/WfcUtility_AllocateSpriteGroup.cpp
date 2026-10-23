#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
#include <System/Interrupts.h>
struct Link { Link* previous; Link* next; };
struct SpriteNode {Link link;unsigned base;unsigned char count,pad[3];};
struct SpritePool {unsigned char prefix[0x200];SpriteNode head,tail;unsigned unknown;unsigned char* ring;};
extern "C" SpritePool* WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage;
extern "C" void* WfcUtility_PopPointerRingBack(unsigned char*);
extern "C" void WfcUtility_InsertListNodeBefore(Link*,Link*);
extern "C" void DisableInterruptsAndHaltForever();
#define POOLS WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage
// Original: arm9/ov031 @ 0x0223B8C4; symbol: func_ov031_0223b8c4; size: 0x15C.
// Allocates a sprite range from either end of the list while interrupts are masked.
extern "C" void* WfcUtility_AllocateSpriteGroup(int pool,unsigned count,int fromFront){
 SpriteNode* result=(SpriteNode*)WfcUtility_PopPointerRingBack(POOLS[pool].ring);
 SpriteNode* position;
 unsigned irq=DisableSpecificInterrupts(1);
 if(fromFront){
  position=&POOLS[pool].head;
  while(position!=&POOLS[pool].tail){
   SpriteNode* next=(SpriteNode*)position->link.next;
   unsigned start=position->base+position->count*8;
   if(start+count*8<=next->base){result->base=start;WfcUtility_InsertListNodeBefore(&next->link,&result->link);break;}
   position=next;
  }
  if(position==&POOLS[pool].tail)DisableInterruptsAndHaltForever();
 }else{
  position=&POOLS[pool].tail;
  while(position!=&POOLS[pool].head){
   SpriteNode* previous=(SpriteNode*)position->link.previous;
   unsigned start=position->base-count*8;
   if(start>=previous->base+previous->count*8){result->base=start;WfcUtility_InsertListNodeBefore(&position->link,&result->link);break;}
   position=previous;
  }
  if(position==&POOLS[pool].head)DisableInterruptsAndHaltForever();
 }
 EnableSpecificInterrupts(irq);result->count=count;return result;
}
