#include <globaldefs.h>
ARM
extern "C" char* MenuRecordList_LocateByKey(...);
extern "C" void Menu_QueueScriptEntry(...);
extern "C" void Menu_StartIndexedCallback(...);
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Four {short values[4];};struct Eight {short values[8];};struct Vec {int x,y,z;};
// Original: arm9/ov023 @ 0x021F6AC8; symbol: System_DispatchFirstInactiveRecordGroup; size: 0xe0.
// Scans three twenty-two-byte groups and dispatches positive state codes for first group with no active virtual records.
extern "C" bool System_DispatchFirstInactiveRecordGroup(char* self,void* state){if(B(Main_UnknownRoleZeroInitializedStorage_Variant4,0x55)){for(int i=0;i<3;++i){char* record=self+0x30+22*i;if(!B(record,0))continue;int active=0;for(int j=0;j<B(record,0)&&!active;++j){char* object=MenuRecordList_LocateByKey(self,H(record+2*j,2));if(object&&((int(*)(void*))P(P(object,0),0xf8))(object))active=1;}if(active)continue;if(S(record,18)>0)Menu_QueueScriptEntry(state,S(record,18));if(S(record,20)>0)Menu_StartIndexedCallback(state,S(record,20));return true;}}return false;}
