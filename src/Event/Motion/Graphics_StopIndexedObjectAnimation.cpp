#include <globaldefs.h>
ARM
struct Entry { int kind; int a,b; unsigned char* object; };
extern "C" void _ZN8Object3D20StopCurrentAnimationEv(void*);
// Original: arm9/ov001 @ 0x021646B8; symbol: func_ov001_021646b8; size: 0x9C.
extern "C" int Graphics_StopIndexedObjectAnimation(Entry* entries,int index) {
if(index<0 || index>=32)return 0;
Entry* entry=&entries[index];
switch(entry->kind){
case 0:case 1:case 4:case 5:
if(!entry->object)return 0;
_ZN8Object3D20StopCurrentAnimationEv(entry->object);return 1;
case 6:
if(!entry->object)return 0;
unsigned char* object=*(unsigned char**)(entry->object+0x18);
if(!object)return 0;
_ZN8Object3D20StopCurrentAnimationEv(object);return 1;
}
return 0;
}
