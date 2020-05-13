#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int idServicio;
    char descripcionServicio[25];
    int precioServicio;
} eServicio;

typedef struct
{
    int idTrabajo;
    int idMascota;
    int idServicio;
    eFecha fechaTrabajo;

} eTrabajo;

#endif // TRABAJOS_H_INCLUDED

//funciones mostrar servicios
void mostrarServicio(eServicio servicio, int tamServ);
void mostrarServicios(eServicio servicios[], int tamServ);
