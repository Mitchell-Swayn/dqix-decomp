#include <globaldefs.h>
#include <std_library_functions.h>
struct State {unsigned unknown;char text[47];};
// Original: arm9/main @ 0x020294CC; symbol: func_020294cc; size: 0x94.
extern "C" void DebugMenu_SetEntryLabel(State* self,const unsigned char* input) {if(!input)return;unsigned length=0;unsigned extra;const unsigned char* cursor=input;unsigned c;while((c=*cursor)!=0){extra=0;if((c>=0x81 && c<=0x9f)||(c>=0xe0 && c<=0xea)){c=*++cursor;++extra;if(c==0)break;}unsigned next=length+(extra+1);++cursor;if(next>46)break;length=next;}memcpy(self->text,input,length);self->text[length]=0;}
