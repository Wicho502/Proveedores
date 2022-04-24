#include <iostream>
#include <mysql.h>
#include <string>
#include "Persona.h"
#include "ConexionBD.h"

using namespace std;

class Prov : Persona{
	//Atributos

public:
	Prov() {}

	Prov(string pro, int n, string dir, int tel) : Persona(pro,n, dir, tel) {
	}

	//Metodos
	//set(modificar)

	void setProveedor(string pro) { proveedor = pro; }
	void setApellidos(int n) { nit = n; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }

	//get(mostrar)
	
	string getProveedor() { return proveedor; }
	int getNit() { return nit; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	//metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string n = to_string(nit);
			string insert = "INSERT INTO proveedores(proveedor, nit, direccion,telefono)VALUES('" + proveedor + "','" + n + "','" + direccion + "','" + t + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso..." << endl;
			}
			else {
				cout << "xxx Error al Ingresar xxx" << endl;
			}
		}
		else {
			cout << "xx-- Error en la Conexion --xx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "Select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "-----------------Proveedores---------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ". " << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << endl;
				}
			}
			else {
				cout << "xxx Error al Ingresar Informacion xxx" << endl;
			}
		}
		else {
			cout << "xx-- Error en la Conexion --xx" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string n = to_string(nit);
			string insert = "UPDATE proveedores(proveedor, nit, direccion,telefono) SET('" + proveedor + "','" + n + "','" + direccion + "','" + t + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa..." << endl;
			}
			else {
				cout << "xxx Error en la actualizacion xxx" << endl;
			}
		}
		else {
			cout << "xx-- Error en la Conexion --xx" << endl;
		}
		cn.cerrar_conexion();
	}

	void borrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(telefono);
			string n = to_string(nit);
			string insert = "DELETE  proveedores(proveedor, nit, direccion,telefono) SET('" + proveedor + "','" + n + "','" + direccion + "','" + t + "') WHERE (idproveedores);" ;
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Borrado Exitoso..." << endl;
			}
			else {
				cout << "xxx Error al Borrar registro xxx" << endl;
			}
		}
		else {
			cout << "xx-- Error en la Conexion --xx" << endl;
		}
		cn.cerrar_conexion();
	}

};

