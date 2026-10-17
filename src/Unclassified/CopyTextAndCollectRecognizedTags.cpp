struct Tags { unsigned char tags[4]; int count; unsigned short values[4]; };
extern "C" const unsigned char* data_020f0afc[];
extern "C" int String_CountBytesUntilTerminator(const unsigned char*);
extern "C" int RuntimeMemory_CompareByteRanges(const unsigned char*,const unsigned char*,int);
extern "C" unsigned short Runtime_ParseStringAsBaseTenInteger(const unsigned char*);
// Original: arm9/main @ 0x0206F550; symbol: func_0206f550; size: 0x17C.
extern "C" int CopyTextAndCollectRecognizedTags(Tags* tags,const unsigned char* source,unsigned char* dest) {
 if(!source) return 0;
 if(!dest) return 0;
 tags->count=0;
 while(*source) {
  if(*source==60) {
   bool found=false;
   if(tags->count<4) {
    const unsigned char* tag; int len;
    for(unsigned char i=1;i<13;++i) {
     tag=data_020f0afc[i]; len=String_CountBytesUntilTerminator(tag);
     if(RuntimeMemory_CompareByteRanges(source,tag,len)==0) {
      if(i==4 || (unsigned char)(i+255)<=1) {source+=len;tags->values[tags->count]=Runtime_ParseStringAsBaseTenInteger(source);}
      found=true; tags->tags[tags->count]=i; ++tags->count; break;
     }
    }
   }
   if(found) {while(*source!=62) {if(!*source)return tags->count;++source;} ++source;}
   else {while(*source!=62) {*dest=*source;if(!*source)return tags->count;++source;++dest;}*dest++=*source; ++source;}
  } else {
   unsigned char c=*source;
   if((c>=0x81 && c<=0x9f)||(c>=0xe0 && c<=0xea)) {*dest++=c;++source;}
   *dest++=*source++;
  }
 }
 return tags->count;
}
