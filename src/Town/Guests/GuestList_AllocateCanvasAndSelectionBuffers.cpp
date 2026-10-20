#include <globaldefs.h>
ARM
extern "C" int Menu_ResetLayout(...);
extern "C" int Graphics_InitializeCanvasTransferState(...);
extern "C" int Selection_InitializeDisplayController(...);
extern "C" int SpriteAnimation_ResetTrackList(...);
extern "C" int TextCanvas_InitializeLayoutAndTransferDefaults(...);
extern "C" int _ZN13SafeAllocator11CreateTypeAEPvj(...);
extern "C" int _ZN13SafeAllocator5ResetEv(...);
extern "C" int _ZN13SafeAllocator8AllocateEj(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x0216E02C; symbol: AllocateAndInitializeDisplayCanvasBuffers.
extern "C" void GuestList_AllocateCanvasAndSelectionBuffers(char*self,char*allocator){
if(!allocator)return;P(self,208)=allocator;P(self,60)=C(_ZN13SafeAllocator8AllocateEj(allocator,188));P(self,64)=C(_ZN13SafeAllocator8AllocateEj(P(self,208),64));P(self,68)=C(_ZN13SafeAllocator8AllocateEj(P(self,208),448));P(self,96)=C(_ZN13SafeAllocator8AllocateEj(P(self,208),880));P(self,100)=C(_ZN13SafeAllocator8AllocateEj(P(self,208),8));P(self,212)=C(_ZN13SafeAllocator8AllocateEj(P(self,208),76));SpriteAnimation_ResetTrackList(P(self,100));void*buffer=(void*)_ZN13SafeAllocator8AllocateEj(P(self,208),1024);_ZN13SafeAllocator11CreateTypeAEPvj(self+188,buffer,1024);_ZN13SafeAllocator5ResetEv(self+188);Selection_InitializeDisplayController(P(self,60));for(int i=0;i<2;i++)Graphics_InitializeCanvasTransferState(P(self,64)+i*32);for(int i=0;i<2;i++)TextCanvas_InitializeLayoutAndTransferDefaults(P(self,68)+i*224);Menu_ResetLayout(P(self,212));
}
