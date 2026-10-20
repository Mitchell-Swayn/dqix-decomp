#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Tree; struct State; struct Record;
struct Vec { int x,y,z; };
struct DisplayObject { virtual void F0(); virtual void F1(); virtual void F2(); virtual void F3(); virtual void F4(); virtual void F5(); virtual void F6(); virtual void SetPosition(Vec*); };
struct Packed { unsigned a:14,b:17,c:1; unsigned d:14,e:17,f:1; unsigned g:7,h:7,i:7,j:7,k:4; unsigned l:10,m:14,n:7,o:1; unsigned p:9,q:14,r:7,s:2; short t; unsigned char u:1,v:7; };
struct Summary { char pad[0x180]; unsigned a,b,c; unsigned short color; unsigned short pad18e; unsigned char* source; Packed* packed; unsigned char flag; char pad199[3]; void* buffer; unsigned char active; };
extern "C" {
// Original data: arm9/ov004 @ 0x21700d4; symbol: data_ov004_021700d4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0040020000a0020000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
// Original data: arm9/ov004 @ 0x2171030; symbol: data_ov004_02171030.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern Summary* MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage; extern Vec GraphicsInitializeSavedSummaryDisplay_UnknownRoleInitializedBytes;
void* _ZN9GameState11GetInstanceEv(); void* _ZN9GameState14GetProtagonistEv(void*);
void* Network_GetConnectionManager(); unsigned Network_GetSessionPhase(void*);
void GameState_CopyElapsedTimeIntoTwoConfigurationRecords(int);
Tree* Menu_FindSessionArenaById(Tree*,unsigned);
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
bool GameState_CopyStatisticsRecord(void*); int GameState_CopyAlchemyOperationCount(void*);
void* memset(void*,int,unsigned);
unsigned GameStats_GetCompletionPercentOf307(Record*); unsigned GameStats_GetCompletionPercentOf232(Record*); unsigned GameStats_GetCompletionPercentOf944(Record*); unsigned GameStats_GetCompletionPercentOf448(unsigned*);
void* Zone3D_GetMainInstance(); unsigned short _ZN12ZoneFeatures8GetColorEv(void*);
void* GameResources_GetInstance(); int GameResources_GetPrimaryFlags(void*); unsigned GameResources_GetSecondaryFlags(void*); unsigned GameResources_GetTertiaryFlags(void*);
void GameResources_SetPrimaryFlags(unsigned*,unsigned); void GameResources_SetSecondaryFlags(int,unsigned);
void G3X_SetClearColor(unsigned,unsigned,unsigned short,unsigned,int);
void* TileGrid_ResolveByKey(void*,unsigned); void Menu_QueueScriptEntry(State*,unsigned); void* Ov004_FindObjectWithFieldEleven(void*,unsigned);
unsigned TextContext_GetSharedInstance(); void TextWindow_ResetGlyphBuffersAndFrameContexts(void*); void WindowControl_SetInsideMaskWithEffect(void*,int,int);
}
#pragma always_inline on
struct Bits24 {unsigned a:24,b:8;};
inline unsigned Low24(void* x){return ((Bits24*)x)->a;}
struct Bits9 {unsigned a:9,b:23;};
inline unsigned Low9(void* x){return ((Bits9*)x)->a;}
struct Flag { unsigned char a:1,b:7; };
inline unsigned GetFlag(unsigned char* p){return ((Flag*)p)->a;}
inline void SetA(Packed* p,unsigned x){p->a=x;}
inline void SetD(Packed* p,unsigned x){p->d=x;}
inline void SetE(Packed* p,unsigned x){p->e=x;}
inline void SetB(Packed* p,unsigned x){p->b=x;}
inline void SetL(Packed* p,unsigned x){p->l=x;}
inline void SetP(Packed* p,unsigned x){p->p=x;}
inline void SetM(Packed* p,unsigned x){p->m=x;}
inline void SetQ(Packed* p,unsigned x){p->q=x;}
// Original: arm9/ov004 @ 0x02168B44; symbol: func_ov004_02168b44; size: 0x600.
extern "C" int Graphics_InitializeSavedSummaryDisplay(Tree* root) {
 unsigned char* gs=(unsigned char*)_ZN9GameState11GetInstanceEv();
 unsigned char* connection=(unsigned char*)Network_GetConnectionManager();
 unsigned char* entry=gs+0x74c0;
 for(int i=0;i<3;i++,entry+=10) if((signed char)entry[6]>=4 && (entry[7]||entry[8]||(signed char)entry[9]>=0)) return 1;
 unsigned mode=Network_GetSessionPhase(connection); int count=connection[0x100d]; int both=0;
 if((mode==5&&count>1)||mode==6)both=1;
 GameState_CopyElapsedTimeIntoTwoConfigurationRecords(both);
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage=0;
 unsigned char* owner=(unsigned char*)Menu_FindSessionArenaById(root,0);
 if(!owner)return 0;
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage=(Summary*)_ZN13SafeAllocator8AllocateEj((unsigned)(owner+4),0x1a4);
 if(!MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage)return 0;
 Summary* init=MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage;
 init->a=0; init->b=0; init->c=0;
 init->color=0; init->flag=0; init->source=0; init->packed=0; init->buffer=0; init->active=1;
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->source=gs+0x71fc;
 unsigned char snapshot[176]; bool valid=GameState_CopyStatisticsRecord(snapshot);
 unsigned value=0; GameState_CopyAlchemyOperationCount(&value); if(value>99999)value=99999;
 unsigned flag=0; unsigned char* protagonist=(unsigned char*)_ZN9GameState14GetProtagonistEv(gs);
 if(protagonist)flag=GetFlag(*(unsigned char**)(protagonist+0x150)+0x49c);
 unsigned char* packedSource=gs+0x569c;
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed=(Packed*)_ZN13SafeAllocator8AllocateEj((unsigned)(owner+4),24);
 memset(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed,0,24);
 if(valid){
 SetA(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed,*(unsigned short*)snapshot);
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed->g=snapshot[2];
 SetD(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed,*(unsigned short*)(snapshot+4));
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed->h=snapshot[6];
 SetE(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed,Low24(snapshot+8));
 SetB(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed,value);
 SetL(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed,Low9(snapshot+16));
 SetP(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed,*(unsigned*)(snapshot+8)>>24);
 SetM(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed,(*(unsigned*)(snapshot+12)<<4)>>18);
 SetQ(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed,(*(unsigned*)(snapshot+16)<<9)>>18);
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed->i=(unsigned char)GameStats_GetCompletionPercentOf307((Record*)snapshot);
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed->j=(unsigned char)GameStats_GetCompletionPercentOf232((Record*)snapshot);
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed->n=(unsigned char)GameStats_GetCompletionPercentOf944((Record*)snapshot);
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed->r=(unsigned char)GameStats_GetCompletionPercentOf448((unsigned*)snapshot);
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed->t=(int)(*(unsigned*)(packedSource+4)<<2)>>21;
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->packed->u=(unsigned char)flag;
 }
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->buffer=_ZN13SafeAllocator8AllocateEj((unsigned)(owner+4),0x800); memset(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->buffer,0,4);
 unsigned char* zone=(unsigned char*)Zone3D_GetMainInstance(); if(!zone)return 0; zone+=0x6c; if(!zone)return 0;
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->color=_ZN12ZoneFeatures8GetColorEv(zone);
 unsigned char* resources=(unsigned char*)GameResources_GetInstance();
 MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->a=GameResources_GetPrimaryFlags(resources); MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->b=GameResources_GetSecondaryFlags(resources); MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->c=GameResources_GetTertiaryFlags(resources);
 GameResources_SetPrimaryFlags((unsigned*)resources,4); GameResources_SetSecondaryFlags((int)resources,0x8de); G3X_SetClearColor(0,0,0x7fff,0,0);
 unsigned char* node=(unsigned char*)TileGrid_ResolveByKey(root,100);
 if(MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->source[0]<=8){*(short*)(node+0x5c)=0;*(short*)(node+0x5e)=1;}else{*(short*)(node+0x5c)=0;*(short*)(node+0x5e)=2;}
 unsigned char* rd=*(unsigned char**)(resources+0x3b84);
 if(!MenuRefreshSavedRecordPageRows_UnknownRoleZeroInitializedStorage->source[0])Menu_QueueScriptEntry((State*)root,101);
 else if(rd[9]){Menu_QueueScriptEntry((State*)root,103); void* object=Ov004_FindObjectWithFieldEleven(root,2); Vec position=GraphicsInitializeSavedSummaryDisplay_UnknownRoleInitializedBytes; ((DisplayObject*)object)->SetPosition(&position);}
 else Menu_QueueScriptEntry((State*)root,100);
 unsigned char* text=(unsigned char*)TextContext_GetSharedInstance(); TextWindow_ResetGlyphBuffersAndFrameContexts(text); text[0x1962]=1; WindowControl_SetInsideMaskWithEffect(text+0x1964,9,1); WindowControl_SetInsideMaskWithEffect(text+0x1988,25,1); return 0;
}
