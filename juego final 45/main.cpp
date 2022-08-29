# include <allegro.h>
BITMAP *lienzo;
# include <iostream>
using namespace std;
# include <list>
# include <math.h>
# include "Alarm.h"
# include "Bala.h"
# include "Objetos.h"
# include "Personaje2.h"
# include "Enemigos.h"
# include "Background.h"
# include "Menu.h"
Alarm *Timer = new Alarm(); 


void init();
void deinit();
void crear();
void Enemigo_action();
void menu();


int main(){
	
	init();
	BITMAP *buffer = create_bitmap(940, 640);
	BITMAP *fondo;
	BITMAP *fondo2;
	BITMAP *fondo3;
	BITMAP *fondo4;
	BITMAP *fondogameover;
	BITMAP *cursor;
	SAMPLE* sample;
	SAMPLE* sample2;
	
	// inicializa las variables 
	clear_to_color(buffer, 0x333333);		
	fondo = load_bitmap("fondomenu.bmp",NULL);
	fondo2 = load_bitmap("fondomenuj1.bmp",NULL);
	fondo3 = load_bitmap("fondomenuj2.bmp",NULL);
	fondo4 = load_bitmap("salir.bmp",NULL);
	fondogameover = load_bitmap("gameover.bmp",NULL);
	cursor = load_bitmap("cursor.bmp",NULL);
	
	sample= load_sample("juego-de-tronos-1.wav");
	play_sample(sample, 255, 128, 1000, 1);
	sample2 = load_sample("Juhani Junkala [Retro Game Music Pack] Title Screen.wav");
	
	

    bool salida = false;

    // primer menu simple
	while ( !salida )	
	{
		
		
         // posicion del boton 
         if ( mouse_x > 270 && mouse_x < 670 &&
              mouse_y > 205 && mouse_y < 320) 
         {  
	        
            blit(fondo2, buffer, 0, 0, 0, 0, 940, 640); 
            // se ha pulsado el boton del raton
			if ( mouse_b & 1 )
            {
                  	lienzo = create_bitmap(640,640);
					Personaje *p1 = new Personaje();
					Background* background = new Background("fondo.bmp");
					Menu<int>* menu = new Menu<int>(640,0);
					stop_sample(sample);
					play_sample(sample2, 255, 128, 1000, 1);
					
					
					srand(time(NULL)); // hace que los numeros sean aleatorios
					
					
					
					while (!key[KEY_ESC]) 
					{
						background->action();
						 // mostrar el fondo
						crear();
						menu->action(p1->vida);
						Enemigo_action();
						if (p1->vida > 0 )
						{
							p1->movBala();
							p1->mov();
							
							draw_sprite(screen,lienzo,0,0);
							clear_to_color(lienzo,0x000000);
							
						}	
						
						  // mover la nave si su vida es mayor a 0
						
						 // mover la nave si su vida es mayor a 0
						
						
					}
                  
	        }
         }else{
            blit(fondo, buffer, 0, 0, 0, 0, 940, 640);  
			if ( mouse_x > 270 && mouse_x < 770 &&
	              mouse_y > 324 && mouse_y < 440) 
	         {  
	            blit(fondo3, buffer, 0, 0, 0, 0, 940, 640); 
	           
	            // se ha pulsado el boton del raton
				if ( mouse_b & 1 )
	            {
	                    lienzo = create_bitmap(640,640);
						Personaje *p1 = new Personaje();
						Personaje2 *p2 = new Personaje2();
						Background* background = new Background("fondo.bmp");
						Menu<int>* menu = new Menu<int>(640,0);
						stop_sample(sample);
						play_sample(sample2, 255, 128, 1000, 1);
						
						srand(time(NULL)); // hace que los numeros sean aleatorios
						
						
						
						while (!key[KEY_ESC]) 
						{
							background->action();
							 // mostrar el fondo
							crear();
							menu->action(p1->vida);
							menu->action2(p2->vida);
							Enemigo_action();
							if (p1->vida > 0 && p2->vida > 0)
							{
								p1->movBala();
								p1->mov();
								p2->movBala();
								p2->movimientoP2();
								draw_sprite(screen,lienzo,0,0);
								clear_to_color(lienzo,0x000000);
								
							}
							  // mover la nave si su vida es mayor a 0
							
							 // mover la nave si su vida es mayor a 0
							
							
						}
	                  
		        }
			 }
			 else{
	            blit(fondo, buffer, 0, 0, 0, 0, 940, 640);  
				if ( mouse_x > 270 && mouse_x < 770 &&
		              mouse_y > 500 && mouse_y < 590) 
		         {  
		            blit(fondo4, buffer, 0, 0, 0, 0, 940, 640); 
		            // se ha pulsado el boton del raton
					if ( mouse_b & 1 )
		            {
		                  salida = true;
		                  
			        }
				 }
				 else{
		            blit(fondo, buffer, 0, 0, 0, 0, 940, 640);    
		         }    
	         }  
         }
		 
         
          

         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22); 
         
         // se muestra todo por pantalla 
	     blit(buffer, screen, 0, 0, 0, 0, 940, 640);
	     
          if ( key[KEY_ESC] )
          {
               salida = true;
          } 
	     
    }
    
	
	deinit();
	return 0;
}
END_OF_MAIN()


void crear(){
	static int cont = 0; // cuenta los enemigos que se crean
	static int type = rand()%3; // crea un numero aleatorio entre el 0 y 2
	
	if(cont < 5){
		if(Timer->alarm(180)){
			Enemigos.push_back(new Enemigo(-80,15,type)); // crear un enemigo random
			cont++;	
		}
	}else{
		if(Timer->alarm(320))		{
			cont = 0; //reinicia el contador
			type = rand()%3;
		}
	}
	
}


void Enemigo_action(){
	for(list<Enemigo*>::iterator it = Enemigos.begin(); it != Enemigos.end(); it++){
		Enemigo *b = *it;
		b->action();
	}
}

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 940, 640, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	install_sound(DIGI_AUTODETECT  ,MIDI_AUTODETECT, NULL);
	/* add other initializations here */
}
void menu(){
	BITMAP *buffer = create_bitmap(940, 640);
	BITMAP *fondo;
	BITMAP *fondo2;
	BITMAP *cursor;
	
	// inicializa las variables 
	clear_to_color(buffer, 0x333333);		
	fondo = load_bitmap("simple1f.bmp",NULL);
	fondo2 = load_bitmap("simple1n.bmp",NULL);
	cursor = load_bitmap("cursor.bmp",NULL);

    bool salida = false;

    // primer menu simple
	while ( !salida )	
	{
         // posicion del boton 
         if ( mouse_x > 270 && mouse_x < 370 &&
              mouse_y > 295 && mouse_y < 340) 
         {  
            blit(fondo2, buffer, 0, 0, 0, 0, 940, 640); 
            
            // se ha pulsado el boton del raton
            if ( mouse_b & 1 )
            {
                  salida = true;
            }
         }else{
            blit(fondo, buffer, 0, 0, 0, 0, 940, 640);    
         }

         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22); 
         
         // se muestra todo por pantalla 
	     blit(buffer, screen, 0, 0, 0, 0, 940, 640);
	     
          if ( key[KEY_ESC] )
          {
               salida = true;
          } 
	     
    }
    
    // inicializa las variables con el nuevo menu 
    salida = false;
	destroy_bitmap(fondo);
	destroy_bitmap(fondo2);
	fondo  = load_bitmap("simple2f.bmp",NULL);
	fondo2 = load_bitmap("simple2n.bmp",NULL);
	
	// menu simple 2, igual que el anterior
	while ( !salida )
	{
         if ( mouse_x > 230 && mouse_x < 410 &&
              mouse_y > 390 && mouse_y < 440) 
         {  
            blit(fondo2, buffer, 0, 0, 0, 0, 940, 640); 
            
            if ( mouse_b & 1 )
            {
                  salida = true;
            }
         }else{
            blit(fondo, buffer, 0, 0, 0, 0, 940, 640);    
         }
         
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22); 
          
	     blit(buffer, screen, 0, 0, 0, 0, 940, 640);
	     
	     // se cambia la tecla de salida
          if ( key[KEY_ENTER] )
          {
               salida = true;
          } 
	     
    }	
     

    // libera memoria quitando las imagenes 	
	destroy_bitmap(buffer);
	destroy_bitmap(fondo);
	destroy_bitmap(fondo2);
	destroy_bitmap(cursor);
}


void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}

