#include <iostream>
#include <string>

using namespace std;

void agregar(string arreglo[5][4], int posI)
{
    int posJ = 0;
    long telf;
    printf("Ingresa el nuevo nombre: ");
    string nom, apellido,bio="";
    cin >> nom;
    arreglo[posI][posJ] = nom;
    posJ++;
    printf("Ingresa tu apellido: ");
    cin >> apellido;
    arreglo[posI][posJ] = apellido;
    posJ++;
    bool valido = false;
    while (!valido)
    {
        printf("Ingresa tu numero de telefono: ");
        cin >> telf;
        if (telf > 59999999 && telf < 80000000)
        {
            valido = true;
            string cad = to_string(telf);
            arreglo[posI][posJ] = cad;
            posJ++;
        }
        else
        {
            printf("Ingrese un numero de telefono valido, por favor.\n");
        }

    }
    printf("Ingrese su descripcion: ");
    std::getline(cin,bio,'.');
    arreglo[posI][posJ]= bio;

}
void actualizar(string arreglo[5][4])
{
    if (arreglo[0][0].empty())
        printf("Aun no se agrego a nadie en la lista.");
    else
    {
        string buscar,act,act2,des;
        int telf,j=0;
        printf("Ingrese el nombre que desea actualizar:");
        cin >> buscar;
        bool encontrado = false;
        for (int i = 0; i<sizeof(arreglo) && !encontrado; i++)
        {
            if ((buscar.compare(arreglo[i][0])) == 0)
            {
                printf("Nombre a actualizar encontrado. Ingrese el nombre por el cual se actualizara: ");
                encontrado = true;
                cin >> act;
                arreglo[i][j] = act;
                j++;
                printf ("Ingrese su apellido: ");
                cin >> act2;
                arreglo[i][j] = act2;
                j++;
                bool valido = false;
                while (!valido)
                {
                    printf("Ingresa tu numero de telefono: ");
                    cin >> telf;
                    if (telf > 59999999 && telf < 80000000)
                    {
                        valido = true;
                        string cad = to_string(telf);
                        arreglo[i][j] = cad;
                        j++;
                    }
                    else
                    {
                        printf("Ingrese un numero de telefono valido, por favor.\n");
                    }

                }
                printf("Ingrese su descripcion:");
                getline(cin,des,'.');
                arreglo[i][j]= des;
            }
        }
        if (!encontrado)
            printf ("El nombre no se encontro, ingrese un nombre valido");
    }
    system("pause");
}
void eliminar(string arreglo[5][4])
{
    if (arreglo[0][0].empty())
        printf("Aun no se agrego a nadie en la lista.");
    else
    {
        string buscar;
        printf("Ingrese el nombre que desea eliminar:");
        cin >> buscar;
        bool encontrado = false;
        for (int i = 0; i<sizeof(arreglo) && !encontrado; i++)
        {
            if ((buscar.compare(arreglo[i][0]))== 0)
            {
                printf("Nombre a eliminar encontrado. Se procede a eliminacion.");
                encontrado = true;
                for (int j = 0; j<4; j++)
                {
                    arreglo[i][j].clear();
                }
            }
        }
        if (!encontrado)
            printf ("El nombre no se encontro, ingrese un nombre valido");
    }
    system("pause");
}
void mostrar(string arreglo[5][4])
{
    for (int i = 0; i < 5; i++)
    {
        if (!arreglo[i][0].empty())
            printf("\n");
        for (int j = 0; j<4; j++)
        {
            if (!arreglo[i][j].empty())
                cout << arreglo[i][j]<< "\t";
        }
    }
    system("pause");
}


void agregarP(string platos [5][4],int posI)
{
    int posJ = 0;
    long telf;
    printf("Ingresa el nombre del plato: ");
    string nom, apellido,bio="";
    cin >> nom;
    platos[posI][posJ] = nom;
    posJ++;
    printf("Ingrese su descripcion o los ingredientes del plato: ");
    std::getline(cin,bio,'.');
    platos[posI][posJ]= bio;
}

void actualizarP(string platos [5][4])
{
    if (platos[0][0].empty())
        printf("Aun no se agrego a nadie en la lista.");
    else
    {
        string buscar,act,act2,des;
        int telf,j=0;
        printf("Ingrese el nombre que desea actualizar:");
        cin >> buscar;
        bool encontrado = false;
        for (int i = 0; i<sizeof(platos) && !encontrado; i++)
        {
            if ((buscar.compare(platos[i][0])) == 0)
            {
                printf("Plato a actualizar encontrado. Ingrese el nombre por el cual se actualizara: ");
                encontrado = true;
                cin >> act;
                platos[i][j] = act;
                j++;
                printf("Ingrese su descripcion o ingredientes:");
                getline(cin,des,'.');
                platos[i][j]= des;
            }
        }
        if (!encontrado)
            printf ("El nombre no se encontro, ingrese un nombre valido");
    }
}

void generarRestaurant(string chefs[5][4], string platos[5][4], string clientes[5][4])
{
    int elec, posC=0, posP=0, posCl=0,a;
    bool  r1, r2, r3,continuar = true;
    while (continuar)
    {
        printf ("\t\t\t\tProyecto Restaurant\n 1.Chefs disponibles\n 2.Lista de platos\n 3.Clientes VIP\n================================\nElija una opcion(Seleccione un numero):");
        cin >> elec;
        switch (elec)
        {
        case 1:
        {
            printf(" 1.Agregar un nuevo chef\n 2.Actualizar informacion de un chef\n 3.Eliminar chef\n 4.Mostrar la lista de chefs\n================================\nElija una opcion(Seleccione un numero):");
            cin >> a;
            switch (a)
            {
            case 1:
            {
                agregar(chefs,posC);
                posC++;
                break;
            }
            case 2:
            {
                actualizar(chefs);
                break;
            }
            case 3:
            {
                eliminar(chefs);
                break;
            }
            case 4:
            {
                mostrar(chefs);
                break;
            }
            default:
                printf("Ingrese una opcion valida.\n");
            }
            break;
        }
        case 2:
        {
            printf(" 1.Agregar un nuevo plato\n 2.Actualizar informacion del plato\n 3.Eliminar plato\n 4.Mostrar la lista de platos\n================================\nElija una opcion(Seleccione un numero):");
            cin >> a;
            switch (a)
            {
            case 1:
            {
                agregarP(platos,posP);
                posP++;
                break;
            }
            case 2:
            {
                actualizarP(platos);
                break;
            }
            case 3:
            {
                eliminar(platos);
                break;
            }
            case 4:
            {
                mostrar(platos);
                break;
            }
            default:
                printf("Ingrese una opcion valida.\n");
            }
            break;
        }
        case 3:
        {
            printf(" 1.Agregar un nuevo cliente\n 2.Actualizar informacion de un cliente\n 3.Eliminar cliente\n 4.Mostrar la lista de clientes\n================================\nElija una opcion(Seleccione un numero):");
            cin >> a;
            switch (a)
            {
            case 1:
            {
                agregar(clientes,posCl);
                posCl++;
                break;
            }
            case 2:
            {
                actualizar(clientes);
                break;
            }
            case 3:
            {
                eliminar(clientes);
                break;
            }
            case 4:
            {
                mostrar(clientes);
                break;
            }
            default:
                printf("Ingrese una opcion valida.\n");
            }
            break;
        }
        default:
            printf ("No selecciona un parametro de menu disponible, elija uno por favor");
        }
        char res;
        system("cls");
        printf ("Desea continua?.Responda y/n \n================================\n");
        cin >> res;
        if (res != 'y')
        {
            printf("El programa pasa a ser cerrado");
            continuar = false;
        }
        system("cls");
    }
}

int main()
{
    string chefs[5][4], platos[5][4], clientes[5][4];
    generarRestaurant(chefs,platos,clientes);
    return 0;
}
