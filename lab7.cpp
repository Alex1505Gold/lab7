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
    
    if (q.q_begin == nullptr) {
        Queue_element* newQ_e = new Queue_element;
        newQ_e->value = n.value;
        q.q_begin = newQ_e;
        q.q_end = newQ_e;
    } else if (q.q_begin != nullptr) {
        Queue_element* newQ_e = new Queue_element;
        newQ_e->value = n.value;
        q.q_end->qe_next = newQ_e;
        q.q_end = newQ_e;
    }

}

Queue_element pop_q(Queue_struct& q)
{
    int a = q.q_begin->value;
    Queue_element rez;
    Queue_element* tmp = new Queue_element;
    tmp = q.q_begin;
    q.q_begin = q.q_begin->qe_next;
    delete tmp;
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
    return counter;
}

void destructor_q(Queue_struct& q)
{
    while (q.q_begin != nullptr) {
        Queue_element* tmp = new Queue_element;
        tmp = q.q_begin;
        q.q_begin = q.q_begin->qe_next;
        delete tmp;
    }
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
    std::cout << "there is " << size_q(queue_0) << " in queue." << std::endl;
    cur_element = pop_q(queue_0);
    std::cout << "Get the first element from queue. It is " << cur_element.value << std::endl;
    cur_element = pop_q(queue_0);
    std::cout << "Get the first element from queue. It is " << cur_element.value << std::endl;
    cur_element = pop_q(queue_0);
    std::cout << "Get the first element from queue. It is " << cur_element.value << std::endl;
    std::cout << "there is " << size_q(queue_0) << " in queue." << std::endl;
    destructor_q(queue_0);
    return 0;
}


