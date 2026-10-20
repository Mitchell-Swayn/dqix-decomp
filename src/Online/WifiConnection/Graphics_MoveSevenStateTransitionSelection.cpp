#include <globaldefs.h>
ARM
struct Transition {unsigned char selected;char pad[3];unsigned char* object;};
// Original data: arm9/ov031 @ 0x2290cc0; symbol: data_ov031_02290cc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Transition ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_PositionProfileSelectionHighlight();
extern "C" int WfcUtility_PlaySequenceArchiveEntry(unsigned);
// Original: arm9/ov031 @ 0x02232D64; symbol: func_ov031_02232d64; size: 0x1F4.
// Advances seven-state selection navigation, remembering the last base choice for central transitions.
extern "C" void Graphics_MoveSevenStateTransitionSelection(int direction){
int apply=1;
switch(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected){
case 0:ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.object[28]=0;if(direction==0)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=2;else if(direction==2)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=1;else if(direction==1)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=3;else ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=4;break;
case 1:ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.object[28]=1;if(direction==0)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=0;else if(direction==2)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=2;else if(direction==1)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=3;else ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=5;break;
case 2:ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.object[28]=2;if(direction==0)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=1;else if(direction==2)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=0;else if(direction==1)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=3;else ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=6;break;
case 3:{unsigned next;unsigned previous=ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.object[28];next=previous+4;if(direction==1)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=next;else if(direction==3)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=previous;else apply=0;break;}
case 4:ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.object[28]=0;if(direction==0)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=6;else if(direction==2)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=5;else if(direction==1)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=0;else ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=3;break;
case 5:ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.object[28]=1;if(direction==0)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=4;else if(direction==2)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=6;else if(direction==1)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=1;else ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=3;break;
case 6:ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.object[28]=2;if(direction==0)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=5;else if(direction==2)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=4;else if(direction==1)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=2;else ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage.selected=3;break;
}
if(apply){WfcUtility_PlaySequenceArchiveEntry(8);WfcUtility_PositionProfileSelectionHighlight();}
}
