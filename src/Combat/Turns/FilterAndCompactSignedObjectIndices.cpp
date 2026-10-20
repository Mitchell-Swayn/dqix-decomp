#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_GetIndexList(void*);
// Original: arm9/ov000 @ 0x0217EE7C; symbol: func_ov000_0217ee7c; size: 0x190.
extern "C" void FilterAndCompactSignedObjectIndices(signed char* indices,signed char* length,int remove,int mode) {
 unsigned char* list=GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
 signed char count=*length;
 switch(mode) {
 case 0:break;
 case 1:
 for(signed char i=0;i<*length;i++) {
 signed char value=indices[i];
 int found=0;
 for(signed char j=0;j<list[0xf7c];j++) {
 if(value==*(list+j+0xf78)) {found=1;break;}
 }
 if(!found) {count--;indices[i]=-1;}
 }
 break;
 case 2:
 if(remove>=0 && remove<=3 ? 1:0) {
 for(signed char i=0;i<count;i++) {
 if(remove==indices[i]) {count--;indices[i]=-1;break;}
 }
 }
 break;
 }
 for(signed char i=0;i<*length-1;i++) {
 if(indices[i]<0) {
 for(signed char j=i+1;j<*length;j++) {
 if(indices[j]>=0) {indices[i]=indices[j];indices[j]=-1;break;}
 }
 }
 }
 *length=count;
}
