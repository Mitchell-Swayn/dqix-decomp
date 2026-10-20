#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
struct State; struct Object; struct T;
extern "C" {
void* memset(void*,int,unsigned); char* strcpy(char*,const char*); void* __clear(void*,unsigned);
void* Zone3D_GetMainInstance();
void TreasureMapPanel_RequestTextRefresh(char*,int); void TreasureMapPanel_SetActive(int,unsigned char);
void WorldMap_SetTitleAndMeasureWidth(char*,const char*);
void WorldMap_FormatTreasureMapLevelLabel(unsigned char*,int);
void TreasureMapPanel_SetDiscovererName(void*,char*,int,int);
void TreasureMapPanel_SetClearerName(int,char*,int,int);
void TreasureMapPanel_SetMinimumTurnCount(Object*,unsigned);
void FormatThreeIndexedTextAndValueSlots(unsigned char*,unsigned,const char*,unsigned);
unsigned TextContext_GetSharedInstance();
void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
unsigned MessageTextTable_FindTextById(T*,int);
void Text_FormatGlobalDataAndSubmitToResource();
void* Text_LookupNameTableEntry(void*,int);
unsigned short Resource_MapThousandRangeIdToLocalCode(unsigned);
void* Menu_GetDisplayRecordRegistry(State*);
void* MenuRecordList_LocateByKey(void**,unsigned short);
unsigned MenuRecord_GetType(void*);
unsigned Menu_GetSelectedGridRow(void*);
void* Menu_GetRecordMessageTable(void*);
// Original data: arm9/ov004 @ 0x2171010; symbol: data_ov004_02171010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern char* PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage[3];
}
struct Record { unsigned char prefix[0x3d]; unsigned char present[3]; short ids[3]; unsigned char values[3]; unsigned char tail[0x17b]; };
// Original: arm9/ov004 @ 0x021636B0; symbol: func_ov004_021636b0; size: 0x294.
// Copies record name/details and converts three indexed text/value pairs into the resource panel.
extern "C" void PopulateSelectedRecordTextPanel(State* self,const char* name){
 char* global=(char*)Zone3D_GetMainInstance();
 char* panel=*(char**)((char*)GameResources_GetInstance()+0x36d0);
 strcpy(global+0x26,name);
 Text_FormatGlobalDataAndSubmitToResource();
 TreasureMapPanel_SetActive((int)panel,1);
 *(int*)(panel+20)=1;
 void* grid=MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(self),10);
 if(grid && MenuRecord_GetType(grid)==7){
  Record* record=(Record*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage[0]+0xad4+Menu_GetSelectedGridRow(grid)*0x1c4);
  if(record->prefix[1]==1){
   WorldMap_SetTitleAndMeasureWidth(panel,(char*)record+0x67);
   WorldMap_FormatTreasureMapLevelLabel((unsigned char*)panel,((unsigned char*)record)[0x65]);
  }else if(record->prefix[1]==2){
   WorldMap_SetTitleAndMeasureWidth(panel,(char*)record+0xbc);
   WorldMap_FormatTreasureMapLevelLabel((unsigned char*)panel,((unsigned char*)record)[0x56]);
  }
  ((void(*)(void*,char*))TreasureMapPanel_SetDiscovererName)(panel,(char*)record+2);
  ((void(*)(int,char*))TreasureMapPanel_SetClearerName)((int)panel,(char*)record+14);
  if(record->prefix[1]==2) TreasureMapPanel_SetMinimumTurnCount((Object*)panel,*(unsigned short*)((char*)record+0x58));
  void** head=(void**)Menu_GetDisplayRecordRegistry(self);
  memset(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage[1],0,0x333);
  for(int i=0;i<3;i++){
   char scratch[128]={0}; char formatted[128]={0};
   void* owner=(void*)TextContext_GetSharedInstance();
   if(!record->present[i]){
    FormatThreeIndexedTextAndValueSlots((unsigned char*)panel,(unsigned char)i,0,record->values[i]);
   }else{
    char* output=PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage[1]+i*128;
    memset(output,0,128);
    unsigned code=Resource_MapThousandRangeIdToLocalCode((unsigned short)record->ids[i]);
    if(code){
     void* list=MenuRecordList_LocateByKey(head,50);
     if(!list || MenuRecord_GetType(list)!=4) return;
     unsigned value=MessageTextTable_FindTextById((T*)Menu_GetRecordMessageTable(list),(short)code);
     Text_FormatAndConditionallyUppercaseOutput((const char*)value,formatted,0);
     TextMarkup_ExpandAndWrapText(owner,0,formatted,output,96,0,0);
    }else{
     void* value=Text_LookupNameTableEntry(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage[2],record->ids[i]);
     Text_FormatAndConditionallyUppercaseOutput(*(const char**)value,formatted,0);
     TextMarkup_ExpandAndWrapText(owner,0,formatted,output,96,0,0);
    }
    FormatThreeIndexedTextAndValueSlots((unsigned char*)panel,(unsigned char)i,output,record->values[i]);
   }
  }
  TreasureMapPanel_RequestTextRefresh(panel,1);
 }
}
