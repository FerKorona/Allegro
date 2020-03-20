#include <allegro.h>
#include"animaciones.h"
#include "batallas.h"
#include"basejuego.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0



int main()
{
    inicia_juego();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
   int x,y,ax,ay,ypoder,desplazamiento,direccion,animacion,salir,animacionprota;
    int direccionprota,desplazamientopoder;
   set_volume(230, 200);
   BITMAP *buffer=create_bitmap(800,600);
   MIDI *musica1  = load_midi("dracula.mid");
    BITMAP *ataque  = load_bmp("darkness.bmp",NULL);
   BITMAP *satori=load_bmp("Dracula.bmp",NULL);
    BITMAP *prota=load_bmp("Chrono.bmp",NULL);
    BITMAP *mapa=load_bmp("EsDracula.bmp",NULL);
   BITMAP *comandos=load_bmp("commandos.bmp",NULL);
     //SAMPLE *dano = load_wav("ding.wav");
play_midi(musica1,1);



 // inicializar variables de personajes
 x = 20;
 y = 20;
 ax=10;
 ay=10;
 direccion=0;
 animacion=0;
 direccionprota=0;
 desplazamiento=4;
 salir = FALSE;
 //inicializar variables de vida
int vidaenemigo=3000,vidaprota=3000;
//variable para los ataques aleatorios
int eleccionenemigo;

int opcion;

 while ( vidaenemigo>0 )
 {
    eleccionenemigo=rand()%3;
         clear_to_color(buffer, 0xaaaaaa);
          blit(mapa,buffer,0,0,0,0,800,600);
         masked_blit(satori, buffer, animacion*147, direccion*4, x+308, y, 147,246);
         masked_blit(prota, buffer, animacionprota*149, direccionprota*150, x+350, y+430, 149,150);
         masked_blit(comandos, buffer, 0, 0, x+250, y+400, 125,151);
         textprintf(buffer,font,330,40,0xFFFFFF,"%d",vidaenemigo);
          textprintf(buffer,font,470,450,0xFFFFFF,"%d",vidaprota);

          animacionprota=0;
         ax = x;
         ay = y;


        if (key[KEY_UP])
         {

               garras_obscuras("bgbatalla.bmp","satori.bmp");
               //play_sample(dano,200,150,1000,0);
               animacionprota=3;
              // play_sample(dano,200,150,1000,0);
             switch(eleccionenemigo)
                    {
                  case 1:
              eleccionenemigo=0;
           garras_obscuras("bgbatalla.bmp","satori.bmp");
            break;
          case 2:
              eleccionenemigo=1;
             bola_obscura("bgbatalla.bmp","satori.bmp");
            break;
          case 3:
              eleccionenemigo=2;
           thunder("bgbatalla.bmp","satori.bmp");
            break;
             case 4:
                 eleccionenemigo=3;
            cura("bgbatalla.bmp","satori.bmp");

            break;
            }

        vidaenemigo-=200;

         }
         if ( key[KEY_DOWN] )
         {

               garras_obscuras("bgbatalla.bmp","satori.bmp");
         }
         if ( key[KEY_LEFT] )
         {
             cura("bgbatalla.bmp","satori.bmp");

         }
         if ( key[KEY_RIGHT] )
         {

              thunder("bgbatalla.bmp","satori.bmp");
         }


         if ( ax != x || ay != y )
         {
              // entra si a cambiado alguna de las variables x,y
              animacion++;
              if ( animacion > 3 ) animacion = 0;
         }

      blit(buffer, screen, 0, 0, 0, 0, 800, 600);

       rest(45);

      // tecla de salida
      if ( key[KEY_ESC] ) salir = TRUE;

   }

 destroy_bitmap(prota);
 destroy_bitmap(buffer);
destroy_bitmap(mapa);
  destroy_midi(musica1);
  return 0;
}
END_OF_MAIN();
