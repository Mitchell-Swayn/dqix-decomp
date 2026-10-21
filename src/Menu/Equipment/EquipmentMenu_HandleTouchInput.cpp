#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <World/Zone3DContainers.h>
ARM
struct StateRecord;
extern "C" {
unsigned int ReadSelectedCoordinatePair(const StateRecord* state, unsigned int* first, unsigned int* second);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
void Grid_ChangeDisplayModeAndTransitionFlags(unsigned char* p, unsigned char mode);
void EquipmentMenu_HandleCategoryAndPageTouch(unsigned char* p, int x, int y);
void EquipmentMenu_SelectTouchedInventoryItem(unsigned char* p, int x, int y);
void EquipmentMenu_SelectTouchedEquipmentSlot(unsigned char* p, int x, int y);
void EquipmentMenu_SetCursorForDisplayMode(char* self, unsigned mode, int index);
unsigned Field_GetSharedSubscreenInstance(void* self);
void Graphics_ClampAndSnapScreenTarget(unsigned char* p, int x, int y);
void FinishDraggedGridRowAndSwapEntries(unsigned char* p, int x, int y);
// Original data: arm9/main @ 0x2114e54; symbol: Main_UnknownRoleZeroInitializedStorage_Variant4.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/main @ 0x2108760; symbol: Main_UnknownRoleZeroInitializedStorage.
extern unsigned char Main_UnknownRoleZeroInitializedStorage[];
}
#define B(o) (*(unsigned char*)(p+(o)))
#define S(o) (*(signed char*)(p+(o)))
#define H(o) (*(short*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
// Original: arm9/ov005 @ 0x021562B8; symbol: func_ov005_021562b8; size: 0x3A0.
// Tracks grid press, drag, release and repeated-tap confirmation using stored row and coordinate state.
extern "C" void EquipmentMenu_HandleTouchInput(unsigned char* p){
 unsigned int x,y;ReadSelectedCoordinatePair((const StateRecord*)Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
 unsigned ticks=GameState::GetInstance()->GetTickCount();if(!ticks)ticks=1;
 if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]){
  if(!x || !y)return;
  char* resources=(char*)GameResources_GetInstance();char* object=(char*)Field_GetSharedSubscreenInstance(*(void**)(resources+0x3708));
  if(!(W(0x3dcc)&0x400) && (*(unsigned short*)(object+0x634)&0x800)){
   SoundSfx_StartCurrentSequenceArchiveEntry((char*)Main_UnknownRoleZeroInitializedStorage,27,0);Grid_ChangeDisplayModeAndTransitionFlags(p,1);return;
  }
  EquipmentMenu_HandleCategoryAndPageTouch(p,x,y);
  if(!(W(0x3dcc)&0x400) && (int)x>=128 && (int)y>=176){Grid_ChangeDisplayModeAndTransitionFlags(p,7);W(0x3dcc)|=0x80000;return;}
  if(S(0x3dc0)!=-1)return;
  EquipmentMenu_SelectTouchedInventoryItem(p,x,y);EquipmentMenu_SelectTouchedEquipmentSlot(p,x,y);
  if((int)x>131 && (int)y>21 && (int)y<46){Grid_ChangeDisplayModeAndTransitionFlags(p,3);B(0x3dbb)=B(0x3dbc);EquipmentMenu_SetCursorForDisplayMode((char*)p,B(0x3db8),0);}
  if(H(0x3d78)<0)return;
  if(S(0x3e07)==H(0x3d78)){
   if(S(0x3e06)>0){
    if(*(short*)(p+S(0x3dbb)*28+0x2d90)>=0){
     Grid_ChangeDisplayModeAndTransitionFlags(p,5);SoundSfx_StartCurrentSequenceArchiveEntry((char*)Main_UnknownRoleZeroInitializedStorage,1,0);
     *(unsigned short*)(object+0x634)&=~1;*(unsigned short*)(object+0x634)&=~0x80;
    }
    ((ZoneContainerRenderPart*)(p+0x3cf0))->ResetIfFlag0();H(0x3d78)=-1;S(0x3dc0)=-1;B(0x3e05)=0;S(0x3e07)=-2;B(0x3e06)=0;return;
   }else{S(0x3e07)=-2;B(0x3e06)=0;}
  }
  B(0x3e05)=0;H(0x3e08)=x;H(0x3e0a)=y;
 }else if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x5f] && *(unsigned short*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x24)){
  Graphics_ClampAndSnapScreenTarget(p,x,y);
  if(H(0x3d78)>=0)S(0x3e05)=S(0x3e05)+ticks;
 }else if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x54]){
  if(H(0x3d78)>=0){
   int dx=H(0x3e08)-(short)x;int dy=H(0x3e0a)-(short)y;
   int moved=0;if(dx*dx+dy*dy>=25)moved=1;
   if(S(0x3e05)<=20 && !moved){B(0x3e06)=20;S(0x3e07)=H(0x3d78);}
   else{B(0x3e05)=0;S(0x3e07)=-2;B(0x3e06)=0;}
   H(0x3e08)=-1;H(0x3e0a)=-1;
  }
  FinishDraggedGridRowAndSwapEntries(p,x,y);((ZoneContainerRenderPart*)(p+0x3cf0))->ResetIfFlag0();H(0x3d78)=-1;S(0x3dc0)=-1;
 }
}
