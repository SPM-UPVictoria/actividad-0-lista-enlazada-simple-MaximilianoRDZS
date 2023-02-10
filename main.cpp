/** Maximiliano Rodriguez Sanchez*/
#include <iostream>

using namespace std;
/** Se crea la estructura para la lista */
struct Node {
    int dato;
    Node *sig;
};

Node *head = NULL;

/** Se crean todas las funciones necesarias */
/** aqui es donde se insertan los datos*/
void insertar(int dato, Node *&p) {
    if (p == NULL) {
        p = new Node;
        p->dato = dato;
        p->sig = NULL;
    } else {
        insertar(dato, p->sig);
    }
}

/** aqui es donde busca el dato */
bool buscar(int dato, Node *p) {
    if (p == NULL) {
        return false;
    } else if (p->dato == dato) {
        return true;
    } else {
        return buscar(dato, p->sig);
    }
}

/** aqui es donde se elimina */
void eliminar(int dato, Node *&p) {
    if (p != NULL) {
        if (p->dato == dato) {
            Node *temp = p;
            p = p->sig;
            delete temp;
        } else {
            eliminar(dato, p->sig);
        }
    }
}

/** Aqui es donde se imprime los datos */
void imprimir(Node *p) {
    if (p != NULL) {
        cout << p->dato << " ";
        imprimir(p->sig);
    }
    else return;
}
/** main */
int main() {
    cout<<"Elementos de la lista\n";
    insertar(5, head);
    insertar(10, head);
    insertar(15, head);

    imprimir(head);
    cout <<endl;
    cout <<buscar(NULL, head) << endl;
    eliminar(5, head);
    imprimir(head);
    cout << endl;
    return 0;
}
