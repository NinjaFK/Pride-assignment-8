#include <iostream>
#include <string>
#include <fstream>
#include "prideImp.cpp"

int main()
{
    DoublyLinkedList<std::string> DLL;
    readData(DLL);
    DLL.print();
    DLL.searchDelete("cir");
    DLL.searchDelete("his");
    DLL.print();
    return 0;
}