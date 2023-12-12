/* #include <iostream> */
#include <stdexcept>
#include "Linked_list.h"

//lista di base, esiste un unico nodo vuoto. La condizione di lista vuota
//è che begin e last puntino allo stesso elemento
//last è l'ultimo elemento e ha come valore sempre nullo
Linked_list::Linked_list() : begin{new Link()}, last{begin}{

}

//la lista inizializzata non è vuota, e il nodo begin contiene il valore
Linked_list::Linked_list(const std::string& val) : begin{new Link()}, last{new Link()}{
    begin -> set_value(val);
    begin -> set_succ(last);
    last -> set_prev(begin);
}

/* Linked_list::Linked_list(int size) : begin{new Link("")}, last{new Link("")}{ */
/*     if(size <= 0){ */
/*         throw std::invalid_argument("grandezza minore di 0"); */
/*     } */
/* } */

Linked_list::Linked_list(Linked_list& p){
    if(p.is_empty()){
        this -> begin = new Link();
        this -> last = begin;
    }

    //inizializzo il nodo di partenza allo stesso valore del nodoo di partenza della 
    //lista da copiare
    this -> begin = new Link((p.get_begin()) -> get_value());


}

//restituisce false se p è null
bool Linked_list::is_present(Link* p){
    Link* iterator = begin;
    while(iterator){
        if(iterator == p){
            //dealloco la memoria
            return true;
        }
        iterator = iterator -> get_succ();
    }
    return false;
}

Link* Linked_list::insert(Link* p, const std::string& val){
    if(!is_present(p)){
        return nullptr;
    }
    Link* new_p = new Link(val);

    new_p -> set_succ(p);

    //se esiste un precedente a p, imposta come suo nuovo successivo il nodo new_p
    if(p -> get_prev()) (p->get_prev()) -> set_succ(new_p);

    //se non esiste, aggiorna begin per puntare al nuovo elemento aggiunto in testa
    //alla lista
    else begin = new_p;

    //imposta come precedente di new_p il precedente di p: valido anche se questo è un nullptr
    new_p -> set_prev(p -> get_prev());

    //il nuovo precedente di p diventa new_p
    p -> set_prev(new_p);

    return new_p;

}

Link* Linked_list::add(Link* p, const std::string& val){
    if(!is_present(p)) return nullptr;

    Link* new_p = new Link(val);

    new_p -> set_prev(p);

    //se esiste un successivo a p, imposta come suo nuovo precedente il nodo new_p
    if(p -> get_succ()) (p->get_succ()) -> set_prev(new_p);

    //imposta come successivo di new_p il successivo di p: valido anche se questo è un nullptr
    new_p -> set_succ(p -> get_succ());

    //il nuovo successivo di p diventa new_p
    p -> set_succ(new_p);

    if(p == last) last = new_p;

    return new_p;
}

//attenzione che se si usa erase sul puntatore all'ultimo elemento, verrà eliminato il valore
//dell'elemento precedente per mantenere la proprietà dell'ultimo nodo
void Linked_list::erase(Link* p){

    //se la lista è vuota non elimina
    if(!is_present(p) || is_empty()) return;

    else if(p == begin) begin = p -> get_succ();

    else if(p == last){

        last = p -> get_prev();
        last -> set_value("");
    }

    //se p ha un nodo precedente, assegna al precedente di p il successivo di p come successivo
    if(p -> get_prev()) (p -> get_prev()) -> set_succ( p-> get_succ());

    if(p -> get_succ()) (p -> get_succ()) -> set_prev(p -> get_prev());

    p -> set_prev(nullptr);
    p -> set_succ(nullptr);
    
    //se dealloco p con delete si creano problemi di gestione della memoria. Perchè?

}

Link* Linked_list::find(const std::string& val){
    Link* iterator = begin;

    while(iterator){
        if((iterator -> get_value()).compare(val) == 0) return iterator;

        iterator = iterator -> get_succ();
    }
    return nullptr;
}

Link* Linked_list::advance(int n){

    Link* iterator = begin;

    int i = 1;
    //il ciclo si ferma quando i diventa > n oppure quando iterator diventa null: quindi se la lista ha meno di
    //n nodi ritorna null in automatico
    while(iterator){

        iterator = iterator -> get_succ();
        i++;
        if(i == n) break;

    }
    return iterator;
}

//inserisce prima di last, che deve mantenere sempre il valore null
void Linked_list::push_back(const std::string& val){
    /* Link* new_l = new Link(val); */

    /* last -> set_succ(new_l); */

    /* new_l -> set_prev(last); */

    /* last = new_l; */

    insert(last, val);
}

//inserisce in testa alla lista
void Linked_list::push_front(const std::string& val){
    /* Link* new_l = new Link(val); */

    /* begin -> set_prev(new_l); */

    /* new_l -> set_succ(begin); */

    /* begin = new_l; */

    insert(begin, val);

}

void Linked_list::pop_back(){
    //elimina il nodo precedente a last, poichè così si mantiene la proprietà del nodo last
    //(valore nullo)
    //gestisce il caso in cui facendo il pop_back la lista diventa vuota
    if(last -> get_prev() == begin){
        std::cout << "whwhw";
        begin -> set_value("");
        last -> set_prev(nullptr);
        begin -> set_succ(nullptr);
        last = begin;
        return;
    }
    erase(last -> get_prev());
}

void Linked_list::pop_front(){
    //aggiunto per gestire il caso in cui la lista diventa vuota
    if(begin -> get_succ() == last){
        begin -> set_value("");
        last -> set_prev(nullptr);
        begin -> set_succ(nullptr);
        last = begin;
        return;
    }
    erase(begin);
}

void print_all(Linked_list& list){
    Link* iterator = list.get_begin();
    int i = 1;

    //non stampo last poichè è sempre vuoto per costruzione
    /* while(iterator -> get_succ()){ */
    /*     std::cout << i++ << ": " << iterator -> get_value() << "\n"; */
    /*     iterator = iterator -> get_succ(); */
    /* } */
    while(iterator){
        std::cout << i++ << ": " << iterator -> get_value() << "\n";
        iterator = iterator -> get_succ();
    }

}

