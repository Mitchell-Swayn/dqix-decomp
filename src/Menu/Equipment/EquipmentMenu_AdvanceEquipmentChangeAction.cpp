#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" void EquipmentMenu_ChangeCharacterEquipment(char*,int,int);
// Original: arm9/ov005 @ 0x0215916C; symbol: AdvanceSelectionLoadTwoStepState; size: 0x9c.
extern "C" void EquipmentMenu_AdvanceEquipmentChangeAction(char* self){
int state=B(self,0x3ddc);if(!state){int index=*(signed char*)(self+0x3dbb);if(index>=0&&index<8)EquipmentMenu_ChangeCharacterEquipment(self,65535,0);else if(index>=8&&index<24)EquipmentMenu_ChangeCharacterEquipment(self,*(short*)(self+index*28+0x2d90),0);B(self,0x3ddc)++;}else if(state==1){B(self,0x3ddf)=4;B(self,0x3ddc)=0;}
}
