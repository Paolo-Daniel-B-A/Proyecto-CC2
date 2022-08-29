# include <allegro.h>
#include <iostream>
using namespace std;
template <class T>
class Menu{
	public:
		// Variables
		T x;
		T y;
		BITMAP* sprite;
		
		BITMAP* visor;
		BITMAP* NVIDA;
		BITMAP* NVIDA2;
		BITMAP* b_vida;
		//Funciones
		Menu(T x, T y);
		~Menu();
		void action(T &vida);
		void action2(T &vida2);
};

template<class T>
Menu<T>::Menu(T x, T y){
	this->x = x;
	this->y = y;
	sprite = create_bitmap(300,640);
	NVIDA=load_bitmap("imagenvidajugador2.bmp",NULL);
	NVIDA2=load_bitmap("imagenvida.bmp",NULL);
	visor = load_bitmap("visor.bmp",NULL);
	this->b_vida = load_bitmap("b_vida.bmp",NULL);
	
}

template <class T>
void Menu<T>::action(T &vida){
	draw_sprite(sprite,NVIDA2,70,20);
	draw_sprite(sprite,visor,30,70);
	 // dibuja el visor 
	//-----------------------------------
	T b_tam = (104.0/100.0) * vida; // tama?o de la barra de vida
	stretch_sprite(sprite,b_vida,102,76,b_tam,12); // crea una barra de vida estirando una imagen
	//-----------------------------------
	draw_sprite(screen,sprite,x,y);	
	
}
template <class T>
void Menu<T>::action2(T &vida2){
	draw_sprite(sprite,NVIDA,70,150);
	draw_sprite(sprite,visor,30,230);
	
	
	 // dibuja el visor 
	//-----------------------------------
	T b_tam = (104.0/100.0) * vida2; // tama?o de la barra de vida
	stretch_sprite(sprite,b_vida,102,236,b_tam,12); // crea una barra de vida estirando una imagen
	//-----------------------------------
	draw_sprite(screen,sprite,x,y);	
	
	
}



