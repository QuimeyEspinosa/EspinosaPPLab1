#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "trabajos.h"
#include "dataWarehouseVeterinaria.h"

#define TAM 12
#define TAMTIPO 5
#define TAMCOLOR 5
#define TAMSERV 3
#define TAMHARDCODE 10

//funcion harcodear
void hardcodearMascotas(eMascota mascota[], int cantidadHardcodeo);

//funciones menu
int showMenu();

int main()
{
    char seguir = 's';
    char salirProg;
    int seIngresaronDatos = 1; //FLAG QUE CORROBORA SI SE DIERON DE ALTA MASCOTAS PARA LUEGO PODER MODIFICAR, DAR DE BAJA, ETC.
    //int nextId = 1000;

    eMascota list[TAM]; //DECLARAR UNA LISTA DE MASCOTAS
    eTipo tiposMascota[TAMTIPO] =
    {
        {1, "Ave"},
        {2, "Perro"},
        {3, "Gato"},
        {4, "Roedor"},
        {5, "Pez"}
    };

    eColor coloresMascota[TAMCOLOR] =
    {
        {1, "Negro"},
        {2, "Blanco"},
        {3, "Gris"},
        {4, "Rojo"},
        {5, "Azul"}
    };

    eServicio servicios[TAMSERV] =
    {
        {1, "Corte", 250},
        {2, "Desparasitado" , 300},
        {3, "Castrado" , 400}
    };
    initMascotas(list, TAM); //INICIALIZAR MASCOTAS

    hardcodearMascotas(list, TAMHARDCODE);

    do
    {
        switch(showMenu())
        {
        case 1:
            if(altaMascota(list, TAM, tiposMascota, TAMTIPO, coloresMascota, TAMCOLOR))
            {
                seIngresaronDatos = 1;
            }
            break;
        case 2:
            if(seIngresaronDatos == 0)
            {
                system("cls");
                printf("No hay mascotas que modificar\n\n");
            }
            else
            {
                modificarMascota(list, TAM, tiposMascota, TAMTIPO, coloresMascota, TAMCOLOR);
            }
            break;
        case 3:
            if(seIngresaronDatos == 0)
            {
                system("cls");
                printf("No hay mascotas que dar de baja\n\n");
            }
            else
            {
                bajaMascota(list, TAM, tiposMascota, TAMTIPO, coloresMascota, TAMCOLOR);
            }
            break;
        case 4:
            mostrarMascotas(list, TAM, tiposMascota, TAMTIPO, coloresMascota, TAMCOLOR);
            break;
        case 5:
            mostrarTipos(tiposMascota, TAMTIPO);
            break;
        case 6:
            mostrarColores(coloresMascota, TAMCOLOR);
            break;
        case 7:
            mostrarServicios(servicios, TAMSERV);
            break;
        case 8:
            do
            {
                fflush(stdin);
                printf("Desea salir del programa? s/n: ");
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

    return 0;
}

int showMenu()
{
    int opcion;

    system("cls");
    printf("**** Titulo ****\n\n");
    printf("1-Alta Mascota\n");
    printf("2-Modificar Mascota\n");
    printf("3-Baja Mascota\n");
    printf("4-Listar mascotas\n");
    printf("5-Listar tipos\n");
    printf("6-Listar colores\n");
    printf("7-Listar servicios\n");
    printf("8-Salir\n\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void hardcodearMascotas(eMascota mascota[], int cantidadHardcodeo)
{
    for(int i =0; i<cantidadHardcodeo; i++)
    {
        mascota[i].id = idsMascota[i];
        strcpy(mascota[i].nombre, nombresMascota[i]);
        mascota[i].edad = edadesMascota[i];
        mascota[i].idTipo = idsTipoMascota[i];
        mascota[i].idColor = idsColores[i];
        mascota[i].isEmpty = 0;
    }
}


