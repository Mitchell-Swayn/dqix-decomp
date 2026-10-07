// The list stores 32-bit ARM addresses; the node link used here is at 0x18.
struct Function0205e18cNode
{
    unsigned char unknown_000[0x18];
    Function0205e18cNode* next;
};

struct Function0205e18cList
{
    Function0205e18cNode* head;
    Function0205e18cNode* tail;
    unsigned int count;
};

extern "C" void func_020d8654();
extern "C" void func_020d8694();

extern "C" void func_0205e18c(
    Function0205e18cList* list, Function0205e18cNode* node)
{
    func_020d8654();

    if (list->head != 0)
    {
        list->tail->next = node;
        list->tail = node;
    }
    else
    {
        list->head = node;
        list->tail = node;
        list->head->next = 0;
    }

    ++list->count;
    list->tail->next = 0;

    func_020d8694();
}
