#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

/**
 *  Toma un puntero a char y valida que sean solo numeros si esto es correcto lo transforma a int
 *  @param toma como param los limites inferior y superior permitidos
 *  @return 0 si solo se ingresaron numeros - 1 si hubo algun error
 */

int validar_soloNumeros(char* aux,int limInferior, int limSuperior)
{
    int numero;
    int i;
    int validar = 0;

    for(i=0;aux[i] != '\0';i++)
    {
        if(aux[i] < '0' || aux[i] > '9')
        {
            validar = 1;
            break;
        }
    }

    numero = atoi(aux);

    if(numero < limInferior || numero > limSuperior)
    {
        validar = 1;
    }

    return validar;
}


/**
 *  pide el ingreso de un puntero a char y valida que sean solo numeros
 *  @param mensaje para pedir numero y mensaje de error
 *  @return el numero ingresado
 */
int get_numeros(char* msj,char* msjError, int limInferior, int limSuperior)
{
    char* aux;
    int numero;
    aux = (char*) malloc(sizeof(char)*15);

    printf("\n%s", msj);
    fflush(stdin);
    scanf("%s",aux);

    while(validar_soloNumeros(aux,limInferior,limSuperior))
    {
        printf("\n%s", msjError);
        fflush(stdin);
        scanf("%s",aux);
    }
    numero = atoi(aux);
    return numero;
}

/**
 *  Muestra menu principal, pide opcion y valida que sea correcta
 *  @param void
 *  @return el numero ingresado
 */
int menu(void)
{
    char auxOpcion[250];
    int opcion;

    system("cls");
    printf("***\tMENU DE PELICULAS\t***\n\n");
    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n");
    printf("\n\nElija opcion: ");

    fflush(stdin);
    scanf("%s",auxOpcion);

    while(validar_soloNumeros(auxOpcion,1,5))
    {
        printf("\nError. Ingrese opcion valida: ");
        fflush(stdin);
        scanf("%s",auxOpcion);
    }

    opcion = atoi(auxOpcion);


    return opcion;
}

/**
 *  busca espacio para estructura y pide al usuario que ingrese los campos
 *  @param puntero a estructura
 *  @return void
 */

void movie_new(eMovie* pMovie)
{
    int index;
    index = BuscarEspacioLibre(pMovie, TAM_MOVIES);

    get_stringLetras(pMovie[index].titulo, "Ingrese titulo: ", "Error. Ingrese titulo valido: ", 50);
    //strcpy(pMovie[index].titulo,strlwr(pMovie[index].titulo)); /*Pasa toda la cadena de texto a minusculas */
    //pMovie[index].titulo[0] = toupper(pMovie[index].titulo); /* Pasa la primer letra de la cadena a mayuscula */

    get_stringLetras(pMovie[index].genero, "Ingrese genero: ", "Error. Ingrese genero valida: ", 20);
    //strcpy(pMovie[index].genero,strlwr(pMovie[index].genero)); /*Pasa toda la cadena de texto a minusculas */
    //pMovie[index].genero[0] = toupper(pMovie[index].genero); /* Pasa la primer letra de la cadena a mayuscula */

    pMovie[index].duracion = get_numeros("Ingrese duracion en minutos: ", "Error. Ingrese duracion valida: ",1,300);

    get_texto(pMovie[index].descripcion, "Ingrese descripcion: ", "Error. Ingrese descripcion valida: ", 256);
    //strcpy(pMovie[index].descripcion,strlwr(pMovie[index].descripcion)); /*Pasa toda la cadena de texto a minusculas */
    //pMovie[index].descripcion[0] = toupper(pMovie[index].descripcion); /* Pasa la primer letra de la cadena a mayuscula */

    pMovie[index].puntaje = get_numeros("Ingrese puntaje: ", "Error. Ingrese puntaje valido: ",0,10);

    get_texto(pMovie[index].linkImagen, "Ingrese link de imagen: ", "Error. Ingrese link valido: ", 256);

    pMovie[index].id = index + 1000;

    printf("\n ***\tPelicula cargada con exito!!!\t***\n\n");

    system("pause");

}

/**
 *  Busca un id ingresado y lo compara con las estructuras, cuando lo encuentra devuelve el indice
 *  @param puntero a la estructura a buscar, id seleccionado por el usuario, tam del array de estructuras
 *  @return indice de la estructura con el id
 */
int BuscarPorId(eMovie* x, int id, int tamArray)
{
	int i;
	int indice = -1;

	for(i=0; i<tamArray; i++)
	{
		if(x[i].id == id)
        {
            indice = i;
            return indice;
        }

	}
	return indice;
}


/**
 *  pide un id a modificar, muestra los datos y mediante un switch pide seleccionar el campo a modificar
 *  @param puntero a estructura y tamaño del array
 *  @return void
 */
void movie_modificar(eMovie* pMovie, int tamArray)
{
	int indice, id, opcion;

	id = get_numeros("Ingrese ID a modificar: ", "Error. Ingrese ID valido: ",1000,1499);

	indice = BuscarPorId(pMovie, id, tamArray);

    if(indice == -1)
    {
        printf("\n*** No se encontro pelicula con ese Id ***\n\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n| ID     | TITULO                                      | GENERO             | PUNTAJE |\n");
        printf("| %-7d| %-44s| %-19s| %-8d|\n", pMovie[indice].id, pMovie[indice].titulo, pMovie[indice].genero, pMovie[indice].puntaje);
        printf("\nDescripcion: %s", pMovie[indice].descripcion);
        printf("\nLink de imagen: %s", pMovie[indice].linkImagen);
        printf("\n\n***\tMENU DE MODIFICACION\t***\n");
        printf("1- Titulo\n");
        printf("2- Genero\n");
        printf("3- Duracion\n");
        printf("4- Descripcion\n");
        printf("5- Puntaje\n");
        printf("6- LinkImagen\n");
        printf("7- Salir\n");

        opcion = get_numeros("Ingrese opcion: ","Error. Ingrese opcion valida: ", 1,7);

        switch(opcion)
        {
            case 1:
                get_stringLetras(pMovie[indice].titulo, "Ingrese nuevo titulo: ", "Error. Ingrese titulo valido: ", 50);
                printf("\n***\tMODIFICACION REALIZADA\t***\n");
                system("pause");
                break;
            case 2:
                get_stringLetras(pMovie[indice].genero, "Ingrese nuevo genero: ", "Error. Ingrese genero valida: ", 20);
                printf("\n***\tMODIFICACION REALIZADA\t***\n");
                system("pause");
                break;
            case 3:
                pMovie[indice].duracion = get_numeros("Ingrese nueva duracion en minutos: ", "Error. Ingrese duracion valida: ",1,300);
                printf("\n***\tMODIFICACION REALIZADA\t***\n");
                system("pause");
                break;
            case 4:
                get_texto(pMovie[indice].descripcion, "Ingrese descripcion: ", "Error. Ingrese descripcion valida: ", 256);
                printf("\n***\tMODIFICACION REALIZADA\t***\n");
                system("pause");
                break;
            case 5:
                pMovie[indice].puntaje = get_numeros("Ingrese nuevo puntaje: ", "Error. Ingrese puntaje valido: ",0,10);
                printf("\n***\tMODIFICACION REALIZADA\t***\n");
                system("pause");
                break;
            case 6:
                get_texto(pMovie[indice].linkImagen, "Ingrese link de imagen: ", "Error. Ingrese link valido: ", 256);
                printf("\n***\tMODIFICACION REALIZADA\t***\n");
                system("pause");
                break;
            case 7:
                printf("\n***\tMODIFICACION CANCELADA\t***\n");
                system("pause");
                break;

        }


    }
}

/**
 *  crea un puntero a file, carga los datos del archivo y la cantidad de peliculas en cont
 *  @param puntero de estructura y contador de peliculas
 *  @return void
 */
void CargarPeliculas(eMovie* pMovie, int* cont)
{
	FILE* fMovie;
	int size, x;

	fMovie = fopen("peliculas.dat", "r");
	if(fMovie==NULL){
		printf("\n No existe el archivo");
		system("pause");
	}

	fseek(fMovie, 0, SEEK_END);
	size = ftell(fMovie);
	(*cont) = size / sizeof(eMovie);
	fseek(fMovie, 0, SEEK_SET);

	for(x=0; x<(*cont); x++){
		fread(&pMovie[x], sizeof(eMovie), 1, fMovie);
	}
	fclose(fMovie);

}

/**
 *  crea un puntero a file y guarda las altas/bajas/modificaciones dentro del archivo de peliculas
 *  @param puntero de estructura y contador de peliculas
 *  @return void
 */
void GuardarArchivo(eMovie* pMovie, int cont)
{
	FILE* fMovie;

	fMovie = fopen("peliculas.dat", "w");
	if(fMovie==NULL)
    {
		printf("\n Error al guardar el archivo\n\n");
		system("pause");
	}
	fwrite(pMovie, sizeof(eMovie), cont, fMovie);
	fclose(fMovie);
}

/**
 *  pide un id, muestra los datos de la pelicula seleccionada y solicita confirmacion para dar baja logica
 *  @param puntero a estructura y tam del array
 *  @return retorna 0 si no se dio de baja o 1 si se dio de baja, para poder modificar el contador de peliculas
 */

int movie_baja(eMovie* pMovie, int tamArray)
{
	int indice, id,retorno = 0;
	char confirma;

	id = get_numeros("Ingrese ID a dar de baja: ", "Error. Ingrese ID valido: ",1000,1499);

	indice = BuscarPorId(pMovie, id, tamArray);

    if(indice == -1)
    {
        printf("\n*** No se encontro pelicula con ese Id ***\n\n");
        system("pause");
    }
    else
    {
        printf("\n| ID     | TITULO                                      | GENERO             | PUNTAJE |\n");
        printf("| %-7d| %-44s| %-19s| %-8d|\n", pMovie[indice].id, pMovie[indice].titulo, pMovie[indice].genero, pMovie[indice].puntaje);

        printf("\n\nConfirma baja de pelicula? S/N   ");
        fflush(stdin);
        confirma=tolower(getchar());

        while(confirma != 's' && confirma != 'n')
        {
            printf("\nRespuesta invalida. Confirme S o N ");
            fflush(stdin);
            confirma=tolower(getchar());
        }

        if(confirma == 's')
        {
            pMovie[indice].id = 0;
            printf("\n***   PELICULA DADA DE BAJA   ***\n\n");
            retorno = 1;
            system("pause");
        }
        else
        {
            printf("\n***   BAJA CANCELADA   ***\n\n");
            system("pause");
        }
    }
    return retorno;
}


/**
 *  valida que un strig sean solo letras o espacios
 *  @param puntero a char
 *  @return 0 si hay error - 1 si es correcto
 */
int validar_soloLetras(char* string)
{
   int validar = 1;
   int i=0;
   while(string[i] != '\0')
   {
       if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
           validar = 0;
       i++;
   }
   return validar;
}

/**
 *  valida un texto ingresado para que no exceda el tam
 *  @param puntero a char, mensaje de ingreso, mensaje de error, tam del array a validar
 *  @return void
 */
void get_texto(char* string,char* msj,char* msjError,int tamArray)
{
    char aux[400];

    printf("\n%s",msj);
    fflush(stdin);
    gets(aux);

    while(strlen(aux) > tamArray)
    {
        printf("\n%s", msjError);
        fflush(stdin);
        gets(aux);
    }
    strcpy(string,aux);

}

/**
 *  pide un texto y valida que sean solo letras/espacios y que no exceda el tamaño
 *  @param puntero a char, mensaje de ingreso, mensaje de error, tam de array a validar
 *  @return void
 */
void get_stringLetras(char* string,char* msj,char* msjError,int tamArray)
{
    char aux[400];

    printf("\n%s",msj);
    fflush(stdin);
    gets(aux);

    while(!validar_soloLetras(aux)|| strlen(aux) > tamArray)
    {
        printf("\n%s", msjError);
        fflush(stdin);
        gets(aux);
    }
    strcpy(string,aux);

}

/**
 *  inicializa los estados de las peliculas en 0
 *  @param puntero de estructura, tam del array y valor a inicializar
 *  @return void
 */
void InicializarPeliculas(eMovie* x, int tamArray, int valor)
{
    int i;
    for(i=0; i<tamArray; i++) /* Inicializa los id para que esten vacios */
    {
        x[i].id = valor;
    }
}

/**
 *  crea un puntero a file de un archivo html, valida que se pueda crear y carga el texto necesario para crear la pagina, iterando por la cantidad de peliculas dadas de alta
 *  @param puntero a estructura, contador de peliculas
 *  @return void
 */
void generarPagina(eMovie* pMovie, int cont)
{
	FILE *fHtml;
	int i;

	fHtml = fopen("lista.html", "w");
	if(fHtml==NULL){
		printf("\nNo se pudo crear el archivo\n\n");
		system("pause");
	}

	fprintf(fHtml, "<!DOCTYPE html>\n<!-- Template by Quackit.com and Fede -->\n<html lang='en'>\n<head>\n\t<meta charset='utf-8'>\n\t<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n\t<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n\t<title>Lista peliculas</title>\n\t<!-- Bootstrap Core CSS -->\n\t<link href='css/bootstrap.min.css' rel='stylesheet'>\n\t<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n\t<link href='css/custom.css' rel='stylesheet'>\n\t<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n\t<!-- WARNING: Respond.js doesn't work if you view the page via file:\x2f\x2f -->\n\t<!--[if lt IE 9]>\n\t\t<script src='https:\x2f\x2foss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n\t\t<script src='https:\x2f\x2foss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n\t<![endif]-->\n</head>\n<body>\n\t<div class='container'>\n\t\t<div class='row'>\n");

	for(i=0; i<cont; i++){
		fprintf(fHtml, "\n\n\t\t\t<!-- Repetir esto para cada pelicula -->\n\t\t\t<article class='col-md-4 article-intro'>\n\t\t\t\t<a href='#'>\n\t\t\t\t\t<img class='img-responsive img-rounded' src='");
		fprintf(fHtml, "%s", pMovie[i].linkImagen);
		fprintf(fHtml, "' alt=''>\n\t\t\t\t</a>\n\t\t\t\t<h3>\n\t\t\t\t\t<a href='#'>");
		fprintf(fHtml, "%s", pMovie[i].titulo);
		fprintf(fHtml, "</a>\n\t\t\t\t</h3>\n\t\t\t\t<ul>\n\t\t\t\t\t<li>");
		fprintf(fHtml, "Genero: %s", pMovie[i].genero);
		fprintf(fHtml, "</li>\n\t\t\t\t\t<li>");
		fprintf(fHtml, "Puntaje: %d", pMovie[i].puntaje);
		fprintf(fHtml, "</li>\n\t\t\t\t\t<li>");
		fprintf(fHtml, "Duracion: %d minutos", pMovie[i].duracion);
		fprintf(fHtml, "</li>\n\t\t\t\t</ul>\n\t\t\t\t<p>");
		fprintf(fHtml, "%s", pMovie[i].descripcion);
		fprintf(fHtml, "</p>\n\t\t\t</article>\n\t\t\t<!-- Repetir esto para cada pelicula -->\n\n\n");
	}

	fprintf(fHtml, "\t\t</div>\n\t\t<!-- /.row -->\n\t</div>\n\t<!-- /.container -->\n\t<!-- jQuery -->\n\t<script src='js/jquery-1.11.3.min.js'></script>\n\t<!-- Bootstrap Core JavaScript -->\n\t<script src='js/bootstrap.min.js'></script>\n\t<!-- IE10 viewport bug workaround -->\n\t<script src='js/ie10-viewport-bug-workaround.js'></script>\n\t<!-- Placeholder Images -->\n\t<script src='js/holder.min.js'></script>\n</body>\n</html>");
	fclose(fHtml);

}


/**
 *  recorre el array buscando un indice con id en 0
 *  @param puntero a estructura, tam del array
 *  @return el indice encontrado
 */
int BuscarEspacioLibre(eMovie* x, int tamArray)
{
	int indice = -1;
	int i;

	for(i=0; i<tamArray; i++)
	{
		if((x+i)->id == 0 && x != NULL)
        {
            indice = i;
            return indice;
        }

	}
	return indice;
}
