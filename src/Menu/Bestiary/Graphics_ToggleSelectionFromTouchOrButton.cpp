#include <globaldefs.h>
ARM
extern "C" {
unsigned char* TextCanvas_FindDisplayPartByKey(unsigned char*,unsigned);
int TextCanvas_HasActiveTilemap(char*);
int ReadSelectedCoordinatePair(void*,int*,int*);
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
char* BestiaryScreen_ResolveSelectedMonster(char*);
void* Util_FilterAndRebuildNodeList(void*,int,int,int,int,short*);
void BestiaryScreen_SelectPageContainingEntry(char*,char*);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void TextCanvas_ClearGroupEntrySelection(unsigned char*,int);
void Graphics_SetRecordOptionIndexDisplay(char*);
void Graphics_PopulateRecordListPage(char*);
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage[];
}
struct NodeFlags { unsigned char a:1; unsigned char enabled:1; unsigned char b:6; };
// Original: arm9/ov014 @ 0x02187074; symbol: func_ov014_02187074; size: 0x1B4.
extern "C" int Graphics_ToggleSelectionFromTouchOrButton(char* self) {
 int active=0;
 char* record=(char*)TextCanvas_FindDisplayPartByKey(*(unsigned char**)(self+0xc0),4);
 if(record && TextCanvas_HasActiveTilemap(record)) {
  short bottom=*(short*)(record+0xae);
  short height=*(short*)(record+0xaa);
  bottom--;
  height++;
  short x=*(short*)(record+0xac);
  short width=*(short*)(record+0xa8);
  x*=8;
  bottom*=8;
  short right=x+(short)(width*8);
  short end=bottom+(short)(height*8);
  if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]) {
   int px,py;
   ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&px,&py);
   if(x<=px && px<right && bottom<=py && py<end)active=1;
  }
 }
 if(Input_IsKeyMaskNewlyPressed((unsigned short*)KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,4))active=1;
 if(active) {
  char* target=BestiaryScreen_ResolveSelectedMonster(self);
  if(!target)return 0;
  if(!((NodeFlags*)(target+0x13))->enabled) {
   *(short*)(self+0x176)=-1;
   *(short*)(self+0x178)=-1;
   target=0;
  }
  if((*(unsigned char*)(self+0x17e))&8)(*(unsigned char*)(self+0x17e))&=~8;
  else (*(unsigned char*)(self+0x17e))|=8;
  short value=0;
  *(void**)(self+0xb8)=Util_FilterAndRebuildNodeList(self+0xa4,*(signed char*)(self+0x17d),-1,((*(unsigned char*)(self+0x17e))&8)!=0,16,&value);
  BestiaryScreen_SelectPageContainingEntry(self,target);
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
  TextCanvas_ClearGroupEntrySelection(*(unsigned char**)(self+0xc0),5);
  Graphics_SetRecordOptionIndexDisplay(self);
  Graphics_PopulateRecordListPage(self);
 }
 return active;
}
