struct UnknownFlagState02089758
{
    unsigned char unknown_00[0x3a];
    unsigned char state;
    unsigned char flags_3b;
    unsigned char flags_3c;
};

extern "C" void func_02089758(UnknownFlagState02089758* object)
{
    object->flags_3b &= ~2;
    object->flags_3c &= ~0x40;
    object->state = 0;
}
