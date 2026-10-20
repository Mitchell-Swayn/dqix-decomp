#include <globaldefs.h>
ARM
extern "C" int Ssl_ReceiveChangeCipherSpecAndFinished(...);
extern "C" int System_BuildAndCopyThreeContextRecords(...);
extern "C" int SslSessionCache_StoreMasterSecret(...);
extern "C" int System_BuildAndCopyThreeContextRecords(...);
extern "C" int Ssl_DeriveRecordKeysAndInitializeRc4(...);
extern "C" int Ssl_ReceiveAndProcessRecord(...);
extern "C" int Ssl_SendChangeCipherSpecAndFinished(...);
extern "C" int Ssl_SendClientHello(...);
extern "C" int Ssl_SendRsaClientKeyExchange(...);
extern "C" int Ssl_ReceiveChangeCipherSpecAndFinished(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0220A474; symbol: WaitForContextResultAndFinalizeModeEight.
extern "C" int Ssl_RunClientHandshake(char* self){
char* context=P(self,12);Ssl_SendClientHello(self);int result;do{result=Ssl_ReceiveAndProcessRecord(self);if(result==9)return 1;}while(result!=4&&!B(context,49));if(B(context,49)){Ssl_DeriveRecordKeysAndInitializeRc4(context);if(Ssl_ReceiveChangeCipherSpecAndFinished(self))return 1;Ssl_SendChangeCipherSpecAndFinished(self);}else{Ssl_SendRsaClientKeyExchange(self);System_BuildAndCopyThreeContextRecords(context);if(B(context,48))SslSessionCache_StoreMasterSecret(context,W(self,28),H(self,24));Ssl_DeriveRecordKeysAndInitializeRc4(context);Ssl_SendChangeCipherSpecAndFinished(self);if(Ssl_ReceiveChangeCipherSpecAndFinished(self))return 1;}B(context,0x455)=8;return 0;
}
