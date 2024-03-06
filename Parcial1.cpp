#include <iostream>
#include <string>
#include <Locale>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

class parcial{
	public:
		nodo* pInicial;
	
	public:
		parcial() : pInicial() {}
		
		// Metodo del caso 1
		void insertarPrincipio(int numero){
			nodo* nuevoNodo = new nodo;
			nuevoNodo -> dato = numero;
			nuevoNodo -> siguiente = pInicial;
			pInicial = nuevoNodo;
		}
		
		// Metodo del caso 2
		void insertarFinal (int numero){
			nodo* nuevoNodo = new nodo;
			nuevoNodo -> dato = numero;
			nuevoNodo -> siguiente = NULL;
			
			if(!pInicial){
				pInicial = nuevoNodo;
				return;
			}
			
			nodo* actual = pInicial;
			while (actual -> siguiente){
				actual = actual -> siguiente;
			}
			actual -> siguiente = nuevoNodo;
		}
		
		// Metodo del caso 3
		void insertarPosicion(int numero, int posicion){
			nodo* nuevoNodo = new nodo();
			nuevoNodo -> dato = numero;
			
			if (posicion == 0){
				nuevoNodo -> siguiente = pInicial;
				pInicial = nuevoNodo;
				return;
			}
			
			nodo* actual =pInicial;
			int contador = 0;
			while (actual && contador < posicion - 1){
				actual = actual -> siguiente;
				contador++;
			}
			
			if (actual){
				nuevoNodo -> siguiente = actual -> siguiente;
				actual -> siguiente = nuevoNodo;
			}else{
				cout << "Posicion NO valida. No se puedo insertar!\n";
			}
			cout << endl;
		}
		
		// Metodo del caso  4
		void descendente(){
			nodo* actual = pInicial;
			nodo* anterior = NULL;
			nodo* siguiente = NULL;
			
			while (actual){
				siguiente = actual -> siguiente;
				actual -> siguiente = anterior;
				anterior = actual;
				actual = siguiente;
			}
			
			cout << "--------------------------------------\n";
			cout << "Lista modificada en orden descendente: \n";
			cout << "--------------------------------------\n\n";	
			actual = anterior;
			while (actual){
				cout << actual -> dato <<" ";
				actual = actual -> siguiente;
			}
			cout << endl;
		}
		
		// Clase del caso 5
		int ubicacion(int numero){
			nodo* actual = pInicial;
			int contador = 0;
			
			while(actual){
				if(actual -> dato == numero){
					return contador;
				}
				actual = actual -> siguiente;
				contador++;
			}
			return -1;
		}
		
		// Clase del caso 6
		nodo* posicion(int numero) {
		    nodo* actual = pInicial;
		    
		    while (actual) {
		        if (actual -> dato == numero) {
		            return actual;
		        }
		        actual = actual -> siguiente;
		    }
		    
		    return NULL;
		}
		
		// Clase del caso 7
		nodo* ultimo(){
			nodo* actual = pInicial;
				while(actual -> siguiente){
					actual = actual -> siguiente;
				}
				cout << "El valor del ultimo nodo es: " << actual -> dato << endl;
				cout << endl;
			
		}
		
		// Metodo para mostrar los elementos de la lista
		void mostrarLista() {
        nodo* actual = pInicial;
        while (actual) {
            cout << actual -> dato << " ";
            actual = actual -> siguiente;
        }
        cout << endl;
    }
    
    	//Metodo para limpiar los resultados
    	void limpiarLista() {
            nodo* actual = pInicial;
            while (actual) {
                nodo* temp = actual;
                actual = actual -> siguiente;
                delete temp;
            }
            pInicial = NULL;
        }
};

	// Metodo principal
int main(int argc, char*argv[]){
	setlocale(LC_ALL, "spanish");
	parcial corte1;
		
	int opcion;
	do{
		corte1.limpiarLista();
		
		cout << "\n\tMenú de opciones:\n\n";
		cout << "<--------------------------------------->\n";
        cout << "| 1. Insertar al principio              |\n";
        cout << "| 2. Insertar al final                  |\n";
        cout << "| 3. Insertar en la posición indicada   |\n";
        cout << "| 4. Insertar en orden ASC/DESC         |\n";
        cout << "| 5. Buscar un nodo según un valor      |\n";
        cout << "| 6. Localizar la posición de un nodo   |\n";
        cout << "| 7. Obtener el último nodo             |\n";
        cout << "<--------------------------------------->\n\n";

        cout << "Elija una opción: ";
        cin >> opcion;
   
    system("cls");
    
	    int numNodos;
		cout << "\n\t\t\tParcial Corte I\n\n";
		cout << "Ingrese la cantidad de nodos que desea tener en la lista: ";
		cin >> numNodos;
		
		system("cls");
    
    	for (int i=0; i<numNodos; i++){
		int numero;
		cout << "\nIngrese el valor del elemento " << i+1 <<": ";
		cin >> numero;
		corte1.insertarFinal(numero);
	}
	
		cout << endl;
		cout << "<--------------------------------------->\n\n";
        
        switch (opcion){
        	case 1:{
			    int numero;
			    cout << "Ingrese el valor a insertar al principio: ";
			    cin >> numero;
			    corte1.insertarPrincipio(numero);
			    cout << endl;
			    cout << "<--------------------------------------------------------->\n" << endl;
			    cout << "Valores de la lista modificada con el elemento al principio: \n\n";
        		corte1.mostrarLista();
        		
        		char respuesta;
        		cout << "\n¿Desea realizar otra consulta? (S/N): ";
        		cin >> respuesta;
        		
        		if(respuesta != 's' && respuesta != 'S'){
        			opcion = 0;
				}
				system("cls");
			    break;
			}
            case 2:{
            	int numero;
                cout << "Ingrese el valor a insertar al final: ";
			    cin >> numero;
			    corte1.insertarFinal(numero);
			    cout << endl;
			    cout << "<------------------------------------------------------>\n" << endl;
			    cout << "Valores de la lista modificada con el elemento al final: \n\n";
        		corte1.mostrarLista();
        		
        		char respuesta;
        		cout << "\n¿Desea realizar otra consulta? (S/N): ";
        		cin >> respuesta;
        		
        		if(respuesta != 's' && respuesta != 'S'){
        			opcion = 0;
				}
				system("cls");
                break;
            }
            case 3:{
                int numero, posicion;
                cout << "Ingrese el valor a insertar: ";
			    cin >> numero;
			    cout << "Ingrese la posicion donde desea que se ubique: ";
			    cin >> posicion;
			    cout << endl;
			    
			    corte1.insertarPosicion(numero, posicion);
			    
			    cout << "<------------------------------------------------------------------>\n" << endl;
			    cout << "Valores de la lista con elemento modificado en la posicion indicada: \n\n";
        		corte1.mostrarLista();
        		
        		char respuesta;
        		cout << "\n¿Desea realizar otra consulta? (S/N): ";
        		cin >> respuesta;
        		
        		if(respuesta != 's' && respuesta != 'S'){
        			opcion = 0;
				}
				system("cls");
                break;
            }
            case 4:{
			    
			    corte1.mostrarLista();
			    
			    corte1.descendente();
			    
	       		char respuesta;
        		cout << "\n¿Desea realizar otra consulta? (S/N): ";
        		cin >> respuesta;
        		
        		if(respuesta != 's' && respuesta != 'S'){
        			opcion = 0;
				}
				system("cls");
                break;
            }
            case 5:{
                int buscar;
                cout << "Ingrese el numero a encontrar: ";
                cin >> buscar;
                cout << endl;
                
                int posicion = corte1.ubicacion(buscar);
                	if(posicion != -1){
                		cout << "<--------------------------------------->\n\n";
                		cout << "El numero " << buscar << " se encuentra en la posición " << posicion << ".\n\n";
   						} else {
   							cout << "<--------------------------------------->\n\n";
       						 cout << "El numero " << buscar << " no se encuentra en la lista.\n\n";
						}
        		
        		char respuesta;
        		cout << "\n¿Desea realizar otra consulta? (S/N): ";
        		cin >> respuesta;
        		
        		if(respuesta != 's' && respuesta != 'S'){
        			opcion = 0;
				}
				system("cls");
                break;
            }
            case 6:{
			    int buscar;
			    cout << "Ingrese el numero a encontrar: ";
			    cin >> buscar;
			    cout << endl;
			    
			    nodo* nodoBuscado  = corte1.posicion(buscar);
			    if (nodoBuscado) {
			        cout << "El numero " << buscar << " tiene la direccion de memoria: " << nodoBuscado << ".\n\n";
			    } else {
			        cout << "El numero " << buscar << " no se encuentra en la lista.\n\n";
			    }
			    cout << "<--------------------------------------->\n\n";
        		
        		char respuesta;
        		cout << "\n¿Desea realizar otra consulta? (S/N): ";
        		cin >> respuesta;
        		
        		if(respuesta != 's' && respuesta != 'S'){
        			opcion = 0;
				}
				system("cls");
				break;
			}
            case 7:{
			    corte1.ultimo();
			    cout << "<--------------------------------------->\n\n";

        		
        		char respuesta;
        		cout << "\n¿Desea realizar otra consulta? (S/N): ";
        		cin >> respuesta;
        		
        		if(respuesta != 's' && respuesta != 'S'){
        			opcion = 0;
				}
				system("cls");
                break;
            }
            default:
            	if(opcion < 1 || opcion > 7){
                cout << "\t\t\n\nOpción NO valida! Intente nuevamente.\n";
				}
		}
	}while (opcion != 0);
	
	cout << "\nSaliendo del programa...!\n";

	
	return 0;
}












