/*
	Desarrollar un programa que permita registrar el nombre, apellido paterno y
	materno, DNI, edad y sexo de los pacientes de un hospital.
	El programa debe reportar las siguientes:
		1. Listado de todas las personas: nombre completo, sexo(masculino y femenino)
		y edad.
		2.Listado de las mujeres menores de edad.
		3.Dado un DNI los datos del paciente: nombre, apellido, sexo y edad.
		4.La edad promedio de las mujeres y los hombres.
		5. Listado de las personas que tienen la edad mas alta.
*/

#include "basicas.cpp"

#define MAXDNI 9
#define MAXPACIENTES 6

class Paciente{
  private:
	char nombre[MAX];
	char apPaterno[MAX];
	char apMaterno[MAX];
	char dni[MAXDNI];
	int edad;
	char sexo;

  public:
	void getNombreCompleto(char *nombreCompleto)
	{
   		strcpy(nombreCompleto, this->apPaterno);
      	strcat(nombreCompleto, " ");
      	strcat(nombreCompleto, this->apMaterno);
      	strcat(nombreCompleto, " ");
      	strcat(nombreCompleto, this->nombre);
   	}
    void getDescripcionSexo(char *sexo)
	{
   	 	if(this->sexo=='F')
		{
      		strcpy(sexo,"Femenino");
      	}else
		{
       		strcpy(sexo,"Masculino");
      	}
   	}
   	int getEdad(){
   		return this->edad;
   	}
   	char getSexo()
	{
   		return this->sexo;
   	}
   	char *getDNI()
	{
   		return this->dni;
   	}
   	void getDNI(char *nDNI)
	{
   		strcpy(nDNI,this->dni);
   	}
   	void setDNI(char *numDNI)
	{
   		strcpy(this->dni,numDNI);
   	}
   	void inicializar()
	{
   		this->nombre[0]=NULL;
      	this->apPaterno[0]=NULL;
      	this->apMaterno[0]=NULL;
      	this->dni[0]=NULL;
      	this->edad=0;
      	this->sexo='\0';
   	}
	void leer()
	{
   		cout << "Nombre : ";
   		cin >> this->nombre;
   		cout << "Ap. Paterno : ";
   		cin >> this->apPaterno;
   		cout << "Ap. Materno : ";
   		cin >> this->apMaterno;
   		this->edad=leeEntero("Edad[0-130] : ",0,130);
   		this->sexo=leeSexo("Sexo[F/M] : ");
	}
   	void mostrar()
	{
   		cout << "\n";
		cout << this->nombre << endl;
   		cout << this->apPaterno << endl;
   		cout << this->apMaterno << endl;
   		cout << this->dni << endl;
      	cout << this->edad << endl;
      	cout << this->sexo << endl;
	}
};

Paciente pacientes[MAXPACIENTES];

void inicializar()
{
	for(int i=0;i<MAXPACIENTES;i++)
	{
   		pacientes[i].inicializar();
   	}
}

//Modularizado
int buscar(char *DNIbuscar)
{
	char dni[MAXDNI];

	for(int i=0;i<MAXPACIENTES;i++)
	{
   		pacientes[i].getDNI(dni);

   		if(strcmpi(DNIbuscar,dni)==0)
		{
      		return i;
   		}
   }
   return -1;
}

void proceso()
{
	char DNI[MAXDNI];
   	int pos;
	system("cls");
	gotoxy(22,1);
	printf("REGISTRO DE PACIENTES");
	for(int i=0;i<MAXPACIENTES;i++)
	{
		cout<<"\nPaciente nro ["<<(i+1)<<"]"<<endl;
      	cout<<"================"<<endl;
      	do
		{
         	do
			{
		   		cout<<"DNI(8 digitos) : ";
         		cin>>DNI;
		   	}while(!(strlen(DNI)==MAXDNI-1));
         	pos=buscar(DNI);
         	if(pos==-1)
			{
         		pacientes[i].setDNI(DNI);
            	pacientes[i].leer();
         	}
			else
			{
         		cout<<"\t* El DNI ingresado ya ha sido registrado"<<endl;
         	}
      	}while(pos>-1);
   		cout<<"\n";
   	}
}

//1. Listado de todas las personas: nombre completo, sexo(masculino y femenino) y edad.
void presentarListado()
{
   	char nombreCompleto[MAX+3];
   	char descripcionSexo[10];

   	cout << "\n";
   	cout << "LISTADO DE PACIENTES" << endl;
	for(int i=0;i<MAXPACIENTES;i++)
	{
      	pacientes[i].getNombreCompleto(nombreCompleto);
   		pacientes[i].getDescripcionSexo(descripcionSexo);

      	cout << "\n";
      	cout << " " << (i+1) << ".- " << nombreCompleto << " - "
      	<< descripcionSexo << "(" << pacientes[i].getEdad()
        << ")" << endl;
   	}
   	cout << "=================================================" <<endl;
}
//2.Listado de las mujeres menores de edad.
void listadoMujeresMenores()
{
	char nombreCompleto[MAX+3];
   	int flag=0;
   	int n=0;

   	cout << "\n";
   	cout << "LISTADO DE MUJERES MENORES DE EDAD" << endl;
   	for(int i=0;i<MAXPACIENTES;i++)
	{
   		if(pacientes[i].getSexo()=='F' && pacientes[i].getEdad() < 18)
		{
         	pacientes[i].getNombreCompleto(nombreCompleto);

      		cout << "\n";
      		cout << " " << (n+1) << ".- " << nombreCompleto << "-"
      		<< "(" << pacientes[i].getEdad()
         	<< ")" << endl;
      		flag=1;
         	n++;
      	}
   	}
   	if(flag==0)
	{
      	cout << "\n";
   		cout << "  *No hay mujeres menores de edad." << endl;
   	}
   	cout << "=================================================" <<endl;
}

//3.Dado un DNI los datos del paciente: nombre, apellido, sexo y edad.
void pacienteDadoDNI()
{
   	char nombreCompleto[MAX+3];
   	char descripcionSexo[10];
	char nDNI[MAXDNI];
   	int flag=0;

   	cout << "\n";
	do
	{
   		cout << " Ingrese DNI a consultar(8 digitos) : ";
      	cin >> nDNI;
   	}while(!(strlen(nDNI)==MAXDNI-1));
   	for(int i=0;i<MAXPACIENTES;i++)
	{
   		if(strcmpi(pacientes[i].getDNI(),nDNI)==0)
		{
      		pacientes[i].getNombreCompleto(nombreCompleto);
   			pacientes[i].getDescripcionSexo(descripcionSexo);

      		cout << "\n";
      		cout << "  " << "Paciente : " << nombreCompleto << "-"
      		<< descripcionSexo << "(" << pacientes[i].getEdad()
         	<< ")" << endl;
      		flag=1;
   		}
   	}
   	if(flag==0)
	{
   		cout << "\n";
      	cout << "  *No hay paciente registrado con ese DNI." << endl;
   	}
   	cout << "=================================================" <<endl;
}

//4.La edad promedio de las mujeres y los hombres.
void edadPromedio()
{
	int sumHombres=0;
   	int sumMujeres=0;
   	int numHombres=0;
   	int numMujeres=0;

	cout << "\n";
   	cout << "EDAD PROMEDIO" << endl;
   	cout << "\n";
	for(int i=0;i<MAXPACIENTES;i++)
	{
      	if(pacientes[i].getSexo()=='M')
	  	{
         	sumHombres+=pacientes[i].getEdad();
         	numHombres++;
      	}
		else
		{
      		sumMujeres+=pacientes[i].getEdad();
         	numMujeres++;
      	}
   	}
   	if(numHombres>0)
	{
      	cout << "  Hombres : " << (float)sumHombres/numHombres << endl;
   	}
	else
	{
		cout << "  *No hay hombres. " << endl;
   	}
   	if(numMujeres>0)
	{
      	cout << "  Mujeres : " << (float)sumMujeres/numMujeres << endl;
   	}
	else
	{
		cout << "  *No hay mujeres. " << endl;
   	}
}

//5. Listado de las personas que tienen la edad mas alta.
void listadoEdadAlta()
{
	char nombreCompleto[MAX+3];
   	char descripcionSexo[10];
   	int edadMayor=0;
   	int n=0;

   	cout << "\n";
   	cout << "LISTADO DE PACIENTES(edad mas alta)" << endl;
	for(int i=0;i<MAXPACIENTES;i++)
	{
      	if(edadMayor<pacientes[i].getEdad()){
         	edadMayor=pacientes[i].getEdad();
      	}
   	}
   	for(int i=0;i<MAXPACIENTES;i++)
	{
      	if(edadMayor==pacientes[i].getEdad())
		{
      		pacientes[i].getNombreCompleto(nombreCompleto);
   			pacientes[i].getDescripcionSexo(descripcionSexo);

      		cout << "\n";
      		cout << " " << (n+1) << ".- " << nombreCompleto << "-"
      		<< descripcionSexo << "(" << pacientes[i].getEdad()
         	<< ")" << endl;
         	n++;
      	}
   	}
   	cout << "=================================================" <<endl;
}

// Menu
void menu()
{
	int op;

	do
	{
   		system("cls");
   		cout << "=======================================================================================" <<endl;
   		gotoxy(32,1);
   		cout << "- Lista de reportes -" << endl;
   		cout << "=======================================================================================" <<endl;
   		cout << "  1. Listado de todos los pacientes: nombre completo, sexo(masculino y femenino) y edad." << endl;
		cout << "  2. Listado de las mujeres menores de edad." << endl;
		cout << "  3. Dado un DNI los datos del paciente: nombre, apellido, sexo y edad." <<endl;
		cout << "  4. La edad promedio de las mujeres y los hombres." << endl;
		cout << "  5. Listado de los pacientes que tienen la edad mas alta." << endl;
   		cout << "  6. Salir." << endl;
   		op=leeEntero("Ingrese opcion : ",1,6);
   		switch(op)
		{
      		case 1:	presentarListado();
         		break;
         	case 2:	listadoMujeresMenores();
         		break;
	        case 3:	pacienteDadoDNI();
	         	break;
	        case 4:	edadPromedio();
	         	break;
	        case 5:	listadoEdadAlta();
	         	break;
	        case 6:  cout << "\n  Adio :'3" << endl;
	         	break;
      	}
      	getch();
   	}while(!(op==6));
}

int main()
{
   inicializar();
   proceso();
   menu();
   
   return 1;
};
