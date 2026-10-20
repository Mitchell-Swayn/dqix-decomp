#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/main @ 0x0209F030; symbol: FilterSixtyFourByteRecordsByHalfwordThreshold.
extern "C" void ScriptQueryContext_FilterByUnsignedValueThreshold(char*self,int refilter,int threshold,int atLeast){
int stride=64;if(!refilter){W(self,152)=0;char*output=self+156;int count=B(P(self,4)+0x8000,0xe07);for(int i=0;i<count;i++){char*record=P(self,4)+0x5c60+i*64;if(!record)continue;int value=H(record,22);if(atLeast){if(value<threshold)continue;}else if(value>=threshold)continue;memcpy(output+W(self,152)++*64,record,stride);}}else{W(self,1180)=0;memset(self+1184,0,1024);char*output;char*input=self+156;output=self+1184;for(int i=0;i<W(self,152);i++){char*record=input+i*64;int value=H(record,22);if(atLeast){if(value<threshold)continue;}else if(value>=threshold)continue;int ordinal=W(self,1180);W(input,1024)=W(input,1024)+1;memcpy(output+ordinal*64,record,stride);}W(self,152)=W(self,1180);memcpy(self+156,self+1184,1024);}
}
