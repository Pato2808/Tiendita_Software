#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "Persona.h"
#include "Articulo.h"
#include <cmath>
#include <iostream>
using namespace std;

class Cliente{
public:
    //Constructores
    Cliente();
    Cliente(Persona,float,float);
    //Metodos de Modificacion
    void setCliente(Persona);
    void setSaldo(float);
    void setDeuda(float);
    //Metodos de Acceso
    Persona getCliente();
    float getSaldo();
    float getDeuda();
    //Otros Metodos
    void depositarSaldo(float);
    void retirarSaldo(float);
    void comprarArticulo(Articulo&,int);
    void printCliente();
private:
    Persona cliente;
    float saldo;
    float deuda;
};
//Constructores
Cliente :: Cliente(){
    Persona tempCliente;
    cliente = tempCliente;
    saldo = 0.0;
    deuda = 0.0;
}
Cliente :: Cliente(Persona tempCliente, float TempSaldo, float TempDeuda){
    cliente = tempCliente;
    saldo = TempSaldo;
    deuda = TempDeuda;

    if(saldo < 0){
        deuda = abs(deuda + saldo);
        saldo = 0;
    }
    if(saldo > deuda && deuda > 0){
        saldo = saldo - deuda;
        deuda = 0;
    }else if(deuda > saldo && saldo > 0){
        deuda = deuda - saldo;
        saldo = 0;
    }
}
//Metodos de Modificacion
void Cliente :: setCliente(Persona tempCliente){
    cliente = tempCliente;
}
void Cliente :: setSaldo(float TempSaldo){
    saldo = TempSaldo;
}
void Cliente :: setDeuda(float TempDeuda){
    deuda = TempDeuda;
}
//Metodos de Acceso
Persona Cliente :: getCliente(){
    return cliente;
}
float Cliente :: getSaldo(){
    return saldo;
}
float Cliente :: getDeuda(){
    return deuda;
}
//Otros Metodos
void Cliente :: depositarSaldo(float sumSaldo){
    saldo = saldo + sumSaldo;
    if (saldo < 0){
        deuda = abs(deuda + saldo);
        saldo = 0;
    }
}
void Cliente :: retirarSaldo(float resSaldo){
    saldo = saldo - resSaldo;
    if (saldo < 0){
        deuda = deuda - saldo;
        saldo = 0;
    }
}
void Cliente :: comprarArticulo(Articulo& art,int cantArt){
    if(art.getNumExistencias() >= cantArt){
        int totalPagar = art.getPrecio() * cantArt;
        saldo = saldo - totalPagar;
        if (saldo < 0){
            deuda = abs(deuda + saldo);
            saldo = 0;
            if(saldo > deuda && deuda > 0){
                saldo = saldo - deuda;
                deuda = 0;
            }else if(deuda > saldo && saldo > 0){
                deuda = deuda - saldo;
                saldo = 0;
    }
        }
        art.setNumExistencias(art.getNumExistencias() - cantArt);
    } else{
        cout << "Solo hay: " << art.getNumExistencias() << " " << art.getNombre() << " en este momento" << endl;
    }
}
void Cliente :: printCliente(){
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Edad: " << cliente.getEdad() << endl;
    cout << "Numero de Celular: " << cliente.getNumCel() << endl;
    cout << "Saldo: " << saldo << endl;
    cout << "Deuda: " << deuda << endl;
}

#endif // CLIENTE_H_INCLUDED
