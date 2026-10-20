#include <globaldefs.h>
ARM
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int ProfileEditor_GeneratePreviewText(...);
extern "C" int Graphics_CopyContextTextForProtagonistAndSpecialMode(...);
extern "C" int GameState_UpdateRecordTextBuffers(...);
extern "C" int Menu_DispatchSecondaryPanelCharacterView(...);
extern "C" int System_DispatchSelectedHandlerWithValidatedValue(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov012 @ 0x0218ADAC; symbol: ApplyCopiedModeBitsAndDispatchSelectedHandler; size: 0xc8.
extern "C" void ProfileEditor_RefreshPreview(char* self,int enable,int mode,int retain){
char* state=C(_ZN9GameState11GetInstanceEv());Graphics_CopyContextTextForProtagonistAndSpecialMode(self);char temporary[124];char* source;if(mode==-1)source=state+0x569c;else{memcpy(temporary,state+0x569c,124);W(temporary,0)=(W(temporary,0)&~0x1e00000)|((unsigned)mode<<28>>7);source=temporary;}if(!retain){B(self,0x14bd)=0;B(self,0x1334)=0;}int result=ProfileEditor_GeneratePreviewText(self,source);if(result||!retain){if(enable)Menu_DispatchSecondaryPanelCharacterView(self+0xd28,2,0);else System_DispatchSelectedHandlerWithValidatedValue(self+0xd28,2,0);}GameState_UpdateRecordTextBuffers(self);
}
