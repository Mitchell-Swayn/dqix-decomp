#include <globaldefs.h>
ARM
extern "C" int Menu_GetLayoutCellScreenCoordinates(...);
extern "C" int ReadSelectedCoordinatePair(...);
extern "C" int Menu_ResolveFirstLayoutCellForGroup(...);
extern "C" int TestEnabledRecordTraversal(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant4[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov023 @ 0x021E29D0; symbol: FindSelectableRecordContainingCurrentCoordinates.
extern "C" int Menu_HitTestEnabledLayoutGroups(char*self){
if(!B(Main_UnknownRoleZeroInitializedStorage_Variant4,85))return -1;int x,y;ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);unsigned count=H(self,20);char*records=P(self,8);for(unsigned short i=0;i<count;i++){short key=S(records+i*24,0);if(!TestEnabledRecordTraversal(self,key))continue;char*record=C(Menu_ResolveFirstLayoutCellForGroup(self,S(records+i*24,0)));if(!record||!B(record,2))continue;short left,top;Menu_GetLayoutCellScreenCoordinates(self,S(record,0),&left,&top);short right=left+S(record,8),bottom=top+S(record,10);if(top>y||y>=bottom||left>x||x>=right)continue;return S(records+i*24,0);}return -1;
}
