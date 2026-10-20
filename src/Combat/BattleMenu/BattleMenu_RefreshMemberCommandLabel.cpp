#include <globaldefs.h>
#include "GameState/GameState.h"
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
#include <std_library_functions.h>
typedef unsigned int undefined4;
struct Record { unsigned int field0; unsigned int identifier:12; unsigned int remaining:20; };
struct Bytes { unsigned char values[8]; };
struct RecordKind { unsigned kind:4; unsigned unused:28; };
struct Eight { short values[8]; };
struct Triple { int x, y, z; };
struct Entry { char pad[5]; signed char mode:6; unsigned char unused:1; signed char enabled:1; };
extern "C" {
ARM Record* BattleMenu_FindActionDefinition(unsigned char*,unsigned);
void* BattleMenu_FindItemByEquipmentKey(char*,int);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
ARM undefined4 GameObject_GetLinkedIndexedState(int);
int BattleMenu_HasCommandBlockingStatus(char*);
void* __clear(void*,unsigned);
int Graphics_FormatPriorityFlaggedPartyLabel(char*,void*);
void TextSprite_FormatAndUpdateTextReference(unsigned char*,const char*);
void* ResourceStringTable_GetTextByKey(void*,void*);
void String_ReplaceBracketedNamesByRowColumnTable(const signed char*,signed char*,int,unsigned,unsigned,int);
void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
unsigned TextContext_GetSharedInstance();
void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
void BattleMenu_BroadcastPartyDisplayStats(void*);
// Original data: arm9/ov000 @ 0x02183ff4; symbol: data_ov000_02183ff4.
// The single null byte is the empty-string fallback passed to TextSprite_FormatAndUpdateTextReference when a command label cannot be resolved.
// Values (char[1]): "" (one NUL byte).
extern const char BattleMenu_EmptyCommandLabel[];
}
// Original: arm9/ov000 @ 0x02170DB0; symbol: func_ov000_02170db0; size: 0x220.
// Formats priority labels, class override text, or primary/equipment descriptions into the record display context.
ARM
extern "C" void BattleMenu_RefreshMemberCommandLabel(unsigned char* self) {
 char* named=(char*)BattleMenu_FindActionDefinition(self,*(unsigned short*)(self+0x26));
 char* equipment=(char*)BattleMenu_FindItemByEquipmentKey((char*)self,*(short*)(self+0x2c));
 GameObject* object=GameState_GetObjectWithFlag100(GameState::GetInstance(),*(int*)(self+0x4c));
 if(!object)return;
 unsigned char* state=(unsigned char*)GameObject_GetLinkedIndexedState((int)object);
 *(int*)(self+0x60)=1;
 if(BattleMenu_HasCommandBlockingStatus((char*)self)) {
 char priority[128];__clear(priority,128);
 if(Graphics_FormatPriorityFlaggedPartyLabel((char*)self,priority)>=0)TextSprite_FormatAndUpdateTextReference(self+0x50,priority);
 }else {
 if(state && (signed char)*(int*)(state+0x94c)!=5 && *(signed char*)(self+0x1c)!=6) {
 short textId=(signed char)*(int*)(state+0x94c)+0x753e;
 char* text=(char*)ResourceStringTable_GetTextByKey(*(void**)(self+4),(void*)textId);
 if(text)TextSprite_FormatAndUpdateTextReference(self+0x50,text);
 else TextSprite_FormatAndUpdateTextReference(self+0x50,BattleMenu_EmptyCommandLabel);
 }else if(named) {
 char replaced[128];__clear(replaced,128);
 char formatted[128];__clear(formatted,128);
 String_ReplaceBracketedNamesByRowColumnTable(*(signed char**)named,(signed char*)replaced,1,0,0,0);
 Text_FormatAndConditionallyUppercaseOutput(replaced,formatted,0);
 TextSprite_FormatAndUpdateTextReference(self+0x50,formatted);
 }else if(equipment) {
 if(*(short*)(equipment+0x18)>0) {
 char replaced[128];__clear(replaced,128);
 char formatted[128];__clear(formatted,128);
 String_ReplaceBracketedNamesByRowColumnTable(*(signed char**)(equipment+4),(signed char*)replaced,1,0,0,0);
 Text_FormatAndConditionallyUppercaseOutput(replaced,formatted,0);
 TextMarkup_ExpandAndWrapText((void*)TextContext_GetSharedInstance(),10,formatted,replaced,256,0,0);
 TextSprite_FormatAndUpdateTextReference(self+0x50,replaced);
 }
 }else if(*(signed char*)(self+0x1c)==6) {
 char* text=(char*)ResourceStringTable_GetTextByKey(*(void**)(self+4),(void*)0x7531);
 TextSprite_FormatAndUpdateTextReference(self+0x50,text);
 }else TextSprite_FormatAndUpdateTextReference(self+0x50,BattleMenu_EmptyCommandLabel);
 }
 BattleMenu_BroadcastPartyDisplayStats(self);
}
