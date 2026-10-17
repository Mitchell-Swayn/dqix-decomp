#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct Entry {unsigned value;float score;};
extern "C" void Util_QuickSortPairsByFloatScore(Entry*,int,int,int);
// Original: arm9/main @ 0x020749AC; symbol: func_020749ac; size: 0x148.
extern "C" void Util_QuickSortPairsByFloatScore(Entry* entries,int first,int last,int descending) {
 int left;int right;float pivot;
 left=first; right=last; pivot=entries[left].score;
 if(descending) {
 for(;;) {
 while(entries[left].score>pivot)++left;
 while(entries[right].score<pivot)--right;
 if(left>=right)break;
 float score=entries[left].score;unsigned value=entries[left].value;
 entries[left].score=entries[right].score;
 entries[left].value=entries[right].value;
 entries[right].score=score;entries[right].value=value;
 ++left;--right;
 }
 }else {
 for(;;) {
 while(entries[left].score<pivot)++left;
 while(entries[right].score>pivot)--right;
 if(left>=right)break;
 float score=entries[left].score;unsigned value=entries[left].value;
 entries[left].score=entries[right].score;
 entries[left].value=entries[right].value;
 entries[right].score=score;entries[right].value=value;
 ++left;--right;
 }
 }
 if(first<left-1)Util_QuickSortPairsByFloatScore(entries,first,left-1,descending);
 if(right+1<last)Util_QuickSortPairsByFloatScore(entries,right+1,last,descending);
}
