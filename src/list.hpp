#ifndef LIST_H
#define LIST_H

        // pay attention to the comments: behaviour, description of arguments and return value 
#include <iostream>

template <typename T> class list;

template <typename T>
std::ostream& operator<<(std::ostream& out, const list<T>& l);

template <typename T>
struct node
{
    T data;
    node* next;
};

template <typename T>
class list
{
    private:
        int m_size;
        node <T> * m_first;
        node <T> * m_last;
    public:
        list();
        ~list();
        
        list(const list& list);
        list<T>& operator=(const list& list);

        bool is_empty();
        void print_list();

        void insert(int pos, T item);
        void remove(int pos);

        void push_back(T item);
        void pop_back();

        T& front();
        T& back();
        void reverse();

        friend std::ostream& operator<< <>(std::ostream& out, const list& l);
};

#endif

    template <typename T>
list<T>::list()
    : m_first(NULL)
    , m_last(NULL)
    , m_size(0)
{}

    template <typename T>
list<T>::~list()
{
    node<T> * tmp = m_first;
    while (tmp != NULL) {
        node<T> * current = tmp;
        delete tmp;
        --m_size;
        tmp = current->next;
    }
}

    template <typename T>
list<T>::list(const list<T>& list)
    : m_size(0)
    , m_first(NULL)
      , m_last(NULL)
{
    node<T> * new_node = list.m_first;
    while (new_node != NULL) {
        push_back(new_node->data);
        new_node = new_node->next;
    }
}

    template <typename T>
list<T>& list<T>::operator=(const list<T>& list)
{
    delete m_first;
    node<T> * new_node = list.m_first;
    while (new_node != NULL) {
        push_back(new_node->data);
        new_node = new_node->next;
    }
    return * this;
}

    template <typename T>
bool list<T>::is_empty()
{
    return (m_first == NULL);
}

    template <typename T>
void list<T>::print_list()
{
    node<T> * tmp = m_first;
    while (tmp != NULL) {
        std::cout << tmp->data <<" ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}


    template <typename T>
void list<T>::insert(int p, T value)
{
    if (p > m_size) {
        std::cout << "Error - out of range :" << std::endl;
        return;
    }
    node<T> * tmp = new node<T>;
    if (p == 0) {
        tmp->data = value;
        tmp->next = m_first;
        m_first = tmp;
        ++m_size;
        return;
    }
    node<T> * current = m_first;
    for (int i = 1; i < p; ++i) {
        current = current->next;
    }
    tmp->next = current->next;
    current->next = tmp;
    tmp->data = value;
    ++m_size;
}

    template <typename T>
void list<T>::push_back(T value)
{
    node<T> * tmp = new node<T>;
    tmp->data = value;
    tmp->next = NULL;
    if (m_first == NULL) {
        m_first = tmp;
        m_last = tmp;
    } else {
        m_last->next = tmp;
        m_last = tmp;
    }
    ++m_size;
}

    template <typename T>
void list<T>::pop_back()
{
    remove(m_size - 1);
}

    template <typename T>
void list<T>::remove(int p)
{
    if (is_empty()) {
        std::cout << "List is empty" <<std::endl;
        return;
    }
    if (p >= m_size) {
        std::cout << "Error - out of range :" << std::endl;
        return;
    }
    node<T> * current = m_first;
    node<T> * tmp = NULL;
    if (p == 0) {
        m_first = m_first->next;
        delete current;
        --m_size;
        return;
    }
    for (int i = 0; i < p; ++i) {
        tmp = current;
        current = current->next;
    }
    tmp->next = current->next;
    delete current;
    --m_size;
}
    template <typename T>
void list<T>::reverse()
{
    node<T> * current = m_first;
    node<T> * previous = NULL;
    node<T> * next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    m_first = previous;
}

template <typename T>
T& list<T>::front()
{
//    if (m_size == 0) {
  //      std::cout << "List is empty" << std::endl;
   // } else {
    return m_first->data;
   // }
}

template <typename T>
T& list<T>::back()
{
    if (m_size == 0) {
        std::cout << "list is empty" << std::endl;
    } else {
    return m_last->data;
    }
}
    template <typename T>
std::ostream& operator<<(std::ostream& out, const list<T>& l)
{
    node<T>* tmp = l.m_first;
    while (tmp) {
        out << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
    return out;
}
