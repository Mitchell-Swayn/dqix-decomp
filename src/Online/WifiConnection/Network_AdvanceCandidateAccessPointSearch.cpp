#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
extern "C" unsigned long long _Z19GetCurrentTimestampv();
extern "C" int Network_AdvanceAndPublishAccessPointScanPhase(unsigned char*,int);
extern "C" void System_DispatchWithIndexedTableFlag(void*,void*,int,unsigned);
// Original: arm9/ov031 @ 0x02214d80; symbol: Network_AdvanceTimedPendingEntry.
struct EntryFlags {unsigned char lo:7,done:1;unsigned char rest[3];};
extern "C" int Network_AdvanceCandidateAccessPointSearch(unsigned char* p){
unsigned long long elapsed=(_Z19GetCurrentTimestampv()-*(unsigned long long*)(p+0xcb0))*64/33514;
if(elapsed>=150 || ((EntryFlags*)(p+0x447))[p[0xd0f]].done==1){
((EntryFlags*)(p+0x447))[p[0xd0f]].done=1;
for(;p[0xd0f]<p[0xd12];p[0xd0f]++){if(!((EntryFlags*)(p+0x447))[p[0xd0f]].done)break;}
if(p[0xd12]<=p[0xd0f]){p[0xd0f]=0;return Network_AdvanceAndPublishAccessPointScanPhase(p,4);}
*(unsigned long long*)(p+0xcb0)=_Z19GetCurrentTimestampv();
int offset=(short)p[0xd0f]*(short)192;
System_DispatchWithIndexedTableFlag(p+0x474+offset,p+0x47c+offset,U(p+offset,0x4a6)-1,0x300000);
}return 4;
}
