struct Tags { unsigned char tags[4]; int count; unsigned short values[4]; };
// Original data: arm9/main @ 0x20f0afc; symbol: data_020f0afc.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 8c0a0f028d0a0f02c10a0f02930a0f02a10a0f02a80a0f02b00a0f02b80a0f02ca0a0f029a0a0f02ec0a0f02d40a0f02df0a0f02.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const unsigned char* ScriptExtractFacilityTagsAndCopyText_UnknownRoleDataReferences[];
extern "C" int String_CountBytesUntilTerminator(const unsigned char*);
extern "C" int RuntimeMemory_CompareByteRanges(const unsigned char*,const unsigned char*,int);
extern "C" unsigned short Runtime_ParseStringAsBaseTenInteger(const unsigned char*);
// Original: arm9/main @ 0x0206F550; symbol: func_0206f550; size: 0x17C.
extern "C" int Script_ExtractFacilityTagsAndCopyText(Tags* tags,const unsigned char* source,unsigned char* dest) {
 if(!source) return 0;
 if(!dest) return 0;
 tags->count=0;
 while(*source) {
  if(*source==60) {
   bool found=false;
   if(tags->count<4) {
    const unsigned char* tag; int len;
    for(unsigned char i=1;i<13;++i) {
     tag=ScriptExtractFacilityTagsAndCopyText_UnknownRoleDataReferences[i]; len=String_CountBytesUntilTerminator(tag);
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
