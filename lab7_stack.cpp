#include <iostream>

struct Stack_element
{
    Stack_element* ste_prev = nullptr;
    int value = -7;
};

struct Stack_struct
{
    Stack_element* st_begin;
    Stack_element* st_end;
};

void constructor_st(Stack_struct& st)
{
    st.st_begin = nullptr;
    st.st_end = nullptr;
}

void push_st(Stack_struct& st, Stack_element& n)
{
    if (st.st_begin == nullptr) {
        Stack_element* newSt_e = new Stack_element;
        newSt_e->value = n.value;
        st.st_begin = newSt_e;
        st.st_end = newSt_e;
    }
    else if (st.st_begin != nullptr) {
        Stack_element* newSt_e = new Stack_element;
        newSt_e->value = n.value;
        newSt_e->ste_prev = st.st_end;
        st.st_end = newSt_e;
    }
    

}

Stack_element pop_st(Stack_struct& st)
{
    int a = st.st_end->value;
    Stack_element rez;
    Stack_element* tmp = new Stack_element;
    tmp = st.st_end;
    st.st_end = st.st_end->ste_prev;
    delete tmp;
    rez.value = a;
    rez.ste_prev = st.st_end;
    return rez;
}

unsigned int size_st(Stack_struct& st)
{
    Stack_element* current = new Stack_element;
    current = st.st_end;
    unsigned int counter = 0;
    while (current != nullptr) {
        counter++;
        current = current->ste_prev;
    }
    return counter;
}

void destructor_st(Stack_struct& st)
{
    while (st.st_end != nullptr) {
        Stack_element* tmp = new Stack_element;
        tmp = st.st_end;
        st.st_end = st.st_end->ste_prev;
        delete tmp;
    }
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
    std::cout << "there is " << size_st(stack_0) << " in stack." << std::endl;
    cur_element = pop_st(stack_0);
    std::cout << "Get the last element from stack. It is " << cur_element.value << std::endl;
    cur_element = pop_st(stack_0);
    std::cout << "Get the last element from stack. It is " << cur_element.value << std::endl;
    cur_element = pop_st(stack_0);
    std::cout << "Get the last element from stack. It is " << cur_element.value << std::endl;
    std::cout << "there is " << size_st(stack_0) << " in stack." << std::endl;
    destructor_st(stack_0);
    return 0;
}