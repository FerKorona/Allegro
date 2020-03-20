#include <allegro.h>
#include"basejuego.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main()
{
char *fondo={"prueba.bmp"};
   inicia_juego();
 BITMAP *buffer = create_bitmap(800, 600);
 BITMAP *prota  = load_bmp("protagonista.bmp",NULL);
BITMAP *mapa=load_bmp("prueba.bmp",NULL);

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
blit(mapa, screen, 0, 0, 0, 0, 800, 600);
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
destroy_bitmap(mapa);
 return 0;
}
END_OF_MAIN();

