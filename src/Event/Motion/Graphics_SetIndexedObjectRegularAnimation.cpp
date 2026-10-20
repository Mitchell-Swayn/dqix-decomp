#include <globaldefs.h>
ARM
struct Entry { unsigned kind,unknown[2]; unsigned char* object; };
extern "C" void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);
// Original: arm9/ov001 @ 0x02164578; symbol: func_ov001_02164578; size: 0xAC.
extern "C" int Graphics_SetIndexedObjectRegularAnimation(Entry* entries,int index,const char* animation,int flag) {
 if(index<0 || index>=32) return 0;
 Entry* entry=&entries[index];
 switch(entry->kind) {
 case 0: case 1: case 4: case 5:
  if(!entry->object) return 0;
  _ZN8Object3D18SetAnimationByNameEPKci(entry->object,animation,flag);
  return 1;
 case 6:
  if(!entry->object) return 0;
  { void* object=*(void**)(entry->object+0x18);
  if(!object) return 0;
  _ZN8Object3D18SetAnimationByNameEPKci(object,animation,flag);
  return 1; }
 default: return 0;
 }
}
