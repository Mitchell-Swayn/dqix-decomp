#include <globaldefs.h>
ARM
struct Records { unsigned short ids[16];short a[16];short b[16];char pad[0x40];unsigned char modes[16];void* values[16];char pad2[0x60];unsigned char count; };
inline void* Value(Records* p,int i){return p->values[i];}
// Original: arm9/ov025 @ 0x021ED564; symbol: func_ov025_021ed564; size: 0x8C.
extern "C" short FindMatchingRecordIndex(Records* p,unsigned short id,short a,int mode,void* value,short b){
if(mode>=6)return -1;
if(id==0)return -1;
unsigned short* ids=p->ids;
for(int i=0;i<p->count;i++,ids++){
if(*ids==id && a==p->a[i] && Value(p,i)==value && b==p->b[i] && mode==p->modes[i])return i;
}
return -1;
}
