extern "C" int func_0202bcbc(const void* object, int value)
{
    int index = 0;
    int result;

    goto loop_test;
loop_body:
    {
        const signed char* slot = (const signed char*)((const unsigned char*)object + index + 0x1038);
        if (value == *slot)
            goto done;
    }
    ++index;
loop_test:
    if (index < 16)
        goto loop_body;
done:
    if (index == 16)
        result = -1;
    else
        result = (signed char)index;
    return result;
}
