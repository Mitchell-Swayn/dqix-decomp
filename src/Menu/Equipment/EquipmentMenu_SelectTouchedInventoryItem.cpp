#include <globaldefs.h>
ARM
struct GameResources; struct GridSelection;
extern "C" {
void* _ZN9GameState11GetInstanceEv();
GameResources* GameResources_GetInstance();
unsigned Field_GetSharedSubscreenInstance(void*);
int GameState_IsObjectAssociatedWithProtagonistWhenConnected(void*,int);
int EquipmentMenu_HitTestInventoryGrid(void*,int,int);
void Grid_ChangeDisplayModeAndTransitionFlags(unsigned char*,unsigned char);
void EquipmentMenu_SetCursorForDisplayMode(char*,unsigned,int);
void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[];
}
#define H(o) (*(short*)(p+(o)))
#define B(o) (*(unsigned char*)(p+(o)))
#define S(o) (*(signed char*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
// Original: arm9/ov005 @ 0x021567AC; symbol: func_ov005_021567ac; size: 0x160.
// Selects a touched populated row, updates cursor/page selection and disables header/arrow hit areas.
extern "C" void EquipmentMenu_SelectTouchedInventoryItem(unsigned char* p,int x,int y){
 _ZN9GameState11GetInstanceEv();
 char* resources=(char*)GameResources_GetInstance();
 char* object=(char*)Field_GetSharedSubscreenInstance(*(void**)(resources+0x3708));
 if(!GameState_IsObjectAssociatedWithProtagonistWhenConnected(p,*(int*)(object+0x4fc)))return;
 H(0x3d78)=EquipmentMenu_HitTestInventoryGrid(p,x,y);
 if(H(0x3d78)>=8 && H(0x3d78)<24){
  if(*(short*)(p+H(0x3d78)*28+0x2d90)==-1){H(0x3d78)=-1;S(0x3dc0)=-1;return;}
  Grid_ChangeDisplayModeAndTransitionFlags(p,4);
  B(0x3dbb)=H(0x3d78);
  EquipmentMenu_SetCursorForDisplayMode((char*)p,B(0x3db8),B(0x3dbb));
  Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p+0x19f4),S(0x3dbb)-8);
  H(0x3de0)=S(0x3dbb)-8+(S(0x3dbd)<<4);
  B(0x3dc0)=0;
  W(0x3dcc)|=0x80;
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,2,0);
  *(unsigned short*)(object+0x634)&=~1;
  *(unsigned short*)(object+0x634)&=~0x80;
  W(0x3dcc)&=~4;
  W(0x3dcc)&=~8;
 }else{H(0x3d78)=-1;S(0x3dc0)=-1;}
}
