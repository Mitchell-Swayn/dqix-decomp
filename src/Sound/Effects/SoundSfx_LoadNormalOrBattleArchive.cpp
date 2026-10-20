#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2257180; symbol: data_ov031_02257180.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 102567 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char SoundSfx_LoadNormalOrBattleArchive_PathDataSoundSeNormSdat[],SoundSfx_LoadNormalOrBattleArchive_PathDataSoundSeBtlSdat[],SharedData_UnknownRoleZeroInitializedStorage_Variant7[];
extern "C" void ResourceHandle_AllocateLoadAndReadValue(void*,const char*,void*,int,int);
extern "C" unsigned ResourceHandle_ReadValueIfPresent(void*);
extern "C" bool TestBoundedResourceValueAfterStateInitialization(void*,int);
struct State {char pad[0xb0];unsigned first;short id;short padb6;unsigned second;unsigned unused;unsigned third;};
// Original: arm9/main @ 0x0205EA20; symbol: func_0205ea20; size: 0x80.
extern "C" void SoundSfx_LoadNormalOrBattleArchive(State* p,int id) {
    const char* path=0;
    if(id==100)path=SoundSfx_LoadNormalOrBattleArchive_PathDataSoundSeNormSdat;else if(id==101)path=SoundSfx_LoadNormalOrBattleArchive_PathDataSoundSeBtlSdat;
    if(path)ResourceHandle_AllocateLoadAndReadValue(p,path,SharedData_UnknownRoleZeroInitializedStorage_Variant7,0x4b000,0);
    p->first=ResourceHandle_ReadValueIfPresent(p);p->id=id;
    TestBoundedResourceValueAfterStateInitialization(p,id);
    unsigned result=ResourceHandle_ReadValueIfPresent(p);p->third=result;p->second=result;
}
