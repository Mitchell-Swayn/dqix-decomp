// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original: arm9/main @ 0x0203F1C8; symbol: func_0203f1c8; size: 0x1C.
extern "C" void* ActorSpriteResource_GetAnimation(char* p,unsigned int i) {if(*(unsigned int*)(p+0x18)<=i)return 0;return *(char**)(p+0x1c)+i*20;}
