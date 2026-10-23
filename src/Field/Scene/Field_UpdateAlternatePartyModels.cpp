#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
ARM
extern "C" {
GameResources* GameResources_GetInstance();
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
void* GameResources_FindUnusedPartyResourceRecord(void*);
void TextureVRAM_SnapshotAllocationBounds(char*);
void Graphics_RestoreTextureImageAndPaletteVRAMState(const unsigned char*);
void Object_InvokeSaveTextureImageVRAMState(char*);
int Field_QueuePartyMemberEquipmentRefresh(unsigned char*,int,int,int,int);
void Resource_SetIndexedObjectCodeAndApply(int);
int Resource_ApplyUpdateOnlyWhenValidationPasses(void*,unsigned,unsigned);
extern char Field_UpdateAlternatePartyModels_PathDataCharaSubS023N2Chr[];
extern char Field_UpdateAlternatePartyModels_PathDataCharaSubS069Chr[];
extern char Field_UpdateAlternatePartyModels_PathDataPackLv5CharaPdGp2[];
extern char Field_UpdateAlternatePartyModels_TextDWingChr[];
extern char Field_UpdateAlternatePartyModels_TextDWaChr[];
extern char Field_UpdateAlternatePartyModels_TextStand[];
extern char Field_UpdateAlternatePartyModels_TextRun[];
}
#define B(p,n) (*(unsigned char*)((char*)(p)+(n)))
#define H(p,n) (*(short*)((char*)(p)+(n)))
#define W(p,n) (*(unsigned*)((char*)(p)+(n)))
#define P(p,n) (*(Object3D**)((char*)(p)+(n)))
struct ModelRequest {unsigned char prefix[8];short tasks[4];unsigned char state,type;};
#pragma force_active on
// Original: arm9/ov017 @ 0x021BDC34; symbol: func_ov017_021bdc34; size: 0x468.
// Loads the four alternate party models, updates their equipment state, and chooses the requested animation.
extern "C" void Field_UpdateAlternatePartyModels(unsigned char* self) {
    GameState* game=GameState::GetInstance();
    GameResources* resources=GameResources_GetInstance();
    BackgroundLoader* loader=BackgroundLoader::GetInstance();
    GameObject* actor=GameState_GetObjectWithFlag100(game,0);
    if(!actor) return;
    char* record=(char*)GameResources_FindUnusedPartyResourceRecord(resources);
    if(!record) {self[1]=1;return;}
    SafeAllocator* allocators[4]={(SafeAllocator*)(record+4),(SafeAllocator*)(record+4),(SafeAllocator*)(record+0x52c),(SafeAllocator*)(record+4)};
    char* textures[4]={record+0xcc,record+0xcc,record+0x1ac,record+0xcc};
    if(!self[0x10]) {
        int type=self[0x11];
        if(type==1 && P(resources,0x4334) && P(resources,0x4338) && (W(actor,0x18c)&0x40)) {self[1]=1;return;}
        if(type==2 && P(resources,0x4334) && P(resources,0x4338) && !(W(actor,0x18c)&0x40)) {self[1]=1;return;}
        if(type==0 && !P(resources,0x4334) && !P(resources,0x4338) && !(W(actor,0x18c)&0x40)) {self[1]=1;return;}
        if(self[0x11]==1 || self[0x11]==2) {
            if(!P(resources,0x4334)) {
                H(self,8)=loader->QueueLoadFile(Field_UpdateAlternatePartyModels_PathDataCharaSubS023N2Chr,0);
                H(self,10)=loader->QueueLoadFile(Field_UpdateAlternatePartyModels_PathDataCharaSubS069Chr,0);
                H(self,12)=loader->QueueLoadFileInGP2(Field_UpdateAlternatePartyModels_PathDataPackLv5CharaPdGp2,Field_UpdateAlternatePartyModels_TextDWingChr,0);
                H(self,14)=loader->QueueLoadFileInGP2(Field_UpdateAlternatePartyModels_PathDataPackLv5CharaPdGp2,Field_UpdateAlternatePartyModels_TextDWaChr,0);
                for(int i=0;i<4;++i) {allocators[i]->Reset();TextureVRAM_SnapshotAllocationBounds(textures[i]);}
            } else {for(int i=0;i<4;++i) ((ModelRequest*)self)->tasks[i]=-1;}
            if(self[0x11]==1) W(actor,0x18c)|=0x40;
            else W(actor,0x18c)&=~0x40;
            Field_QueuePartyMemberEquipmentRefresh((unsigned char*)resources,0,1,0,0);
            self[0x10]=1;
        } else {
            P(resources,0x4334)=0;
            P(resources,0x4338)=0;
            P(resources,0x433c)=0;
            P(resources,0x4340)=0;
            if(actor) W(actor,0x18c)&=~0x40;
            Field_QueuePartyMemberEquipmentRefresh((unsigned char*)resources,0,1,0,0);
            self[0x10]=2;
        }
    } else if(self[0x10]==1) {
        int waiting=0;
        for(int i=0;i<4;++i) {
            if(((ModelRequest*)self)->tasks[i]<0) continue;
            if(loader->GetTaskStatus(((ModelRequest*)self)->tasks[i]) && loader->GetDetailedTaskStatus(((ModelRequest*)self)->tasks[i])==2) {
                void* file;
                unsigned length;
                loader->GetLoadedFileByID(((ModelRequest*)self)->tasks[i],&file,&length);
                SafeAllocator* allocator=allocators[i];
                Object3D* object=(Object3D*)allocator->Allocate(0xac);
                if(file && object) {
                    ObjectArchiveLoadInfo info;
                    info.unk_0=0;
                    info.fileData=file;
                    info.unk_8=length;
                    info.allocator=allocator;
                    info.unk_14=0;
                    info.unk_18=0;
                    info.packageID=0;
                    info.unk_10=1;
                    char* texture=textures[i];
                    Graphics_RestoreTextureImageAndPaletteVRAMState((unsigned char*)texture);
                    object->Initialize();
                    object->LoadFromCCHROrCMOTArchive(&info,0);
                    Object_InvokeSaveTextureImageVRAMState(texture);
                    switch(i) {
                    case 0:P(resources,0x4334)=object;break;
                    case 1:P(resources,0x4338)=object;break;
                    case 2:P(resources,0x433c)=object;break;
                    case 3:P(resources,0x4340)=object;break;
                    }
                }
                loader->RemoveTask(((ModelRequest*)self)->tasks[i]);
                ((ModelRequest*)self)->tasks[i]=-1;
            } else waiting=1;
        }
        if(!waiting) self[0x10]=2;
    } else if(self[0x10]==2) {
        if(self[0x11]==1) Resource_SetIndexedObjectCodeAndApply(0);
        else {H(actor,0x9c)=0;Resource_ApplyUpdateOnlyWhenValidationPasses(resources,0,0);}
        Object3D* object=P(resources,0x4334);
        if(object) {
            if(self[0x11]==1) object->SetAnimationByName(Field_UpdateAlternatePartyModels_TextStand,0);
            else object->SetAnimationByName(Field_UpdateAlternatePartyModels_TextRun,0);
        }
        self[1]=1;
    }
}
#pragma force_active off
