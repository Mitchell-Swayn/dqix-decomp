#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/Script.h>
#include <Resource/GameResources.h>
#include <std_library_functions.h>
extern "C" unsigned short* ReadGlobalValueAt020FB3F0();
extern "C" void *ReadGlobalAt02105AB4();extern "C" unsigned *Graphics_GetGlobalBackgroundState();
extern "C" int Object_TestSelectedFloatWithinSixteen(GameResources*,int);
extern "C" void Graphics_AdvanceSubBrightnessTowardExtreme(void*,int),InitializeStateFieldsAndFourEntries(void*),Graphics_ConfigureSubDisplayForThreeBackgrounds(void*),ClearThreeThirtyTwoByteMemoryRegions(void*),ResetEmbeddedRecordAt10(void*),Graphics_InitializeSubOamStagingState(void*),Graphics_UploadDirtySubBackgroundScreenMaps(void*);
extern "C" unsigned Graphics_AppendAndUploadBackgroundCharacterData(void*,int,unsigned short,const void*,unsigned,unsigned);
extern "C" void FillSelectedBankBufferAndMarkSlot(void*,int,int,unsigned);
extern "C" void InitializeFixedPointScalesAndInvalidIndices(void*),InitializeRecordBuffersAndEnabledByte(void*),ConsumeLoadedTaskAndInitializeEmbeddedResources(void*,int*,SafeAllocator*),Object_ResetTasksAndFourEntrySlots(void*);
extern "C" void ClearWordsAndHalfwordsAtOffsets8Through18(void*),Graphics_InitializeBackgroundMapFromDataAndPalette(void*,const void*,SafeAllocator*,int,unsigned short),Graphics_SubmitObjectBackgroundParameters(void*,int,int);
extern "C" void CopyObjectXZAndClampScaledCoordinate(void*),BuildActiveAndProtagonistSlotLists(GameResources*),System_WaitForInterruptOneAfterShortDelay(),Object_UpdateGraphicsReadinessAndBrightness(void*),SetBitsForPresentFirstFourGameObjects(void*),WorldMap_ApplyObjectIdFilterRules(void*,int);
extern "C" const char data_020ef67c[],data_020ef692[],data_020ef69f[],data_020ef6b5[];extern "C" char* data_020ef460[];extern "C" unsigned data_020fdc4c[];extern "C" Script::OpcodeLookupEntry data_020ef498[];
// Original: arm9/main @ 0x020227DC; symbol: func_020227dc; size: 0x3B4.
extern "C" void BackgroundLoader_AdvanceQueuedGraphicsLoadState(char *self){
GameState::GetInstance();BackgroundLoader *loader=BackgroundLoader::GetInstance();unsigned short *location=ReadGlobalValueAt020FB3F0();GameResources *resources=GameResources_GetInstance();int i;void *texture=ReadGlobalAt02105AB4();SafeAllocator *allocator;unsigned *background=Graphics_GetGlobalBackgroundState();allocator=&resources->allocator_array_38[12];
if(*(signed char*)(self+0x9c2)==0){Graphics_AdvanceSubBrightnessTowardExtreme(self,25);loader->AddFence();*(int*)(self+0xa24)=loader->QueueLoadFile(data_020ef67c,0);*(int*)(self+0xa20)=loader->QueueLoadFileInGP2(data_020ef460[2],data_020ef692,0);*(int*)(self+0xa28)=loader->QueueLoadFile(data_020ef69f,0);++*(signed char*)(self+0x9c2);}
else if(*(signed char*)(self+0x9c2)==1&&loader->GetTaskStatus(*(int*)(self+0xa24))&&loader->GetTaskStatus(*(int*)(self+0xa20))&&loader->GetTaskStatus(*(int*)(self+0xa28))){Graphics_AdvanceSubBrightnessTowardExtreme(self,25);if(!Object_TestSelectedFloatWithinSixteen(resources,1)){
InitializeStateFieldsAndFourEntries(self);Graphics_ConfigureSubDisplayForThreeBackgrounds(self);ClearThreeThirtyTwoByteMemoryRegions(background);allocator->Reset();ResetEmbeddedRecordAt10(texture);Graphics_InitializeSubOamStagingState(texture);
char empty[32];memset(empty,0,32);Graphics_AppendAndUploadBackgroundCharacterData(background,1,1,empty,32,1);FillSelectedBankBufferAndMarkSlot(background,1,0,0);FillSelectedBankBufferAndMarkSlot(background,1,1,0);Graphics_UploadDirtySubBackgroundScreenMaps(background);
for(i=0;i<28;i++)InitializeFixedPointScalesAndInvalidIndices(self+0xe8+i*40);InitializeRecordBuffersAndEnabledByte(self+0x94);self[0xe4]=1;*(char**)(self+0xd4)=self+0xe8;*(short*)(self+0xe0)=28;*(unsigned*)(self+20)=1;ConsumeLoadedTaskAndInitializeEmbeddedResources(self,(int*)(self+0xa24),allocator);Object_ResetTasksAndFourEntrySlots(self);*(unsigned*)(self+0x24)=1;*(unsigned*)(self+0x30)=1;
void *file=0;unsigned length=0;loader->GetLoadedFileByID(*(int*)(self+0xa20),&file,&length);*(void**)(self+0x20)=allocator->Allocate(36);ClearWordsAndHalfwordsAtOffsets8Through18(*(char**)(self+0x20)+8);Graphics_InitializeBackgroundMapFromDataAndPalette(*(char**)(self+0x20)+8,file,allocator,1,0);Graphics_SubmitObjectBackgroundParameters(*(char**)(self+0x20)+8,0,0);BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self+0xa20));*(int*)(self+0xa20)=-1;
loader->GetLoadedFileByID(*(int*)(self+0xa28),&file,&length);data_020fdc4c[4]=(unsigned)self;data_020fdc4c[2]=(unsigned)allocator;Script script;script.Initialize();script.SetOpcodeLookup(data_020ef498);script.Load(file,length);script.Execute();if(*location==10000||*location==10100){self[0x12]=1;self[0x779]=0;self[0x9ba]=0;strcpy(self+2,data_020ef6b5);}BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self+0xa28));*(int*)(self+0xa28)=-1;CopyObjectXZAndClampScaledCoordinate(self);BuildActiveAndProtagonistSlotLists(resources);self[0x55c]=1;self[0x9c4]=1;self[0x9c8]=0;self[0x9c3]=0;++*(signed char*)(self+0x9c2);System_WaitForInterruptOneAfterShortDelay();Object_UpdateGraphicsReadinessAndBrightness(self);SetBitsForPresentFirstFourGameObjects(self);WorldMap_ApplyObjectIdFilterRules(self,0);}}
}
