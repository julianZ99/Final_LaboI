#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include <time.h>

const char archivoPedidos[]= {"pedidos.dat"};
const char archivoClientes[]= {"clientes.dat"};
const char archivoProductos[]= {"productos.dat"};
const char archivoTemp[]= {"temp.dat"};


typedef struct
{
    int idCliente;
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20];
    char mail[30];
    char genero;
    int rol;
    int activo;

} stCliente;

typedef struct
{
    int idPedido;
    int idCliente;
    char fecha[20];
    char descripcion[300];
    float costo;
    int pedidoAnulado;
} stPedido;

typedef struct
{
    int idProducto;
    char nombreProducto [30];
    char descripcionProducto [140];
    float valor;
    int cantidad;
    int productoAnulado;
} stProducto;

void logo ();
void pantallaInicial();
///Funciones de login
void menuCliente();
void cliente(int idCliente);
void funcionLogin();
int buscarUsuario(char userIngresado[], FILE * archiC);
int verificarClave(int id,char claveIngresado[], FILE * archiC);
int verificar(char userIngresado[],char claveIngresado[],FILE * archiC);
int buscaRol(char userIngresado[], FILE * archiC);
int verificarEstado(char userIngresado[], FILE * archiC);

///funciones de admin
void cargarArchivoProducto();
void administrarPerfilAdmin(int idCliente);
void administrarClientes(int idCliente);
void administrarPedidos();
void mostrarPedidos();
void estadisticaCliente();
void cambiarRolCliente();
void modificarPedidoAdmin();
void administrarProductos ();
void menuProductos ();

///Funciones de carga de clientes
int verificarUsernameRepetido (char usernameIngresado[]);
int verificarMail(char mailIngresado[]);
stCliente CargarCliente();
void cargarArchivoCliente();
int cantidadClientes();
void mostrarStructCliente(stCliente c);

void listarClientes();
void visualizarPerfil(int id);
stCliente modificacion (stCliente c, int id);
void modificarCliente(int id);
void mostrarUnCliente();
stCliente buscarCliente(FILE * archiC,int id);
void modificarCualquierCliente ();

///funciones pedidos
void menuPedido();
void pedidos(int idCliente);
stPedido cargarPedido(stPedido p, int idCliente);
void fechaPedido(stPedido * p);

void mostrarPedidosCliente(int idCliente);
void mostrarStructPedido(stPedido p);
int cantidadPedidos();
void buscarPedido();
void buscarPedidoCliente(int idCliente);
void archAltaPedido( stPedido p, int idCliente);
stPedido anularPedido (int idPedido, int idCliente,FILE *  archiP);
void modificarPedido(int idCliente);
stPedido modificacionPedidoCliente (stPedido p,int idPedido, int idCliente, FILE * archiP);
void menuModificarPedidoCliente();


///funciones productos
float costoPedido ();
float calcularCosto ();
void muestraProducto (stProducto p);
stProducto CargarProducto();
int cantidadProductos();
void mostrarProductos();
float buscarPrecio(int idProducto,FILE * archiProd);
stProducto anularProducto (int idProducto,FILE *  archiP);
void productoAnulado ();
void eliminarProductos ();



int main()
{
    logo();
    pantallaInicial();
    logo();
    return 0;
}

void logo()
{
    system("color f0");
    puts("                            :=========:====     ====:====-       -==== ========-:        :-=====-:  ");
    puts("                            #@@@@@@@@*#@@@*    :@@@@=@@@@@      =@@@@@.@@@@@@@@@@@+   :+*********##+.       ");
    puts("                           #####@@@@=@@@@-    +@@@%*@@@@@+    +@@@@@*=@@@%***%@@@@: =********######*.      ");
    puts("                               :@@@@=@@@@     %@@@+%@@@@@@   +@@@@@@-#@@@+   =@@@% =******=  =######+      ");
    puts("                               +@@@#*@@@#    .@@@@=@@@%@@@= +@@@@@@@.@@@@%###@@@+ .******=    *#####*      ");
    puts("                               %@@@=@@@@=    =@@@@+@@@-%@@%*@@@-@@@#=@@@@@@@@@@@= :******-    *####**   ");
    puts("                              .@@@@-@@@@:    %@@@+%@@@ =@@@@@%.=@@@=#@@@*:::=@@@@::******+   -####**=      ");
    puts("                              +@@@%.@@@@#-:-%@@@%:@@@*  @@@@@. #@@@.@@@@-  .+@@@@: +******+:+##****+       ");
    puts("                        *-  .%@@@+ *@@@@@@@@@@#.=@@@-  *@@%.  @@@%-@@@@@@@@@@@@+   +*************=        ");
    puts("                      .%@@@%@@@@@.  -#@@@@@%*:  #@@@    ..   -@@@+*@@@@@@@@@#+.     :=********+-.         ");
    puts("                       +@@@@@@@*.      ...                                              ....              ");
    puts("                          -===-                                                                           ");

}

void menuInicio()
{
    puts("\n\t\t\t\t\t[=================================]");
    printf("\t\t\t\t\t[       Bienvenido a JUMB-0       ]\n");
    printf("\t\t\t\t\t[ 1-Iniciar Sesion                ]\n");
    printf("\t\t\t\t\t[ 2-Registrarse                   ]\n");
    printf("\t\t\t\t\t[ 0-Salir                         ]\n");
    printf("\t\t\t\t\t[=================================]\n\n\t");
}

void menuAdmin1()
{
    puts("\n\t\t\t\t\t        Hello JUMB-O World!        ");
    puts("\t\t\t\t\t[=================================]\n");
    puts("\t\t\t\t\t[--------Menu Administrador-------]\n");
    puts("\t\t\t\t\t[ 1-Perfil de administrador       ]\n");
    puts("\t\t\t\t\t[ 2-Administrar Clientes          ]\n");
    puts("\t\t\t\t\t[ 3-Administrar Pedidos           ]\n");
    puts("\t\t\t\t\t[ 4-Administrar Productos         ]\n");
    puts("\t\t\t\t\t[ 0-Salir                         ]\n");
    puts("\t\t\t\t\t[=================================]\n\n\t");
}

void menuPerfilAdmin()
{
    puts("\n\t\t\t\t\t        Hello JUMB-O World!        ");
    puts("\t\t\t\t\t[=================================]\n");
    puts("\t\t\t\t\t[-----------Administrador---------]\n");
    puts("\t\t\t\t\t[ 1-Ver perfil                    ]\n");
    puts("\t\t\t\t\t[ 2-Modificar Perfil              ]\n");
    puts("\t\t\t\t\t[ 0-Regresar                      ]\n");
    puts("\t\t\t\t\t[=================================]\n\n\t");
}
void menuAdminClientes()
{
    puts("\n\t\t\t\t\t        Hello JUMB-O World!        ");
    puts("\t\t\t\t\t[=================================]\n");
    puts("\t\t\t\t\t[-------Administar clientes-------]\n");
    puts("\t\t\t\t\t[ 1-Lista de Clientes             ]\n");
    puts("\t\t\t\t\t[ 2-Buscar cliente                ]\n");
    puts("\t\t\t\t\t[ 3-Modificar cliente             ]\n");
    puts("\t\t\t\t\t[ 4-Dar/Quitar Rol Admin          ]\n");
    puts("\t\t\t\t\t[ 5-Estadistica cliente           ]\n");
    puts("\t\t\t\t\t[ 0-Regresar                      ]\n");
    puts("\t\t\t\t\t[=================================]\n\n\t");
}
void menuAdminPedidos()
{
    puts("\n\t\t\t\t\t        Hello JUMB-O World!        ");
    puts("\t\t\t\t\t[=================================]\n");
    puts("\t\t\t\t\t[-------Administrar pedidos-------]\n");
    puts("\t\t\t\t\t[ 1-Lista de pedidos              ]\n");
    puts("\t\t\t\t\t[ 2-Buscar pedido                 ]\n");
    puts("\t\t\t\t\t[ 3-Modificar pedido              ]\n");
    puts("\t\t\t\t\t[ 0-Regresar                      ]\n");
    puts("\t\t\t\t\t[=================================]\n\n\t");
}


void menuCliente()
{
    puts("\n\t\t\t\t\t        Hello JUMB-O World!        ");
    puts("\t\t\t\t\t[=================================]\n");
    puts("\t\t\t\t\t[---------Mi Cuenta JUMB-O--------]\n");
    puts("\t\t\t\t\t[ 1-Pedidos                       ]\n");
    puts("\t\t\t\t\t[ 2-Mi perfil                     ]\n");
    puts("\t\t\t\t\t[ 3-Modificar Perfil              ]\n");
    puts("\t\t\t\t\t[ 0-Regresar                      ]\n");
    puts("\t\t\t\t\t[=================================]\n\n\t");
}

void menuPedido()
{
    puts("\n\n");
    puts("\t\t\t\t\t[=================================]\n");
    puts("\t\t\t\t\t[-----------Menu Pedidos----------]\n");
    puts("\t\t\t\t\t[ 1-Realizar Pedido               ]\n");
    puts("\t\t\t\t\t[ 2-Mis Pedidos                   ]\n");
    puts("\t\t\t\t\t[ 3-Buscar Pedido                 ]\n");
    puts("\t\t\t\t\t[ 4-Modificar Pedido              ]\n");
    puts("\t\t\t\t\t[ 0-Regresar                      ]\n");
    puts("\t\t\t\t\t[=================================]\n\t");
}
void menuProductos ()
{
    puts("\n\n");
    puts("\t\t\t\t\t[=================================]\n");
    puts("\t\t\t\t\t[-----------Menu Productos--------]\n");
    puts("\t\t\t\t\t[ 1-Cargar Productos              ]\n");
    puts("\t\t\t\t\t[ 2-Dar de baja/anular Productos  ]\n");
    puts("\t\t\t\t\t[ 3-Visualizar Productos          ]\n");
    puts("\t\t\t\t\t[ 4-Eliminar Producto             ]\n");
    puts("\t\t\t\t\t[ 0-Regresar                      ]\n");
    puts("\t\t\t\t\t[=================================]\n\t");
}

void menuModificarPerfil()
{
    puts("\n\t\t\t\t\t[=================================]");
    puts("\t\t\t\t\t[---------Modificar Perfil--------]\n");
    puts("\t\t\t\t\t[ 1-Nombre                        ]\n");
    puts("\t\t\t\t\t[ 2-Apellido                      ]\n");
    puts("\t\t\t\t\t[ 3-Usuario                       ]\n");
    puts("\t\t\t\t\t[ 4-Clave                         ]\n");
    puts("\t\t\t\t\t[ 5-Mail                          ]\n");
    puts("\t\t\t\t\t[ 6-Genero                        ]\n");
    puts("\t\t\t\t\t[ 7-Baja/Alta                     ]\n");
    puts("\t\t\t\t\t[ 0-Regresar                      ]\n");
    puts("\t\t\t\t\t[=================================]\n\n\t");
}

void pantallaInicial()
{
    int op1=0;
    do
    {
        system("color f0");
        menuInicio();
        puts("\n\tIngrese una opcion...");
        fflush(stdin);
        scanf("%d",&op1);
        switch(op1)
        {
        case 1:
        {
            system("cls");
            funcionLogin();
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            cargarArchivoCliente();
            system("cls");
            break;
        }
        case 0:
        {
            system("cls");
            puts("Gracias por utilizar el servicio\n \n\t\t\t\t\tSaliendo... \n");
            break;
        }
        }
    }
    while (op1!=0);
}

///interaccion con admin
void admin1(int idCliente)
{
    int op1=0;
    do
    {
        system("cls");
        system("color f0");
        menuAdmin1();
        puts("\n\tIngrese una opcion... \t");
        fflush(stdin);
        scanf("%d",&op1);
        switch(op1)
        {
        case 1:
        {
            system("cls");
            administrarPerfilAdmin(idCliente);
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            administrarClientes(idCliente);
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            administrarPedidos();
            system("cls");
            break;
        }
        case 4:
        {
            system("cls");
            administrarProductos();
            system("cls");

            break;
        }
        case 0:
        {
            system("cls");
            puts("Regresando... \n");
            system("pause");
            system("cls");
            break;
        }
        }
    }
    while(op1!=0);
}
void administrarProductos ()
{
    int op1=0,op=0;
    do
    {
        system("cls");
        system("color f0");
        menuProductos();
        puts("\n\tIngrese una opcion... \t");
        fflush(stdin);
        scanf("%d",&op1);
        switch(op1)
        {
        case 1:
        {
            system("cls");
            do
            {
                cargarArchivoProducto();
                printf("\nPresione ENTER para seguir cargando productos o ESC para salir\n ");
                op=getch();
            }
            while(op!=27);
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            productoAnulado();
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            mostrarProductos();
            getch();
            system("cls");
            break;
        }
        case 4:
        {
            system("cls");
            eliminarProductos();
            system("cls");
            break;
        }
        case 0:
        {
            system("cls");
            puts("Regresando... \n");
            system("pause");
            system("cls");
            break;
        }
        }
    }
    while(op1!=0);
}

void administrarPerfilAdmin(int idCliente)
{
    int op1=0;
    do
    {
        system("cls");
        system("color f0");
        menuPerfilAdmin();
        puts("\n\tIngrese una opcion... \t");
        fflush(stdin);
        scanf("%d",&op1);
        switch(op1)
        {
        case 1:
        {
            system("cls");
            visualizarPerfil(idCliente);
            getch();
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            modificarCliente(idCliente);
            system("cls");
            break;
        }
        case 0:
        {
            system("cls");
            puts("Regresando... \n");
            system("pause");
            system("cls");
            break;
        }
        }
    }
    while(op1!=0);
}

void administrarClientes(int idCliente)
{
    int op1=0;
    do
    {
        system("cls");
        system("color f0");
        menuAdminClientes();
        puts("\n\tIngrese una opcion... \t");
        fflush(stdin);
        scanf("%d",&op1);
        switch(op1)
        {
        case 1:
        {
            system("cls");
            listarClientes();
            getch();
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            mostrarUnCliente();
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            modificarCualquierCliente();
            getch();

            break;
        }
        case 4:
        {
            system("cls");
            ///cambiar rol
            cambiarRolCliente();
            break;
        }
        case 5:
        {
            system("cls");
            ///estadistica clliente
            estadisticaCliente();
            break;
        }

        case 0:
        {
            system("cls");
            puts("Regresando... \n");
            system("cls");
            break;
        }
        }
    }
    while(op1!=0);
}


void administrarPedidos()
{
    int op1=0;
    do
    {
        system("cls");
        system("color f0");
        menuAdminPedidos();
        puts("\n\tIngrese una opcion... \t");
        fflush(stdin);
        scanf("%d",&op1);
        switch(op1)
        {
        case 1:
        {
            system("cls");
            mostrarPedidos();
            getch();
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            buscarPedido();
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            modificarPedidoAdmin();
            getch();

            break;
        }
        case 0:
        {
            system("cls");
            puts("Regresando... \n");
            system("pause");
            system("cls");
            break;
        }
        }
    }
    while(op1!=0);
}




///interaccion menu cliente
void cliente(int idCliente)
{
    int op1=0;
    do
    {
        system("cls");
        system("color f0");
        menuCliente();
        puts("\n\tIngrese una opcion... \t");
        fflush(stdin);
        scanf("%d",&op1);
        switch(op1)
        {
        case 1:
        {
            system("cls");
            pedidos(idCliente);

            break;
        }
        case 2:
        {
            system("cls");
            visualizarPerfil(idCliente);
            getch();
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            modificarCliente(idCliente);
            getch();
            system("cls");
            break;
        }
        case 0:
        {
            system("cls");
            puts("Regresando... \n");
            system("pause");
            system("cls");
            break;
        }
        }
    }
    while(op1!=0);
}

stCliente buscarCliente(FILE * archiC,int id)
{
    stCliente aux;
    int flag=0;

    if(archiC!=NULL)
    {
        while(flag==0 && fread(&aux,sizeof(stCliente),1,archiC))
        {
            if(id==aux.idCliente)
            {
                flag=1;
            }
        }
    }
    if (flag==0)
    {
        aux.idCliente=-1;
        printf("\nNo se encontro el cliente\n");
        system("pause");
    }
    return aux;
}
void modificarCualquierCliente ()
{
    int idConsigna=0;

    FILE * archiC=fopen(archivoClientes,"rb");

    stCliente c;


    printf("\nIngrese ID del cliente a modificar:\n");
    scanf("%i", &idConsigna);

    c=buscarCliente(archiC,idConsigna);
    fclose(archiC);
    if(c.idCliente!=-1)
    {
        modificarCliente(idConsigna);
    }
}
void mostrarUnCliente()
{
    int id=-1;
    FILE * archiC=fopen(archivoClientes,"rb");
    stCliente c;
    fseek(archiC,0,SEEK_SET);
    printf("\n\n\t\tIngrese numero de ID del cliente que desea buscar: ");
    scanf("%d",&id);

    c=buscarCliente(archiC,id);

    if (c.idCliente!=-1)
    {
        mostrarStructCliente(c);
        system("pause");
    }

    fclose(archiC);

}
int buscaRol(char userIngresado[], FILE * archiC)
{
    int rol=-1;
    stCliente aux;
    fseek(archiC, 0, SEEK_SET);
    if (archiC!=NULL)
    {
        while(rol==-1 &&  fread(&aux,sizeof(stCliente),1,archiC)>0)
        {
            if(strcmp(userIngresado,aux.userName)==0)
            {
                rol=aux.rol;
            }
        }

        if (rol==-1)
        {
            printf("\nError en la verificacion de Rol\n");
            system("pause");
        }
    }
    return rol;
}
int verificarEstado(char userIngresado[], FILE * archiC)
{
    int estado=-1;
    stCliente aux;
    fseek(archiC, 0, SEEK_SET);
    if (archiC!=NULL)
    {
        while(estado==-1 &&  fread(&aux,sizeof(stCliente),1,archiC)>0)
        {
            if(strcmp(userIngresado,aux.userName)==0)
            {
                estado=aux.activo;
            }
        }

    }
    return estado;
}

void funcionLogin()
{
    char userIngresado[20];
    char claveIngresado[20];

    int control=0,ret=0,idCliente=0;

    FILE * archiC=NULL;

    archiC=fopen(archivoClientes,"rb");


    do
    {
        system("cls");
        puts("\n\t\t------------------------------Ingrese sus datos para iniciar----------------------------------\n");


        printf("\n\t <>  Usuario: ");
        fflush(stdin);
        gets(userIngresado);

        printf("\n\t <>  Clave: ");
        fflush(stdin);
        int i=-1;
        do
        {
            i++;
            fflush(stdin);
            claveIngresado[i]=getch();
            if(claveIngresado[i]==13)
            {
                claveIngresado[i]='\0';
            }
            else
            {
                printf("*");
            }

        }
        while(claveIngresado[i]!='\0');

        ret=verificar(userIngresado,claveIngresado,archiC);
        if(ret==0)
        {
            system("pause");
            control=27;
        }

    }
    while(ret!=1 && control!=27);
    if(ret==1)
    {
        idCliente=buscarUsuario(userIngresado,archiC);
        if(buscaRol(userIngresado,archiC)==1)
        {
            admin1(idCliente);
        }
        else
        {
            if(verificarEstado(userIngresado,archiC)==1)
            {
                cliente(idCliente);
            }
            else
            {
                printf("\n\n\tCuenta inactiva, para activarla comuniquese con el servicio al cliente de JUMB-O.\n");
                printf("\n\tservicios@jumb0.com.ar\n\n\t");
                system("pause");
            }

        }
        fclose(archiC);
    }

}

int buscarUsuario(char userIngresado[], FILE * archiC)
{
    int pos=-1;
    stCliente aux;
    fseek(archiC, 0, SEEK_SET);
    if (archiC!=NULL)
    {
        while(pos==-1 &&  fread(&aux,sizeof(stCliente),1,archiC)>0)
        {
            if(strcmp(userIngresado,aux.userName)==0)
            {
                pos=aux.idCliente;
            }
        }
        if (pos==-1)
        {
            printf("\nEl usuario no existe\n");
        }
    }
    return pos;
}

int verificarClave(int id, char claveIngresado[], FILE * archiC)
{
    int flag=0;
    stCliente aux;
    fseek(archiC, 0, SEEK_SET);
    if (archiC!=NULL)
    {
        while(fread(&aux,sizeof(stCliente),1,archiC)>0)
        {
            if(id==aux.idCliente)
            {
                if(strcmp(claveIngresado, aux.password)==0)///la posicion no puede ir en esta variable de aux
                {
                    flag=1;
                }
            }
        }
        if(flag==0)
        {
            printf("\nClave incorrecta\n");
        }
    }
    return flag ;
}
int verificar(char userIngresado[],char claveIngresado[],FILE * archiC)
{
    int ret=0,pos=-1;
    pos=buscarUsuario(userIngresado,archiC);
    if(pos!=-1)
    {
        if(verificarClave(pos,claveIngresado,archiC)==1)
        {
            ret=1;
        }
    }
    return ret;
}
int verificarMail(char mailIngresado[])
{
    int i=0,cantArrobas=0, posArroba=0, posPunto=0,verif=0;

    while(mailIngresado[i]!='\0')
    {
        if (mailIngresado[i]=='@')
        {
            posArroba=i;
            cantArrobas++;
        }
        i++;
    }
    if (i>0 && cantArrobas==1)
    {
        i=posArroba+1;
        while(mailIngresado[i]!='\0' && posPunto==0)
        {
            if (mailIngresado[i]=='.')
            {
                posPunto=i;
            }
            i++;
        }
        printf("\t\npos punto %i", posPunto);
        if(mailIngresado[posPunto+1]!='\0')
        {
            verif=1;
        }
    }
    else
    {
        printf("\t \t \nEl e-mail ingresado no es correcto, intentelo nuevamente.\n");
        system("pause");
    }
    return verif;
}
int verificarUsernameRepetido (char usernameIngresado[])
{
    stCliente c;
    int flag=0;
    FILE *archiC=fopen(archivoClientes, "rb");
    fseek(archiC, 0,SEEK_SET);
    if (archiC!=NULL)
    {
        while (fread(&c, sizeof(stCliente),1,archiC)>0 && flag==0)
        {
            if(strcmp(usernameIngresado, c.userName)==0)
            {
                flag=1;
                printf("\t \t \n Nombre de usuario existente, por favor seleccione otro: \n");
                system("pause");
            }
        }
    }
    fclose(archiC);
    return flag;
}

/// Carga cliente
stCliente CargarCliente()
{
    stCliente cliente;
    int idC=0,mal=0;
    char genero=' ';
    idC=cantidadClientes();
    cliente.idCliente=idC+1;
    if (idC==-1)
    {
        strcpy(cliente.userName,"admin");
        strcpy(cliente.password,"admin");
        strcpy(cliente.nombre,"JUMB-O");
        strcpy(cliente.apellido,"Servicios");
        cliente.genero='H';

        strcpy(cliente.mail,"servicio@jumb0.com");
        cliente.rol=1;
        printf("\nGeneracion de usuario administrador, para conocimiento de las credenciales refierase al manual de instrucciones: \n");
        system("pause");
    }
    else
    {

        puts("\n\t\t---------------Ingrese sus datos para registrarse--------------------");

        do
        {
            printf("\n\n\t <>  Usuario: ");
            fflush(stdin);
            gets(cliente.userName);
        }
        while(verificarUsernameRepetido(cliente.userName)==1);

        printf("\n\n\t <>  Clave: ");
        fflush(stdin);
        gets(cliente.password);
        printf("\n\n\t <>  Nombre: ");
        fflush(stdin);
        gets(cliente.nombre);
        printf("\n\n\t <>  Apellido: ");
        fflush(stdin);
        gets(cliente.apellido);
        printf("\n\n\t <>  Genero M(mujer)-H(hombre): ");
        do
        {
            fflush(stdin);
            scanf("%c", &genero);
            if(genero!='M' && genero!='H')
            {
                mal=1;
                printf("\n\tIngrese correctamente el genero(MAYUSCULA)\n");
            }
            else
            {
                mal=0;
            }
        }
        while(mal==1);
        cliente.genero=genero;
        do
        {
            printf("\n\n\t <>  Mail: ");
            fflush(stdin);
            gets(cliente.mail);
        }
        while (verificarMail(cliente.mail)==0);

        cliente.rol=0;

    }
    cliente.activo=1;
    return cliente;
}
/// pasa estructura de cliente a archivo
void cargarArchivoCliente()
{

    stCliente c;

    FILE * cliente = fopen(archivoClientes, "ab");

    if (cliente ==NULL)
    {

        printf("El archivo no existe!");

    }
    else
    {

        c=CargarCliente();

        fwrite(&c, sizeof(stCliente),1, cliente);

    }
    fclose(cliente);
}


/// cuenta la cantidad de clientes
int cantidadClientes()
{
    stCliente c;
    FILE *archiCliente= fopen(archivoClientes,"rb");
    int cantClientes=-1;

    if(archiCliente!=NULL)
    {
        while(fread(&c, sizeof(stCliente), 1, archiCliente))
        {
            cantClientes++;
        }
    }
    fclose(archiCliente);
    return cantClientes;
}
///rol 1
void listarClientes()
{
    FILE * archiC=NULL;

    archiC=fopen(archivoClientes,"rb");

    stCliente aux;

    if(archiC!=NULL)
    {
        while(fread(&aux,sizeof(stCliente),1,archiC))
        {
            mostrarStructCliente(aux);
        }
    }
    else
    {
        printf("\nERROR\n");
    }
    fclose(archiC);
}


void visualizarPerfil(int id)
{
    FILE * archiC = NULL;

    archiC=fopen(archivoClientes,"rb");

    stCliente c;


    if(archiC!=NULL)
    {
        while(fread(&c,sizeof(stCliente),1,archiC))
        {
            if(id==c.idCliente)
            {
                mostrarStructCliente(c);
            }

        }
    }
    fclose(archiC);
}

void mostrarStructCliente(stCliente c)
{

    puts("\n------------------------------------------------------------\n");
    printf("\n\tID Cliente: %d\n",c.idCliente);
    printf("\n\t    Nombre: %s\n",c.nombre);
    printf("\n\t  Apellido: %s\n",c.apellido);
    printf("\n\t  Username: %s\n",c.userName);
    printf("\n\t      Mail: %s\n",c.mail);
    printf("\n\t    Genero: %c\n",c.genero);
    if(c.activo==0)
    {
        printf("\n\t    Perfil: Inactivo\n");
    }
    else
    {
        printf("\n\t    Perfil: Activo\n");
    }
    if(c.rol==1)
    {
        printf("\n\t       Rol: Administrador\n");
    }
    else
    {
        printf("\n\t       Rol: Cliente\n");
    }

    puts("\n------------------------------------------------------------\n");
}


stCliente modificacion (stCliente c, int id)
{
    int op=0;
    do
    {
        system("color f0");
        menuModificarPerfil();
        puts("\n\tIngrese una opcion...");
        fflush(stdin);
        scanf("%d",&op);
        switch(op)
        {
        case 1:
        {
            system("cls");
            printf("\nIngrese nuevo Nombre:\n");
            fflush(stdin);
            gets(c.nombre);
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            printf("\nIngrese nuevo Apellido:\n");
            fflush(stdin);
            gets(c.apellido);
            system("cls");
            break;
        }
        case 3:
        {
            do
            {
                system("cls");
                printf("\nIngrese nuevo Usuario: \n");
                fflush(stdin);
                gets(c.userName);
                system("cls");
            }
            while(verificarUsernameRepetido(c.userName)==1);
            break;
        }
        case 4:
        {
            system("cls");
            printf("\nIngrese nueva Clave:\n");
            fflush(stdin);
            gets(c.password);
            system("cls");
            break;
        }
        case 5:
        {
            do
            {
                system("cls");
                printf("\nIngrese nuevo mail:\n");
                fflush(stdin);
                gets(c.mail);
                system("cls");
            }
            while (verificarMail(c.mail)==0);
            break;
        }
        case 6:
        {
            system("cls");
            printf("\nIngrese nuevo genero:\n");
            fflush(stdin);
            scanf("%c",&c.genero);
            system("cls");
            break;
        }
        case 7:
        {
            system("cls");
            if(id>0)
            {
                if(c.activo==1)
                {
                    c.activo=0;
                    printf("\t\t\nCuenta desactivada en caso de cerrar sesion no podra volver a ingresar\n");
                    system("pause");
                }
                else
                {
                    c.activo=1;
                    printf("\t\t\nCuenta activada.\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nEste usuario no puede darse de baja.\n\n\n");
                system("pause");
            }
            system("cls");
            break;
        }
        case 0:
        {
            system("cls");
            puts("Regresando... \n");
            break;
        }
        }
    }
    while(op!=0);
    return c;
}


void modificarCliente( int id )
{
    FILE * archiC=fopen(archivoClientes,"r+b");
    fseek(archiC, 0, SEEK_SET);
    stCliente aux;
    stCliente modif;

    int flag=0;

    if(archiC!=NULL)
    {
        //BUSCO CLIENTE
        while(!feof(archiC)&& flag==0)
        {
            if(fread(&aux,sizeof(stCliente),1,archiC)>0)
            {
                if(aux.idCliente==id)
                {
                    flag=1;
                }
            }
        }

        if (flag==1)
        {
            // muevo una posicion hacia atras en el id
            fseek(archiC,(-1)*sizeof(stCliente), SEEK_CUR);
            modif=modificacion(aux,id);
            fwrite(&modif, sizeof(stCliente),1,archiC);

        }
        fclose(archiC);
    }
}

///llama a las funciones del menu de pedidos
void pedidos(int idCliente)
{
    stPedido pedidos;
    int op1;

    do
    {
        system("color f0");
        menuPedido();
        puts("\n\tIngrese una opcion... \t");
        fflush(stdin);
        scanf("%d",&op1);
        switch(op1)
        {
        case 1:
        {
            archAltaPedido(pedidos,idCliente);
            break;
        }
        case 2:
        {
            system("cls");
            mostrarPedidosCliente(idCliente);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            system("cls");
            buscarPedidoCliente(idCliente);
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            system("cls");
            modificarPedido(idCliente);
            system("pause");
            system("cls");
            break;
        }
        case 0:
        {
            system("cls");
            break;
        }
        }
    }
    while(op1!=0);
}

///carga la estructura stPedido
stPedido cargarPedido(stPedido p, int idCliente)
{
    int pedidos=0, confirmar=0, estadoPedido=0;
    pedidos=cantidadPedidos();
    system("cls");
    puts("\n\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>-Realizar pedido-<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");


    printf("\n\n\t\t\t\t\t\t\t\t\t\tId Pedido: %d", pedidos+1);
    p.idPedido=pedidos+1;


    printf("\n\t\t\t\t\t\t\t\t\t\tId Cliente: %d", idCliente);
    p.idCliente=idCliente;


    fechaPedido(&p);
    printf("\n\t\t\t\t\t\t\t\t\t\tFecha y Hora: %s", p.fecha);

    p.costo=costoPedido();

    printf("\n\nDescripcion del pedido(opcional): ");
    fflush(stdin);
    gets(p.descripcion);

    printf("\n\n\t\t\t\t\tEl valor del pedido es de %.2f\n\n", p.costo);

    printf("\n\n\tPara confirmar el pedido presione cualquier tecla - Esc para anular...\n\n");
    confirmar=getch();
    if(confirmar!=27)
    {
        p.pedidoAnulado=estadoPedido;
        puts("\nPedido Confirmado\n");
    }
    else
    {

        p.pedidoAnulado=estadoPedido+1;
        puts("\nPedido anulado\n");
    }
    system("pause");
    return p;
}

void fechaPedido(stPedido * p)
{
    int i=0;
    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    char *formato = "%d-%m-%Y %H:%M:%S";

    strftime(p[i].fecha, sizeof p[i].fecha, formato, &tiempoLocal);
}



///guarda en archivo pedidos.dat
void archAltaPedido(stPedido p, int idCliente)
{
    FILE * archPedido = fopen(archivoPedidos, "ab");

    if(archPedido!=NULL)
    {
        system("cls");
        p=cargarPedido(p,idCliente);
        system("cls");
        fwrite(&p, sizeof(stPedido), 1, archPedido);
    }
    fclose(archPedido);
}

///muestra todos los pedidos
void mostrarPedidos()
{
    stPedido p;
    FILE * archPedido = fopen(archivoPedidos, "rb");
    puts("\n                     -------------------------------------Pedidos------------------------------------------\n");
    if(archPedido!=NULL)
    {
        while(fread(&p, sizeof(stPedido), 1, archPedido))
        {
            mostrarStructPedido(p);
        }
    }
    fclose(archPedido);
}


///muestra pedidos de cliente
void mostrarPedidosCliente(int idCliente)
{
    stPedido p;
    FILE * archPedido = fopen(archivoPedidos, "rb");
    if(archPedido!=NULL)
    {
        puts("\n                     -------------------------------------Mis Pedidos------------------------------------------\n");
        while(fread(&p, sizeof(stPedido), 1, archPedido))
        {
            if(idCliente==p.idCliente)
            {
                mostrarStructPedido(p);
            }
        }
    }
    fclose(archPedido);
}



///cuenta la cantidad de pedidos
int cantidadPedidos()
{
    stPedido p;
    FILE *archPedido= fopen(archivoPedidos,"rb");
    int cantidadPedidos=0;

    if(archPedido!=NULL)
    {
        while(fread(&p, sizeof(stPedido), 1, archPedido))
        {
            cantidadPedidos++;
        }
    }
    fclose(archPedido);
    return cantidadPedidos;
}

///busca pedidos desde menu admin
void buscarPedido()
{
    FILE * archiP = NULL;
    int idPed;
    printf("\n-----------------Buscar Pedido-------------------\n");
    printf("\n Ingresa el Id de pedido para buscar: ");
    scanf("%d", &idPed);

    archiP=fopen(archivoPedidos,"rb");
    fseek(archiP,0,SEEK_SET);
    stPedido p;



    if(archiP!=NULL)
    {
        while(fread(&p,sizeof(stPedido),1,archiP))
        {
            if(idPed==p.idPedido)
            {
                mostrarStructPedido(p);
                system("pause");
            }
        }
    }
    fclose(archiP);
}



///busca pedido desde el menu cliente
void buscarPedidoCliente(int idCliente)
{
    FILE * archiP = NULL;
    int idPed;
    printf("\n-----------------Buscar Pedido-------------------\n");
    printf("\n Ingresa el Id de pedido para buscar: ");
    scanf("%d", &idPed);

    archiP=fopen(archivoPedidos,"rb");

    stPedido p;

    if(archiP!=NULL)
    {
        while(fread(&p,sizeof(stPedido),1,archiP))
        {
            if(idPed==p.idPedido)
            {
                if(idCliente==p.idCliente)
                {
                    mostrarStructPedido(p);
                }
                else
                {
                    printf("\nEl pedido no fue encontrado\n\n");
                }
            }
        }
    }
    fclose(archiP);
}

///muestra estructura
void mostrarStructPedido(stPedido p)
{
    puts("\n------------------------------------------------------------\n");
    printf("\nIdPedido: %d\n", p.idPedido);
    printf("\n\nIdCliente: %d\n", p.idCliente);
    printf("\n\nFecha: %s\n", p.fecha);
    printf("\n\nDescripcion: %s\n", p.descripcion);
    printf("\n\nCosto: %.2f\n", p.costo);
    if(p.pedidoAnulado==0)
    {
        printf("\nPedido: Activo\n");
    }
    else
    {
        printf("\nPedido: Anulado\n");
    }

    puts("\n------------------------------------------------------------\n");
}

float buscarPrecio(int idProducto,FILE * archiProd)
{
    stProducto aux;
    float valor=0;
    fseek(archiProd, 0, SEEK_SET);
    while(fread(&aux,sizeof(stProducto),1,archiProd)>0)
    {
        if(idProducto==aux.idProducto)
        {
            valor=aux.valor;
        }
    }
    return valor;
}
float costoPedido ()
{
    stProducto prod;
    char salida=0;
    int idProd=0,flag=0,cantProd=0;
    float costo=0;
    FILE *archi = fopen(archivoProductos, "rb");
    fseek(archi, 0,SEEK_SET);
    FILE *temp =fopen(archivoTemp, "wb");
    fseek(temp, 0, SEEK_SET);
    if (archi!=NULL)
    {
        printf("\n\n------>>>Lista de productos:\n\n");
        while (fread(&prod, sizeof(stProducto),1, archi)>0)
        {
            if(prod.productoAnulado!=1)
            {
                muestraProducto(prod);
            }
        }

        while (salida!=13)
        {
            do
            {
                fseek(archi,0,SEEK_SET);
                flag=0;
                printf("\nQue Nro de producto desea ordenar: ");
                scanf("%i", &idProd);
                while (flag==0 && fread(&prod,sizeof(stProducto),1,archi)>0)
                {
                    if(idProd==prod.idProducto && prod.productoAnulado!=1)
                    {
                        flag=1;
                    }
                }
                if(flag==0)
                {
                    printf("\nProducto no disponible.\n");

                }

            }
            while(flag==0);

            prod.valor=buscarPrecio(prod.idProducto,archi);

            do
            {
                printf("Que cantidad desea ordenar: ");
                scanf("%i", &cantProd);
                if(cantProd>0)
                {
                    prod.cantidad=cantProd;
                }
                else
                {
                    printf("\nCantidad no valida\n");
                }
            }
            while(cantProd<=0);
            printf("\nPara ordenar mas productos presione cualquier tecla - ENTER para confirmar pedido...");
            salida=getch();
            fwrite(&prod, sizeof(stProducto), 1, temp);

        }
        fclose(temp);

        costo=calcularCosto();
    }
    fclose(archi);
    return costo;
}


float calcularCosto ()
{
    FILE * temp=fopen(archivoTemp, "rb");
    fseek(temp, 0, SEEK_SET);
    stProducto p;
    float aux=0;
    while(fread(&p, sizeof(stProducto), 1, temp)>0)
    {
        aux=(p.cantidad*p.valor)+aux;
    }
    fclose(temp);
    return aux;
}
void muestraProducto(stProducto p)
{
    printf("\nProducto Nro %i\t\n", p.idProducto);
    printf("%s",p.nombreProducto);
    printf("\n\nDescripcion:\t\t");
    printf("%s", p.descripcionProducto);
    printf("\n\n\t\t\t\t\t\tCosto: %.2f", p.valor);
    if (p.productoAnulado==1)
    {
        printf("\nStock=AGOTADO\n");
    }

    puts("\n----------------------------------------------------------------------------\n");
}

///rol 1
stProducto CargarProducto()
{
    stProducto producto;
    int idP=0;

    printf("\nIngrese nombre del producto: \n");
    fflush(stdin);
    gets(producto.nombreProducto);
    printf("Ingrese descripcion del producto: \n");
    fflush(stdin);
    gets(producto.descripcionProducto);
    printf("Ingrese valor del producto en pesos: \n");
    fflush(stdin);
    scanf("%f", &producto.valor);
    producto.productoAnulado=0;

    idP=cantidadProductos();
    producto.idProducto=idP+1;

    return producto;
}
///rol 1
int cantidadProductos()
{
    stProducto p;
    FILE *archiProd= fopen(archivoProductos,"rb");
    int cantProd=-1;

    if(archiProd!=NULL)
    {
        while(fread(&p, sizeof(stProducto), 1, archiProd))
        {
            cantProd++;
        }
    }
    fclose(archiProd);
    return cantProd;
}
///rol 1
void cargarArchivoProducto()
{

    stProducto p;

    FILE * producto = fopen(archivoProductos, "ab");

    if (producto ==NULL)
    {

        printf("El archivo no existe!");

    }
    else
    {

        p=CargarProducto();
        fwrite(&p, sizeof(stProducto),1, producto);
    }
    fclose(producto);
}


void mostrarProductos()
{
    stProducto p;
    FILE * archiProd = fopen(archivoProductos, "rb");
    if(archiProd!=NULL)
    {
        while(fread(&p, sizeof(stProducto), 1, archiProd)>0)
        {
            muestraProducto(p);

        }
    }
    else
    {
        puts("\nEl arcivo no existe\n");
    }
    fclose(archiProd);
}

stPedido anularPedido (int idPedido, int idCliente,FILE *  archiP)
{
    stPedido p;

    while(fread(&p, sizeof(stPedido), 1, archiP)>0)
    {
        if(idPedido==p.idPedido && idCliente==p.idCliente)
        {
            p.pedidoAnulado=1;
        }
    }
    if(p.pedidoAnulado==1)
    {
        printf(" \t \n Pedido %i anulado con exito.\n\n", p.idPedido);
        system("pause");
    }
    else
    {
        if(fread(&p, sizeof(stPedido), 1, archiP)==0)
        {
            printf("\t \t \n No se encontro el pedido");
            system("pause");
        }
    }
    fseek(archiP,(-1)*sizeof(stPedido), SEEK_CUR);
    return p;
}
void modificarPedido(int idCliente)
{
    stPedido aux;
    stPedido modif;
    int idPedido=0;
    printf("\t \t \n Ingrese la ID del Pedido a Modificar:");
    scanf("%i", &idPedido);
    system("cls");
    int flag=0;
    FILE * archiP=fopen(archivoPedidos,"r+b");
    fseek(archiP, 0, SEEK_SET);
    if(archiP!=NULL)
    {
        while(!feof(archiP)&& flag==0)
        {
            if(fread(&aux,sizeof(stPedido),1,archiP)>0)
            {
                if(aux.idPedido==idPedido)
                {
                    flag=1;
                }
            }
        }
        if (flag==1)
        {
            fseek(archiP,(-1)*sizeof(stPedido), SEEK_CUR);
            modif=modificacionPedidoCliente(aux, idPedido,  idCliente, archiP);
            fwrite(&modif, sizeof(stPedido),1,archiP);
        }
        else
        {
            printf("\nNo se encontro pedido con esa ID\n");
        }
    }
    fclose(archiP);
}
void modificarPedidoAdmin()
{
    int id=-1,flag=0;
    FILE * archiC=fopen(archivoClientes,"rb");
    fseek(archiC,0,SEEK_SET);
    stCliente c;
    if(archiC!=NULL)
    {
        printf("\nIngrese ID del cliente que desea anular pedido: ");
        scanf("%d",&id);
        while(fread(&c,sizeof(stCliente),1,archiC))
        {
            if(id==c.idCliente)
            {
                flag=1;
            }
        }
    }
    fclose(archiC);
    if (flag==1)
    {
        modificarPedido(id);
    }
    else
    {
        printf("\nEl cliente no existe. \n");
        system("pause");
    }

}
stPedido modificacionPedidoCliente (stPedido p,int idPedido, int idCliente, FILE * archiP)
{
    int op=0;
    if (p.idCliente==idCliente)
    {
        do
        {
            system("color f0");
            menuModificarPedidoCliente();
            puts("\n\tIngrese una opcion...");
            fflush(stdin);
            scanf("%d",&op);
            system("cls");
            switch(op)
            {
            case 1:
            {
                system("cls");
                printf("\t \t \nIngrese nueva descripcion:\n");
                fflush(stdin);
                gets(p.descripcion);
                system("cls");
                break;
            }
            case 2:
            {
                system("cls");
                p=anularPedido (idPedido,idCliente,archiP);
                system("cls");
                break;
            }

            case 0:
            {
                system("cls");
                puts("Regresando... \n");
                break;
            }
            }
        }
        while(op!=0);
    }
    return p;
}
void menuModificarPedidoCliente()
{
    puts("\n\t\t\t\t\t[=================================]");
    puts("\t\t\t\t\t[---------Modificar Pedido--------]\n");
    puts("\t\t\t\t\t[ 1-Cambiar descripcion           ]\n");
    puts("\t\t\t\t\t[ 2-Anular Pedido                 ]\n");
    puts("\t\t\t\t\t[ 0-Regresar                      ]\n");
    puts("\t\t\t\t\t[=================================]\n\n\t");
}

void estadisticaCliente()
{
    FILE *archiP=fopen(archivoPedidos, "rb");
    fseek(archiP, 0,SEEK_SET);
    int idCliente=0, cantPedidos=0, montoTotal=0;
    stPedido p;
    printf("\t \t \n Ingrese la ID del Cliente a analizar:");
    scanf("%i", &idCliente);
    if(archiP!=NULL)
    {
        while(fread(&p,sizeof(stPedido),1,archiP)>0)
        {
            if(idCliente==p.idCliente)
            {
                cantPedidos++;
                montoTotal=montoTotal+p.costo;
            }
        }
        if(cantPedidos>0)
        {
            puts("\t\t\t\t\t[---------Estadisticas Cliente--------]\n");

            printf("\t\t\t\tID Nro: %i\n\n", idCliente);
            printf("\t\t\t\tCantidad de Pedidos Realizados: %i\n\n", cantPedidos);
            printf("\t\t\t\tMonto total gastado: %i\n\n", montoTotal);
            system("pause");
        }
        else
        {
            printf("\t\t\t\n No existen pedidos con el ID ingresado...\n\n");
            system("pause");
        }
        fclose(archiP);
    }

}

void cambiarRolCliente()
{
    FILE * archiC=fopen(archivoClientes,"r+b");
    fseek(archiC, 0, SEEK_SET);
    stCliente aux;
    int idCliente=0, flag=0;
    printf("\t \t \n Ingrese la ID del cliente para cambiar el rol:");
    scanf("%i", &idCliente);
    if (idCliente>0)
    {
        if(archiC!=NULL)
        {
            while(flag==0 && fread(&aux,sizeof(stCliente),1,archiC)>0)
            {
                if(aux.idCliente==idCliente)
                {
                    flag=1;
                }
            }
        }
        if (flag==1)
        {
            if(aux.rol==0)
            {
                printf("\t\t\n El usuario es ahora un ADMINISTRADOR...\n");
                aux.rol=1;
            }
            else
            {
                printf("\t\t\n El usuario es ahora un CLIENTE...\n");
                aux.rol=0;
            }
            fseek(archiC,(-1)*sizeof(stCliente), SEEK_CUR);
            fwrite(&aux, sizeof(stCliente),1,archiC);
            mostrarStructCliente(aux);
        }
        else
        {
            printf("\nNo se encontro usuario con la ID solicitada.\n");
        }
    }
    else
    {
        printf("\t\t\n Este usuario NO se puede modificar...\n");
    }
    getch();
    fclose(archiC);
}
void productoAnulado ()
{
    int idProd=0;
    FILE * archiProd = fopen(archivoProductos,"r+b");
    stProducto prod;
    fseek(archiProd,0,SEEK_SET);

    if (archiProd!=NULL)
    {
        printf("\nIngrese ID del producto a anular:");
        fflush(stdin);
        scanf("%d",&idProd);
        prod=anularProducto(idProd,archiProd);
        fwrite(&prod,sizeof(stProducto),1,archiProd);

    }
    fclose(archiProd);
}
stProducto anularProducto (int idProducto,FILE *  archiP)
{
    stProducto p;

    while(fread(&p, sizeof(stProducto), 1, archiP)>0)
    {
        if(idProducto==p.idProducto)
        {
            p.productoAnulado=1;
        }
    }
    if(p.productoAnulado==1)
    {
        printf(" \t \n Producto %i anulado con exito.\n\n", p.idProducto);
        system("pause");
    }
    else
    {
        if(fread(&p, sizeof(stProducto), 1, archiP)==0)
        {
            printf("\t \t \n No se encontro el producto");
            system("pause");
        }
    }
    fseek(archiP,(-1)*sizeof(stProducto), SEEK_CUR);
    return p;
}
void eliminarProductos()
{
    FILE * arch=NULL;
    arch=fopen(archivoProductos,"rb");

    printf("Ingrese el ID de producto a eliminar: ");
    int id=0,i=0;
    scanf("%i", &id);
    stProducto producto;

    FILE * nuevo=NULL;
    nuevo=fopen(archivoTemp,"wb");

    int existe=0;
    fread(&producto, sizeof(stProducto), 1, arch);
    while(!feof(arch))
    {
        if (id == producto.idProducto)
        {
            printf("Producto %i Eliminado: %s, valor:$%0.2f\n", producto.idProducto, producto.descripcionProducto, producto.valor);
            system("pause");
            existe=1;
        }
        else
        {
            producto.idProducto=i;
            fwrite(&producto, sizeof(stProducto), 1, nuevo);
            i++;
        }
        fread(&producto, sizeof(stProducto), 1, arch);
    }
    if (existe==0)
    {
        printf("No existe un producto con esta ID\n");
        system("pause");
    }
    fclose(arch);
    fclose(nuevo);

    remove(archivoProductos);
    rename(archivoTemp, archivoProductos);
}
