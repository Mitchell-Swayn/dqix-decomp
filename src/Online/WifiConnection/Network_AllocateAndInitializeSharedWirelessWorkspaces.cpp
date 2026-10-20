#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[];
extern "C" void MIi_CpuClear32(int,void*,unsigned);
extern "C" int Network_InitializeWirelessWorkspace(unsigned char*,unsigned);
extern "C" int GameState_InvokeHandlerOncePerMask(unsigned,unsigned);
extern "C" void Network_ReleaseConnectionWorkspaces();
extern "C" int System_SubmitIPCCommand300AndReturnSuccess(unsigned);
typedef void*(*Allocator)(unsigned,unsigned);
#define F(T,p,o) (*(T*)((char*)(p)+(o)))
#define G(o) F(char*,NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage,o)
struct ModeBits {unsigned char mode:2,other:6;};
struct OptionBits {unsigned char low:4,upper:2,other:2;};
// Original: arm9/ov031 @ 0x02212D40; symbol: func_ov031_02212d40; size: 0x1A8.
// Allocates and clears shared wireless workspaces and initializes request options and timers.
extern "C" bool Network_AllocateAndInitializeSharedWirelessWorkspaces(char* config){
void* control=F(Allocator,config,0)(1,36);G(12)=(char*)control;MIi_CpuClear32(0,control,36);
char* record=G(12);F(unsigned,record,0)=F(unsigned,config,0);F(unsigned,record,4)=F(unsigned,config,4);F(unsigned char,record,9)=1;F(unsigned char,record,22)=1;F(unsigned char,record,8)=1;
G(16)=(char*)GameState_InvokeHandlerOncePerMask(16,0xd18);
G(0)=(char*)GameState_InvokeHandlerOncePerMask(2,0x2300);
G(4)=(char*)GameState_InvokeHandlerOncePerMask(4,0x58);
G(8)=(char*)GameState_InvokeHandlerOncePerMask(8,12);
MIi_CpuClear32(0,G(16),0xd18);MIi_CpuClear32(0,G(0),0x2300);MIi_CpuClear32(0,G(4),0x58);MIi_CpuClear32(0,G(8),12);
char* work=G(16);F(unsigned char,work,0xd0a)=F(unsigned char,config,8);
((ModeBits*)(work+0xd0b))->mode=F(unsigned char,config,9);
char* handlers=G(8);F(unsigned,handlers,0)=F(unsigned,config,0);F(unsigned,handlers,4)=F(unsigned,config,4);F(unsigned,handlers,8)=0;
((OptionBits*)(work+0xd0c))->low=F(unsigned char,config,10);
((OptionBits*)(work+0xd0c))->upper=F(unsigned char,config,11);
System_SubmitIPCCommand300AndReturnSuccess((unsigned)work);
int status=Network_InitializeWirelessWorkspace((unsigned char*)G(0),0x2300);
if(status==1 || status>4){Network_ReleaseConnectionWorkspaces();return false;}return true;
}
