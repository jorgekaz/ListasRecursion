#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dato;
    struct nodo* siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(int dato);
nodo* agregarNodoPrincipio(nodo* listaFuncion, nodo* nuevoNodo);
void mostrarDatos(int dato);
void mostrarNodo(nodo* nodoActual);
void recorrerMostrarInvertida(nodo* listaFuncion);
void recorrerMostrar(nodo* listaFuncion);
int sumaElementosLista(nodo* listaFuncion);
void recorrerMostrarPosicionPar(nodo* listaFuncion);
nodo* borrarNodo(nodo* nodoBorrar);
nodo* borrarNodoBuscado(nodo* listaFuncion, int dato);
nodo* insertarElementoOrdenado(nodo* listaOrdenada, nodo* nuevoNodo);
nodo* invertirLista(nodo* listaFuncion);


int main()
{
    nodo* listaMain = inicLista();

    listaMain = agregarNodoPrincipio(listaMain, crearNodo(2));
    listaMain = agregarNodoPrincipio(listaMain, crearNodo(5));
    listaMain = agregarNodoPrincipio(listaMain, crearNodo(7));
    listaMain = agregarNodoPrincipio(listaMain, crearNodo(6));
    listaMain = agregarNodoPrincipio(listaMain, crearNodo(4));
    printf(" LISTA ORIGINAL INVERTIDA\n");
    recorrerMostrarInvertida(listaMain);

    printf("\n\n LA SUMATORIA DE TODOS LOS ELEMENTOS DE LA LISTA ES DE: %i \n", sumaElementosLista(listaMain));

    printf("\n\n LOS ELEMENTOS EN LAS POSICIONES PARES SON: \n");
    recorrerMostrarPosicionPar(listaMain);

    printf("\n\n LISTA LUEGO DE ELIMINAR UN ELEMENTO X: \n");
    listaMain = borrarNodoBuscado(listaMain, 7);
    recorrerMostrar(listaMain);

    nodo* listaOrdenada = inicLista();
    listaOrdenada = agregarNodoPrincipio(listaOrdenada, crearNodo(50));
    listaOrdenada = agregarNodoPrincipio(listaOrdenada, crearNodo(40));
    listaOrdenada = agregarNodoPrincipio(listaOrdenada, crearNodo(30));
    listaOrdenada = agregarNodoPrincipio(listaOrdenada, crearNodo(20));
    listaOrdenada = agregarNodoPrincipio(listaOrdenada, crearNodo(10));
    printf("\n\n LISTA ORDENADA\n");
    recorrerMostrar(listaOrdenada);
    printf("\n\n");

    listaOrdenada = insertarElementoOrdenado(listaOrdenada,crearNodo(25));
    recorrerMostrar(listaOrdenada);

    printf("\n\n LISTA INVERTIDA\n");
    nodo* listaInvertida = invertirLista(listaOrdenada);
    recorrerMostrar(listaInvertida);
    printf("\n");

    return 0;
}

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(int dato){
    nodo* nodoNuevo = (nodo*) malloc(sizeof(nodo));
    nodoNuevo->siguiente = NULL;
    nodoNuevo->dato = dato;

    return nodoNuevo;
}

nodo* agregarNodoPrincipio(nodo* listaFuncion, nodo* nuevoNodo){
    if (listaFuncion != NULL){
        nuevoNodo->siguiente = listaFuncion;
    }
    listaFuncion = nuevoNodo;
    return listaFuncion;
}

void mostrarDatos(int dato){
    printf(" [%i] ", dato);
}

void mostrarNodo(nodo* nodoActual){
    if(nodoActual != NULL){
        mostrarDatos(nodoActual->dato);
    }
}

void recorrerMostrarInvertida(nodo* listaFuncion){
    if(listaFuncion != NULL){
        recorrerMostrarInvertida(listaFuncion->siguiente);
        mostrarNodo(listaFuncion);
    }
}

void recorrerMostrar(nodo* listaFuncion){
    if(listaFuncion != NULL){
        mostrarNodo(listaFuncion);
        recorrerMostrar(listaFuncion->siguiente);
    }
}

int sumaElementosLista(nodo* listaFuncion){
    int suma = 0;
    if(listaFuncion != NULL){
        suma = listaFuncion->dato + sumaElementosLista(listaFuncion->siguiente);
    }

    return suma;
}

void recorrerMostrarPosicionPar(nodo* listaFuncion){
    if(listaFuncion != NULL){
        mostrarNodo(listaFuncion);
        listaFuncion = listaFuncion->siguiente;
        if(listaFuncion != NULL){
            recorrerMostrarPosicionPar(listaFuncion->siguiente);
        }
    }
}

nodo* borrarNodo(nodo* nodoBorrar){
    nodo* auxiliar = nodoBorrar;
    nodoBorrar = nodoBorrar->siguiente;
    free(auxiliar);

    return nodoBorrar;
}

nodo* borrarNodoBuscado(nodo* listaFuncion, int dato){
    if(listaFuncion != NULL){
        if(listaFuncion->dato == dato){
            listaFuncion = borrarNodo(listaFuncion);
        }else{
            listaFuncion->siguiente = borrarNodoBuscado(listaFuncion->siguiente,dato);
        }
    }
    return listaFuncion;
}

nodo* insertarElementoOrdenado(nodo* listaOrdenada, nodo* nuevoNodo){
    if(listaOrdenada != NULL){
        if(nuevoNodo->dato < listaOrdenada->dato){
            nuevoNodo->siguiente = listaOrdenada;
            listaOrdenada = nuevoNodo;
        }else {
            listaOrdenada->siguiente = insertarElementoOrdenado(listaOrdenada->siguiente,nuevoNodo);
            if (listaOrdenada->siguiente == NULL){
                listaOrdenada->siguiente = nuevoNodo;
            }
        }
    }
    return listaOrdenada;
}


nodo* invertirLista(nodo* listaFuncion){
    if(listaFuncion == NULL){
        return NULL;
    }
    if(listaFuncion->siguiente == NULL){
        return listaFuncion;
    }

    nodo* nuevaLista = invertirLista(listaFuncion->siguiente);
    nodo* proximoNodo = listaFuncion->siguiente;
    proximoNodo->siguiente = listaFuncion;
    listaFuncion->siguiente = NULL;

    return nuevaLista;
}







