/*
    Name: Brian Nieh, 5008139573, 1005, 8
    Description: A templated doubly linked list that
                 will be able to open and read a text
                 file containing a list of pronouns
    Input: pronouns.txt
    Output: Sorted pronouns
*/
#include <iostream>
#include <fstream>

template <class type>
class DoublyLinkedList{
public:
    struct node{
        type data;
        node *next;
        node *prev;
    };
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
void readData(DoublyLinkedList<type> &);
// consuctor sets both pointers to nullptr
template <class type>
DoublyLinkedList<type>::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
}
// deconstuctor
template <class type>
DoublyLinkedList<type>::~DoublyLinkedList(){
    if (head != nullptr){
        while (head->next != nullptr){
            head = head->next;
            delete head->prev;
        }
        delete head;
    }
}
// insert function
template <class type>
void DoublyLinkedList<type>::insert(type pass){
    node *temp = new node;
    node *temp2 = this->head;
    // set node to defaults
    temp->data = pass;
    temp->next = nullptr;
    temp->prev = nullptr;
    // checks if empty
    if (this->head != nullptr){
        // if before
        if (pass < this->head->data){
            // set temp next to head and
            // head prev to temp and update head
            temp->next = head;
            this->head->prev = temp;
            this->head = temp;
        }
        // if end
        else if ((pass > this->tail->data) || (pass == this->tail->data))
        {
            // set temp prev to the tail
            // and set tail next to temp and update tail
            temp->prev = this->tail;
            this->tail->next = temp;
            this->tail = temp;
        }
        // middle
        else{
            // while until node data is greater than pass
            while (temp2->next->data < pass){
                temp2 = temp2->next;
            }
            // change the next node prev to temp
            temp2->next->prev = temp;
            // set node to next node in order
            temp->next = temp2->next;
            // set node prev to lower node
            temp->prev = temp2;
            // set lower node to node
            temp2->next = temp;
        }
    }
    // if empty set tail and head to new node
    else{
        this->head = temp;
        this->tail = temp;
    }
}
// print function
template <class type>
void DoublyLinkedList<type>::print(){
    node *temp = this->head;
    while (temp != nullptr){
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << ".\n";
}
// print backwards
template <class type>
void DoublyLinkedList<type>::backwardsPrint(){
    // set temp to tail
    node *temp = this->tail;
    while (temp != nullptr){
        std::cout << temp->data << " -> ";
        // go backwards
        temp = temp->prev;
    }
    std::cout << ".\n";
}
// read data from file
template <class type>
void readData(DoublyLinkedList<type> &read){
    type item;
    std::ifstream infile("pronouns.txt");
    infile >> item;
    while (item != "Source:"){
        // use insert function to add
        read.insert(item);
        infile >> item;
    }
    infile.close();
}
// searchDelete function
template <class type>
bool DoublyLinkedList<type>::searchDelete(type del){
    node *temp = this->head;
    // main while loop to go through
    while (temp != nullptr){
        // if null or one node
        if (this->head == nullptr || this->head->next == nullptr){
            // delete the head then set everything to nullptr
            delete head;
            this->head = nullptr;
            this->tail = nullptr;
            temp = nullptr;
        }
        // if head node
        else if (this->head->data == del){
            // change head to the next
            this->head = this->head->next;
            // delete prev
            delete this->head->prev;
            // set head prev to null
            this->head->prev = nullptr;
            // set temp to head
            temp = this->head;
        }
        // if tail node
        else if (this->tail->data == del){
            // set tail to prev
            this->tail = this->tail->prev;
            // delete tail next
            delete this->tail->next;
            // set tail next to null
            this->tail->next = nullptr;
            // increment temp
            temp = temp->next;
        }
        // if middle node
        else if (temp->data == del){
            // set prev node to one over
            temp->prev->next = temp->next;
            // increment temp
            temp = temp->next;
            // temp pointer
            node *temp2 = temp->prev;
            // set temp prev to one before
            temp->prev = temp->prev->prev;
            // delete node
            delete temp2;
        }
        else{
            // increment temp
            temp = temp->next;
        }
    }
    return true;
}