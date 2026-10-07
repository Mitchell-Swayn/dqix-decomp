#include <globaldefs.h>

struct Function0204acb0Record
{
    unsigned short first;
    unsigned short second;
    unsigned char third;
    unsigned char fourth;
    unsigned char unknown_006[2];
    unsigned int fifth;
    unsigned int sixth;
};

extern "C" ARM void func_0204acb0(Function0204acb0Record* record)
{
    record->first = 0;
    record->second = 0;
    record->third = 0;
    record->fourth = 0;
    record->fifth = 0;
    record->sixth = 0;
}
