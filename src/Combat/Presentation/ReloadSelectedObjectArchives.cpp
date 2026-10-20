#include <globaldefs.h>
ARM
namespace BCFG {struct AnimationRecord;}
extern "C" {
void* _ZN9GameState11GetInstanceEv(); void* _ZN16BackgroundLoader11GetInstanceEv();
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[]; struct PathTemplate {char bytes[80];}; extern PathTemplate ReloadSelectedObjectArchives_PathData;
void* Combat_GetCurrentPresentationAllocator(char*);
char* strcat(char*,const char*);
bool Filesystem_SplitMatchedPathPrefixAndSuffix(char*,char*,char*);
int _ZN16BackgroundLoader22GetLoadedFileInArchiveEPKcS1_PPvPj(void*,const char*,const char*,void**,unsigned*);
int _ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(void*,const char*,void**,unsigned*);
int Combat_DispatchSelectionProcedure(void*,void*,int,int*);
void Resource_ReloadObjectArchivePreservingAnimation(int,int,int,int(*)(BCFG::AnimationRecord*));
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void Resource_RemoveIndexedHalfword(void*,int);
}
// Original: arm9/ov025 @ 0x021E4AAC; symbol: func_ov025_021e4aac; size: 0x138.
// Resolves an archive path, reloads selected objects, and removes the completed load task.
extern "C" int ReloadSelectedObjectArchives(unsigned char* action,void* selection,int unused,void* context) {
 PathTemplate copied; char archive[80],inner[80]; int ids[8]; void* file;unsigned length;
 _ZN9GameState11GetInstanceEv();
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 Combat_GetCurrentPresentationAllocator(*(char**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage+12));
 copied=ReloadSelectedObjectArchives_PathData;
 strcat(copied.bytes,*(char**)(action+12));
 file=0; int task;
 if(Filesystem_SplitMatchedPathPrefixAndSuffix(copied.bytes,archive,inner))task=_ZN16BackgroundLoader22GetLoadedFileInArchiveEPKcS1_PPvPj(loader,archive,inner,&file,&length);
 else task=_ZN16BackgroundLoader19GetLoadedFileByNameEPKcPPvPj(loader,copied.bytes,&file,&length);
 if(file) {int count=Combat_DispatchSelectionProcedure(context,selection,action[8],ids);if(count>0)for(int i=0;i<count;i++)Resource_ReloadObjectArchivePreservingAnimation(ids[i],(int)file,length,0);}
 _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
 Resource_RemoveIndexedHalfword(*(void**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage+12),task);
 return 1;
}
