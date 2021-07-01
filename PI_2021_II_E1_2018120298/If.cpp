#include<iostream>
#include<string>
#include <exception>
#include<stdlib.h>
#include<Windows.h> 
#include<clocale> 
using namespace std;

struct detalle
{
	int linea;
	string producto;
	double cantidad;
	double precio;
	double descuento;
	double isv;
	double subTotalDetalle;
}detalles[3];
struct factura
{
	int numero;
	string fecha;
	string cliente;
	double subTotal;
	double precio;
	double isv;
	double descuento;
	double totalPagar;
	detalle subTotalDetalle[3];
}facturas[3];

//double subTotalDetalle(double detalle )

int subTotalDetalle(double canXPrecio,  double descuento, double impuesto) {
	double subTotalDetalle;
	subTotalDetalle = (canXPrecio * descuento)+(canXPrecio * impuesto);
	return subTotalDetalle;

}
void imprimirfactura(factura factura);

int main () {
	setlocale(LC_ALL, "Spanish");
	SetConsoleCP(1252);
	
		double impuesto = 0.15;
		double descuento = 0.10;
		double canXPrecio;
		double subtotal;
		double subtotalMas;




		for (int i = 0; i < 3; i++)
		{
			cout << "Número de factura: ";
			cin >> facturas[i].numero;
			cout <<endl;
			cout << "Fecha: ";
			cin >> facturas[i].fecha;
			cout << endl;
			cout << "Cliente: ";
			cin >> facturas[i].fecha;
			cout << endl;
			cout << "Detalles";

			for (int j = 0; j < 3; j++)
			{
				int lineas = detalles[j].linea;
				cout << "Linea: " << j+1 << endl;
				cout << "Producto: ";
				cin.ignore();
				getline(cin, detalles[j].producto);
				cout << "cantidad: ";
				cin >> detalles[j].cantidad;
				cout << endl;
				cout << "Precio: ";
				cin >> detalles[j].precio;
				cout << endl;
				cout << "Descuento: "<< descuento*100<<"%";
				cout << endl;
				canXPrecio = (detalles[j].cantidad * detalles[j].precio);
				subTotalDetalle (canXPrecio, descuento, impuesto);
				subtotal = subTotalDetalle(canXPrecio, descuento, impuesto);
				subtotalMas = subtotal++;
				cout << subtotalMas;
				cout << subtotal;
			}
			
		}






		for (int i = 0; i < 2; i++)
		{
			imprimirfactura(facturas[i]);
		}

		 
	
	
	system("pause");
	return 0;
}
void imprimirfactura(factura facturas) {
	cout << "Número de factura: " << facturas.numero << endl;
	cout << "Cliente: " << facturas.cliente << endl;
	cout << "Subtotal: " << facturas.subTotal << endl;
	cout << "Impuesto: " << facturas.isv << endl;
	cout << "Descuento: " << facturas.descuento << endl;
	cout << "Total a pagar: " << facturas.totalPagar << endl;
	cout << "Detalle: "  << endl;
	cout << "linea: " << facturas.subTotalDetalle << endl;




}