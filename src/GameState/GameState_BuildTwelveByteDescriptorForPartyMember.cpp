#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" void Text_InitializeNameDescriptor(void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);struct Flags {unsigned char flag:1;unsigned char rest:7;};
// Original: arm9/main @ 0x020E4BF4; symbol: func_020e4bf4; size: 0x80.
 extern "C" void GameState_BuildTwelveByteDescriptorForPartyMember(void* out,int index){memset(out,0,12);char* p=(char*)GameState::GetInstance()->GetPartyMemberByIndex(index);if(p){unsigned value=*(unsigned*)(p+0x134);char* data=*(char**)(p+0x150);Text_InitializeNameDescriptor(out,value,value,0,0,0,0,((Flags*)(data+0x49c))->flag,0,1,0,1);}}
