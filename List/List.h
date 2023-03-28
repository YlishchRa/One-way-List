#pragma once

template <typename T>
class List
{
public:
    template <typename T1>
    class Node
    {
    public:
        T1 data;
        Node* ptrNext;

        Node(T1 d = T(), Node* p = nullptr) : data{d}, ptrNext{p} {}
    };

private:
    int size;
    Node<T>* head;

public:
    List();
    void push_back(T _data);
    void push_front(T _data);
    void pop_back();
    void pop_front();
    bool empty();
    T& operator[](int index);
    int getSize() { return size; }
    void clear();
    ~List();
};

template <typename T>
List<T>::List() : head{nullptr}, size{0}
{
}

template <typename T>
void List<T>::push_back(T _data)
{
    if (head == nullptr)
    {
        head = new Node<T>(_data);
    }
    else
    {
        Node<T>* current = head;
        while (current->ptrNext != nullptr)
        {
            current = current->ptrNext;
        }
        current->ptrNext = new Node<T>(_data);
    }
    size++;
}

template <typename T>
inline void List<T>::push_front(T _data)
{
    head = new Node<T>(_data, head);
    size++;
}

template <typename T>
void List<T>::pop_back()
{
    if (head == nullptr)
        return;
    // if head is equal to nullptr, it means that this is the end of the list and size = 0
    // so just return method
    if (head->ptrNext == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node<T>* current = head;
        for (size_t i = 1; i < size - 1; i++)
        {
            current = current->ptrNext;
        }
        delete current->ptrNext;
        current->ptrNext = nullptr;
    }
    size--;
}

template <typename T>
void List<T>::pop_front()
{
    if (size == 0)
        return;
    Node<T>* tmp = head->ptrNext;
    delete head;
    head = tmp;
    size--;
}

template <typename T>
inline bool List<T>::empty()
{
    return size == 0;
}

template <typename T>
T& List<T>::operator[](int index)
{
    Node<T>* current = head;

    for (size_t i = 0; i < size; i++)
    {
        if (i == index)
        {
            return current->data;
        }
        current = current->ptrNext;
    }

    return head->data;
}

template <typename T>
inline void List<T>::clear()
{
    while (size)
    {
        pop_back();
    }
}

template <typename T>
inline List<T>::~List()
{
    clear();
}