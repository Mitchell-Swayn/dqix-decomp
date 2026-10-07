extern "C" void *func_ov011_021849c8(void *pointer);
extern "C" void *func_ov023_021f6880(void **value, unsigned short target);
extern "C" unsigned short func_ov023_021f6f10(const void *object);

extern "C" unsigned short func_ov023_021f6378(void *pointer, unsigned short target)
{
    void **root = (void **)func_ov011_021849c8(pointer);
    void *object = func_ov023_021f6880(root, target);
    if (object == 0)
        return 0;

    if (func_ov023_021f6f10(object) != 8)
        return 0;
    return *(unsigned short *)((char *)object + 0x38);
}
