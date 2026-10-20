#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" unsigned GameState_CopyAvailableGrottoTransferMetadata(GameState*,TreasureMapMetadata*);
extern "C" char* PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov004 @ 0x021635D0; symbol: TreasureMapMenu_FindHighlightedMapPosition; size: 0xE0.
// Finds first metadata entry selected by transfer availability and reports page/row.
extern "C" int TreasureMapMenu_FindHighlightedMapPosition(int* page,int* row){
 if(!page)return 0;if(!row)return 0;
 int found=-1;
 if(GameState_CopyAvailableGrottoTransferMetadata(GameState::GetInstance(),0)){
 for(int i=0;i<*(unsigned char*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0x18f4);++i){if(((TreasureMapMetadata*)PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage)[i].GetDiscoveryState()==3){found=i;break;}}
 }else{
 for(int i=0;i<*(unsigned char*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0x18f4);++i){if(((TreasureMapMetadata*)PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage)[i].GetInitialByteUnknownBit()){found=i;break;}}
 }
 if(found<0)return 0;
 int quotient=found/8;int remainder=found-quotient*8;if(remainder<0)remainder=0;*page=quotient;*row=remainder;return 1;
}
