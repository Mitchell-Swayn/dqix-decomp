#include <globaldefs.h>
ARM
#pragma opt_common_subs off
struct Triple { int values[3]; };
struct Character {
 unsigned char pad0[0x18]; unsigned flags; unsigned short first,second;
 unsigned char pad20[0x3c-0x20]; char name[0x3c]; unsigned unused78:30,special:1,unused79:1;
 unsigned char pad7c[0x138-0x7c]; unsigned values[13]; unsigned short attributes[13]; unsigned char bytes[13];
 unsigned char pad193[0x464-0x193]; unsigned char entries[27];
 unsigned char pad47f[9]; unsigned char region488[28],region4a4[192];
 unsigned short value564; unsigned char pad566[4]; unsigned char mode;
 unsigned char low:4,high:4;
 unsigned char pad56c[0x850-0x56c]; Triple triples[13];
 unsigned char region8ec[36],region910[9]; unsigned char pad919[0x94c-0x919]; unsigned category;
 unsigned value950; unsigned short value954;
};
struct Input {
 unsigned char pad0; unsigned char mode:4,special:1,bank:3; unsigned char attributes[13],bytes[13]; unsigned values[13]; unsigned value50; unsigned short value54;
 unsigned char pad56[2]; Triple triples[13]; unsigned short valuef4; unsigned char entries[27];
 unsigned char region111[9],region11a[36]; unsigned char flags13e; unsigned char high:3,category:5;
 unsigned char text[20]; unsigned packedPad:10,first:10,second:10,packedPad2:2; unsigned char pad158[8]; unsigned char region160[28],region17c[192];
};
extern "C" void InitializeCharacterStateArraysAndDefaults(Character*);
extern "C" void CharacterState_LoadVocationGrowthStats(Character*,int);
extern "C" void CharacterState_CopyVocationStatBonuses(Triple*,const Triple*);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void __clear(void*,unsigned);
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const void*,void*,int);
extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x20ef078; symbol: data_020ef078.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25730000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3[];
// Original: arm9/main @ 0x02082D6C; symbol: func_02082d6c; size: 0x23C.
extern "C" void CharacterState_InitializeFromSerializedRecord(Character* self,const Input* input) {
 if(input) {
  InitializeCharacterStateArraysAndDefaults(self);
  self->mode=input->mode;
  self->value950=input->value50;
  self->value954=input->value54;
  for(int i=0;i<13;++i) {self->attributes[i]=input->attributes[i];self->bytes[i]=input->bytes[i];self->values[i]=input->values[i];}
  CharacterState_LoadVocationGrowthStats(self,0);
  for(int i=0;i<13;++i) CharacterState_CopyVocationStatBonuses(&self->triples[i],&input->triples[i]);
  self->value564=input->valuef4;
  for(int i=0;i<27;++i) self->entries[i]=input->entries[i];
  memcpy(self->region910,input->region111,9);
  memcpy(self->region8ec,input->region11a,36);
  unsigned flags=input->flags13e;
  if(flags&1) self->flags|=1;
  if(flags&2) self->flags|=2;
  if(flags&4) self->flags|=4;
  char text[48];__clear(text,48);
  Text_MapInputBytesToVariableLengthOutputSequences(input->text,text,1);
  sprintf(self->name,UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3,text);
  self->special=input->special;
  self->first=input->first;
  self->second=input->second;
  memcpy(self->region488,input->region160,28);
  self->low=input->bank;
  self->high=input->high;
  memcpy(self->region4a4,input->region17c,192);
  self->category=input->category;
 }
}
