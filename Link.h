#include <string>
#include <iostream>

//classe Link rappresenta il nodo di una lista. Al suo interno contiene
//il puntatore al nodo successivo, a quello precedente e un valore(una stringa)
//se non ha nodi precedenti o successivi il puntatore all'elemento successivo
//o precedente vale null

struct Link{

    private:

    std::string value;

    Link* prev;

    Link* succ;

    public:

    //ritorna il puntatore al nodo successivo
    Link* get_succ() const{
        return succ;
    }

    Link* get_prev() const{
        return prev;
    }

    std::string get_value() const{
        return value;
    }

    //permette di impostare la variabile di nodo successivo
    void set_succ(Link* s){
        this -> succ = s;
    }

    void set_prev(Link* p){
        this -> prev = p;
    }

    void set_value(std::string val){
        this -> value = val;
    }
    Link() : prev{nullptr}, succ{nullptr}{}

    Link(const std::string& v, Link* p = nullptr, Link* s = nullptr) : value{v}{}

};
