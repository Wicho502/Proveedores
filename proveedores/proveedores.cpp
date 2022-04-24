#include <iostream>
#include <mysql.h>
#include "Prov.h"

using namespace std;

int main(){

    int opcion;
    bool repetir = true;

    do {
        cout << "---MENU PRINCIPAL---" << endl;
        cout << "--------------------" << endl;
        cout << "1.  CREAR PROVEEDOR" << endl;
        cout << "2.  LISTA DE PROVEEDORES" << endl;
        cout << "3.  MODIFICAR PROVEEDORES" << endl;
        cout << "4.  ELIMINAR PROVEEDORES" << endl;
        cout << "0.  SALIR" << endl;

        cout << "\n\tIngrese una opcion: "; cin >> opcion;

        switch (opcion)
        {
        case 1:crear(); break;
        case 2:leer(); break;
        case 3:actualizar(); break;
        case 4:borrar(); break;
        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

    void crear(Prov); {
        string proveedor, direccion;
        int telefono, nit;
        cout << "Ingrese Proveedor: "; getline(cin, proveedor);
        cout << "Ingrese Nit: "; cin >> nit;
        cout << "Ingrese Direccion: "; getline(cin, direccion);
        cout << "Ingrese Telefono: "; cin >> telefono;
        cin.ignore();

        Prov p = Prov(proveedor, nit, direccion, telefono);
        p.crear();
        p.leer();
    }
   /* p.actualizar();
    p.borrar();*/

    system("pause");
    return 0;
}

