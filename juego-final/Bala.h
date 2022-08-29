# include <allegro.h>
class Bala{
	public:
		// variables
		int x;
		int y;
		int type;
		BITMAP* sprite;
		//funciones		
		void mov() ();
		void mov2() ();
		virtual void accion() const = 0;
		Bala(int x, int y,int type);
		~Bala();
};
list<Bala*> balas;

Bala::Bala(int x, int y,int type){
	this->x = x;
	this->y = y;
	this->sprite = type == 0? load_bitmap("bala.bmp",NULL) : load_bitmap("bala_enemiga.bmp",NULL);
	this->type = type;
}

void Bala::mov(){
	
	//Dibujar en pantalla
	draw_sprite(lienzo,sprite,x,y);
	
	//Movimiento
	switch(this->type){
		case 0:
			if(y > 0) y-=5;
			else this->~Bala();
		break;
		case 1:
			if(y < SCREEN_H) y+=5;
			else this->~Bala();
		break;
	}
}
void Bala::mov2(){
	
	//Dibujar en pantalla
	draw_sprite(lienzo,sprite,x,y);
	
	//Movimiento
	switch(this->type){
		case 0:
			if(y > 0) y-=5;
			else this->~Bala();
		break;
		case 1:
			if(y < SCREEN_H) y+=5;
			else this->~Bala();
		break;
	}
}

Bala::~Bala(){
	destroy_bitmap(this->sprite);
	balas.remove(this);
}



static bool alarm(int secons){
	static int cont = 0;
	
	if(secons == 0){
		return false;
	}
	
	if(cont >= secons){
		cont = 0;
		return true;
	}
	
	cont++;
	
	return false;
}
class BalaPersonaje1 : public Bala{
	public:
		void accion() const carga{
			draw_sprite(lienzo,sprite,x,y);
			switch(this->type){
				case 0:
					if(y > 0)			y-=5;
					else				this->~Bala();
				break;
				case 1:
					if(y < SCREEN_H)			y+=5;
					else				this->~Bala();
				break;
			}
		}
};


class BalaPersonaje2 : public Bala{
	public:
		void accion() const carga{
			draw_sprite(lienzo,sprite,x,y);
			switch(this->type){
				case 0:
					if(y > 0)			y-=5;
					else				this->~Bala();
				break;
				case 1:
					if(y < SCREEN_H)			y+=5;
					else				this->~Bala();
				break;
			}
		}
};



