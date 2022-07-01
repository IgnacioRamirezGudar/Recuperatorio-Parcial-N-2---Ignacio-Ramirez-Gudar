#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL){

    	this->pFirstNode = NULL;
    	this->size = 0;

    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){

    	returnAux = this->size;

    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

	Node* AuxNode = NULL;

	int size;

	size = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex < size){

			for(int i = 0; i <= nodeIndex; i++){

				if(i == 0){

					AuxNode = this->pFirstNode;

				} else {

					AuxNode = AuxNode->pNextNode;

				}
			}
	}
    return AuxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    int size;

    Node* AuxNode, *NewNode;

    size = ll_len(this);

    if(this != NULL && nodeIndex >= 0){

    	AuxNode = (Node*)malloc(sizeof(Node));

    	AuxNode->pElement = pElement;

    	if(nodeIndex == 0){

    		AuxNode->pNextNode = this->pFirstNode;
			this->pFirstNode = AuxNode;
			this->size++;
			returnAux = 0;

    	} else {

    		if(nodeIndex < size){

    			NewNode = getNode(this, nodeIndex);
    			AuxNode->pNextNode = NewNode;
				this->size++;
				returnAux = 0;

    		} else {

    			if(nodeIndex == size){

					this->size++;
					NewNode = getNode(this, nodeIndex-1);
					AuxNode->pNextNode = NULL;
					returnAux = 0;

    			}
    		}
    		NewNode->pNextNode = AuxNode;
    	}

    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    int size;

    if(this != NULL){

    	size = ll_len(this);
    	addNode(this,size,pElement);
    	returnAux = 0;

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;

    Node* AuxNode;

    int size;

    size = ll_len(this);

    if(this != NULL && index >= 0 && index < size){

    	AuxNode = getNode(this,index);
    	returnAux = AuxNode->pElement;

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;

    int size;

    Node* AuxNode;

    size = ll_len(this);

    if(this != NULL && index >= 0 && index < size){

    	AuxNode = getNode(this,index);

    	if(AuxNode != NULL){

    		AuxNode->pElement = pElement;

    		returnAux = 0;

    	}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    int size;

    Node* AuxNodeRemove, *AuxNode;

    size = ll_len(this);

    if(this != NULL && index >= 0 && index < size){

    	AuxNodeRemove = getNode(this,index);

    	if(AuxNodeRemove != NULL){

    		if(index == 0){

    			this->pFirstNode = AuxNodeRemove->pNextNode;

    		} else {

    			AuxNode = getNode(this,index-1);

    			if(AuxNode != NULL){

    				AuxNode->pNextNode = AuxNodeRemove->pNextNode;

    			}

    		}
    		free(AuxNodeRemove);

    		this->size--;

    		returnAux = 0;
    	}

    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    int size;

    size = ll_len(this);

    if(this != NULL){

    	for(int i = 0; i < size; i++){

    		ll_remove(this,i);

    	}

    	returnAux = 0;

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){

    	ll_clear(this);

    	free(this);

    	returnAux = 0;

    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    int size;

    void* AuxpElement;

    size = ll_len(this);

    if(this != NULL){

    	for(int i = 0; i < size ; i++){

    		AuxpElement = ll_get(this,i);

    		if(AuxpElement == pElement){

    			returnAux = i;

    			break;

    		}

    	}

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){

    	returnAux = 0;

    	if(this->pFirstNode == NULL){

    		returnAux = 1;

    	}

    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    int size;

    size = ll_len(this);

    if(this != NULL && index >= 0 && index <= size){

    	returnAux = addNode(this,index,pElement);

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    int size;

    size = ll_len(this);

    if(this != NULL && index >= 0 && index <= size){

    	returnAux = ll_get(this, index);
    	ll_remove(this,index);

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){

    	returnAux = 0;

    	if(ll_indexOf(this,pElement) != -1){

    		returnAux = 1;

    	}

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    int size;

    size = ll_len(this2);

    if(this != NULL && this2 != NULL){

    	returnAux = 1;

    	for(int i = 0; i < size; i++){

    		if(ll_contains(this, ll_get(this2,i)) != 1){

    			returnAux = 0;
    			break;

    		}

    	}

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    int size;

    size = ll_len(this);

    if(this != NULL && from >= 0 && to <= size && to > from){

    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL){

    		for(int i = from; i < to; i++){

    			ll_add(cloneArray, ll_get(this,i));

    		}

    	}

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int size;

    size = ll_len(this);

    if(this != NULL){

    	cloneArray = ll_subList(this, 0 , size);

    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    int size;

    void* AuxElement;
    void* AuxElement2;

    size = ll_len(this);

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){

    	for(int i = 0; i < size-1 ; i++){

    		for(int x = i+1; x < size ; x++){

    			AuxElement = ll_get(this,i);
    			AuxElement2 = ll_get(this,x);

    			if(order == 1){

    				if(pFunc(AuxElement, AuxElement2) > 0){

    					ll_set(this, i, AuxElement);
    					ll_set(this, x, AuxElement2);

    				}

    			} else {

    				if(pFunc(AuxElement, AuxElement2) < 0){

    					ll_set(this, i, AuxElement2);
    					ll_set(this, x, AuxElement);

    				}

    			}

    		}

    	}

    	returnAux = 0;

    }


    return returnAux;

}

/*
 * la función “ll_map” recibirá una lista y una función “pFunc”. se deberán iterar todos los
 *	elementos de la lista y pasárselos a la función “pFunc” que recibirá el elemento y le calculará el
 *	campo totalServicio, el retorno de “pFunc” se agregará a la lista resultado. esta nueva lista será
 *	devuelta por ll_map.
 *
 */
void ll_map(LinkedList* this, void (*pFunc)(void* pelement))
{
	int tam;

	if(this != NULL && pFunc != NULL)
	{
		tam=ll_len(this);
		for(int i = 0; i < tam; i++)
		{
			pFunc(ll_get(this, i));
		}
	}
}


/*
 * la función “ll_filter” recibirá una lista y una función “pFunc”. se deberá iterar todos los
 *	elementos de la lista y pasárselos a la función “pFunc”. la función “pFunc” devolverá 1 si ese
 *	ítem se debe agregar a la lista resultado o 0 si no debe agregarse. la función “ll_filter” generará
 *	la nueva lista resultado, agregará a la misma los ítems correspondientes y la devolverá.
 *
 *
 */

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* pElement))
{
	LinkedList* newListServices  = NULL;

	if (this != NULL && pFunc != NULL) {

		newListServices  = ll_newLinkedList();

		if (newListServices != NULL) {
			for (int i = 0; i < ll_len(this); i++) {

				void* auxElement = ll_get(this, i);

				if (pFunc(auxElement)){
					ll_add(newListServices, auxElement);
				}

			}
		}

	}
	return newListServices;
}
