#include <globaldefs.h>
ARM
struct GameState;
struct Object { char pad[0x178]; signed char kinds[5]; signed char selected; };
struct Words3 { int x,y,z; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(GameState*);
extern "C" int Graphics_ConvertCopiedWorldVectorToScreenCoordinates(void*,const Words3*,int*,int*);
extern "C" bool SystemState_TestAnyFlags(const unsigned int*,unsigned int);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void Graphics_DrawSelectedResource(char*,unsigned);
// Original: arm9/main @ 0x0205337C; symbol: func_0205337c; size: 0x130.
// Projects the object's elevated position, adjusts the selected signed-byte kind,
// and draws its attached resource at fixed-point screen coordinates.
extern "C" void Graphics_DrawProjectedAttachedResource(char* self) {
 if (!SystemState_TestAnyFlags((const unsigned int*)SystemState_GetGlobalFlags(),2) && *(char**)(self+0x190)) {
  void* context=GameState_ReadUnknownB0((GameState*)_ZN9GameState11GetInstanceEv());
  *(volatile unsigned*)0x04000444=0;
  Words3 position=*(Words3*)(self+0x44);
  position.y+=0x1b33;
  int x,y;
  Graphics_ConvertCopiedWorldVectorToScreenCoordinates(context,&position,&x,&y);
  x-=12; y-=12;
  Object* object=(Object*)self;
  int kind=object->kinds[object->selected];
  if(object->kinds[object->selected]==12 || object->kinds[object->selected]==13 || object->kinds[object->selected]==14) {x-=12;y-=6;}
  else if(kind==30) {y+=4;x+=4;}
  int screenX=x,screenY=y;
  char* resource=*(char**)(self+0x190);
  *(int*)(resource+0x1c)=screenX<<12;
  *(int*)(resource+0x20)=screenY<<12;
  *(int*)(resource+0x24)=-0xa000;
  Graphics_DrawSelectedResource(*(char**)(self+0x190),1);
  *(volatile unsigned*)0x04000448=1;
 }
}
