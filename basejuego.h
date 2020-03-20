#ifndef BASEJUEGO_H_INCLUDED
#define BASEJUEGO_H_INCLUDED
#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define ATACAR 72
#define MAGIA 80
#define GUARDIA 75
#define POCION 77


#endif // BASEJUEGO_H_INCLUDED


void inicia_juego()
{
    allegro_init();
 install_keyboard();

 set_color_depth(32);
 set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
}

void protagonista(char *prsj)
{

    BITMAP *buffer = create_bitmap(800, 600);
 BITMAP *prota  = load_bmp(prsj,NULL);
    int x,y,ax,ay,desplazamiento,direccion,animacion,salir;

 // inicializar vbles
 x = 20;
 y = 20;
 ax=10;
 ay=10;
 direccion=0;
 animacion=0;
 desplazamiento=4;
 salir = FALSE;
 while ( !salir )
 {

          clear_to_color(buffer, 0xaaaaaa);

         masked_blit(prota, buffer, animacion*32, direccion*32, x, y, 32,32);
         ax = x;
         ay = y;
         // teclas control usuario
         if ( key[KEY_UP] )
         {
              y-=desplazamiento;
              direccion = 3;
         }
         if ( key[KEY_DOWN] )
         {
              y+=desplazamiento;
              direccion = 0;
         }
         if ( key[KEY_LEFT] )
         {
              x-=desplazamiento;
              direccion = 1;
         }
         if ( key[KEY_RIGHT] )
         {
              x+=desplazamiento;
              direccion = 2;
         }
         if ( ax != x || ay != y )
         {
              // entra si a cambiado alguna de las variables x,y
              animacion++;
              if ( animacion > 2 ) animacion = 0;
         }

         // limites
         if ( x < 0 ) x = 0;
         if ( x > 800 ) x = 800;
         if ( y < 0 ) y = 0;
         if ( y > 600 ) y = 600;


      blit(buffer, screen, 0, 0, 0, 0, 800, 600);

      rest(50);

      // tecla de salida
      if ( key[KEY_ESC] ) salir = TRUE;

   }
   destroy_bitmap(prota);
 destroy_bitmap(buffer);
}





/*void satoribatle()
{

   int i;
    //variables de personajes
    int x,y,ax,ay,ypoder,desplazamiento,direccion,animacion,salir,animacionprota;
    int direccionprota,desplazamientopoder;
   install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
   set_volume(230, 200);
   BITMAP *buffer=create_bitmap(800,600);
   MIDI *musica1  = load_midi("bossbatle.mid");
    BITMAP *ataque  = load_bmp("darkness.bmp",NULL);
   BITMAP *satori=load_bmp("satori.bmp",NULL);
    BITMAP *prota=load_bmp("protagonistabatle.bmp",NULL);
   BITMAP *mapa=load_bmp("bgbatalla.bmp",NULL);
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

 //inicializar variables de vida y ataque del los personajes
 int vidaprota=100;
 int eleccionenemigo;
 int vidaenemigo=100;
 int tecla;
 while ( !salir )
 {

         clear_to_color(buffer, 0xaaaaaa);
          blit(mapa,buffer,0,0,0,0,800,600);
         masked_blit(satori, buffer, animacion*147, direccion*4, x+308, y, 147,246);
         masked_blit(prota, buffer, animacionprota*149, direccionprota*150, x+350, y+430, 149,150);
          animacionprota=0;

         ax = x;
         ay = y;


         // teclas control usuario
         if (eleccionenemigo=0)
         {


              bola_obscura("bgbatalla.bmp","satori.bmp");
              animacionprota=3;
              textout(buffer,font,"3000",500,460, 0xFFFFFF);




         }
         if (eleccionenemigo=1 )
         {

               garras_obscuras("bgbatalla.bmp","satori.bmp");
         }
         if ( eleccionenemigo=2 )
         {
             cura("bgbatalla.bmp","satori.bmp");

         }
         if (eleccionenemigo=3 )
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


     eleccionenemigo=rand()%3;
     tecla=getch();
       switch(tecla)
        {
          case ATACAR:
           garras_obscuras("bgbatalla.bmp","satori.bmp");
            break;
          case MAGIA:
            garras_obscuras("bgbatalla.bmp","satori.bmp");
            break;
          case GUARDIA:
           animacionprota=3;
            break;
             case POCION:
           garras_obscuras("bgbatalla.bmp","satori.bmp");
            break;
        }
   }


 destroy_bitmap(prota);
 destroy_bitmap(buffer);
destroy_bitmap(mapa);
  destroy_midi(musica1);



}*/



void delay(int tiempo)

{

  int i,j;

  for(i=0;i<tiempo*100;i++)

     {

	   for(j=0;j<tiempo*100;j++);
     }

}

