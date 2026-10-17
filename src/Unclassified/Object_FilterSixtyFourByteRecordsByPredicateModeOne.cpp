#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" int Record64_MatchesPackedAttributeConditions(char*,void*,int,int);
// Original: arm9/main @ 0x0209EBE4; symbol: func_0209ebe4; size: 0x128.
extern "C" void Object_FilterSixtyFourByteRecordsByPredicateModeOne(char* p,int mode,int value){
 unsigned char count; if(mode==0){int i=0;*(int*)(p+0x98)=0;count=*(unsigned char*)(*(char**)(p+4)+0x8e07);
 for(;i<count;++i){void* entry=*(char**)(p+4)+0x5c60+i*64;if(entry&&Record64_MatchesPackedAttributeConditions(p,entry,1,value)){memcpy(p+0x9c+(*(int*)(p+0x98))++*64,entry,64);}}return;}
 *(int*)(p+0x49c)=0;memset(p+0x4a0,0,1024);for(int i=0;i<*(int*)(p+0x98);++i){void* entry=p+0x9c+i*64;if(Record64_MatchesPackedAttributeConditions(p,entry,1,value)){int index=*(int*)(p+0x49c);*(int*)(p+0x49c)=*(int*)(p+0x49c)+1;memcpy(p+0x4a0+index*64,entry,64);}}
 *(int*)(p+0x98)=*(int*)(p+0x49c);memcpy(p+0x9c,p+0x4a0,1024);
}
