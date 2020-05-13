#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int idColor;
    char descripcionColor[20];
} eColor;

typedef struct
{
    int idTipo;
    char descripcionTipo[20];
} eTipo;

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
} eMascota;

#endif // MASCOTAS_H_INCLUDED

//funcion inicializar mascotas
void initMascotas(eMascota mascotas[], int tam);

//funciones buscar
int buscarLibre(eMascota mascota[], int tam);
int buscarMascota (int id, eMascota mascota[], int tam);

//funciones mostrar mascotas
void mostrarMascota(eMascota mascota, eTipo tipos[], int tamTipos, eColor colores[], int tamColor);
void mostrarMascotas(eMascota mascotas[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor);
//funciones mostrar colores
void mostrarColor(eColor color, int tamColor);
void mostrarColores(eColor colores[], int tamColor);
//funciones mostrar tipos
void mostrarTipo(eTipo tipo, int tamTipos);
void mostrarTipos(eTipo tipos[], int tamTipos);

//funciones cargar descripciones mascota
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tam);
int cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tam);

//funciones ALTA
int altaMascota(eMascota mascota[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor);

//funciones MODIFICAR MASCOTA
int showMenuModificaciones();
void modificarMascota(eMascota mascota[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor);
void modificarMascotaEdad(eMascota mascota[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor);
void modificarMascotaTipo(eMascota mascota[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor);

//funciones BAJA
void bajaMascota(eMascota mascota[], int tam, eTipo tipos[], int tamTipos, eColor colores[], int tamColor);
