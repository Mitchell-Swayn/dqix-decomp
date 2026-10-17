#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" int Unclassified_IsGlobalObjectMissingOrByte18Zero();
extern "C" int IsGlobalControlAbsentOrByte19Clear();
extern "C" void Network_UnlinkNodeAndReleaseRecords(void*);
extern "C" void Overlay_ClearFourSharedObjects();
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void Unclassified_FreeArgumentAndUpdateGlobalOwner(void*);
extern "C" void System_LoadResourceAndInvokeCallback(void*,void(*)());
extern "C" void LoadToMainObjStandardPalette();
extern "C" void ClearDisplayPlaneMask(unsigned,unsigned);
extern "C" void SetSharedWords10And14(unsigned,unsigned);
extern "C" void SetMainLoopCallback(void(*)());
extern "C" void func_ov031_02228024();
extern "C" void func_ov031_02233248();
extern "C" void func_ov031_0222ea24();
extern "C" void func_ov031_02234520();
extern "C" char* GetSharedObjectRegionAtOffset1024();
extern "C" void SetMainLoopWordPair(unsigned,unsigned);
extern "C" void func_ov031_02230ef0(unsigned char);
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void**);
extern "C" char data_ov031_02290cc0[],data_ov031_0224bcec[];
extern "C" void* data_ov031_02290cc4;
// Original: arm9/ov031 @ 0x02232B44; symbol: func_ov031_02232b44; size: 0x1A4.
extern "C" void System_ResetDisplayObjectsAndSelectMainLoop(){
 if(ReadSelectedContextByte9(1))return;
 if(ReadSelectedContextByte9(0))return;
 if(!Unclassified_IsGlobalObjectMissingOrByte18Zero())return;
 if(!IsGlobalControlAbsentOrByte19Clear())return;
 {char* global=data_ov031_02290cc0;unsigned i=0;do{void* object=*(void**)(*(char**)(global+4)+4+i*4);if(object)Network_UnlinkNodeAndReleaseRecords(object);i++;}while(i<3);}
 {char* global=data_ov031_02290cc0;unsigned i=0;do{void* object=*(void**)(*(char**)(global+4)+16+i*4);if(object)Network_UnlinkNodeAndReleaseRecords(object);i++;}while(i<3);}
 Overlay_ClearFourSharedObjects();Overlay_ProcessPendingFlag();
 Unclassified_FreeArgumentAndUpdateGlobalOwner(**(void***)(data_ov031_02290cc0+4));
 System_LoadResourceAndInvokeCallback(data_ov031_0224bcec,LoadToMainObjStandardPalette);
 ClearDisplayPlaneMask(1,1);ClearDisplayPlaneMask(0,20);
 if(*(unsigned char*)(*(char**)(data_ov031_02290cc0+4)+0x1d)==2){SetSharedWords10And14(0,0);SetMainLoopCallback(func_ov031_02228024);}
 else switch(*(unsigned char*)data_ov031_02290cc0){
 case 0:case 1:case 2:
 SetSharedWords10And14(2,0);
 if(*(unsigned char*)(GetSharedObjectRegionAtOffset1024()+0xe7)==255)SetMainLoopCallback(func_ov031_02233248);
 else {SetMainLoopWordPair(0,0);func_ov031_02230ef0(0);SetMainLoopCallback(func_ov031_0222ea24);}
 break;
 case 3:SetSharedWords10And14(2,1);SetMainLoopCallback(func_ov031_02234520);break;
 }
 FreeSharedAllocationAndClearFlagWithInterruptMask(&data_ov031_02290cc4);
}
