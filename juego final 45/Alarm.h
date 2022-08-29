# include <allegro.h>
# include "Bala.h"
class Alarm {
	public:
		int cont;
		bool alarm(int secons);
		Alarm();
		virtual Bala* MetodoDisparo() const = 0;
		bool accion1() const {
		    Bala* bala = this->MetodoDisparo();
		    bool resultado = bala->accion();
		    delete bala;
		    return resultado;
		}
};

Alarm::Alarm(){
	this->cont = 0;
}

bool Alarm::alarm(int secons){
	
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

class AlarmPersonaje1 : public Alarm{
	Bala* MetodoDisparo() const carga {
		return new BalaPersonaje1();
	}
};

class AlarmPersonaje2 : public Alarm{
	Bala* MetodoDisparo() const carga {
		return new BalaPersonaje();
	}
};
