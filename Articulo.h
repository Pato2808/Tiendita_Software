#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED

#include <iostream>
using namespace std;

class Articulo{
public:
    //Constructores
    Articulo();
    Articulo(string,float,int,string,int);
    //Metodos de Modificacion
    void setNombre(string);
    void setPrecio(int);
    void setNumExistencias(int);
    void setMarca(string);
    void setId(int);
    //Metodos de Acceso
    string getNombre();
    int getPrecio();
    int getNumExistencias();
    string getMarca();
    int getId();
    //Otros Metodos
    void print();
private:
    string nombre;
    float precio;
    int numExistencias;
    string marca;
    int id;
};
//Constructores
Articulo :: Articulo(){
    nombre = "N/A";
    precio = 0;
    numExistencias = 0;
    marca = "N/A";
    id = 0;
}
Articulo :: Articulo(string TempNom, float TempPrecio,int TempNumExistencias,string TempMarca, int TempId){
    nombre = TempNom;
    precio = TempPrecio;
    numExistencias = TempNumExistencias;
    marca = TempMarca;
    id = TempId;
}
//Metodos de Modificacion
void Articulo :: setNombre(string TempNom){
    nombre = TempNom;
}
void Articulo :: setPrecio(int TempPrecio){
    precio = TempPrecio;
}
void Articulo :: setNumExistencias(int TempNumExistencias){
    numExistencias = TempNumExistencias;
}
void Articulo :: setMarca(string TempMarca){
    marca = TempMarca;
}
void Articulo :: setId(int TempId){
    id = TempId;
}
//Metodos de Acceso
string Articulo :: getNombre(){
    return nombre;
}
int Articulo :: getPrecio(){
    return precio;
}
int Articulo :: getNumExistencias(){
    return numExistencias;
}
string Articulo :: getMarca(){
    return marca;
}
int Articulo :: getId(){
    return id;
}
//Otros Metodos
void Articulo :: print(){
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << endl;
    cout << "Existencias: " << numExistencias << endl;
    cout << "Marca: " << marca << endl;
    cout << "Id: " << id << endl;
    cout << endl;
}
#endif // ARTICULO_H_INCLUDED
