#include <iostream>

struct Queue_element
{
    Queue_element* qe_next = nullptr;
    int value = -7;
};

struct Queue_struct
{
    Queue_element* q_begin;
    Queue_element* q_end;
};

void constructor_q(Queue_struct& q)
{
    q.q_begin = nullptr;
    q.q_end = nullptr;
}

void push_q(Queue_struct& q, Queue_element& n)
{
    Queue_element* newQ_e = new Queue_element;
    newQ_e->value = n.value;
    if (q.q_begin == nullptr) {
        q.q_begin = newQ_e;
        q.q_end = newQ_e;
        
    } else if (q.q_begin != nullptr) {
        q.q_end->qe_next = newQ_e;
        q.q_end = newQ_e;
    }

}

Queue_element pop_q(Queue_struct& q)
{
    int a = q.q_begin->value;
    Queue_element rez;
    q.q_begin = q.q_begin->qe_next;
    rez.value = a;
    rez.qe_next = q.q_begin;
    return rez;
}

unsigned int size_q(Queue_struct& q)
{
    Queue_element* current = new Queue_element;
    current = q.q_begin;
    unsigned int counter = 0;
    while (current != nullptr) {
        counter++;
        current = current->qe_next;
    }
    delete current;
    return counter;
}

void print_q(Queue_struct& q)
{
    Queue_element* current = new Queue_element;
    current = q.q_begin;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->qe_next;
    }
    std::cout << std::endl;
    delete current;
}

void del_elem(Queue_element* q)
{
    if (q != nullptr)
    {
        del_elem(q->qe_next);
        delete q;
    }
}

void destructor_q(Queue_struct& q)
{
    del_elem(q.q_begin);
}


int main()
{
    Queue_struct queue_0;
    constructor_q(queue_0);
    Queue_element cur_element;
    int a;
    for (int i = 0; i < 5; ++i) {
        std::cin >> a;
        cur_element.value = a;
        push_q(queue_0, cur_element);
    }
    print_q(queue_0);
    std::cout << "there is " << size_q(queue_0) << " in queue." << std::endl;
    cur_element = pop_q(queue_0);
    std::cout << "Get the first element from queue. It is " << cur_element.value << std::endl;
    cur_element = pop_q(queue_0);
    std::cout << "Get the first element from queue. It is " << cur_element.value << std::endl;
    cur_element = pop_q(queue_0);
    std::cout << "Get the first element from queue. It is " << cur_element.value << std::endl;
    std::cout << "there is " << size_q(queue_0) << " in queue." << std::endl;
    print_q(queue_0);
    destructor_q(queue_0);
    return 0;
}


