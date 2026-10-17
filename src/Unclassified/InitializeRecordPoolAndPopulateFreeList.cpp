#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
struct Record {char bytes[28];};struct List {int a,b,c;};
struct Pool {Record records[192];List lists[3];char flags[32];};
struct Entry {char pad[16];unsigned char flag;char pad2[3];};struct State {Entry entries[5];char tail[16];};
extern "C" void Vector3i_ClearThreeWords(List*);
extern "C" void LinkedList_AppendNodeUnderLockAndIncrementCount(List*,Record*);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" void UpdateEnabledMemberCountAndTimestampOnTransition();
extern "C" State* Object_GetSubrecordAtOffset7C0(void*);
extern "C" State* GetRecordAtResolvedIndexWithStride116(void*,int);
// Original: arm9/main @ 0x0205E22C; symbol: func_0205e22c; size: 0xF8.
extern "C" void InitializeRecordPoolAndPopulateFreeList(Pool* p){
 Vector3i_ClearThreeWords(&p->lists[0]);Vector3i_ClearThreeWords(&p->lists[1]);Vector3i_ClearThreeWords(&p->lists[2]);
 memset(p,0,0x1500);for(int i=0;i<192;++i)LinkedList_AppendNodeUnderLockAndIncrementCount(&p->lists[0],&p->records[i]);
 void* handle=Object_GetGlobalConnectionState();UpdateEnabledMemberCountAndTimestampOnTransition();State* s=Object_GetSubrecordAtOffset7C0(handle);memset(s,0,0x74);
 for(int i=0;i<5;++i)s->entries[i].flag=255;
 for(int i=0;i<4;++i){s=GetRecordAtResolvedIndexWithStride116(handle,i);if(s)memset(s,0,0x74);}
 memset(p->flags,255,32);
}
