extern "C" void func_020d8654();
extern "C" void func_020d8694();

extern "C" unsigned int func_0205e1e4(unsigned int* list)
{
    func_020d8654();

    const unsigned int node = list[0];
    if (node != 0)
    {
        // The list stores 32-bit addresses. Its first entry points at a node
        // whose next link is at byte offset 0x18.
        list[0] = *reinterpret_cast<const volatile unsigned int*>(node + 0x18);
        --list[2];
    }

    func_020d8694();
    return node;
}
