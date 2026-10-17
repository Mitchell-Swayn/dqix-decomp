#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" void __clear(void*,unsigned int);
struct TextPair {char* first;char* second;unsigned int state;};
extern "C" {int PlacementAllocator_ApplyCountByRecordKindAndAvailableActors(void*,int,int,int);void AddNonnegativeAmountWith9999999Limit(void*,int);unsigned int* ReadWordFieldAtOffset1C();void ClearOwnerBuffersAndResetSignedByteSentinels(void*);void SetOneOfSixteenWordFieldsAtOffset8B0(void*,int,unsigned int);const char* LookupGlobalResourceByKey(int);void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,const char*,char*,int,int,int);int GameState_ReadFirstObjectIndex(GameState*);void GameState_BuildTwelveByteDescriptorForPartyMember(void*,int);void ClearMemoryRange12_Main020E46C4(TextPair*);void FormatOutputForPositiveCountAndNonzeroDestination(int,TextPair*);}
// Original: arm9/main @ 0x0207D538; symbol: func_0207d538; size: 0x1A4.
extern "C" int Text_FormatModeDependentKeyResourceResult(void* object,int mode,int id,char* output) {
 char first[128],second[128];unsigned int geometry[3];TextPair text;
 if(mode==2) {
  short selected=id;int result=PlacementAllocator_ApplyCountByRecordKindAndAvailableActors(object,selected,1,0);
  switch(result) {
   case -1:return false;
   case 0:case 1:case 2:case 3:case 5: {
    unsigned int* context=ReadWordFieldAtOffset1C();ClearOwnerBuffersAndResetSignedByteSentinels(context);
    GameState* state=GameState::GetInstance();GameState_BuildTwelveByteDescriptorForPartyMember(geometry,GameState_ReadFirstObjectIndex(state));
    context[0]=(unsigned int)geometry;
    __clear(first,128);__clear(second,128);ClearMemoryRange12_Main020E46C4(&text);
    text.first=first;text.second=second;FormatOutputForPositiveCountAndNonzeroDestination(selected,&text);
    context[6]=(unsigned int)&text;
    const char* format=LookupGlobalResourceByKey(0x54);ProcessSixStagesUsingSharedWordScratchBuffer(context,12,format,output,0xe3,0,1);
   }break;
  }
  if(result==-2)return 0;return 1;
 }
 if(mode==1) {
  AddNonnegativeAmountWith9999999Limit(object,id);unsigned int* context=ReadWordFieldAtOffset1C();ClearOwnerBuffersAndResetSignedByteSentinels(context);
  SetOneOfSixteenWordFieldsAtOffset8B0(context,0,id);const char* format=LookupGlobalResourceByKey(0x3f4);ProcessSixStagesUsingSharedWordScratchBuffer(context,12,format,output,0xe3,0,1);return true;
 }
 const char* format=LookupGlobalResourceByKey(0x2d);sprintf(output,format);return false;
}
