#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define C(p,o) (*(signed char*)((char*)(p)+(o)))
#define V(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void BattleMenu_ResetMemberCommandState(char*);extern "C" void TextSprite_ResetDrawRequest(char*);
// Original: arm9/ov000 @ 0x0216ff28; symbol: Combat_ResetSelectionAndActionWorkspace.
extern "C" void BattleMenu_ResetMemberWorkspace(char* self){
I(self,0)=0;I(self,4)=0;BattleMenu_ResetMemberCommandState(self+8);B(self,0x87)=0;I(self,0x30)=0;I(self,0x38)=0;I(self,0x3c)=0;I(self,0x40)=0;I(self,0x48)=0;I(self,0x44)=0;I(self,0x4c)=-1;H(self,0x82)=0;B(self,0x86)=0;H(self,0x80)=0x7fff;I(self,0x438)=0;B(self,0x43c)=0;H(self,0x430)=0x7fff;H(self,0x432)=0x7fff;I(self,0x434)=0;C(self,0x43d)=-1;B(self,0x43e)=0;B(self,0x440)=0;B(self,0x43f)=0;B(self,0x441)=0;C(self,0x442)=-1;B(self,0x443)=5;B(self,0x444)=0;B(self,0x445)=1;TextSprite_ResetDrawRequest(self+0x68);TextSprite_ResetDrawRequest(self+0x50);memset(self+0x88,0,19);for(int i=0;i<66;++i)I(self+i*4,0x9c)=0;for(int i=0;i<147;++i)I(self+i*4,0x1a4)=0;for(int i=0;i<16;++i)I(self+i*4,0x3f0)=0;B(self,0x24)&=~1;
}
