#include <iostream>
#include "utilidades.hpp"
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

struct Repuesto{
    string nombre;
    string marca;
    string modelo;
    int annio;
    float precio;
};

vector<Repuesto> inventario;

struct Factura{
    string cliente;
    vector<Repuesto> detalle;
};

vector<Factura> compra;


void hr(), br();
void nombre_sistema(), menu_principal(), mostrar_inventario(), opcion_novalida(), mostrar_facturacion();
void agregar(), buscar(), eliminar(), mostrar();
void detalle_pieza(Repuesto);


void menu_facturar(), mostrarFactura(), facturar();
Repuesto agregar_carrito(); 


int main(){
    // printf("\033[2J");


    bool continuar = true;
    nombre_sistema();

   
    do{
        int opcion = 0;
        menu_principal();
        
        cin >> opcion; 
        cin.ignore();
        
        switch(opcion){
            case 1: mostrar_inventario(); break;
            case 2: mostrar_facturacion(); break;
            case 3: continuar = false; break;
            default: opcion_novalida(); break;
        }
    }while(continuar);


    nombre_sistema();
    br();

    return 0;
}





// Menu de inventario
void mostrar_inventario(){

    bool continuar = true;

    do{
        int opcion = 0;
        cout << " ---------------------> Administración productos <----------------------\n";

        cout << "\n\t 1) Agregar producto.\n";
        cout << "\t 2) Buscar productos.\n";
        cout << "\t 3) Eliminar productos.\n";
        cout << "\t 4) Mostrar Inventario\n";
        cout << "\t 5) Salir.\n";
        cout << "\n Opción : ";
        
        cin >> opcion; 
        cin.ignore();
        
        switch(opcion){
            case 1: agregar(); break;
            case 2: buscar(); break;
            case 3: eliminar(); break;
            case 4: mostrar(); break;
            case 5: continuar = false; break;
            default: opcion_novalida(); break;
        }
    }while(continuar);
}


// Menu de facturacion
void mostrar_facturacion(){


    bool continuar = true;

    do{
        int opcion = 0;
        cout << " -----------------------> Facturación productos <------------------------\n";

        cout << "\n\t 1) Comprar articulo.\n";
        cout << "\t 2) Buscar productos.\n";
        cout << "\t 3) Mostrar Inventario\n";
        cout << "\t 4) Volver.\n";
        cout << "\n Opción : ";
        
        cin >> opcion; 
        cin.ignore();
        
        switch(opcion){
            case 1: facturar(); break;
            case 2: buscar(); break;
            case 3: mostrar(); break;
            case 4: continuar = false; break;
            default: opcion_novalida(); break;
        }
    }while(continuar);
}


// Funcion para agregar nuevo Producto
void agregar(){
    
    Repuesto pieza;

    br();
    hr();
    
    cout << "| " 
      << right << setw( 45 ) << "Creación de nuevo producto" 
      << right << setw( 29 ) << "|\n";

    hr();
    br();

    cout << "\t Nombre: "; 
    getline(cin, pieza.nombre);

    cout << "\t Marca: "; 
    getline(cin, pieza.marca);

    cout << "\t Modelo: "; 
    getline(cin, pieza.modelo);

    cout << "\t Año: "; 
    cin >> pieza.annio; 
    cin.ignore();

    cout << "\t Precio: $"; 
    cin >> pieza.precio; 
    cin.ignore();

    inventario.insert(inventario.end(), pieza);

    cout << "\t Resultado: \t *** Producto agregado con éxito *** \n";
    
    br();
    hr();
}


// Mostrar todos los productos
void mostrar(){

    br();
    hr();

    cout << "| " 
      << right << setw( 45 ) << "Mostrando Inventario" 
      << right << setw( 28 ) << "|\n";

    hr();
    br();


    hr();

    cout << "| "
      << left << setw( 20 ) << "Nombre"
      << "|"
      << left << setw( 15 ) << " Marca"
      << "|"
      << left << setw( 15 ) << " Modelo"
      << "|"
      << right << setw( 8 ) << " Año"
      << " | "
      << right << setw( 8 ) << " Precio "
      << "|\n";

    hr();

    for (int i = 0; i < inventario.size(); i++) 
    {
        cout << "| "
             << left << setw( 20 ) << inventario[i].nombre
             << "|"
             << left << setw( 15 ) << inventario[i].marca
             << "| "
             << left << setw( 15 ) << inventario[i].modelo
             << "|"
             << right << setw( 8 ) << inventario[i].annio
             << "|"
             << right << setw( 8 ) << inventario[i].precio
             << "|"
             << endl;
    }
    hr();
}


// Mostrar un producto especifico
void detalle_pieza(Repuesto pieza){

    hr();
    cout << "| " 
      << right << setw( 45 ) << "Mostrando Producto" 
      << right << setw( 28 ) << "|\n";

    hr();
    br();

    hr();

    cout << "| "
      << left << setw( 20 ) << "Nombre"
      << "|"
      << left << setw( 15 ) << " Marca"
      << "|"
      << left << setw( 15 ) << " Modelo"
      << "|"
      << right << setw( 8 ) << " Año"
      << " | "
      << right << setw( 8 ) << " Precio "
      << "|\n";

    hr();
   
    cout << "| "
            << left << setw( 20 ) << pieza.nombre
            << "|"
            << left << setw( 15 ) << pieza.marca
            << "| "
            << left << setw( 15 ) << pieza.modelo
            << "|"
            << right << setw( 8 ) << pieza.annio
            << "|"
            << right << setw( 8 ) << pieza.precio
            << "|"
            << endl;
    hr();
}

// Buscar un producto o pieza
void buscar(){

    string nombre;
    Repuesto pieza;

    br();
    hr();

    cout << "| " 
      << right << setw( 45 ) << "Buscar Repuesto" 
      << right << setw( 28 ) << "|\n";
    hr();
    cout << "| \tNombre: ";
    getline(cin, nombre);

    bool encontrado = false;

    for (int i = 0; i < inventario.size(); i++) {

        if(inventario[i].nombre == nombre){
            encontrado = true;

            pieza = inventario[i];
            break;
        }
    }
    
    if(encontrado){
        detalle_pieza(pieza);
    }else{
        
        hr();

        cout << "| " << right << setw( 45 ) << "Repuesto No Encontrado"  << right << setw( 28 ) << "|\n";
        
        hr();
        br();
    }
}

void eliminar(){


    string nombre;
    Repuesto pieza;

    br();
    hr();

    cout << "| " 
      << right << setw( 45 ) << "Eliminar Repuesto" 
      << right << setw( 28 ) << "|\n";
    hr();
    cout << "| \tNombre: ";
    getline(cin, nombre);

    
    bool encontrado = false;

    for(auto i = inventario.begin(); i != inventario.end(); ++i){
        
        if(i->nombre == nombre){
            encontrado = true;

            i = inventario.erase(i);

            hr();

            cout << "| " << right << setw( 45 ) << "Repuesto Eliminado"  << right << setw( 28 ) << "|\n";
            
            hr();

            break;
        }
    }

    if(!encontrado){
        
        hr();

        cout << "| " << right << setw( 45 ) << "Repuesto No Encontrado"  << right << setw( 28 ) << "|\n";
        
        hr();
        br();
    }
}

// facturar productos a cliente
void facturar(){

    string cliente;
    Factura facturar;
    Repuesto pieza;

    vector<Repuesto> precompra;

    bool continuar = true;
    
    br();
    hr();

    cout << "| " 
      << right << setw( 45 ) << "Comprar Repuestos" 
      << right << setw( 28 ) << "|\n";
    hr();
    cout << "| \tCliente: ";
    getline(cin, cliente);

    pieza = agregar_carrito(); 
   
    if(pieza.nombre != ""){
        precompra.insert(precompra.end(), pieza);
    }

    do{
        int opcion = 0;
        menu_facturar();
        
        cin >> opcion; 
        cin.ignore();
        
        switch(opcion){
            case 1: 
                pieza = agregar_carrito(); 

                if(pieza.nombre != ""){
                    precompra.insert(precompra.end(), pieza);
                }
            break;
            case 2: mostrar(); break;
            case 3: continuar = false; break;
            default: opcion_novalida(); break;
        }
    }while(continuar);

    facturar.cliente = cliente;
    facturar.detalle = precompra;

    compra.insert(compra.end(), facturar);

    mostrarFactura();
}


Repuesto agregar_carrito(){


    string nombre;
    Repuesto pieza;

    br();
    hr();

    cout << "| " 
      << right << setw( 45 ) << "Buscar Repuesto" 
      << right << setw( 28 ) << "|\n";
    hr();
    cout << "| \tNombre: ";
    getline(cin, nombre);

    bool encontrado = false;

    for (int i = 0; i < inventario.size(); i++) {

        if(inventario[i].nombre == nombre){
            encontrado = true;

            pieza = inventario[i];
            break;
        }
    }
    
    if(encontrado){
        return pieza;
    }else{
        
        hr();

        cout << "| " << right << setw( 45 ) << "Repuesto No Encontrado"  << right << setw( 28 ) << "|\n";
        
        hr();
        br();

        return pieza;
    }
}


// Mostrar todos los productos
void mostrarFactura(){

    br();
    hr();

    cout << "| " 
      << right << setw( 45 ) << "Mostrando Factura" 
      << right << setw( 28 ) << "|\n";

    hr();
    br();

    for (int i = 0; i < compra.size(); i++) 
    {
        hr();

        cout << "| " 
        << right << setw( 5 ) << "Cliente: " 
        << left << setw( 20 ) << compra[i].cliente 
        << right << setw( 45 ) << "|\n";
        hr();

        hr();

        cout << "| "
        << left << setw( 20 ) << "Nombre"
        << "|"
        << left << setw( 15 ) << " Marca"
        << "|"
        << left << setw( 15 ) << " Modelo"
        << "|"
        << right << setw( 8 ) << " Año"
        << " | "
        << right << setw( 8 ) << " Precio "
        << "|\n";

        hr();

        for (int j = 0; j < compra[i].detalle.size(); j++) 
        {

            cout << "| "
             << left << setw( 20 ) << compra[i].detalle[j].nombre
             << "|"
             << left << setw( 15 ) << compra[i].detalle[j].marca
             << "| "
             << left << setw( 15 ) << compra[i].detalle[j].modelo
             << "|"
             << right << setw( 8 ) << compra[i].detalle[j].annio
             << "|"
             << right << setw( 8 ) << compra[i].detalle[j].precio
             << "|"
             << endl;
        }
    }
    hr();
}
