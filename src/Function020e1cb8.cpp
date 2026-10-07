struct Function020e1cb8Context
{
    unsigned char unknown_000[4];
    void* volatile object;
};

struct Function020e1cb8Object
{
    unsigned char unknown_000[0x3f];
    volatile unsigned char flags;
};

extern "C" void func_020e1cb8(Function020e1cb8Context* context)
{
    Function020e1cb8Object* object =
        static_cast<Function020e1cb8Object*>(context->object);
    object->flags = static_cast<unsigned char>(object->flags & ~1);
    Function020e1cb8Object* secondObject =
        static_cast<Function020e1cb8Object*>(context->object);
    secondObject->flags = static_cast<unsigned char>(secondObject->flags | 2);
}
