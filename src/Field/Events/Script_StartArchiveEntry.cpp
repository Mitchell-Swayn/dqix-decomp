#include <globaldefs.h>
ARM
extern "C" int Script_ExecuteBytecode(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021D4CE4; symbol: SelectScriptEntryAndInitializeExecutionFrame.
extern "C" int Script_StartArchiveEntry(char*self,int key){
if(!P(self,68))return -1;P(self,20)=P(self,16);P(self,40)=P(self,36);char*entry;int i=0;P(self,52)=0;if(key<0){char*archive=P(self,68);P(self,52)=archive+W(archive,4);}else{char*archive=P(self,68);entry=archive+W(archive,12);for(;i<W(archive,16);i++,entry+=8){if(W(entry,0)==key){P(self,52)=archive+W(entry,4);break;}}}if(!P(self,52))return -1;P(self,48)=P(self,20)-W(P(self,52),12)*8;P(self,20)=P(self,48)+W(P(self,52),8)*8;memset(P(self,48)+W(P(self,52),12)*8,0,(W(P(self,52),8)-W(P(self,52),12))*8);char*code=P(self,72);int offset=W(P(self,52),0);W(self,60)=0;W(self,64)=0;W(self,80)=0;Script_ExecuteBytecode(self,code+offset);return W(self,60)==0;
}
