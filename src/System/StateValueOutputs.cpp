struct StateRecord
{
    unsigned char unknown00[0x20];
    unsigned short first;
    unsigned short second;
    unsigned short useWideValues;
    unsigned char unknown26[0x12];
    unsigned int wideFirst;
    unsigned int wideSecond;
};

extern "C" unsigned int func_02012a84(const StateRecord* state, unsigned int* first, unsigned int* second)
{
    unsigned int result;
    if (state->useWideValues)
    {
        *first = state->first;
        result = state->second;
    }
    else
    {
        *first = state->wideFirst;
        result = state->wideSecond;
    }
    *second = result;
    return result;
}

