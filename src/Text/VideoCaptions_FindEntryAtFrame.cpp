#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct E{int a,b,start,end,pad;};struct T{E *data;int pad,count;};
// Original: arm9/main @ 0x020E58DC; symbol: func_020e58dc; size: 0x44.
E *VideoCaptions_FindEntryAtFrame(T *p,int value){E *n=p->data;for(int i=0;i<p->count;n++,i++)if(n->start<=value&&value<n->end)return n;return 0;}
}
