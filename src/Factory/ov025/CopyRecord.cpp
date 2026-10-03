struct Ov25CopyRecord {
    unsigned int words[5];
    unsigned char trailingByte;
};

extern "C" void func_ov025_021dcd28(Ov25CopyRecord* destination,
                                    const Ov25CopyRecord* source)
{
    destination->words[0] = source->words[0];
    destination->words[1] = source->words[1];
    destination->words[2] = source->words[2];
    destination->words[3] = source->words[3];
    destination->words[4] = source->words[4];
    destination->trailingByte = source->trailingByte;
}
