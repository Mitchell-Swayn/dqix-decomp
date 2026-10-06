extern "C" volatile unsigned int data_02110370;

extern "C" unsigned int func_020bd42c(unsigned int value)
{
    unsigned int previous = data_02110370;
    data_02110370 = value;
    return previous;
}
