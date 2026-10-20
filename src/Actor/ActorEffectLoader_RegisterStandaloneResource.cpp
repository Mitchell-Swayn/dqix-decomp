#include <globaldefs.h>
ARM
struct Pair{void* a;void* b;};extern "C" {void* Object_GetGlobalSixteenEntryDisplayState();void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);void Object_InvokeSaveTextureImageVRAMState(void*);void AllocateInitializeAndAppendLinkedNode(void*,int,void*,int,int,void*);
// Original: arm9/main @ 0x020DAB68; symbol: func_020dab68; size: 0x68.
int ActorEffectLoader_RegisterStandaloneResource(Pair* p,int x,int y){void* q=Object_GetGlobalSixteenEntryDisplayState();void* a=p->a;void* b=p->b;if(!q||!a||!b)return 0;Graphics_RestoreTextureImageAndPaletteVRAMState(b);AllocateInitializeAndAppendLinkedNode(q,22,a,x,y,b);Object_InvokeSaveTextureImageVRAMState(b);return 1;}}
