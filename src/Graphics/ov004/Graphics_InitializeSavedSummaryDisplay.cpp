#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Tree; struct State; struct Record;
struct Vec { int x,y,z; };
struct DisplayObject { virtual void F0(); virtual void F1(); virtual void F2(); virtual void F3(); virtual void F4(); virtual void F5(); virtual void F6(); virtual void SetPosition(Vec*); };
struct Packed { unsigned a:14,b:17,c:1; unsigned d:14,e:17,f:1; unsigned g:7,h:7,i:7,j:7,k:4; unsigned l:10,m:14,n:7,o:1; unsigned p:9,q:14,r:7,s:2; short t; unsigned char u:1,v:7; };
struct Summary { char pad[0x180]; unsigned a,b,c; unsigned short color; unsigned short pad18e; unsigned char* source; Packed* packed; unsigned char flag; char pad199[3]; void* buffer; unsigned char active; };
extern "C" {
extern Summary* data_ov004_02171030; extern Vec data_ov004_021700d4;
void* _ZN9GameState11GetInstanceEv(); void* _ZN9GameState14GetProtagonistEv(void*);
void* Object_GetGlobalConnectionState(); unsigned ReadValue_Main0202BA00(void*);
void GameState_CopyElapsedTimeIntoTwoConfigurationRecords(int);
Tree* FindTreeNodeForwarder(Tree*,unsigned);
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
bool GameState_CopyB0ByteStateBufferToOutput(void*); int GameState_CopyFourByteFieldAtOffset7AC0(void*);
void* memset(void*,int,unsigned);
unsigned ComputePercentOf307WithNonzeroMinimumOne(Record*); unsigned Object_ComputeNonzeroPercentageOf232(Record*); unsigned ComputeNonzeroScaledPercentOf944(Record*); unsigned ComputePercentOf448WithNonzeroMinimumOne(unsigned*);
void* ReadGlobalValueAt020FB3F0(); unsigned short _ZN12ZoneFeatures8GetColorEv(void*);
void* GameResources_GetInstance(); int ReadValue_Main0203B498(void*); unsigned ReadWordFieldAtOffset4(void*); unsigned Object_ReadWordAtOffset8(void*);
void SetWordMaskBits_Main0203B4A0(unsigned*,unsigned); void Object_SetUnsignedIntAtOffset4(int,unsigned);
void WriteCaptureControlRegisterPair(unsigned,unsigned,unsigned short,unsigned,int);
void* HasTypeSevenAtResolvedHandle(void*,unsigned); void func_ov011_021848a0(State*,unsigned); void* Ov004_FindObjectWithFieldEleven(void*,unsigned);
unsigned ReadWordFieldAtOffset1C(); void ResetGlobalOwnerAndEmbeddedSelectionState(void*); void WriteWordPairAtOffsets4And8(void*,int,int);
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
 unsigned char* connection=(unsigned char*)Object_GetGlobalConnectionState();
 unsigned char* entry=gs+0x74c0;
 for(int i=0;i<3;i++,entry+=10) if((signed char)entry[6]>=4 && (entry[7]||entry[8]||(signed char)entry[9]>=0)) return 1;
 unsigned mode=ReadValue_Main0202BA00(connection); int count=connection[0x100d]; int both=0;
 if((mode==5&&count>1)||mode==6)both=1;
 GameState_CopyElapsedTimeIntoTwoConfigurationRecords(both);
 data_ov004_02171030=0;
 unsigned char* owner=(unsigned char*)FindTreeNodeForwarder(root,0);
 if(!owner)return 0;
 data_ov004_02171030=(Summary*)_ZN13SafeAllocator8AllocateEj((unsigned)(owner+4),0x1a4);
 if(!data_ov004_02171030)return 0;
 Summary* init=data_ov004_02171030;
 init->a=0; init->b=0; init->c=0;
 init->color=0; init->flag=0; init->source=0; init->packed=0; init->buffer=0; init->active=1;
 data_ov004_02171030->source=gs+0x71fc;
 unsigned char snapshot[176]; bool valid=GameState_CopyB0ByteStateBufferToOutput(snapshot);
 unsigned value=0; GameState_CopyFourByteFieldAtOffset7AC0(&value); if(value>99999)value=99999;
 unsigned flag=0; unsigned char* protagonist=(unsigned char*)_ZN9GameState14GetProtagonistEv(gs);
 if(protagonist)flag=GetFlag(*(unsigned char**)(protagonist+0x150)+0x49c);
 unsigned char* packedSource=gs+0x569c;
 data_ov004_02171030->packed=(Packed*)_ZN13SafeAllocator8AllocateEj((unsigned)(owner+4),24);
 memset(data_ov004_02171030->packed,0,24);
 if(valid){
 SetA(data_ov004_02171030->packed,*(unsigned short*)snapshot);
 data_ov004_02171030->packed->g=snapshot[2];
 SetD(data_ov004_02171030->packed,*(unsigned short*)(snapshot+4));
 data_ov004_02171030->packed->h=snapshot[6];
 SetE(data_ov004_02171030->packed,Low24(snapshot+8));
 SetB(data_ov004_02171030->packed,value);
 SetL(data_ov004_02171030->packed,Low9(snapshot+16));
 SetP(data_ov004_02171030->packed,*(unsigned*)(snapshot+8)>>24);
 SetM(data_ov004_02171030->packed,(*(unsigned*)(snapshot+12)<<4)>>18);
 SetQ(data_ov004_02171030->packed,(*(unsigned*)(snapshot+16)<<9)>>18);
 data_ov004_02171030->packed->i=(unsigned char)ComputePercentOf307WithNonzeroMinimumOne((Record*)snapshot);
 data_ov004_02171030->packed->j=(unsigned char)Object_ComputeNonzeroPercentageOf232((Record*)snapshot);
 data_ov004_02171030->packed->n=(unsigned char)ComputeNonzeroScaledPercentOf944((Record*)snapshot);
 data_ov004_02171030->packed->r=(unsigned char)ComputePercentOf448WithNonzeroMinimumOne((unsigned*)snapshot);
 data_ov004_02171030->packed->t=(int)(*(unsigned*)(packedSource+4)<<2)>>21;
 data_ov004_02171030->packed->u=(unsigned char)flag;
 }
 data_ov004_02171030->buffer=_ZN13SafeAllocator8AllocateEj((unsigned)(owner+4),0x800); memset(data_ov004_02171030->buffer,0,4);
 unsigned char* zone=(unsigned char*)ReadGlobalValueAt020FB3F0(); if(!zone)return 0; zone+=0x6c; if(!zone)return 0;
 data_ov004_02171030->color=_ZN12ZoneFeatures8GetColorEv(zone);
 unsigned char* resources=(unsigned char*)GameResources_GetInstance();
 data_ov004_02171030->a=ReadValue_Main0203B498(resources); data_ov004_02171030->b=ReadWordFieldAtOffset4(resources); data_ov004_02171030->c=Object_ReadWordAtOffset8(resources);
 SetWordMaskBits_Main0203B4A0((unsigned*)resources,4); Object_SetUnsignedIntAtOffset4((int)resources,0x8de); WriteCaptureControlRegisterPair(0,0,0x7fff,0,0);
 unsigned char* node=(unsigned char*)HasTypeSevenAtResolvedHandle(root,100);
 if(data_ov004_02171030->source[0]<=8){*(short*)(node+0x5c)=0;*(short*)(node+0x5e)=1;}else{*(short*)(node+0x5c)=0;*(short*)(node+0x5e)=2;}
 unsigned char* rd=*(unsigned char**)(resources+0x3b84);
 if(!data_ov004_02171030->source[0])func_ov011_021848a0((State*)root,101);
 else if(rd[9]){func_ov011_021848a0((State*)root,103); void* object=Ov004_FindObjectWithFieldEleven(root,2); Vec position=data_ov004_021700d4; ((DisplayObject*)object)->SetPosition(&position);}
 else func_ov011_021848a0((State*)root,100);
 unsigned char* text=(unsigned char*)ReadWordFieldAtOffset1C(); ResetGlobalOwnerAndEmbeddedSelectionState(text); text[0x1962]=1; WriteWordPairAtOffsets4And8(text+0x1964,9,1); WriteWordPairAtOffsets4And8(text+0x1988,25,1); return 0;
}
