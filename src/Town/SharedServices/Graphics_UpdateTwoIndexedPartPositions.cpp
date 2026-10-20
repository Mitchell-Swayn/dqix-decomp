#include <globaldefs.h>
ARM
extern "C" unsigned char* TextCanvas_FindDisplayPartByKey(unsigned char*,unsigned);
extern "C" bool TextCanvas_IsReady(int);
extern "C" void GameState_CopyLanguageMappedBytes(signed char*,signed char*,signed char*,signed char*);
extern "C" void Shop_SubmitInterfaceSpriteAtPosition(void*,int,int,int,int);
// Original: arm9/ov003 @ 0x0217545C; symbol: func_ov003_0217545c; size: 0xA8.
extern "C" void Graphics_UpdateTwoIndexedPartPositions(char* self) {
unsigned char* record=TextCanvas_FindDisplayPartByKey(*(unsigned char**)(self+0x89c),10);
if(!record || !TextCanvas_IsReady((int)record)) return;
short y=*(short*)(record+0xae);
short x=*(short*)(record+0xac);
signed char a,b,c,d;
GameState_CopyLanguageMappedBytes(&a,&b,&c,&d);
y=(short)(y*8);
y=(short)(y+34);
x=(short)(x*8);
Shop_SubmitInterfaceSpriteAtPosition(self,a+x,y,26,120);
Shop_SubmitInterfaceSpriteAtPosition(self,b+x,y,27,122);
}
