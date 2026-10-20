#include <globaldefs.h>
extern "C" void Tavern_OpenConfirmationOptions(char*);
extern "C" int Tavern_PollConfirmationOptions(unsigned char*);
// Original: arm9/ov003 @ 0x02163F60; symbol: func_ov003_02163f60; size: 0x74.
// Starts selection, then routes acceptance to state43 or rejection to phase10.
extern "C" ARM void AdvanceDisplaySelectionToStateFortyThreeOrTen(char* self){
 unsigned phase=(unsigned char)self[0x4a4];
 if(phase==0){Tavern_OpenConfirmationOptions(self);++((unsigned char*)self)[0x4a4];}
 else if(phase==1){int result=Tavern_PollConfirmationOptions((unsigned char*)self);
  if(result!=-1){if(result==1){*(short*)(self+0x484)=43;self[0x4a4]=0;}}
  else{self[0x4a3]=10;self[0x4a4]=0;}
 }
}
