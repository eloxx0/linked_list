/* #include <iostream> */
#include "Linked_list.h"

int main(){
    Linked_list l("a");

    l.push_back("b");

    print_all(l);

    l.push_back("c");

    print_all(l);

    l.push_back("d");

    print_all(l);

    Link* d = l.find("d");

    l.insert(d, "c");

    print_all(l);

    l.pop_front();

    print_all(l);

    l.pop_back();

    print_all(l);

    l.push_front("a");

    print_all(l);

    l.erase(l.get_last());

    print_all(l);

    std::cout << "valore secondo nodo: " << l.advance(2) -> get_value() << "\n";

    l.pop_back();
    print_all(l);

    l.pop_back();
    print_all(l);

    l.pop_front();
    /* print_all(l); */


    /* l.pop_back(); */

    /* print_all(l); */
    /* l.pop_back(); */

    /* print_all(l); */

    /* Linked_list ll = l; */

    /* print_all(ll); */

}
