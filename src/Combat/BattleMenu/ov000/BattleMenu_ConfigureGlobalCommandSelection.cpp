#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
typedef unsigned int undefined4;
struct GridSelection;
struct State;
extern "C" {
void* GameState_GetIndexList(GameState*);
int GameState_ReadProtagonistObjectIndex(GameState*);
void* Network_GetConnectionManager();
bool Network_IsSessionActive(int*);
unsigned int GameObject_GetLinkedIndexedState(int);
void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
void Grid_SetEntryCountAndClampSelection(int*,int);
void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);
void Selection_EnableTouchInput(int);
void Selection_EnableDirectionalInput(int);
void Selection_DisableTouchInput(int);
void Selection_DisableDirectionalInput(int);
char* BattleMenu_FindPartyCommandRecord(char*,int);
void Memory_CopyConstantBlock16(void*,void*);
unsigned int GameState_CountSetBitsInWord68(void*);
extern int BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov000 @ 0x0217C638; symbol: BattleMenu_ConfigureGlobalCommandSelection; size: 0x2D0.
// Configures paired menu grids using the current stored mode and selection.
extern "C" void BattleMenu_ConfigureGlobalCommandSelection(char* self,int value,int option) {
 int columns=1, rows, count=option, pages=1,index;
 BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[1]=value;BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[0]=option;
 GameState* game=GameState::GetInstance();
 char* list=(char*)GameState_GetIndexList(game);
 switch(*(signed char*)(self+0x1d60+*(signed char*)(self+0x1d68))) {
 case 1: {int slots[4];count=0;Memory_CopyConstantBlock16(self,slots);for(int i=0;i<4;i++)if(slots[i]>=0)count++;rows=count;index=*(signed char*)(self+0x1d69);break;}
 case 2: {void* connection=Network_GetConnectionManager();rows=3;if(Network_IsSessionActive((int*)connection) && GameState_ReadProtagonistObjectIndex(game)==0)rows=4;count=rows;index=*(signed char*)(self+0x1d6a);break;}
 case 3: count=(unsigned char)list[0xf7c];rows=count;index=*(signed char*)(self+0x1d6b);break;
 case 5: count=(unsigned char)list[0xf7c];rows=count;index=*(signed char*)(self+0x1d6b);break;
 case 6: rows=4;count=GameState_CountSetBitsInWord68(self);index=*(signed char*)(self+0x1d6e);if(count<4)rows=count;pages=(count+3)/4;break;
 case 7: count=*(short*)(self+0x66);index=*(signed char*)(self+0x1d6f);rows=4;if(count<4)rows=count;pages=(count+3)/4;break;
 case 4: {index=*(signed char*)(self+0x1d74+*(signed char*)(self+0x1d6b));columns=2;rows=3;count=6;signed char field=0;int valid=index>=0&&index<=3;if(valid && BattleMenu_FindPartyCommandRecord(self,index)){GameObject* object=game->GetPartyMemberByIndex(index);if(object)field=*(int*)(GameObject_GetLinkedIndexedState((int)object)+0x94c);}self[0x1d6c]=field;index=*(signed char*)(self+0x1d6c);break;}
 case 8:count=(unsigned char)self[0x79];index=*(signed char*)(self+0x1d6b);rows=count;break;
 case 23:rows=*(signed char*)(self+0x1a);index=*(signed char*)(self+0x1d6d);count=rows;break;
 case 25:rows=1;columns=count;pages=1;index=*(signed char*)(self+0x1c);break;
 default:Selection_DisableTouchInput((int)(self+0x188));Selection_DisableDirectionalInput((int)(self+0x188));return;
 }
 Selection_EnableTouchInput((int)(self+0x188));Selection_EnableDirectionalInput((int)(self+0x188));
 Grid_SetOrientationAndCoordinatePointers((unsigned char*)self+0x18c,columns,rows,0);Grid_SetOrientationAndCoordinatePointers((unsigned char*)self+0x1dc,columns,rows,0);
 Grid_SetEntryCountAndClampSelection((int*)(self+0x18c),count);Grid_SetEntryCountAndClampSelection((int*)(self+0x1dc),count);
 *(int*)(self+0x190)=pages;*(int*)(self+0x1e0)=pages;
 Grid_SelectIndexAndInvalidateTouchHistory((State*)(self+0x18c),index);Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(self+0x1dc),index);
}
