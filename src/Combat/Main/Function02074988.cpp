extern const int data_020e88e4[];

extern "C" int func_02074988(int index)
{
    if (index < 0) {
        return 0;
    }

    if (index > 4) {
        return 0;
    }

    return data_020e88e4[index];
}
