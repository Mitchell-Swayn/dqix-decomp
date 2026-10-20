#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {unsigned AccessPoint_SelectMatchingProfileKind(void*);void VectorizedMemset(void*,int,unsigned);int AccessPoint_DecodeSelectedWepKey(char*,unsigned,char*);}
// Original: arm9/ov031 @ 0x02213CE0; symbol: Network_DecodeIdentityAndSelectConnectionState; size: 0xf8.
// Decodes selected network identity and selects state9 for incompatible record flags or state8 after reset.
extern "C" int WirelessConnection_PrepareChosenAccessPoint(unsigned char* self){unsigned char* record=self+0x470+self[0xd13]*192;self[0xd0d]=AccessPoint_SelectMatchingProfileKind(self);VectorizedMemset(self+0xcb8,0,82);if(AccessPoint_DecodeSelectedWepKey((char*)self,self[0xd0d],(char*)self+0xcb8)){self[0xd0b]=(self[0xd0b]&~12)|4;if(!((U(record,0x2c)>>4)&1)){(self+self[0xd13]*4)[0x444]=3;return 9;}if(self[0xd0d]==6&&!record[0x15]){(self+self[0xd13]*4)[0x444]=3;return 9;}}else{self[0xd0b]&=~12;if(((U(record,0x2c)>>4)&1)==1){(self+self[0xd13]*4)[0x444]=3;return 9;}}self[0xd15]=0;self[0xd14]=0;return 8;}
