#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
#include <System/Interrupts.h>
struct Link { Link* previous; Link* next; };
struct SpriteNode {Link link;unsigned short base,count;};
struct SpritePool {unsigned char prefix[0x180];SpriteNode head,tail;unsigned unknown;unsigned char* ring;};
extern "C" SpritePool* UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage;
extern "C" void* WfcUtility_PopPointerRingBack(unsigned char*);
extern "C" void WfcUtility_InsertListNodeBefore(Link*,Link*);
extern "C" void DisableInterruptsAndHaltForever();
#define POOLS UnlinkAndNotifyOverlayOwner_UnknownRoleZeroInitializedStorage
// Original: arm9/ov031 @ 0x0223DB7C; symbol: func_ov031_0223db7c; size: 0x178.
// Allocates a sprite range from either end of the list while interrupts are masked.
extern "C" void* WfcUtility_AllocateObjectCharacterRange(int pool,int bytes,int fromFront,int* resultOffset){
 SpriteNode* result=(SpriteNode*)WfcUtility_PopPointerRingBack(POOLS[pool].ring);
 unsigned irq;int count=((bytes+3)&~3)>>2;result->count=count;
 SpriteNode* position;
 irq=DisableSpecificInterrupts(1);
 if(fromFront){
  position=&POOLS[pool].head;
  while(position!=&POOLS[pool].tail){
   SpriteNode* next=(SpriteNode*)position->link.next;
   int start=position->base+position->count;
   if(start+count<=next->base){result->base=start;WfcUtility_InsertListNodeBefore(&next->link,&result->link);break;}
   position=next;
  }
  if(position==&POOLS[pool].tail)DisableInterruptsAndHaltForever();
 }else{
  position=&POOLS[pool].tail;
  while(position!=&POOLS[pool].head){
   SpriteNode* previous=(SpriteNode*)position->link.previous;
   int start=position->base-count;
   if(start>=previous->base+previous->count){result->base=start;WfcUtility_InsertListNodeBefore(&position->link,&result->link);break;}
   position=previous;
  }
  if(position==&POOLS[pool].head)DisableInterruptsAndHaltForever();
 }
 *resultOffset=result->base;EnableSpecificInterrupts(irq);return result;
}
