#include <iostream>
#include <string>
#include <fstream>
#include "prideImp.cpp"

int main()
{
    DoublyLinkedList<std::string> DLL;
    DLL.insert("ge");
    DLL.insert("ge");
    DLL.insert("gg");
    DLL.print(); // should do ge -> ge -> gg
    DLL.backwardsPrint();
    readData(DLL);
    return 0;
}