extern "C" int func_0204ea28(int value0, int value1, int value2, int value3,
                             short lower0, short lower1)
{
    int result = 0;
    if (value2 <= value0 && value0 < lower0 && value3 <= value1)
        result = value1 < lower1;
    return result;
}
