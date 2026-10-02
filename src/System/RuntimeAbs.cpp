#pragma optimize_for_size off

extern "C" int abs(int value)
{
    return value < 0 ? -value : value;
}

extern "C" long labs(long value)
{
    return value < 0 ? -value : value;
}
