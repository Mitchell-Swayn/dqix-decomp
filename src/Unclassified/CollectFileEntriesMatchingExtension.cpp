#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" unsigned FindVariableLengthBlockByIndex(void*,int,const char**,unsigned*);
// Original: arm9/main @ 0x0204684C; symbol: func_0204684c; size: 0xB4.
extern "C" ARM int CollectFileEntriesMatchingExtension(void* p,const char* extension,unsigned* out,int capacity,unsigned* sizes,const char** names){int count=0;for(int i=0;;i++){unsigned size;const char* name;unsigned id=FindVariableLengthBlockByIndex(p,i,&name,&size);if(!id)break;const char* suffix=name;while(*suffix){if(*suffix=='.'){suffix++;break;}suffix++;}if(!strcmp(extension,suffix)){out[count]=id;if(names)names[count]=name;if(sizes)sizes[count]=size;count++;if(count>=capacity)break;}}return count;}
