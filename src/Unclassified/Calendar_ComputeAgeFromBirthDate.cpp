#include <globaldefs.h>
struct Date { int year,month,day,weekday; }; extern "C" int Calendar_ReadCurrentDateThroughSynchronousReply(Date*);
// Original: arm9/main @ 0x02098F20; symbol: func_02098f20; size: 0x50.
 extern "C" int Calendar_ComputeAgeFromBirthDate(int year,int month,int day) { Date now; Calendar_ReadCurrentDateThroughSynchronousReply(&now); now.year+=2000; int age=now.year-year; if(month*100+day>now.month*100+now.day)--age; return age; }
