// The getter only relies on the entry's halfword at offset 6.
struct CountMenuEntryValueLayout
{
    unsigned char unknown_0[6];
    unsigned short value;
};

extern "C" unsigned short func_ov023_021f6f08(CountMenuEntryValueLayout* entry)
{
    return entry->value;
}
