#include <globaldefs.h>
#include <std_library_functions.h>
#include "World/Zone3DEmbeddedState.h"
struct StatWord { unsigned low:10, middle:10, high:10, flags:2; };
struct StatBlock { StatWord fields[3]; unsigned reserved[3]; };
struct Slot828 { unsigned values[10]; short identifier, padding; };
struct State828 {
 StatBlock primary;
 unsigned counter; short values1c[2]; unsigned char flag20, copy21[22], padding37[5];
 char name[48]; unsigned short values6c[5], padding76;
 struct { unsigned low:10, middle:20, flag:1, top:1; } features; unsigned char percentages[22], padding92[2], block94[0xa4];
 unsigned indices[13]; short defaults[13]; unsigned char states[13], gap193[0x161];
 Slot828 slots[8]; unsigned char tags[16], status[27], gap47f[9];
 ZoneState0840::Entry::Configuration1a configuration;
 unsigned char fill4a4[0xc0]; short value564, padding566, value568; unsigned char unknown56a;
 struct { unsigned char low:4, high:4; } nibbles;
 unsigned char flags56c[3], gap56f[0x2e1]; unsigned records[13][3];
 unsigned char bytes8ec[36], bytes910[9], padding919[3]; StatBlock secondary;
 unsigned char percentages934[22], padding94a[2]; unsigned mode, value950;
 short tail[8];
};
typedef char State828Size[(sizeof(State828)==0x964)?1:-1];
extern "C" {
void CombatantState_InitializeStatsAndStatusTimers(void*); void CharacterState_ClearPackedStatBonuses(void*); void CharacterState_CopyAttributePercentages(void*,void*);
void CharacterState_InitializeEquipmentDescriptors(State828*); void System_ReadHardwareMacAddress(unsigned char*);
// Original data: arm9/main @ 0x20ef078; symbol: data_020ef078.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25730000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const char InitializeCharacterStateArraysAndDefaults_FormatNineCC[], UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3[];
}
// Original: arm9/main @ 0x02082828; symbol: func_02082828; size: 0x4B4.
extern "C" ARM void InitializeCharacterStateArraysAndDefaults(State828* s) {
 s->value568= -1;
 for(unsigned char i=0;i<13;i++){s->defaults[i]=1;s->states[i]=0;s->indices[i]=0;}
 s->mode=5;s->value950=0;s->tail[0]=0;
 memset(s->name,0,48);
 s->values6c[0]=1;s->values6c[1]=0;s->values6c[2]=0;s->values6c[3]=0;s->values6c[4]=0;
 s->features.low=0;s->features.flag=0;
 memset(s->percentages,100,22); memset(&s->primary,0,24);s->primary.fields[2].middle=1;
 memset(&s->secondary,0,24);s->secondary.fields[2].middle=1;memset(s->percentages934,100,22);
 CombatantState_InitializeStatsAndStatusTimers(s->block94);
 for(int i=0;i<13;i++)CharacterState_ClearPackedStatBonuses(s->records[i]);
 s->configuration.Reset();memset(s->fill4a4,-1,192);
 s->primary.fields[0].low=s->secondary.fields[0].low=0;
 s->primary.fields[0].high=s->secondary.fields[0].high=0;
 s->primary.fields[0].middle=s->secondary.fields[0].middle=0;
 s->primary.fields[1].low=s->secondary.fields[1].low=0;
 s->primary.fields[1].middle=s->secondary.fields[1].middle=0;
 s->primary.fields[1].high=s->secondary.fields[1].high=0;
 s->primary.fields[2].low=s->secondary.fields[2].low=0;
 s->primary.fields[2].middle=s->secondary.fields[2].middle=1;
 s->primary.fields[2].high=s->secondary.fields[2].high=0;
 s->values6c[0]=s->primary.fields[2].middle;s->values6c[1]=s->primary.fields[2].high;
 s->value564=0;s->flags56c[0]=0;s->flags56c[1]=0;s->flags56c[2]=0;
 s->values1c[0]=s->values6c[0];s->values1c[1]=s->values6c[1];
 CharacterState_CopyAttributePercentages(s->copy21,s->percentages);s->counter=0;s->flag20=0;
 memset(s->tags,-1,16);memset(s->status,0,27);CharacterState_InitializeEquipmentDescriptors(s);
 memset(s->bytes8ec,0,36);memset(s->bytes910,0,9);
 for(unsigned char i=0;i<8;i++){
 s->slots[i].values[0]=0;s->slots[i].values[1]=0;s->slots[i].values[2]=0;s->slots[i].values[3]=0;s->slots[i].values[4]=0;
 s->slots[i].values[5]=0;s->slots[i].values[6]=0;s->slots[i].values[7]=0;s->slots[i].values[8]=0;s->slots[i].values[9]=0;s->slots[i].identifier= -1;}
 unsigned char identifier[6];char text[18];System_ReadHardwareMacAddress(identifier);
 int a=(identifier[0]+identifier[2]+identifier[4])%26;
 int b=(identifier[1]+identifier[3]+identifier[5])%26;
 sprintf(text,InitializeCharacterStateArraysAndDefaults_FormatNineCC,(signed char)(a+65),(signed char)(b+65));sprintf(s->name,UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3,text);
 s->tail[1]=0;s->tail[2]= -1;s->tail[3]=0;s->tail[4]=0;s->tail[5]= -1;s->tail[6]=0;s->tail[7]=0;
 s->nibbles.low=0;s->nibbles.high=0;
}
