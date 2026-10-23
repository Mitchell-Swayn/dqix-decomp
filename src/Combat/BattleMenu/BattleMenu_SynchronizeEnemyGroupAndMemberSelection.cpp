#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_repositioncode off
#pragma force_active on
#define WORD(p,o) (*(int*)((p)+(o)))
#define HALF(p,o) (*(short*)((p)+(o)))
#define UHALF(p,o) (*(unsigned short*)((p)+(o)))
#define BYTE(p,o) (*(unsigned char*)((p)+(o)))
#define SBYTE(p,o) (*(signed char*)((p)+(o)))
#define PTR(p,o) (*(char**)((p)+(o)))
struct GridSelection;
extern "C" {
int Grid_UpdateDirectionalSelection(void*,int);
int Selection_ReadEnabledIndexFromControl(void*);
int Grid_ComputeSelectedLinearIndex(int*);
int BattleMenu_GetEnemyTargetGroupIndex(unsigned char*,int);
void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
void Window_SetEnabledSelectionIndices(unsigned char*,int);
}
// Original: arm9/ov000 @ 0x0217F304; symbol: func_ov000_0217f304; size: 0xE0.
// Synchronizes the member index and transition-counted group grid for command types 14 and 25.
extern "C" void BattleMenu_SynchronizeEnemyGroupAndMemberSelection(char* self,int unused,int count,char* actor) {
    if(!actor) return;
    int member;
    signed char command=SBYTE(actor+SBYTE(actor,0x18),0x10);
    if(command!=14 && command!=25) return;
    Grid_UpdateDirectionalSelection(self+0x244,1);
    member=Selection_ReadEnabledIndexFromControl(self+0x188);
    int group=Grid_ComputeSelectedLinearIndex((int*)(self+0x244));
    int previousMember=SBYTE(actor,0x1d);
    int selectedGroup=BattleMenu_GetEnemyTargetGroupIndex((unsigned char*)self,member);
    if(command==25) previousMember=SBYTE(self,0x1c);
    if(member!=previousMember) {
        Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(self+0x244),selectedGroup);
        return;
    }
    if(group==selectedGroup) return;
    int previous=-1, currentGroup=-1;
    for(int i=0;i<count;++i) {
        int id=WORD(self+i*4,0x1d1c);
        if(previous!=id) {
            ++currentGroup;
            previous=id;
            if(group==currentGroup) {
                Window_SetEnabledSelectionIndices((unsigned char*)self+0x188,i);
                WORD(self,0x118)=1;
                return;
            }
        }
    }
}
