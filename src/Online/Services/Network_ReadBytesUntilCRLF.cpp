#include <globaldefs.h>
ARM
extern "C" int Http_ReceiveSocketBytes(void*,void*,void*,int,int);
// Original: arm9/ov031 @ 0x02241694; symbol: func_ov031_02241694; size: 0x8C.
extern "C" int Network_ReadBytesUntilCRLF(void* stream,void* context){
 signed char bytes[2];
 int i;int total=0;i=0;
 bytes[0]=0;bytes[1]=0;
 while(bytes[i&1]!=13 || bytes[(i-1)&1]!=10){
 int count=Http_ReceiveSocketBytes(stream,context,bytes+(i&1),1,0);
 if(count<=0)return count;
 total+=count;i++;
 }
 return total;
}
