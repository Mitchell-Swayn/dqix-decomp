#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Grotto/Main/ActiveGrottoClass.h>
#include <Grotto/Main/TreasureMapDataStructs.h>
#include <World/ZonePredicates.h>
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* Network_GetConnectionManager();
extern "C" void* GameState_ReadUnkF8(GameState*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" int Filesystem_FreeCachedTableIfAllocationNeedsSpace(unsigned);
extern "C" int TreasureMap_LoadLanguageDataAndOffsets();
extern "C" void GameState_FreeTreasureMapLanguageBuffersAndRestoreCache();
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable();
extern "C" bool Network_IsClientSession(unsigned*);
extern "C" bool Network_IsSessionActive(int*);
extern "C" void GameState_FillFiveHundredTwelveByteRangeWithZeroOrFF(void*,int);
// Original: arm9/main @ 0x0208fa8c; symbol: ActiveGrottoClass_PrepareZoneTransition; size: 0x1a4.
extern "C" ARM void ActiveGrottoClass_PrepareZoneTransition(ActiveGrottoClass* self) {
void* network; GrottoStruct* grotto; int last; unsigned short* previous; GameState* state=GameState::GetInstance(); GameResources* resources=GameResources_GetInstance(); network=Network_GetConnectionManager();
previous=(unsigned short*)GameState_ReadUnkF8(state); grotto=state->GetGrottoStruct(); void* roster=resources->unknown_ptr_36d0;
unsigned short* currentRecord=(unsigned short*)Zone3D_GetMainInstance(); last=*previous; int current=*currentRecord;
if(IsGrottoZone(last)&&!IsGrottoZone(current)&&(current<30000||current>39999)) {
self->overallMapData_.Clear(); Filesystem_FreeCachedTableIfAllocationNeedsSpace(0x2000); TreasureMap_LoadLanguageDataAndOffsets(); ExportDetailedTreasureMapData(&grotto->activeMapData,&self->overallMapData_,true,0); GameState_FreeTreasureMapLanguageBuffersAndRestoreCache(); FileCache_RestoreRomTablesIfSpaceAvailable();
if(!grotto->unknown_0[0])self->unknown_260_[0]=1; grotto->unknown_0[1]=0;
if(Network_IsClientSession((unsigned*)network))grotto->activeMapLevel=self->overallMapData_.GetLevel();
if(roster&&current)GameState_FillFiveHundredTwelveByteRangeWithZeroOrFF(roster,*(unsigned char*)self==3);
} else if(!IsGrottoZone(last)&&IsGrottoZone(current)&&(last<30000||last>39999)) {
if(Network_IsSessionActive((int*)network)&&Network_IsClientSession((unsigned*)network)&&!grotto->unknown_0[1])grotto->unknown_0[1]=0; else grotto->unknown_0[1]=1;
if(roster)GameState_FillFiveHundredTwelveByteRangeWithZeroOrFF(roster,0);
}
}
