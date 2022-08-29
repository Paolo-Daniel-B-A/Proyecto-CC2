#include "Objetos.h"
# include <allegro.h>
class Personaje2:public Personaje
{
	public:
		BITMAP* sprite;
		Personaje2();
		~Personaje2();
		void movimientoP2();
		
	private:
		int x=200;
		int y=450;
		
};


Personaje2::Personaje2(){
	sprite = load_bitmap("personaje2.bmp",NULL);
}
void Personaje2::movimientoP2()
{
	
	draw_sprite(lienzo,sprite,x,y);
	if(key[KEY_G] and alarm(5))		
		balas.push_back(new Bala(x+(sprite->w/2)-7,y,0)); // agrega una bala a la lista
		
	if(key[KEY_D] and x + sprite->w < lienzo->w){
		x+=vel;
	}
	if(key[KEY_A] and x > 0){
		x-=vel;
	}
	if(key[KEY_W] and y > 0){
		y-=vel;
	}
	if(key[KEY_S] and y + sprite->h < lienzo->h){
		y+=vel;
	}
	
}

