#include <iostream>


using namespace std;

class Persona{
		//Atributos
protected: string proveedor, direccion;
		 int nit = 0, telefono = 0;

		 //Constructor
protected:
	Persona() {

	}
	Persona(string pro, int n, string dir, int tel) {
		proveedor = pro;
		nit = n;
		direccion = dir;
		telefono = tel;
	}		
};

