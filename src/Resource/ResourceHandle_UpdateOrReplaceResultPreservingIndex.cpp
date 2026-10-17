#include <globaldefs.h>
struct Object {void* active;char pad4[0x98];char context[8];short index;unsigned short unused;void* result;};
extern "C" void* func_020becd4(void*);
extern "C" void* ReplaceValueAndInvalidateFileIndices(Object*,void*,unsigned);
extern "C" void ResourceHandle_StartIndexedRecordOperation(Object*,int,void*,void*);
// Original: arm9/main @ 0x0203AE4C; symbol: func_0203ae4c; size: 0x94.
extern "C" void ResourceHandle_UpdateOrReplaceResultPreservingIndex(Object* p,int replace,void* context) {if(!p->active)return;if(p->index<0)return;if(replace){void* result;if(context)result=func_020becd4(context);else result=func_020becd4(p->context);short index=p->index;p->result=ReplaceValueAndInvalidateFileIndices(p,context,0);p->index=index;if(p->result==result)p->index=-1;return;}if(p->result)ResourceHandle_StartIndexedRecordOperation(p,p->index,context,p->result);}
