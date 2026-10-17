#include <globaldefs.h>
ARM
extern "C" unsigned int strlen(const char*);
extern "C" void __clear(void*,unsigned);
extern "C" int func_ov009_0218a888(void*, const unsigned char*, int, int);
// Original: arm9/ov009 @ 0x0218A518; symbol: func_ov009_0218a518; size: 0x370.
extern "C" int Util_MatchEncodedBytePattern(unsigned char* self, const unsigned char* pattern, const unsigned char* text, int unused, int count) {
 int any=self[0x2a], open=self[0x2b], close=self[0x2c], repeat=self[0x2d], end=self[0x2e], scan=self[0x31];
 for(int start=0;start<count;start++,text++) {
  const unsigned char* p=pattern; const unsigned char* s=text;
  while(1) {
   unsigned char c=*p;
   if(!c)return 1;
   unsigned char value=*s; int len; int lo=1; int neg; int hi=1;
   const unsigned char* q=p;
   if(c==open) { do { if(*q==close) {q++;break;} q++; }while(1); } else q=p+1;
   if(*q==repeat) {lo=q[1]-8;hi=q[3]-8;if(q[4]-8==0)hi*=10;}
   int ok=1;
   if(c==scan) {
    if(lo==0&&hi==60) {
     int target=p[7];
     while(1){if(*s==0||*s==255)return 0;if(target==*s)break;s++;}
     p+=8;s++;continue;
    }
   } else if(c==any) {
    if(value<0x12||value>0x2b)ok=0;
   } else if(c==open) {
    unsigned char bytes[8];__clear(bytes,8);
    neg=0;
    const unsigned char* in;unsigned char* out=bytes;in=p+1;len=0;
    int rangemark,negmark,close2; close2=self[0x2c];negmark=self[0x2f];rangemark=self[0x30];
    int ch; while((ch=*in),ch!=close2){*out=ch;if(ch==negmark)len=2;if(ch==rangemark)neg=1;in++;out++;}
    neg+=len;
    len=strlen((const char*)bytes);
    if(neg==0)ok=func_ov009_0218a888(self,bytes,len,value);
    else if(neg==1){unsigned int last=bytes[len-1];ok=bytes[0]<=value&&value<=last;}
    else if(neg==2)ok=!func_ov009_0218a888(self,bytes+1,len-1,value);
    else if(neg==3){unsigned int last=(bytes+1)[len-2];ok=!(bytes[1]<=value&&value<=last);}
    p+=len+1;
   }else if(c!=value)ok=0;
   if(ok){
    for(int i=0;i<lo;i++,s++){if(value!=*s){ok=0;break;}}
    if(!ok)break;
    for(;lo<hi;lo++,s++){if(value!=*s)break;}
   }else if(!ok&&lo!=0)break;
   p++;
   if(*p==repeat){do {if(*p==end)break;p++;}while(1);p++;}
  }
 }
 return 0;
}
