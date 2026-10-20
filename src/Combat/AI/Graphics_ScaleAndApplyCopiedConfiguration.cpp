#include <globaldefs.h>
ARM
struct Config { float value;unsigned char pad[3],intensity,kind;unsigned char rest[3]; };
extern "C" void AppendTenByteRecordIfCapacity(void*,Config*);
// Original: arm9/ov024 @ 0x021FD7B8; symbol: func_ov024_021fd7b8; size: 0xA0.
extern "C" void Graphics_ScaleAndApplyCopiedConfiguration(unsigned char* p) {
float scale=12.5f;
scale*=((float)(int)*(unsigned char*)(*(unsigned char**)(*(unsigned char**)(p+0x668)+0x138)+0x48)/100.0f);
Config config=*(Config*)(p+0x65c);
config.value=(float)*(short*)(*(unsigned char**)(p+0x64c)+0x32);
config.intensity=(int)((float)(unsigned int)config.intensity*scale/100.0f);
config.kind=2;
AppendTenByteRecordIfCapacity(*(void**)(p+0x658),&config);
}
