/*
    Name: Brian Nieh, 5008139573, 1005, 8
    Description: A templated doubly linked list that will be able to open and read a text file containing a list of pronouns
    Input: pronouns.txt
    Output: Sorted pronouns
*/
#include <iostream>

template <class type>
class DoublyLinkedList
{
    struct node
    {
        type data;
        int *next;
        int *prev;
    };

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insert(type);
    bool searchDelete(type);
    void print();
    void backwardsPrint();

private:
    node *head;
    node *tail;
};

void readData();

template <class type>
DoublyLinkedList<type>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <class type>
void DoublyLinkedList<type>::insert(type pass)
{
    node *temp = new node;
    node *temp2 = this->head;
    temp->data = pass;
    temp->next = nullptr;
    temp->prev = nullptr;

    if (head != nullptr)
    {
        // if before
        if (pass < this->head->data)
        {
            temp->next = head;
            this->head->prev = temp;
            this->head = temp;
        }
        // if end
        else if (pass > this->tail->data)
        {
            temp->prev = this->tail;
            this->tail = temp;
            this->tail = temp;
        }
        // middle
        else
        {
            while (temp2->next->data < pass)
            {
                temp2 = temp2->next;
            }
            temp2->next->prev = temp;
            temp->next = temp2->next;
            temp->prev = temp2;
            temp2->next = temp;
        }
    }
    else
    {
        this->head = temp;
        this->tail = temp;
    }
}

template <class type>
void DoublyLinkedList<type>::print()
{
}

template <class type>
void DoublyLinkedList<type>::backwardsPrint()
{
}

template <class type>
bool DoublyLinkedList<type>::searchDelete(type del)
{
}