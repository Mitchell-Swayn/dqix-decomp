struct OverrideContext
{
    unsigned char padding_000[0x6ac];
    void* value_6ac;
};

extern "C" void* func_ov017_021b8468(OverrideContext* context)
{
    return context->value_6ac;
}
