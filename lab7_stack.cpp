#include <iostream>

struct Stack_element
{
    Stack_element* ste_prev = nullptr;
    int value = -7;
};

struct Stack_struct
{
    Stack_element* st_end;
};

void constructor_st(Stack_struct& st)
{
    st.st_end = nullptr;
}

void push_st(Stack_struct& st, Stack_element& n)
{
    Stack_element* newSt_e = new Stack_element;
    newSt_e->value = n.value;
    if (st.st_end == nullptr) {
        st.st_end = newSt_e;
    }
    else if (st.st_end != nullptr) {
        newSt_e->ste_prev = st.st_end;
        st.st_end = newSt_e;
    }
}

Stack_element pop_st(Stack_struct& st)
{
    int a = st.st_end->value;
    Stack_element rez;
    Stack_element* del = st.st_end;
    st.st_end = st.st_end->ste_prev;
    delete del;
    rez.value = a;
    rez.ste_prev = st.st_end;
    return rez;
}

unsigned int size_st(Stack_struct& st)
{
    Stack_element* current;
    current = st.st_end;
    unsigned int counter = 0;
    while (current != nullptr) {
        counter++;
        current = current->ste_prev;
    }
    delete current;
    return counter;
}

void print_elem(Stack_element* st)
{
    if (st != nullptr)
    {
        print_elem(st->ste_prev);
        std::cout << st->value << " ";
    }
}

void print_st(Stack_struct& st)
{
    print_elem(st.st_end);
    std::cout << std::endl;
}

void del_elem(Stack_element* st)
{
    if (st != nullptr)
    {
        del_elem(st->ste_prev);
        delete st;
    }
}

void destructor_st(Stack_struct& st)
{
    del_elem(st.st_end);
}


int main()
{
    Stack_struct stack_0;
    constructor_st(stack_0);
    Stack_element cur_element;
    int a;
    for (int i = 0; i < 5; ++i) {
        std::cin >> a;
        cur_element.value = a;
        push_st(stack_0, cur_element);
    }
    print_st(stack_0);
    std::cout << "there is " << size_st(stack_0) << " in stack." << std::endl;
    cur_element = pop_st(stack_0);
    std::cout << "Get the last element from stack. It is " << cur_element.value << std::endl;
    print_st(stack_0);
    cur_element = pop_st(stack_0);
    std::cout << "Get the last element from stack. It is " << cur_element.value << std::endl;
    print_st(stack_0);
    cur_element = pop_st(stack_0);
    std::cout << "Get the last element from stack. It is " << cur_element.value << std::endl;
    print_st(stack_0);
    std::cout << "there is " << size_st(stack_0) << " in stack." << std::endl;
    std::cin >> a;
    cur_element.value = a;
    push_st(stack_0, cur_element);
    std::cout << "there is " << size_st(stack_0) << " in stack." << std::endl;
    cur_element = pop_st(stack_0);
    std::cout << "Get the last element from stack. It is " << cur_element.value << std::endl;
    std::cout << "there is " << size_st(stack_0) << " in stack." << std::endl;
    print_st(stack_0);
    destructor_st(stack_0);
    return 0;
}