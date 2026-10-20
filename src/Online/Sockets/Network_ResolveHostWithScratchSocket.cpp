#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Hooks{unsigned pad[6];void*(*allocate)(unsigned);void(*release)(void*);};
// Original data: arm9/ov031 @ 0x22496a4; symbol: data_ov031_022496a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Hooks* NetworkCleanupSocketStack_UnknownRoleInitializedBytes;
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void Network_AttachSocketToCurrentThread(void*);
extern "C" void Network_DetachSocketFromCurrentThread();
extern "C" unsigned Network_ResolveIpv4Host(void*);
// Original: arm9/ov031 @ 0x02206E0C; symbol: ParseAddressWithTemporaryWorkspace; size: 0xb0.
// Allocates FD0 workspace, installs two scratch regions for parsing, restores context and frees workspace.
extern "C" unsigned Network_ResolveHostWithScratchSocket(void* p){
 if(!p)return 0;char* workspace=(char*)NetworkCleanupSocketStack_UnknownRoleInitializedBytes->allocate(0xfd0);if(!workspace)return 0;
 unsigned config[25];VectorizedMemset(config,0,100);config[16]=(unsigned)workspace;config[15]=0xb68;config[19]=(unsigned)(workspace+0xb68);config[18]=0x466;Network_AttachSocketToCurrentThread(config);
 unsigned result=Network_ResolveIpv4Host(p);Network_DetachSocketFromCurrentThread();NetworkCleanupSocketStack_UnknownRoleInitializedBytes->release(workspace);return result;
}
