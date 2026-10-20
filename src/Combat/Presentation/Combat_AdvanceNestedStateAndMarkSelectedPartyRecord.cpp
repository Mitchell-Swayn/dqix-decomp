#include <globaldefs.h>
ARM
extern "C" char* BattleScene_ResolveCurrentActionRecord(char*);
extern "C" void Combat_AdvanceActionPresentation(void*);
extern "C" int Combat_IsActionProgramAndMessageQueueIdle(void*);
extern "C" int BattleScene_FinishCurrentActionPresentation(void*);
extern "C" void Scene_CancelLoadsAndRestoreObjects(void*);
extern "C" void BattleScene_AdvanceActionCommand(char*);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Flags {unsigned char low:2,blocked:1,high:5;};
// Original: arm9/ov025 @ 0x021DC590; symbol: Combat_AdvanceNestedStateAndMarkSelectedPartyRecord; size: 0x104.
extern "C" void Combat_AdvanceNestedStateAndMarkSelectedPartyRecord(char* self){char* resolved=BattleScene_ResolveCurrentActionRecord(self);Combat_AdvanceActionPresentation(self+0x2a8);if(!Combat_IsActionProgramAndMessageQueueIdle(self+0x2a8))return;if(!BattleScene_FinishCurrentActionPresentation(self))return;Scene_CancelLoadsAndRestoreObjects(self+0x2a8);char* node=P(resolved,16);if(node){int index=H(node,32);unsigned char valid=index>=0&&index<=3;if(valid){char* found;unsigned char validAgain=index>=0&&index<=3;if(validAgain){for(int i=0;i<4;++i){char* row=self+i*0x448;if(index==W(row,0x4104)){found=self+0x40b8+i*0x448;goto foundRecord;}}}found=0;foundRecord:if(found&&!((Flags*)(resolved+11))->blocked)B(found+*(signed char*)(found+24),16)=102;}}BattleScene_AdvanceActionCommand(self);}