#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void* GameObject_GetLinkedStatsOrNull(char*);
extern "C" void* Field_GetSharedSubscreenInstance(void*);
// Original data: arm9/ov005 @ 0x215cbd4; symbol: data_ov005_0215cbd4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0708060004010509.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
extern "C" unsigned char GameStateCopySelectedSubrecordValues_UnknownRoleInitializedBytes[];
struct Entry { short value; char flag; char pad[25]; };
// Original: arm9/ov005 @ 0x02155544; symbol: func_ov005_02155544; size: 0x7C.
extern "C" void GameState_CopySelectedSubrecordValues(char* p) {
 void* state = _ZN9GameState11GetInstanceEv();
 char* res = (char*)GameResources_GetInstance();
 char* obj = (char*)Field_GetSharedSubscreenInstance(*(void**)(res+0x3708));
 char* out;
 short* values = (short*)GameObject_GetLinkedStatsOrNull((char*)GameState_GetObjectWithFlag100(state, *(int*)(obj+0x4fc)));
 out = p+0x2d90;
 for(int i=0;i<8;i++) { short value=values[GameStateCopySelectedSubrecordValues_UnknownRoleInitializedBytes[i]]; char* entry=p+0x2d90+i*28; *(short*)entry=value; entry[2]=1; }
}
