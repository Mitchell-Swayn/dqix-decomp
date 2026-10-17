#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct E{unsigned short key,pad;};struct A{E data[66];int count;};
// Original: arm9/main @ 0x0209A9DC; symbol: func_0209a9dc; size: 0x64.
E *GetDirectOrScannedRecordForKeyBelow66(A **p,int key){int i;A *a=*p;if(!a)return 0;if(key>=66)return 0;if(a->data[key].key==key)return a->data+key;for(i=0;i<a->count;i++)if(a->data[i].key==key)return a->data+i;return 0;}
}
