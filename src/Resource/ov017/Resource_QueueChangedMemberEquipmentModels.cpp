#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* _ZN16BackgroundLoader11GetInstanceEv();
unsigned char* GameState_GetObjectWithFlag100(void*,int);
unsigned char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
unsigned char* ReadWordFieldAtOffset150(void*);
unsigned char* GetIndirectField150Address488(void*);
unsigned char* GameResources_GetInstance();
void InitializeElevenContextBoundedResourceRegions(void*,void*);
void GameState_BuildEquipmentObjectIdsAndDefaultValues(int,int*,short*);
char* FindKeyAmongElevenThirtyTwoByteEntries(void*,int);
int Graphics_FormatSelectedRecordValue(char*,int,int,char*,void*);
void _ZN8Object3D10InitializeEv(void*);
void _ZN8Object3D7DestroyEv(void*);
void _ZN13SafeAllocator5ResetEv(void*);
void _ZN16BackgroundLoader8AddFenceEv(void*);
int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
void _ZN8Object3D8SetScaleEiii(void*,int,int,int);
int fix32_Divide(int,int);
void FormatResourceNameWithPartyGenderVariant(int,char*,char*);
void _ZN8Object3D26RemoveAllAnimationPackagesEv(void*);
int sprintf(char*,const char*,...);
extern const char* data_ov017_021d7a38[];
extern char data_ov017_021d7ace[],data_ov017_021d7ad6[];
}
struct EquipmentPart {short pad,key;};
#define FIXMUL(a,b) ((int)(((long long)(a)*(b)+0x800)>>12))
// Original: arm9/ov017 @ 0x021B38C8; symbol: func_ov017_021b38c8; size: 0x54C.
extern "C" int Resource_QueueChangedMemberEquipmentModels(unsigned char* self) {
 void* state;unsigned char* member;
 unsigned char *stats,*part,*resources;
 state=_ZN9GameState11GetInstanceEv();
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 member=GameState_GetObjectWithFlag100(state,*(short*)(self+8));
 if(!member)return 0;
 resources=*(unsigned char**)(member+0x154);
 if(!resources)return 0;
 unsigned char* data=ReadWordFieldAtOffset150(member);
 if(!data)return 0;
 stats=GetIndirectField150Address488(member);
 if(!stats)return 0;
 if(!*(void**)(member+8)){
   unsigned char* all=GameResources_GetInstance();
   int index=*(short*)(self+8);int party=0;
   if(index>=0)party=(index<=3);
   unsigned char* context;
   context=party ? (all+0x2cc)+(*(unsigned short*)(resources+2)+1)*0x70 : (unsigned char*)((unsigned int)(all+0x2cc)+0x930);
   InitializeElevenContextBoundedResourceRegions(resources,context);
 }
 char path[128];char animation[80];int ids[11];short values[12];char name[40];char alternate[40];
 GameState_BuildEquipmentObjectIdsAndDefaultValues(*(short*)(self+8),ids,values);
 unsigned char* object=_ZN9GameState20GetGameObjectByIndexEi(state,ids[7]);
 if(object && values[7]!=*(short*)(object+2)){
   unsigned char* a=_ZN9GameState20GetGameObjectByIndexEi(state,ids[3]);
   unsigned char* b=_ZN9GameState20GetGameObjectByIndexEi(state,ids[4]);
   if(a)*(short*)(a+2)=-1;if(b)*(short*)(b+2)=-1;
 }
 object=_ZN9GameState20GetGameObjectByIndexEi(state,ids[1]);
 if(object && values[1]!=*(short*)(object+2)){
   object=_ZN9GameState20GetGameObjectByIndexEi(state,ids[0]);if(object)*(short*)(object+2)=-1;
 }
 if(values[0]!=*(short*)(member+2) && *(short*)(stats+8)<0){object=_ZN9GameState20GetGameObjectByIndexEi(state,ids[5]);if(object)*(short*)(object+2)=-1;}
 int reload=self[11]&2;
 object=_ZN9GameState20GetGameObjectByIndexEi(state,ids[8]);
 if(object && values[8]!=*(short*)(object+2))reload=1;
 int first;
 int force=self[11]&1;self[11]&=~1;
 int changed=0;first=1;
 FindKeyAmongElevenThirtyTwoByteEntries(data,values[7]);
 for(int i=0;i<11;i++){
   part=_ZN9GameState20GetGameObjectByIndexEi(state,ids[i]);
   if(!part)continue;
   if(!force){short expected=values[i];if(expected==((EquipmentPart*)part)->key)continue;}
   *(short*)(part+2)=values[i];
   if(values[i]<0)continue;
   char* entry=FindKeyAmongElevenThirtyTwoByteEntries(data,values[i]);
   if(!entry)continue;
   if(!Graphics_FormatSelectedRecordValue(path,*(short*)(self+8),i,entry,data+0x194)){
     _ZN8Object3D10InitializeEv(part);*(short*)(part+2)=values[i];continue;
   }
   _ZN8Object3D7DestroyEv(part);
   void* allocator=resources+4+i*20;
   _ZN13SafeAllocator5ResetEv(allocator);
   if(first){_ZN16BackgroundLoader8AddFenceEv(loader);first=0;}
   *(int*)(self+0x10+i*4)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_ov017_021d7a38[0],path,allocator);
   if((unsigned)i<=1){
     int scale=*(short*)(stats+0x1a);
     short x=(short)(int)(0.065f*(float)FIXMUL(scale,*(short*)(stats+0x18)));
     short y=(short)(int)(0.065f*(float)scale);
     _ZN8Object3D8SetScaleEiii(part,x,y,x);
     reload=1;
   }else if(i==2 || i==3 || (unsigned)(i-7)<=2){
     int x=fix32_Divide(0x1000,FIXMUL(*(short*)(stats+0x1a),*(short*)(stats+0x18)));
     int y=fix32_Divide(0x1000,*(short*)(stats+0x1a));
     int z=x;
     if(i==2 || i==3 || i==7){
       int scale=*(short*)(stats+0x1a);
       scale=scale-((scale-0x1000)>>1);
       x=FIXMUL(x,scale);y=FIXMUL(y,scale);z=FIXMUL(z,scale);
     }
     _ZN8Object3D8SetScaleEiii(part,x,y,z);
   }
   if(i==8 || i==1)reload=1;
   changed=1;
 }
 if(reload){
   FormatResourceNameWithPartyGenderVariant(*(short*)(self+8),name,alternate);
   if(self[11]&4){name[0]='m';sprintf(animation,data_ov017_021d7ace,name);self[11]&=~4;}
   else sprintf(animation,data_ov017_021d7ad6,name);
   _ZN8Object3D26RemoveAllAnimationPackagesEv(member);
   _ZN13SafeAllocator5ResetEv(resources+0x52c);
   _ZN13SafeAllocator5ResetEv(resources+0x540);
   *(int*)(self+0x3c)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_ov017_021d7a38[1],animation,resources+0x52c);
   sprintf(animation,data_ov017_021d7ad6,alternate);
   *(int*)(self+0x44)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_ov017_021d7a38[1],animation,0);
   changed=1;
 }
 return changed;
}
