#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
// Original recomputes field addresses across calls; preserve that compiler behavior.
#pragma opt_common_subs off
struct MenuLayout { char prefix[0xec8]; unsigned char grids[0xa4]; };
struct GridSelection;
struct State;
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
extern "C" void Grid_SetEntryCountAndClampSelection(int*,int);
extern "C" void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
extern "C" void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);
extern "C" void Selection_EnableTouchInput(int);
extern "C" void Selection_EnableDirectionalInput(int);
extern "C" void Selection_DisableTouchInput(int);
extern "C" void Selection_DisableDirectionalInput(int);
extern "C" unsigned char TreasureMapCollection_ReadMapCount();
extern "C" int CountEligiblePartyEntriesAfterExclusions();
extern "C" int GameState_CountRecordsForCategory(void*,int);
extern "C" void PartyMenu_BuildAvailableConnectionActions(char*,short*,short*);
#define W(o) (*(int*)(self+(o)))
#define S(o) (*(short*)(self+(o)))
#define B(o) (*(unsigned char*)(self+(o)))
#define C(o) (*(signed char*)(self+(o)))
// Original: arm9/ov002 @ 0x02161CF0; symbol: PartyMenu_ConfigureSelectionForCurrentScreen; size: 0x5FC.
// Configures paired selection grids for the current category; category semantics remain uncertain.
extern "C" void PartyMenu_ConfigureSelectionForCurrentScreen(char* self) {
register int height,count,pages,index;
register char* grid=self+0xec8;
register int width;
GameState::GetInstance();
register int orientation=0;
Selection_EnableTouchInput((int)((MenuLayout*)self)->grids);Selection_EnableDirectionalInput((int)((MenuLayout*)self)->grids);

switch((unsigned)W(0x1bb8)) {
case 1: width=2;height=3;count=6;pages=1;index=S(0x1be0);break;
case 2:width=1;height=count=C(0x1c73);pages=width;index=S(0x1be2);break;
case 3:pages=1;count=3;width=pages;height=count;index=S(0x1be4);GameState::GetInstance();if(TreasureMapCollection_ReadMapCount()==0){count=2;height=count;}break;
case 4:count=C(0x1c73)+2;pages=1;width=pages;height=count;if(B(0x2485))height=count-1;index=S(0x1be6);break;
case 5:case 10:
if(S(0x1be6)>=0){C(0x1c20)=*(signed char*)(self + S(0x1be6) + 0x1c6e);if(S(0x1be6)==C(0x1c73))C(0x1c20)=4;if(S(0x1be6)==C(0x1c73)+1)C(0x1c20)=-1;}
width=1;height=8;count=GameState_CountRecordsForCategory(self,C(0x1c20));pages=(count+7)/8;if(count<8)height=count;if(count<=S(0x1be8))S(0x1be8)=count-1;index=S(0x1be8);break;
case 6:pages=1;count=4;width=pages;height=count;index=S(0x1bea);break;
case 7:pages=1;width=pages;if(B(0x1c84)==7)count=C(0x1c73);else count=B(0x1c6d);index=S(0x1bec);height=count;break;
case 9:count=B(0x1c6d)+1;pages=1;width=pages;height=count;index=S(0x1bee);break;
case 11:count=W(0x1c38)+1;pages=1;width=pages;height=count;index=S(0x1bf0);break;
case 12:pages=1;count=2;width=pages;height=count;index=S(0x1bf2);break;
case 13:width=1;height=8;count=GameState_CountRecordsForCategory(self,C(0x1c21))+1;pages=width;if(count>8)count=8;if(count<8)height=count;index=S(0x1bf4);break;
case 14:{signed char n=CountEligiblePartyEntriesAfterExclusions();count=n+1;if(S(0x1bf6)>n)S(0x1bf6)=n;width=1;height=count;pages=width;if(S(0x1bf6)<0)S(0x1bf6)=0;index=S(0x1bf6);break;}
case 16:count=C(0x1c73);width=1;height=count;pages=width;index=S(0x1bf8);break;
case 17:count=B(0x2520);height=8;width=1;pages=(count+7)/8;if(count<8)height=count;index=S(0x1bfa);break;
case 20:if(W(0x2474)){count=*(unsigned short*)(W(0x2474)+12);height=6;width=1;if(count<6)height=count;index=S(0x1bfc);pages=(count-1)/6+1;}else{width=0;height=width;count=width;index=width;pages=width;}break;
case 21:{short ids[9];short n=0;PartyMenu_BuildAvailableConnectionActions(self,ids,&n);count=n;width=1;height=count;pages=width;index=S(0x1bfe);break;}
// Original category 23 enters the shared tail without initializing these locals.
// Reachability and the incoming register values for that category remain unknown.
case 23:break;
case 24:width=3;height=C(0x1c73)+1;count=height*3;pages=1;index=S(0x1c02);break;
case 25:pages=1;count=6;width=pages;height=count;index=S(0x1c04);break;
case 28:height=4;pages=1;width=height;orientation=1;count=16;index=S(0x1c06);break;
case 31:count=C(0x1c73);pages=1;width=pages;height=count;index=S(0x1c08);break;
case 33:pages=1;count=8;width=pages;height=count;index=S(0x1c0a);break;
case 34:width=2;pages=width;height=8;count=32;orientation=1;index=S(0x1c0c);break;
case 35:pages=1;count=3;width=pages;height=count;index=S(0x1c0e);break;
case 36:pages=1;count=2;width=pages;height=count;index=S(0x1c10);break;
case 37:pages=1;count=2;width=pages;height=count;index=S(0x1c12);break;
case 39:pages=1;count=2;width=pages;height=count;index=S(0x1c14);break;
default:Selection_DisableTouchInput((int)((MenuLayout*)self)->grids);Selection_DisableDirectionalInput((int)((MenuLayout*)self)->grids);return;
}
Grid_SetOrientationAndCoordinatePointers((unsigned char*)grid+4,width,height,orientation);
Grid_SetOrientationAndCoordinatePointers((unsigned char*)grid+0x54,width,height,orientation);
Grid_SetEntryCountAndClampSelection((int*)(grid+4),count);Grid_SetEntryCountAndClampSelection((int*)(grid+0x54),count);
*(int*)(grid+8)=pages;*(int*)(grid+0x58)=pages;
Grid_SelectIndexAndInvalidateTouchHistory((State*)(grid+4),index);Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(grid+0x54),index);W(0x247c)&=~4;
}
