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
extern "C" {
char* BattleMenu_FindPartyCommandRecord(char*,int);
void BattleMenu_PositionStackedWindowsWithinScreen(void*,int,int);
void Window_RefreshSelectionGeometry(unsigned char*);
// Original data: arm9/ov000 @ 0x02183548/4a/4c; stride-six signed halfword columns.
extern short BattleMenuRepositionCommandWindowsAroundActor_UnknownRoleInitializedBytes_Variant2[];
extern short BattleMenuRepositionCommandWindowsAroundActor_UnknownRoleInitializedBytes_Variant3[];
extern short BattleMenuRepositionCommandWindowsAroundActor_UnknownRoleInitializedBytes_Variant4[];
// Original data: arm9/ov000 @ 0x021834d4; canvas-id pairs terminated by 0xff.
extern unsigned char BattleMenuRepositionCommandWindowsAroundActor_UnknownRoleInitializedBytes[];
}
// Original: arm9/ov000 @ 0x0217A8F4; symbol: func_ov000_0217a8f4; size: 0xDC.
// Offsets seven canvases from actor coordinates using signed halfword table columns, then applies paired-window constraints.
extern "C" void BattleMenu_RepositionCommandWindowsAroundActor(char* self) {
    char* actor=BattleMenu_FindPartyCommandRecord(self,WORD(self,0x17c));
    if(!actor) return;
    int x=WORD(actor,0x44), y=WORD(actor,0x48);
    char* canvas;
    for(int i=0;i<7;++i) {
        canvas=self+0x284+i*0xe0;
        unsigned id=BYTE(canvas,0xc4);
        int tableId;
        for(int j=0;(tableId=HALF((char*)BattleMenuRepositionCommandWindowsAroundActor_UnknownRoleInitializedBytes_Variant2+j*6,0))>0;++j) {
            if(id==tableId) {
                HALF(canvas,0xac)=HALF((char*)BattleMenuRepositionCommandWindowsAroundActor_UnknownRoleInitializedBytes_Variant3+j*6,0)+(x>>3);
                HALF(canvas,0xae)=HALF((char*)BattleMenuRepositionCommandWindowsAroundActor_UnknownRoleInitializedBytes_Variant4+j*6,0)+(y>>3);
                break;
            }
        }
    }
    unsigned char* pair=BattleMenuRepositionCommandWindowsAroundActor_UnknownRoleInitializedBytes;
    for(;;) {
        unsigned first=pair[0];
        if(first==0xff) break;
        BattleMenu_PositionStackedWindowsWithinScreen(self+0x188,first,pair[1]);
        pair+=2;
    }
    Window_RefreshSelectionGeometry((unsigned char*)self+0x188);
}
