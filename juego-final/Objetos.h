#ifndef OBJETOS_H
# define OBJETOS_H
# include <allegro.h>
#include "Alarm.h"
class Personaje{
	public:
		//varibles
		
		BITMAP* sprite;
		float vel;
		int vida;
		//Funciones
		void mov();
		void movBala();
		void cargador(const Alarm& generar);
		Personaje();
		~Personaje();
	private:
		int x;
		int y;	
};


Personaje::Personaje(){
	x = 400;
	y = 450;
	sprite = load_bitmap("nave.bmp",NULL);
	
	vel = 2;
	vida = 100;
	
}

void Personaje::mov(){
	
	draw_sprite(lienzo,sprite,x,y);	
	if(key[KEY_SPACE] and alarm(5))		
		balas.push_back(new Bala(x+(sprite->w/2)-7,y,0)); // agrega una bala a la lista

	if(key[KEY_RIGHT] and x + sprite->w < lienzo->w){
		x+=vel;
	}
	if(key[KEY_LEFT] and x > 0){
		x-=vel;
	}
	if(key[KEY_UP] and y > 0){
		y-=vel;
	}
	if(key[KEY_DOWN] and y + sprite->h < lienzo->h){
		y+=vel;
	}
	
	
}
void Personaje::movBala(){	
	std::shared_ptr<Bala> b = std::make_shared<Bala>(*it);	
	for(list<Bala*>::iterator it = balas.begin(); it != balas.end(); it++){
		std::shared_ptr<Bala> b2=b;
		b2->mov();
	}
	
	//colision
	for(list<Bala*>::iterator it = balas.begin(); it != balas.end(); it++){
		std::shared_ptr<Bala> b3 = b;
		std::weak_ptr<Bala> b4 = b3;
		if(b->type == 1){ // si la bala es de tipo 1 (creada por el enemigo)
			if(b->x >= x and b->x <= x+sprite->w and b->y >= y and b->y <= y+sprite->h)
			{
				delete b4;
				this->vida-=3;	
			}	
		}
	}
}
void cargador(const Alarm& generar){
	generar.MetodoDisparo();
}

Personaje::~Personaje(){
	
}
#endif
