extern "C" volatile unsigned int data_021015a0[];

extern "C" void func_0202c848(int value) {
    int state = data_021015a0[4];
    if ((unsigned int)(state - 9) > 1U) {
        data_021015a0[18] = value;
    }
}
