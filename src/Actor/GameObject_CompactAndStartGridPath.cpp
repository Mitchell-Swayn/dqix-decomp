#include <globaldefs.h>
#include <World/Object3D.h>
#pragma opt_propagation off
#pragma opt_common_subs off
ARM
union Pair { struct { int x,y; }; long long packed; };
struct GridPathComponent { unsigned char unknown0[0x20]; unsigned flags; unsigned char indices[16]; unsigned char count; unsigned char unknown35[11]; int x; int unknown44; int y; };
extern "C" void BattleGrid_GetCellCoordinates(Pair*,int*);
// Original: arm9/main @ 0x02048E2C; symbol: GameObject_CompactAndStartGridPath; size: 0x138.
// Removes adjacent repeated grid indices, then drops reached leading waypoints.
// The linked component is reloaded after byte stores because its owner may alias.
extern "C" void GameObject_CompactAndStartGridPath(Object3D* object)
{
 unsigned char* self=(unsigned char*)object;
 {
 int previous;
 int index;
 int count;
 GridPathComponent* linked=*(GridPathComponent**)(self+0x13c);
 if (!linked) return;
 count=1;
 previous=linked->indices[0];
 for (index=1;index<linked->count;++index) {
  unsigned char* indices=linked->indices;
  int current=indices[index];
  if (previous!=current) {
   (*(GridPathComponent**)(self+0x13c))->indices[count]=current;
   linked=*(GridPathComponent**)(self+0x13c);
   ++count;
   previous=linked->indices[index];
  }
 }
 linked->count=count;
 }
 unsigned remaining;
 GridPathComponent* head=*(GridPathComponent**)(self+0x13c);
 remaining=head->count;
 if (remaining<=1) {head->count=0;return;}
 GridPathComponent* linked;
 for (;;) {
  Pair copy;
  Pair coordinate;
  int index=head->indices[1];
  BattleGrid_GetCellCoordinates(&coordinate,&index);
  copy=coordinate;
  linked=*(GridPathComponent**)(self+0x13c);
  if (linked->x!=copy.x || linked->y!=copy.y) break;
  --linked->count;
  head=*(GridPathComponent**)(self+0x13c);
  if (head->count<=1) {head->count=0;return;}
  for (int i=1;i<(*(GridPathComponent**)(self+0x13c))->count;++i) {
   GridPathComponent* component=*(GridPathComponent**)(self+0x13c);
   component->indices[i]=component->indices[i+1];
  }
  head=*(GridPathComponent**)(self+0x13c);
 }
 linked->flags|=0x10;
}
