#include <globaldefs.h>
ARM
extern "C" void Menu_AllocateAndAppendTextLabelWidget(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned char);
extern "C" void TitleMenu_PositionCursorAfterTextLabel(void*,int,int);
// Original data: arm9/ov004 @ 0x2171034; symbol: data_ov004_02171034.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0216B498; symbol: func_ov004_0216b498; size: 0x324.
// Builds mode-specific byte lookup nodes for keys 50-52 and positions the related text object.
extern "C" void BuildModeSpecificByteLookupNodes(unsigned owner,unsigned mode,int position){
 bool enabled=true;
 switch(mode){
 case 0:
  Menu_AllocateAndAppendTextLabelWidget(owner,50,1,210,35,12,6,10,enabled);
  Menu_AllocateAndAppendTextLabelWidget(owner,51,1,210,53,12,19,10,enabled);
  Menu_AllocateAndAppendTextLabelWidget(owner,52,1,210,60,12,32,10,1);
  break;
 case 1:
  if(position==0){
   if(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[3]==5)enabled=false;
   Menu_AllocateAndAppendTextLabelWidget(owner,50,1,210,2,12,6,10,enabled);
   Menu_AllocateAndAppendTextLabelWidget(owner,51,1,210,3,12,19,10,1);
   Menu_AllocateAndAppendTextLabelWidget(owner,52,1,210,60,12,32,10,1);
   TitleMenu_PositionCursorAfterTextLabel((void*)owner,52,position);
  }else{
   if(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[3]==5)enabled=false;
   Menu_AllocateAndAppendTextLabelWidget(owner,50,1,210,2,12,6,10,enabled);
   Menu_AllocateAndAppendTextLabelWidget(owner,51,1,210,3,12,19,10,1);
   Menu_AllocateAndAppendTextLabelWidget(owner,52,1,210,60,12,32,10,1);
   TitleMenu_PositionCursorAfterTextLabel((void*)owner,52,position);
  }
  break;
 case 2:
  Menu_AllocateAndAppendTextLabelWidget(owner,50,1,210,1,12,8,10,enabled);
  Menu_AllocateAndAppendTextLabelWidget(owner,51,1,210,60,12,22,10,enabled);
  TitleMenu_PositionCursorAfterTextLabel((void*)owner,51,3);
  break;
 case 3:
  Menu_AllocateAndAppendTextLabelWidget(owner,50,1,210,2,12,7,10,enabled);
  break;
 }
}
