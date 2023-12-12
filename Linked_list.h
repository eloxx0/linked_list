#include "Link.h"

//la classe Linked_list rappresenta una lista di Link(nodi)
//contiene tutti i metodi per operare su una lista

class Linked_list{

    private:
    //puntatore al primo elemento della lista
    Link* begin;

    //puntatore all'ultimo elemento della lista
    Link* last;

    public:

    Link* get_begin(){
        return begin;
    }

    Link* get_last(){
        return last;
    }

    //costruttore di base, inizializza una lista vuota con begin == last
    explicit Linked_list();

    //costruttore che permette di inizializzare size nodi vuoti
    explicit Linked_list(int size);

    //inizializza il primo nodo con il valore val
    explicit Linked_list(const std::string& val);

    //costruttore di copia
    Linked_list(Linked_list& p);

    //ritorna true se la lista è vuota, false altrimenti
    //condizione di lista vuota è che begin e last puntino allo stesso elemento
    bool is_empty(){
        return (begin == last);
    }

    //restituisce true se il nodo p è interno alla lista, false altrimenti
    bool is_present(Link* p);

    //crea e inserisce un nodo con valore val PRIMA del nodo p appartenente
    //alla lista e ne restituisce il puntatore, nullptr se il nodo p non esiste
    Link* insert(Link* p, const std::string& val);

    //crea e inserisce un nodo con valore val DOPO al nodo p appartenente
    //alla lista e ne restituisce il puntatore, nullptr se il nodo p non
    //appartiene alla lista ritorna nullptr
    Link* add(Link* p, const std::string& val);

    //elimina il nodo p dalla lista
    void erase(Link* p);

    //cerca nodo con il valore val all'interno della lista e lo ritorna, 
    //se non presente ritorna nullptr
    Link* find(const std::string& val);

    //trova l'n-esimo elemento della lista e ritorna il puntatore se esiste, nullptr
    //se non esiste
    Link* advance(int n);

    //inserisce alla fine della lista un nodo con valore val
    void push_back(const std::string& val);

    //inserisce all'inizio della lista un nodo con valore val
    void push_front(const std::string& val);

    //elimina l'ultimo nodo della lista e ne ritorna il puntatore
    void pop_back();

    //elimina il primo nodo della lista e ne ritorna il puntatore
    void pop_front();


    //distruttore
    ~Linked_list(){
        std::cout << "delete";
        Link* l = this -> begin;
        //itera il ciclo fino a che non punta a last
        while(l <= last){
            //next_l contiene il nodo successivo a l
            Link* next_l = l->get_succ();

            delete l;

            l = next_l;
        }
    }
};

//stampa tutti gli elementi della lista
void print_all(Linked_list& list);
