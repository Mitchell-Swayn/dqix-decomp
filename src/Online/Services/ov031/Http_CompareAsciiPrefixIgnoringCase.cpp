#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02241540; symbol: Http_CompareAsciiPrefixIgnoringCase; size: 0x68.
// Returns the remaining comparison count on mismatch; matching terminators return zero.
extern "C" int Http_CompareAsciiPrefixIgnoringCase(const signed char* left,const signed char* right,int count) {
 while(count>0) {
  int b; int a;
  a=*left++;
  b=*right++;
  if(!a || !b) {if(!a && !b) count=0;break;}
  if(b>=0x41 && b<=0x5a) b+=0x20;
  if(a>=0x41 && a<=0x5a) a+=0x20;
  if(a!=b) break;
  count--;
 }
 return count;
}
