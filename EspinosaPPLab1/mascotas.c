#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"

void initMascotas(eMascota mascotas[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        mascotas[i].isEmpty = 1;
    }
}

//buscar indice libre para dar de alta una mascota
int buscarLibre(eMascota mascota[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(mascota[i].isEmpty /*== 1*/)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//busca y devuelve el indice del id de la mascota buscada
int buscarMascota (int id, eMascota mascota[], int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(mascota[i].id == id && mascota[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void mostrarMascota(eMascota mascota, eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    char nombreTipo[20];
    char nombreColor[20];

    cargarDescripcionTipo(nombreTipo, mascota.idTipo, tipos, tamTipos);
    cargarDescripcionColor(nombreColor, mascota.idColor, colores, tamColor);
    //MODIFICAR EN RELACION A LO QUE SE NECESITE MOSTRAR
    printf("  %d %10s    %2d %10s %10s\n", mascota.id, mascota.nombre, mascota.edad, nombreTipo, nombreColor);
}

void mostrarMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    int flag = 0;
    //system("cls");
    //MODIFICAR EN RELACION A LO QUE SE NECESITE MOSTRAR
    printf("***** Lista de mascotas *****\n");
    printf("   Id      Nombre    Edad     Tipo     Color\n\n");

    for(int i=0; i<tam; i++)
    {
        if(mascotas[i].isEmpty == 0)
        {
            mostrarMascota(mascotas[i], tipos, tamTipos, colores, tamColor);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("*** No hay mascotas que listar ***\n");
    }
}

void mostrarTipo(eTipo tipo, int tamTipos)
{
    printf("  %d %10s\n", tipo.idTipo, tipo.descripcionTipo);
}

void mostrarTipos(eTipo tipos[], int tamTipos)
{
    printf("\n***** Lista de tipos *****\n");
    printf("   Id      Tipo\n\n");

    for(int i=0; i<tamTipos; i++)
    {
            mostrarTipo(tipos[i], tamTipos);
    }
}

void mostrarColor(eColor color, int tamColor)
{
    printf("  %d %10s\n", color.idColor, color.descripcionColor);
}

void mostrarColores(eColor colores[], int tamColor)
{
    printf("\n***** Lista de Colores *****\n");
    printf("   Id      Color\n\n");

    for(int i=0; i<tamColor; i++)
    {
            mostrarColor(colores[i], tamColor);
    }
}

//cargar descripcion de un tipo de mascota al id de un vector especifico
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(tipos[i].idTipo == id)
        {
            strcpy(descripcion, tipos[i].descripcionTipo);
            todoOk = 1;
        }
    }
    return todoOk;
}

int cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(colores[i].idColor == id)
        {
            strcpy(descripcion, colores[i].descripcionColor);
            todoOk = 1;
        }
    }
    return todoOk;
}

int altaMascota(eMascota mascota[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    int seIngresaronDatos = 0;
    int indice = buscarLibre(mascota, tam);
    int id;
    int existeId;
    eMascota auxMascota;

    char auxCad[100];

    system("cls");

    printf("***** ALTA MASCOTA *****\n\n");

    if(indice == -1) //verificar si hay lugar
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        //PEDIR ID SI NO SE NECESITA AUTOINCREMENTAL
        printf("Ingrese id: ");
        scanf("%d", &id);

        existeId = buscarMascota(id, mascota, tam);

        if(existeId != -1) //verificar si el id ya existe
        {
            printf("Ya existe una mascota registrada con ese id\n\n");
        }
        else
        {
        auxMascota.id = id; //copio el id de la mascota

        //PEDIR RESTO DE DATOS CON FUNCIONES Y VALIDACIONES
        printf("Ingrese nombre mascota: ");
        fflush(stdin);
        fgets(auxCad, 20, stdin);
        auxCad[strlen(auxCad)-1] = '\0';
        while(strlen(auxCad) >= 18 || strlen(auxCad) == 0)
        {
            printf("Error, supero la cantidad de caracteres posibles.\n\n");
            printf("Reingrese de nuevo su nombre: ");
            fflush(stdin);
            fgets(auxCad, 20, stdin);
            auxCad[strlen(auxCad)-1] = '\0';
        }
        strcpy(auxMascota.nombre, auxCad);

        printf("Ingrese edad de la mascota: ");
        scanf("%d", &auxMascota.edad);
        while(auxMascota.edad > 50 || auxMascota.edad < -1)
        {
            printf("Error, Reingrese edad de la mascota: ");
            scanf("%d", &auxMascota.edad);
        }

        mostrarTipos(tipos, tamTipos);

        printf("Ingrese id de tipo de mascota: ");
        scanf("%d", &auxMascota.idTipo);
        while(auxMascota.idTipo > 5 || auxMascota.idTipo < 1)
        {
            printf("Error, Reingrese id valido de tipo mascota: ");
            scanf("%d", &auxMascota.idTipo);
        }

        mostrarColores(colores, tamColor);

        printf("Ingrese id de color de mascota: ");
        scanf("%d", &auxMascota.idColor);
        while(auxMascota.idColor > 5 || auxMascota.idColor < 1)
        {
            printf("Error, Reingrese id valido de color de mascota: ");
            scanf("%d", &auxMascota.idColor);
        }

        auxMascota.isEmpty = 0;

        mascota[indice] = auxMascota;//copio datos de la mascota al vector en el indice disponible

        seIngresaronDatos = 1;
        }//else interior

    }//else exterior

    return seIngresaronDatos;

}//fin funcion ALTA

//MENU MODIFICACIONES
int showMenuModificaciones()
{
    int opcion;

    system("cls");
    printf("**** MODIFICAR MASCOTA ****\n\n");
    printf("1-Modificar tipo mascota\n");
    printf("2-Modificar edad mascota\n");
    printf("3-Volver al menu principal\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
//modificar un criterio de una mascota ((switch submenu))
void modificarMascota(eMascota mascota[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    char seguir = 's';
    char salirProg;

    do
    {
        switch(showMenuModificaciones())
        {
        case 1:
            modificarMascotaTipo(mascota, tam, tipos, tamTipos, colores, tamColor);
            break;
        case 2:
            modificarMascotaEdad(mascota, tam, tipos, tamTipos, colores, tamColor);
            break;
        case 3:
            do
            {
                fflush(stdin);
                printf("Desea salir de modificaciones? s/n: ");
                scanf("%c", &salirProg);
            }
            while(salirProg != 's' && salirProg != 'n');
            break;
        default:
            system("cls");
            printf("No es una opcion valida\n");
            system("pause");
            fflush(stdin);
            break;
        }
        system("pause");
        fflush(stdin);

        if(salirProg == 's')
        {
            seguir = 'n';
        }

    }
    while(seguir == 's');
}//fin funcion OPCION MENU MODIFICAR

void modificarMascotaTipo(eMascota mascota[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    int indice;
    int idBuscado;
    char confirmMod;
    int nuevoTipo;

    system("cls");

    printf("***** Modificar tipo mascota *****\n\n");

    printf("Ingrese id de la mascota a modificar el tipo: ");
    scanf("%d", &idBuscado);

    indice = buscarMascota(idBuscado, mascota, tam);

    if(indice == -1)
    {
        printf("No existe una mascota con el ID ingresado\n\n");
    }
    else
    {
        printf("*** Mascota encontrada con el id ingresado ***\n\n");
        mostrarMascota(mascota[indice], tipos, tamTipos, colores, tamColor);

        mostrarTipos(tipos, tamTipos);

        printf("Ingrese nuevo tipo de mascota a actualizar: ");
        scanf("%d", &nuevoTipo);
        while(nuevoTipo > 5 || nuevoTipo < 1)
        {
            printf("Error, Reingrese id valido de tipo mascota: ");
            scanf("%d", &nuevoTipo);
        }

        printf("Confirma la modificacion del tipo de mascota? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmMod);

        if(confirmMod == 's')
        {
            mascota[indice].idTipo = nuevoTipo;
            printf("Se ha actualizado el tipo de mascota con exito\n\n");
        }
        else
        {
            printf("No se ha modificado la mascota\n\n");
        }//else interior
    }//else exterior
}

void modificarMascotaEdad(eMascota mascota[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    int indice;
    int idBuscado;
    char confirmMod;
    int nuevaEdad;

    system("cls");

    printf("***** Modificar edad mascota *****\n\n");

    printf("Ingrese id de la mascota a modificar la edad: ");
    scanf("%d", &idBuscado);

    indice = buscarMascota(idBuscado, mascota, tam);

    if(indice == -1)
    {
        printf("No existe una mascota con el ID ingresado\n\n");
    }
    else
    {
        mostrarMascota(mascota[indice], tipos, tamTipos, colores, tamColor);

        printf("Ingrese nueva edad a actualizar: ");
        scanf("%d", &nuevaEdad);

        printf("Confirma la modificacion de la edad? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmMod);

        if(confirmMod == 's')
        {
            mascota[indice].edad = nuevaEdad;
            printf("Se ha actualizado la edad de la mascota con exito\n\n");
        }
        else
        {
            printf("No se ha modificado la mascota\n\n");
        }//else interior
    }//else exterior
}

//dar de baja una mascota
void bajaMascota(eMascota mascota[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor)
{
    int indice;
    int idBuscado;
    char confirmBaja;

    system("cls");

    printf("***** BAJA MASCOTA *****\n\n");

    printf("Ingrese id de la mascota a dar de baja: ");
    scanf("%d", &idBuscado);

    indice = buscarMascota(idBuscado, mascota, tam);

    if(indice == -1)
    {
        printf("No existe una mascota con el id ingresado\n\n");
    }
    else
    {
        mostrarMascota(mascota[indice], tipos, tamTipos, colores, tamColor);

        printf("Confirma la baja de la mascota? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmBaja);

        if(confirmBaja == 's')
        {
            mascota[indice].isEmpty = 1;
            printf("Se ha dado de baja a la mascota con exito\n\n");
        }
        else
        {
            printf("No se ha dado de baja a la mascota\n\n");
        }//else interior

    }//else exterior

}//fin funcion BAJA
