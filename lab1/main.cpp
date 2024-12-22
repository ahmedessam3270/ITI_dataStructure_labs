#include "LinkedList.h"
#include <iostream>


int main ()
{
    try{
        LinkedList l;
        l.add(5);
        l.add(10);
        l.add(15);
        l.display();
    } catch (const char * e) {
        cout << e << endl;
    }
    return 0;
}