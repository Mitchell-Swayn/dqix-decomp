#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#include <System/Matrix.h>
struct Display{virtual void V0();virtual void V1();virtual void V2();virtual void V3();virtual void V4();virtual void V5();virtual void V6();virtual void SetPosition(const Vector3i&);virtual Vector3i GetPosition();unsigned char extra[54];};extern "C" {int Graphics_GetRecordTextWidth(void*,unsigned);void* Menu_GetDisplayRecordRegistry(void*);void* MenuRecordList_LocateByKey(void**,unsigned short);}
// Original: arm9/ov004 @ 0x0216B390; symbol: Graphics_PositionRelatedObjectAfterRecordText; size: 0x108.
// Positions related virtual graphics object after selected text width, applying mode-specific vertical coordinate.
extern "C" void TitleMenu_PositionCursorAfterTextLabel(void* self,int id,int mode){int width=((int(*)(void*,short))Graphics_GetRecordTextWidth)(self,(short)id);Display* source=(Display*)((void*(*)(void**,int))MenuRecordList_LocateByKey)((void**)Menu_GetDisplayRecordRegistry(self),id);if(!source)return;Vector3i position;position=source->GetPosition();position.x+=(width+10)<<12;Display* target=(Display*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),12);if(!target)return;Vector3i destination;destination=target->GetPosition();destination.x=position.x;if(mode==0)destination.y=0x24000;else if(mode==1)destination.y=0x34000;else if(mode==2)destination.y=0x42000;else if(mode==3)destination.y=0x1b000;target->SetPosition(destination);((unsigned char*)target)[0x3a]=0;}
