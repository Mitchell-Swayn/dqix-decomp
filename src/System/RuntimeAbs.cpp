#pragma optimize_for_size off

extern "C" int abs(int value)
{
    return value < 0 ? -value : value;
}

extern "C" long func_020017b0(long value)
{
    return value < 0 ? -value : value;
}
