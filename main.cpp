#include "Cliente.h"
#include <iostream>
using namespace std;

int main(){

    int numClientes = 0;
    Cliente listClientes[1000];
    int numArticulos = 0;
    Articulo inventario[1000];

    int opcion = 0;

    do{
        cout << "1)  Registrar Nuevos Clientes" << endl;
        cout << "2)  Registrar Nuevos Articulo" << endl;
        cout << "3)  Realizar Compra" << endl;
        cout << "4)  Imprimir Inventario" << endl;
        cout << "5)  Imprimir Datos Clientes" << endl;
        cout << "6)  Salir del Programa" << endl;

        cout << endl << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            {
            string tempNom;
            int tempEdad;
            string tempNumCel;
            float tempSaldo;
            float tempDeuda;
            int tempNumClient;

            cout << "Introduzca el numero de clientes por agregar: ";
            cin >> tempNumClient;

            for(int i = numClientes; i < numClientes + tempNumClient; i++){
                cout << "Cliente " << i + 1 << endl;

                cout << "Nombre: ";
                cin >> tempNom;
                cout << "Edad: ";
                cin >> tempEdad;
                cout << "Numero de Celular: ";
                cin >> tempNumCel;
                cout << "Saldo: ";
                cin >> tempSaldo;
                cout << "Deuda: ";
                cin >> tempDeuda;

                Persona tempPers(tempNom,tempEdad,tempNumCel);
                Cliente tempCliente(tempPers,tempSaldo,tempDeuda);
                listClientes[i] = tempCliente;
            }
            numClientes = numClientes + tempNumClient;

            cout << "Listo!" << endl << endl;
            break;
            }
        case 2:
            {
            string tempNom;
            float tempPrecio;
            int tempNumExist;
            string tempMarca;
            int tempId;
            int tempNumArt;

            cout << "Introduzca el numero de articulos por agregar: ";
            cin >> tempNumArt;

            for(int i = numArticulos; i < numArticulos + tempNumArt; i++){
                cout << "Articulo " << i + 1 << endl;

                cout << "Nombre: ";
                cin >> tempNom;
                cout << "Precio: ";
                cin >> tempPrecio;
                cout << "Numero de Existencias: ";
                cin >> tempNumExist;
                cout << "Marca: ";
                cin >> tempMarca;
                cout << "Id: ";
                cin >> tempId;

                Articulo aTemp(tempNom,tempPrecio,tempNumExist,tempMarca,tempId);
                inventario[i] = aTemp;
            }
            numArticulos = numArticulos + tempNumArt;

            cout << "Listo!" << endl<< endl;
            break;
            }
        case 3:
            {
            string tempNom;
            int tempId;
            int tempCantArt;
            int posArt = 10000;
            int control = 0;

            cout << "Nombre del cliente: ";
            cin >> tempNom;
            cout << "Id del articulo: ";
            cin >> tempId;
            cout << "Cantidad de articulos: ";
            cin >> tempCantArt;

            for(int i = 0; i < numArticulos; i++){
                if(inventario[i].getId() == tempId){
                    posArt = i;
                }
            }
            if(posArt == 10000){
                cout << "No se encontro un articulo con ese Id" << endl;
            }else{
                for(int i = 0; i < numClientes; i++){
                    if(listClientes[i].getCliente().getNombre() == tempNom){
                        listClientes[i].comprarArticulo(inventario[posArt],tempCantArt);
                        control = 1;
                    }
                }
                if(control == 0){
                    cout << "No se encontro un cliente con ese nombre" << endl;
                }
            }

            cout << "Listo!" << endl << endl;
            break;
            }
        case 4:
            {
            for(int i = 0; i < numArticulos; i++){
                cout << endl << "Articulo " << i + 1 << endl;
                inventario[i].print();
            }
            cout << "Listo!" << endl;
            break;
            }
        case 5:
            {
            for(int i = 0; i < numClientes; i++){
                cout << endl << "Cliente " << i + 1 << endl;
                listClientes[i].printCliente();
            }
            cout << "Listo!" << endl << endl;
            break;
            }
        case 6:
            {
            cout << "Gracias por usar este programa :)" << endl;
            break;
            }
        }
    } while(opcion != 6);
    return 0;
}
