/*
Nombre del autor: Patricio Mendoza Pasapera
Matricula: A00830337
*/

#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>
using namespace std;

class Persona{
public:
    //Constructores
    Persona();
    Persona(string, int, string);
    //Metodos de Modificacion
    void setNombre(string);
    void setEdad(int);
    void setNumCel(string);
    //Metodos de Acceso
    string getNombre();
    int getEdad();
    string getNumCel();
private:
    string nombre;
    int edad;
    string numCel;
};
//Constructores
Persona :: Persona(){
    nombre = "N/A";
    edad = 0;
    numCel = "N/A";
}
Persona :: Persona(string TempNom, int TempEdad, string TempNumCel){
    nombre = TempNom;
    edad = TempEdad;
    numCel = TempNumCel;
}
//Metodos de Modificacion
void Persona :: setNombre(string TempNom){
    nombre = TempNom;
}
void Persona :: setEdad(int TempEdad){
    edad = TempEdad;
}
void Persona :: setNumCel(string TempNumCel){
    numCel = TempNumCel;
}
//Metodos de Acceso
string Persona :: getNombre(){
    return nombre;
}
int Persona :: getEdad(){
    return edad;
}
string Persona :: getNumCel(){
    return numCel;
}
#endif // PERSONA_H_INCLUDED
