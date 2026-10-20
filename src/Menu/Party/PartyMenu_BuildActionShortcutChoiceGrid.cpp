struct PartyMenuState;
#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" void PartyMenu_ReadCanvasBounds(PartyMenuState*,int,short*,short*,short*,short*);
extern "C" unsigned Text_AppendPagedLookupGrid(...);
extern "C" unsigned Window_PushTextCanvas(...);
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
extern "C" unsigned memset(...);
// Original: arm9/ov002 @ 0x021609d4; symbol: Graphics_RebuildPagedLookupGridFromRecordBounds; size: 0xcc.
extern "C" void PartyMenu_BuildActionShortcutChoiceGrid(unsigned self){
short bounds[4];bounds[3]=0;bounds[2]=0;bounds[1]=1;bounds[0]=1;
PartyMenu_ReadCanvasBounds((PartyMenuState*)(self),33,(short*)(D(&bounds[3])),(short*)(D(&bounds[2])),(short*)(D(&bounds[1])),(short*)(D(&bounds[0])));bounds[3]+=12;
PartyMenu_ConfigurePanelLayout((PartyMenuState*)(self),U32(self+0x1bb8)&255,4,bounds[2]);memset(U32(self+0x1bd0),0,0x960);Text_AppendPagedLookupGrid(self,U32(self+0x1bd0),0);Window_PushTextCanvas(self+0xec8,U32(self+0x1bd0),0,0,1,1,0,0);
}