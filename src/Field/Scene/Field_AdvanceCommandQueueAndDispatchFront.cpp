#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov017 @ 0x21d6a34; symbol: data_ov017_021d6a34.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 05000000060000000a0000000d0000000f000000100000001100000012000000170000001e0000002a000000370000003d0000003e0000003f00000041000000 ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
struct KeyTable{int values[18];};extern "C" KeyTable FieldAdvanceCommandQueueAndDispatchFront_UnknownRoleInitializedBytes;extern "C" char* GameResources_GetInstance();extern "C" void LinkedQueue_RemoveCompletedFrontNodesOrMarkWaiting(void*);extern "C" void Field_DispatchQueuedCommandByKind(void*,void*);
// Original: arm9/ov017 @ 0x021A3498; symbol: MarkResourceModeForQueuedKeyThenAdvanceQueue; size: 0xac.
extern "C" void Field_AdvanceCommandQueueAndDispatchFront(char** self){
if(*self&&B(*self,1)){char* resources=GameResources_GetInstance();if(resources){KeyTable keys=FieldAdvanceCommandQueueAndDispatchFront_UnknownRoleInitializedBytes;int* key=keys.values;while(*key!=65535){if(*(signed char*)*self==*key){B(resources,0x4354)=12;break;}key++;}}}LinkedQueue_RemoveCompletedFrontNodesOrMarkWaiting(self);Field_DispatchQueuedCommandByKind(self,*self);
}
