#include <globaldefs.h>
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void Graphics_InitializeCanvasTransferState(void*);extern "C" void WorldMap_ResetTrackingOriginToSelectedObject(void*);extern "C" void VectorizedMemset(void*,int,unsigned);struct Global{int a,b,c,d;};extern "C" Global PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage;
struct Fields{char pad[0x558];char active[4];char field[4];int ids[4];char zeros[4];char gap[0x1e4];char bytes[4];};
// Original: arm9/main @ 0x02020720; symbol: func_02020720; size: 0x118.
extern "C" ARM void WorldMap_ResetDisplayAndMarkerState(char* p){*(int*)(p+24)=0;*(int*)(p+28)=0;*(int*)(p+32)=0;*(int*)(p+36)=0;*(int*)(p+40)=0;*(int*)(p+44)=0;*(int*)(p+48)=0;*(int*)(p+52)=0;*(int*)(p+56)=4096;*(int*)(p+60)=-1024;*(int*)(p+64)=-1024;*(int*)(p+108)=0;*(int*)(p+112)=0;*(int*)(p+116)=0;*(int*)(p+20)=1;p[0x55c]=0;*(int*)(p+0x754)=0;*(unsigned*)(p+0x5a4)&=1;*p=0;*(int*)(p+0xa9c)=0;for(int i=0;i<4;++i){Fields* fields=(Fields*)p;fields->ids[i]=-1;fields->zeros[i]=0;fields->bytes[i]=0;fields->active[i]=1;}Graphics_InitializeCanvasTransferState(p+0x4c);p[0x75c]=0;p[0x75d]=0;p[0x77a]=0;*(int*)(p+0x77c)=0;*(int*)(p+0x9b4)=0;*(int*)(p+0x760)=0;p[0x764]=0;*(short*)(p+0x766)=0;p[0x768]=1;WorldMap_ResetTrackingOriginToSelectedObject(p);*(int*)(p+0x9bc)=0;p[0x9c0]=0;PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage.d=0;*(short*)(p+0xaa0)=0;VectorizedMemset(p+0xaa2,0,256);}
