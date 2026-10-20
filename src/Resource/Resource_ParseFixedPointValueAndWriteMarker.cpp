#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" double RuntimeDecimalDouble_ParseTextAsDouble(const char*);
extern "C" unsigned TextContext_GetSharedInstance();
// Original: arm9/main @ 0x02069C1C; symbol: func_02069c1c; size: 0xC4.
extern "C" int Resource_ParseFixedPointValueAndWriteMarker(void** output,char* text){
 float values[1];unsigned short marker;
 for(int i=0;i<1;i++){
 if(!*text || *text<'0' || *text>'9')continue;
 values[i]=(float)RuntimeDecimalDouble_ParseTextAsDouble(text);
 for(;;){
 if(!*text)break;
 if(*text==',' || *text=='>'){text++;break;}
 text++;
 }
 }
 unsigned char* object=(unsigned char*)TextContext_GetSharedInstance();
 *(int*)(object+0x1840)=4096.0f*values[0];
 void* destination=*output;
 marker=0xff2a;
 memcpy(destination,&marker,2);
 return 2;
}
