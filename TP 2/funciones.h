
typedef struct
{
    char nombre[25];
    int edad;
    int dni;
    int estado;
}ePersonas;

int BajaUsuario(ePersonas x[]);
void OrdenarYMostrar(ePersonas x[]);
int BuscarLibre(ePersonas x[]);
int BuscarPorDni(ePersonas x[]);
void Graficar(int rango1, int rango2, int rango3);
int calcularMayor(int x, int y, int z);
