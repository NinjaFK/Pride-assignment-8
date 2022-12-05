/*
    Name: Brian Nieh, 5008139573, 1005, 8
    Description: A templated doubly linked list that will be able to open and read a text file containing a list of pronouns
    Input: pronouns.txt
    Output: Sorted pronouns
*/
#include <iostream>
#include <fstream>

template <class type>
class DoublyLinkedList
{
    struct node
    {
        type data;
        node *next;
        node *prev;
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

template <class type>
void readData(DoublyLinkedList<type>);

template <class type>
DoublyLinkedList<type>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <class type>
DoublyLinkedList<type>::~DoublyLinkedList()
{
    while (head->next != nullptr)
    {
        head = head->next;
        delete head->prev;
    }
    delete head;
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
        else if ((pass > this->tail->data) || (pass == this->tail->data))
        {
            temp->prev = this->tail;
            this->tail->next = temp;
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
    node *temp = this->head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << ".\n";
}

template <class type>
void DoublyLinkedList<type>::backwardsPrint()
{
    node *temp = this->tail;
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->prev;
    }
    std::cout << ".\n";
}

template <class type>
void readData(DoublyLinkedList<type> read)
{
    type item;
    std::ifstream infile("pronouns.txt");
    DoublyLinkedList<type>::node *temp = this->head;
    if (this->head != nullptr)
    {
        while (temp->next != nullptr)
        {
            infile >> item;
            temp->data = item;
            temp = temp->next;
        }
        infile >> item;
        temp->data = item;
    }
    infile >> item;
    while (item != "Source:")
    {
        temp->next = new node;
        temp->next->prev = temp;
        temp->next->data = item;
        temp = temp->next;
        infile >> item;
    }
    temp->next = nullptr;
}

template <class type>
bool DoublyLinkedList<type>::searchDelete(type del)
{
}
