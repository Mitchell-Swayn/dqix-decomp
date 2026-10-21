#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" int CharacterState_EnumerateLearnedSpells(unsigned char*,unsigned char*,int);
extern "C" void __clear(void*,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" unsigned SpellTable_CollectMappedSpellValues(void*,unsigned char*,unsigned,unsigned short*);
extern "C" char* ActionData_GetGlobalTables();
struct Record{unsigned pad[2];unsigned lo:10;unsigned flags:2;unsigned high:20;unsigned padC[3];unsigned low18:12;unsigned kind:4;unsigned high18:16;};
extern "C" void* ActionData_FindDefinitionInPrimaryOrSecondaryTable(char*,int);
extern "C" int GameState_CollectCategoryCodesMeetingRequiredLevel(char* volatile*,void*,unsigned char*);
extern "C" int CharacterState_GetLearnedSkillMask(unsigned char*,int);
extern "C" char* SkillTable_FindEntryById(void*,unsigned);
inline void AppendRecord(Record** output,int& count,Record* value){output[count]=value;count++;}
// Original: arm9/ov002 @ 0x02157174; symbol: func_ov002_02157174; size: 0x284.
extern "C" void GameState_BuildEnabledResolvedRecordList(char* self,int index){
 for(unsigned char i=0;i<32;i++)*(unsigned*)(self+0x24a0+i*4)=0;
 *(unsigned char*)(self+0x2520)=0;
 Record** output=(Record**)(self+0x24a0);
 char* object=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),index);if(!object)return;
 int count,written;char* global;int firsti;
 unsigned char* nested=GameObject_GetLinkedIndexedState(object);if(!nested)return;
 unsigned char ids[66];
 count=CharacterState_EnumerateLearnedSpells(nested,ids,66);
 short resolved[66];__clear(resolved,132);
 count=SpellTable_CollectMappedSpellValues(self+0x2444,ids,count,(unsigned short*)resolved);
 written=0;
 global=ActionData_GetGlobalTables();
 for(firsti=0;firsti<count;firsti++){
  Record* record=(Record*)ActionData_FindDefinitionInPrimaryOrSecondaryTable(global,resolved[firsti]);
  if(record && ids[firsti]==60 && (record->flags&1))AppendRecord(output,written,record);
 }
 if(!*(unsigned*)(*(char**)(object+0x150)+0x950)){
  memset(ids,0,66);count=CharacterState_EnumerateLearnedSpells(nested,ids,66);
 }else{memset(ids,0,66);count=GameState_CollectCategoryCodesMeetingRequiredLevel((char* volatile*)(self+0x2444),object,ids);}
 memset(resolved,0,132);
 count=SpellTable_CollectMappedSpellValues(self+0x2444,ids,count,(unsigned short*)resolved);
 short* resolvedArray;int i=0;resolvedArray=resolved;
 for(;i<count;i++){
  Record* record=(Record*)ActionData_FindDefinitionInPrimaryOrSecondaryTable(global,resolvedArray[i]);
  if(record && ids[i]!=60 && (record->flags&1))AppendRecord(output,written,record);
 }
 char* table;unsigned short j=0;
 for(;j<287;j++){
  if(CharacterState_GetLearnedSkillMask(nested,j)){
   table=self+0x3c;
   char* entry=SkillTable_FindEntryById(table+0x2400,j);
   if(entry && *(unsigned short*)(entry+8)){
    Record* record=(Record*)ActionData_FindDefinitionInPrimaryOrSecondaryTable(global,(short)*(unsigned short*)(entry+8));
    if(record && record->kind==1 && (record->flags&1))AppendRecord(output,written,record);
   }
  }
 }
 *(unsigned char*)(self+0x2520)=written;
}
