#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "trabajos.h"

void mostrarServicio(eServicio servicio, int tamServ)
{
    printf("  %1d     %s         %d\n", servicio.idServicio, servicio.descripcionServicio, servicio.precioServicio);
}

void mostrarServicios(eServicio servicios[], int tamServ)
{
    printf("\n***** Lista de Servicios *****\n");
    printf("  Id      Servicio     Precio en pesos\n\n");

    for(int i=0; i<tamServ; i++)
    {
            mostrarServicio(servicios[i], tamServ);
    }
}
