#include <globaldefs.h>
ARM
struct GameState;struct GameResources;struct S;struct GridSelection;struct Owner;struct ThreeWords{int x,y,z;};
// Original data: arm9/ov005 @ 0x215cd48; symbol: data_ov005_0215cd48.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0001040205030607.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
extern "C" {void* _ZN9GameState11GetInstanceEv();GameResources* GameResources_GetInstance();unsigned Field_GetSharedSubscreenInstance(void*);void EquipmentMenu_CopyRenderPartPosition(Owner*,const ThreeWords*);void EquipmentMenu_ChangeCharacterEquipment(void*,int,int);int EquipmentMenu_HitTestInventoryGrid(void*,int,int);void* GameState_GetIndexList(GameState*);unsigned Inventory_GetGroupItemIds(S*,unsigned);unsigned Inventory_GetGroupQuantities(unsigned char*,unsigned);void EquipmentMenu_RefreshInventoryPage(unsigned char*);void EquipmentMenu_SetCursorForDisplayMode(char*,unsigned,int);void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);extern unsigned char FinishDraggedGridRowAndSwapEntries_UnknownRoleInitializedBytes[];}
#define B(o) (*(unsigned char*)(p+(o)))
#define S8(o) (*(signed char*)(p+(o)))
#define H(o) (*(short*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
// Original: arm9/ov005 @ 0x02156ECC; symbol: func_ov005_02156ecc; size: 0x2A8.
// Restores dragged row position, handles discard/header targets, and swaps indexed entries on row drop.
extern "C" void FinishDraggedGridRowAndSwapEntries(unsigned char* p,int x,int y){
 if(H(0x3d78)<0)return;
 _ZN9GameState11GetInstanceEv();char* resources=(char*)GameResources_GetInstance();char* object=(char*)Field_GetSharedSubscreenInstance(*(void**)(resources+0x3708));
 ThreeWords position=*(ThreeWords*)(p+0x3d0c);
 char* owner=*(char**)(p+H(0x3d78)*28+0x2d98);position.z=0;EquipmentMenu_CopyRenderPartPosition((Owner*)owner,&position);
 *(unsigned short*)(owner+0x82)=0;
 if(H(0x3d78)>=0 && H(0x3d78)<8)*(unsigned short*)(owner+0x82)=31;
 if(x<128){if(S8(0x3dc0)==0)EquipmentMenu_ChangeCharacterEquipment(p,*(short*)(p+H(0x3d78)*28+0x2d90),0);}
 else if(y>21 && y<46){if(x>131 && S8(0x3dc0)==0)EquipmentMenu_ChangeCharacterEquipment(p,*(short*)(p+H(0x3d78)*28+0x2d90),0);}
 else if(y>48 && S8(0x3dc0)==1)EquipmentMenu_ChangeCharacterEquipment(p,65535,0);
 if(S8(0x3dc0)==0){
  int row=EquipmentMenu_HitTestInventoryGrid(p,x,y);
  if(row>=8 && row<24 && S8(0x3dbb)!=row){
   short index=row-8+(S8(0x3dbd)<<4);
   unsigned char* list=(unsigned char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv());
   short* entries=(short*)Inventory_GetGroupItemIds((S*)(list+0x1d4),FinishDraggedGridRowAndSwapEntries_UnknownRoleInitializedBytes[B(0x3dbc)]);
   signed char* attributes=(signed char*)Inventory_GetGroupQuantities(list+0x1d4,FinishDraggedGridRowAndSwapEntries_UnknownRoleInitializedBytes[B(0x3dbc)]);
   short oldEntry=entries[H(0x3de0)];signed char oldAttribute=attributes[H(0x3de0)];
   entries[H(0x3de0)]=entries[index];attributes[H(0x3de0)]=attributes[index];entries[index]=oldEntry;attributes[index]=oldAttribute;
   EquipmentMenu_RefreshInventoryPage(p);W(0x3dcc)|=0x40;B(0x3daa)=0;H(0x3de0)=-1;S8(0x3dbb)=row;
  }
 }
 EquipmentMenu_SetCursorForDisplayMode((char*)p,B(0x3db8),B(0x3dbb));
 Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p+0x19f4),S8(0x3dbb)-8);
 *(unsigned short*)(object+0x634)|=0x81;W(0x3dcc)|=12;
}
