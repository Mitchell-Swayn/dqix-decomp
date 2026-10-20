#pragma thumb off
#pragma optimization_level 2
struct Fields{unsigned a:6,b:6,c:6,d:6,kind:2,flag0:1,flag1:1,flag2:1,pad:2,last:1;};struct Record{char* name;char* text;Fields fields;};
extern "C" int sprintf(char*,const char*,...);
// Original: arm9/main @ 0x020E4F18; symbol: func_020e4f18; size: 0x140.
extern "C" void Text_CopySelectedNameDescriptorFields(const Record* source,Record* dest,unsigned flags){if(!source || !dest)return;if(flags&1){char* text=dest->text;sprintf(dest->name,source->name);sprintf(text,source->text);}if(flags&2){dest->fields.a=source->fields.a;dest->fields.b=source->fields.b;dest->fields.c=source->fields.c;dest->fields.d=source->fields.d;}dest->fields.kind=source->fields.kind;dest->fields.flag0=source->fields.flag0;dest->fields.flag1=source->fields.flag1;dest->fields.flag2=source->fields.flag2;dest->fields.last=source->fields.last;}
