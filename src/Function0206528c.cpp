// Only the fields accessed by this lookup are known.
struct Function0206528cNode
{
    unsigned short key;
    unsigned char unknown_002[0x0e];
    Function0206528cNode* next;
};

struct Function0206528cList
{
    Function0206528cNode* head;
};

extern "C" Function0206528cNode* func_0206528c(
    Function0206528cList* list, unsigned short key)
{
    Function0206528cNode* node = list->head;
    while (node != 0)
    {
        if (node->key == key)
            return node;
        node = node->next;
    }
    return 0;
}
