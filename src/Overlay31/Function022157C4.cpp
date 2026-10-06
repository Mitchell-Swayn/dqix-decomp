extern "C" int func_02001aec(const void* lhs, const void* rhs, unsigned int count);
extern "C" const unsigned char data_ov031_02249b48[];

extern "C" int func_ov031_022157c4(const void* value)
{
    return func_02001aec(value, data_ov031_02249b48, 8) == 0;
}
