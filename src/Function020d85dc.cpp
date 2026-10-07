extern "C" int func_020d8550(int value);

extern "C" int func_020d85dc(const char* first, const char* second)
{
    if (first == 0)
        return 0;
    if (second == 0)
        return 0;
    if (first == second)
        return 1;

    const signed char* left = reinterpret_cast<const signed char*>(first);
    const signed char* right = reinterpret_cast<const signed char*>(second);
    while (*left != 0 && *right != 0 &&
           func_020d8550(*left) == func_020d8550(*right))
    {
        ++left;
        ++right;
    }

    return *right == 0;
}
