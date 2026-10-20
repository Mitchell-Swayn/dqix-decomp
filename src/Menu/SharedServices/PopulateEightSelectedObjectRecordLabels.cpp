#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct State;
extern "C" {
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
void* Menu_FindInventoryTextEntryByKey(State*,unsigned);
void* Menu_FindInventoryTextCanvasByKey(State*,unsigned);
int Menu_GetSelectedInventoryPartyMember(void*);
void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*,void*);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern char* MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[3];
}
struct Indices {unsigned char data[8];};
// Original data: arm9/ov004 @ 0x216fb10; symbol: data_ov004_0216fb10.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 080907000501060a.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" Indices PopulateEightSelectedObjectRecordLabels_UnknownRoleInitializedBytes;
struct Entry {unsigned unused;const char* text;unsigned kind:4,other:28;char padding[12];short count;char tail[6];};
struct Widget { virtual void Reserved0(); virtual void Reserved1(); virtual void Reserved2(); virtual void Reserved3(); virtual void Reserved4(); virtual void Reserved5(); virtual void Reserved6(); virtual void Reserved7(); virtual void Reserved8(); virtual void Reserved9(); virtual void Reserved10(); virtual void Reserved11(); virtual void Reserved12(); virtual void Reserved13(); virtual void Reserved14(); virtual void Reserved15(); virtual void Reserved16(); virtual void Reserved17(); virtual void Reserved18(); virtual void Reserved19(); virtual void Reserved20(); virtual void Reserved21(); virtual void Reserved22(); virtual void Reserved23(); virtual void Reserved24(); virtual void Reserved25(); virtual void Reserved26(); virtual void Reserved27(); virtual void Reserved28(); virtual void Reserved29(); virtual void Reserved30(); virtual void Reserved31(); virtual void Reserved32(); virtual void Reserved33(); virtual void Reserved34(); virtual void Reserved35(); virtual void Reserved36(); virtual void Reserved37(); virtual void Reserved38(); virtual void Reserved39(); virtual void Reserved40(); virtual void Reserved41(); virtual void Reserved42(); virtual void Reserved43(); virtual void Reserved44(); virtual void Reserved45(); virtual void Reserved46(); virtual void Reserved47(); virtual void Reserved48(); virtual void Reserved49(); virtual void Reserved50(); virtual void Reserved51(); virtual void Reserved52(); virtual void Reserved53(); virtual void SetStyle(int); };
// Original: arm9/ov004 @ 0x0215951C; symbol: func_ov004_0215951c; size: 0x134.
// Populates eight indexed text entries from positive-count records and applies active/inactive styles.
extern "C" int PopulateEightSelectedObjectRecordLabels(State* self){
 int selected=Menu_GetSelectedInventoryPartyMember(self);
 GameObject* gameObject=GameState_GetObjectWithFlag100(GameState::GetInstance(),selected);
 if(!gameObject)return 0;
 char* object=(char*)gameObject;
 MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2][18]=selected;
 Indices indices=PopulateEightSelectedObjectRecordLabels_UnknownRoleInitializedBytes;
 int id=900;
 for(short i=0;i<8;i++){
  int style=3;const char* text=0;unsigned index=indices.data[i];
  if(index!=255){
   Entry* entry=(Entry*)(*(char**)(object+0x150)+0x194+index*32);
   if(entry && entry->count>0 && entry->kind!=11){
    text=entry->text;
    if(text){if(text[0])style=15;else text=0;}
   }
  }
  Widget* widget=(Widget*)Menu_FindInventoryTextEntryByKey(self,id);
  if(widget){*(const char**)((char*)widget+32)=text;widget->SetStyle(style);}
  id++;
 }
 void* control=Menu_FindInventoryTextCanvasByKey(self,22);
 if(control)MenuTextCanvas_RefreshConfiguredFrameAndContents(control,self);
 return 0;
}
