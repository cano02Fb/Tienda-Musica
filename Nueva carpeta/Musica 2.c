#include<stdio.h>
#include<stdlib.h>
typedef struct CD{
	int codigo_barras;
	char artista[30];
	char album[30];
	int no_canciones;
	float precio;
	int existencias;
}CD;

int Pedir_cantidad();
CD Agregar_CD();
void Mostrar_cds(CD *cds,int Num_cds);
void Mostrar_cd(CD *cds, int posicion);
int Busqueda(CD *cds,int Codigo,int contador);
void Comprar_CD(CD *cds,int posicion);

int main(){
	int Num_cds,eleccion=0,contador_cds=0;
	Num_cds=Pedir_cantidad();
	CD cds[Num_cds];
	system("cls");
	while(eleccion!=6){
		printf("\nQue deseas realizar:\n");
		printf("1)Agregar CD\n");
		printf("2)Buscar CD\n");
		printf("3)Mostrar todos los CDs\n");
		printf("4)Comprar CD\n");
		printf("5)Modificar\n");
		printf("6)Salir\n");
		scanf("%d",&eleccion);
		switch(eleccion){
			case 1: {
				if(contador_cds==Num_cds){
					printf("\nNo es posible agregar mas CDs");
				}else{
					cds[contador_cds]=Agregar_CD();
					contador_cds++;
				}
				break;
			}
			case 2:{
				int buscado,Codigo;
				printf("\nDame el numero de barras para encontrar el CD: ");
				scanf("%d",&Codigo);
				buscado=Busqueda(cds,Codigo,contador_cds);
				if(buscado==-1){
					printf("\nCD no encontrado");
				}else{
					Mostrar_cd(cds,buscado);
				}
				break;
			}
			case 3:{
				Mostrar_cds(cds,contador_cds);
				break;
			}
			case 4:{
				int buscado,Codigo;
				printf("\nDame el numero de barras para encontrar el producto: ");
				scanf("%d",&Codigo);
				buscado=Busqueda(cds,Codigo,contador_cds);
				if(buscado==-1){
					printf("\nProducto no encontrado");
				}else{
					Comprar_CD(cds,buscado);
				}
				break;
			}
			case 5:	{
				int buscado,Codigo;
				printf("\nDame el numero de barras para encontrar el CD: ");
				scanf("%d",&Codigo);
				buscado=Busqueda(cds,Codigo,contador_cds);
				if(buscado==-1){
					printf("\nCD no encontrado");
				}else{
					Mostrar_cd(cds,buscado);
				}
					Agregar_CD();			
				break;
			}
			case 6:{
				printf("\nAdios\n");
				break;
			}
	}
	}
		return 0;
}

int Pedir_cantidad(){
	int cantidad;
	printf("Dame la cantidad de CDs que deseas agregar a tu tienda: ");
	scanf("%d",&cantidad);
	return cantidad;
}

CD Agregar_CD(){
	CD articulo;
	printf("\nDame el nombre del album: ");
	scanf("%s",&articulo.album);
	printf("\nDame el nombre del artista: ");
	scanf("%s",&articulo.artista);
	printf("\nDame el precio del CD: ");
	scanf("%f",&articulo.precio);
	printf("\nDame el codigo de barras: ");
	scanf("%d",&articulo.codigo_barras);
	printf("\nDame el Numero de canciones: ");
	scanf("%d",&articulo.no_canciones);
	printf("\nDame la cantidad disponible del producto: ");
	scanf("%d",&articulo.existencias);
	return articulo;	
}

void Mostrar_cds(CD *cds,int Num_cds){
	for(int i=0;i<Num_cds;i++){
		printf("\nAlbum: %s",cds[i].album);
		printf("\nArtista: %s",cds[i].artista);
		printf("\nPrecio: %.2f",cds[i].precio);
		printf("\nCodigo de barras: %d",cds[i].codigo_barras);
		printf("\nNumero de canciones: %d",cds[i].no_canciones);
		printf("\nCantidad disponible: %d",cds[i].existencias);
		printf("\n");
	}
}

void Mostrar_cd(CD *cds, int posicion){
		printf("\nAlbum: %s",cds[posicion].album);
		printf("\nArtista: %s",cds[posicion].artista);
		printf("\nPrecio: %.2f",cds[posicion].precio);
		printf("\nCodigo de barras: %d",cds[posicion].codigo_barras);
		printf("\nNumero de canciones: %d",cds[posicion].no_canciones);
		printf("\nCantidad disponible: %d",cds[posicion].existencias);
		printf("\n");
}

int Busqueda(CD *cds,int Codigo,int contador){
	int i=0;
	for(i;i<contador;i++){
		if(cds[i].codigo_barras==Codigo){
			return i;
		}
	}
	return -1;
}

void Comprar_CD(CD *cds,int posicion){
	if(cds[posicion].existencias==0){
		printf("\nNo hay CDs disponibles\n");
	}else{
		int comprar;
		printf("\nCantidad de CDs que deseas adquirir: ");
		scanf("%d",&comprar);
		if(cds[posicion].existencias>=comprar){
			cds[posicion].existencias=cds[posicion].existencias-comprar;
			printf("\nPagaras en total: %.2f",cds[posicion].precio*comprar);
			Mostrar_cd(cds,posicion);
		}else{
			printf("\nNo hay la suficiente cantidad que deseas adquirir, ya que solamente hay %d CDs\n",cds[posicion].existencias);
		}
	}
}
