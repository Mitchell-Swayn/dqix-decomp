#include <globaldefs.h>
struct Block13 { unsigned words[13]; }; struct Block39 { unsigned words[39]; }; struct Block4 { unsigned words[5]; };
struct Bytes13 {unsigned char data[13];}; struct Bytes27 {unsigned char data[27];}; struct Bytes9 {unsigned char data[9];}; struct Bytes36 {unsigned char data[36];}; struct Bytes12 {unsigned char data[12];};
struct Words14 {unsigned short data[14];}; struct Words96 {unsigned short data[96];};
struct Record {
 signed char a; unsigned char b; Bytes13 name,otherName;
 Block13 block1c; unsigned value50; unsigned short value54,unknown56; Block39 block58;
 unsigned short valuef4; Bytes27 bytesf6; Bytes9 bytes111; Bytes36 bytes11a;unsigned char value13e,value13f; Bytes12 bytes140;
 Block4 block14c; Words14 values160; Words96 values17c;
};
// Original: arm9/main @ 0x02086868; symbol: func_02086868; size: 0x19C.
extern "C" ARM Record* Object_CopyExtendedIdentityRecordFields(Record* output,const Record* input) {
    output->a=input->a; output->b=input->b;
    output->name=input->name;
    output->otherName=input->otherName;
    output->block1c=input->block1c; output->value50=input->value50; output->value54=input->value54;
    output->block58=input->block58; output->valuef4=input->valuef4;
    output->bytesf6=input->bytesf6;
    output->bytes111=input->bytes111;
    output->bytes11a=input->bytes11a;
    output->value13e=input->value13e; output->value13f=input->value13f;
    output->bytes140=input->bytes140;
    output->block14c=input->block14c;
    output->values160=input->values160;
    output->values17c=input->values17c;
    return output;
}
