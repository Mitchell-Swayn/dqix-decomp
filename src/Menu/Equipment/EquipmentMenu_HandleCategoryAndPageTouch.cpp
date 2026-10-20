#include <globaldefs.h>
ARM
struct Object;
extern "C" int SwitchIndexedStateAndSavePreviousPhase(Object*,int,int);
extern "C" void Grid_ChangeDisplayModeAndTransitionFlags(unsigned char*,unsigned char);
extern "C" void EquipmentMenu_SetCursorForDisplayMode(char*,unsigned,int);
extern "C" int EquipmentMenu_AdvanceInventoryPage(char*,int);
extern "C" void EquipmentMenu_RefreshInventoryPage(unsigned char*);
// Original: arm9/ov005 @ 0x02156658; symbol: func_ov005_02156658; size: 0x154.
// Hit-tests eight header cells and two page arrows; refreshes rows after a selection change.
extern "C" void EquipmentMenu_HandleCategoryAndPageTouch(unsigned char* p,int x,int y) {
 int changed=0;
 if((*(unsigned*)(p+0x3dcc)&4) && y>1 && y<19 && x>129 && x<255) {
  unsigned char index=p[0x3dbc];
  int left=113;
  for(int i=0;i<8;i++) {
   left+=16;
   if(i==7)left--;
   int right=left+16;
   if(x>=left && x<right){index=i;break;}
  }
  *(unsigned*)(p+0x3dcc)|=0x100;
  changed=SwitchIndexedStateAndSavePreviousPhase((Object*)p,index,0);
  Grid_ChangeDisplayModeAndTransitionFlags(p,2);
  EquipmentMenu_SetCursorForDisplayMode((char*)p,p[0x3db8],index);
 }
 if((*(unsigned*)(p+0x3dcc)&8) && y>157 && y<174) {
  int direction=0;
  if(x>137 && x<153)direction--;
  if(x>230 && x<246)direction=1;
  if(!direction)return;
  changed=EquipmentMenu_AdvanceInventoryPage((char*)p,direction);
  if(direction<0)*(unsigned*)(p+0x3dcc)|=0x20000;
  else *(unsigned*)(p+0x3dcc)|=0x40000;
 }
 if(changed)EquipmentMenu_RefreshInventoryPage(p);
}
