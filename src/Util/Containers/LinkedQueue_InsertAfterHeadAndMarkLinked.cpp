// Reviewed ARM control flow and widths; surrounding object names remain unresolved.
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x02046A3C; symbol: func_02046a3c; size: 0x50.
extern "C" void LinkedQueue_InsertAfterHeadAndMarkLinked(char* p,char* entry){char* head=*(char**)p;if(head && *(char**)(p+4)){*(char**)(entry+4)=*(char**)(head+4);head=*(char**)p;*(char**)(head+4)=entry;if(!*(char**)(entry+4))*(char**)(p+4)=entry;}else{*(char**)p=entry;*(char**)(p+4)=entry;*(char**)(entry+4)=0;}entry[2]=1;}
