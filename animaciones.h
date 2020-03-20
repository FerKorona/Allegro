#ifndef ANIMACIONES_H_INCLUDED
#define ANIMACIONES_H_INCLUDED



#endif // ANIMACIONES_H_INCLUDED

void bola_obscura(char *escenario,char *enemigo)
{
    int x,y,ax,ay,npoder,animacion,xprota,yprota,xenemigo,yenemigo,poseprota,poseenemigo;
    BITMAP *buffer=create_bitmap(800,600);
    BITMAP *poder  = load_bmp("bola obscura.bmp",NULL);
    BITMAP *prota=load_bmp("protagonistabatle.bmp",NULL);
    BITMAP *enemi=load_bmp(enemigo,NULL);
    BITMAP  *mapa=load_bmp(escenario,NULL);

 x = 20;
 y = 20;
 ax=10;
 ay=10;
 npoder=1;
 animacion=0;
 xprota=0;
 yprota=0;
 yenemigo=0;
 xenemigo=0;
 poseprota=0;
 poseenemigo=0;


  while ( y<450 )
 {
     clear_to_color(buffer, 0xaaaaaa);
      blit(mapa,buffer,0,0,0,0,800,600);
      masked_blit(enemi, buffer,poseenemigo*147, 0 , xenemigo+328, yenemigo+20, 147,246);
      masked_blit(prota, buffer, poseprota*150, 0, xprota+370, yprota+450, 149,150);
       masked_blit(poder, buffer, animacion*192, npoder*192, x+320, y, 192,192);
         // teclas control usuario
         y+=20;

         if ( ax != x || ay != y )
         {
              // entra si a cambiado alguna de las variables x,y
              animacion++;
              poseenemigo=2;
              if ( animacion > 2 ) animacion = 0;
         }

      blit(buffer, screen, 0, 0, 0, 0, 800, 600);

       rest(45);

      // tecla de salida

   }

 destroy_bitmap(poder);
 destroy_bitmap(mapa);
 destroy_bitmap(prota);
 destroy_bitmap(enemi);


}

void garras_obscuras(char *escenario,char *enemigo)
{
    int x,y,ax,ay,npoder,animacion,xprota,yprota,xenemigo,yenemigo,poseprota,poseenemigo,desplazamiento;
    BITMAP *buffer=create_bitmap(800,600);
    BITMAP *poder  = load_bmp("bola obscura.bmp",NULL);
    BITMAP *prota=load_bmp("protagonistabatle.bmp",NULL);
    BITMAP *enemi=load_bmp(enemigo,NULL);
    BITMAP  *mapa=load_bmp(escenario,NULL);
 x = 20;
 y = 20;
 ax=10;
 ay=10;
 npoder=2;
 animacion=0;
 xprota=0;
 yprota=0;
 yenemigo=0;
 xenemigo=0;
 poseprota=0;
 poseenemigo=0;
 desplazamiento=4;

int tiempo=0;
//ciclo de animacion
  while ( tiempo<=8 )
 {
     clear_to_color(buffer, 0xaaaaaa);
      blit(mapa,buffer,0,0,0,0,800,600);
      masked_blit(enemi, buffer,poseenemigo*147, 0 , xenemigo+328, yenemigo+20, 147,246);
      masked_blit(prota, buffer, poseprota*150, 0, xprota+370, yprota+450, 149,150);
       masked_blit(poder, buffer, animacion*192, npoder*192, x+328, y+20, 192,192);


        animacion++;
        delay(20);
        tiempo++;
         if ( ax != x || ay != y )
         {
              // entra si a cambiado alguna de las variables x,y

              if ( animacion > 4 ) animacion = 0;
         }

      blit(buffer, screen, 0, 0, 0, 0, 800, 600);

       rest(45);



   }

 destroy_bitmap(poder);
 destroy_bitmap(mapa);
 destroy_bitmap(prota);
 destroy_bitmap(enemi);


}

void cura(char *escenario,char *enemigo)
{
    int x,y,ax,ay,npoder,animacion,xprota,yprota,xenemigo,yenemigo,poseprota,poseenemigo,desplazamiento;
    BITMAP *buffer=create_bitmap(800,600);
    BITMAP *poder  = load_bmp("cura.bmp",NULL);
    BITMAP *prota=load_bmp("protagonistabatle.bmp",NULL);
    BITMAP *enemi=load_bmp(enemigo,NULL);
    BITMAP  *mapa=load_bmp(escenario,NULL);
 x = 20;
 y = 20;
 ax=10;
 ay=10;
 npoder=0;
 animacion=0;
 xprota=0;
 yprota=0;
 yenemigo=0;
 xenemigo=0;
 poseprota=0;
 poseenemigo=0;
 desplazamiento=4;

int tiempo=0;
//ciclo de animacion
  while ( tiempo<=5 )
 {
     clear_to_color(buffer, 0xaaaaaa);
      blit(mapa,buffer,0,0,0,0,800,600);
      masked_blit(enemi, buffer,poseenemigo*147, 0 , xenemigo+328, yenemigo+20, 147,246);
      masked_blit(prota, buffer, poseprota*150, 0, xprota+370, yprota+450, 149,150);
       masked_blit(poder, buffer, animacion*192, npoder*192, x+345, y+430, 192,192);


        animacion++;
        delay(35);
        tiempo++;
         if ( ax != x || ay != y )
         {
              // entra si a cambiado alguna de las variables x,y
              poseenemigo=2;
              if ( animacion > 4 ) animacion = 0;
         }

      blit(buffer, screen, 0, 0, 0, 0, 800, 600);

       rest(45);



   }

 destroy_bitmap(poder);
 destroy_bitmap(mapa);
 destroy_bitmap(prota);
 destroy_bitmap(enemi);


}

void thunder(char *escenario,char *enemigo)
{
    int x,y,ax,ay,npoder,animacion,xprota,yprota,xenemigo,yenemigo,poseprota,poseenemigo,desplazamiento;
    BITMAP *buffer=create_bitmap(800,600);
    BITMAP *poder  = load_bmp("thunder.bmp",NULL);
    BITMAP *prota=load_bmp("protagonistabatle.bmp",NULL);
    BITMAP *enemi=load_bmp(enemigo,NULL);
    BITMAP  *mapa=load_bmp(escenario,NULL);
 x = 20;
 y = 20;
 ax=10;
 ay=10;
 npoder=0;
 animacion=0;
 xprota=0;
 yprota=0;
 yenemigo=0;
 xenemigo=0;
 poseprota=0;
 poseenemigo=0;
 desplazamiento=4;

int tiempo=0;
//ciclo de animacion
  while ( tiempo<=5 )
 {
     clear_to_color(buffer, 0xaaaaaa);
      blit(mapa,buffer,0,0,0,0,800,600);
      masked_blit(enemi, buffer,poseenemigo*147, 0 , xenemigo+328, yenemigo+20, 147,246);
      masked_blit(prota, buffer, poseprota*150, 0, xprota+370, yprota+450, 149,150);
       masked_blit(poder, buffer, animacion*192, npoder*192, x+345, y+430, 192,192);


        animacion++;
        delay(40);
        tiempo++;
         if ( ax != x || ay != y )
         {
              // entra si a cambiado alguna de las variables x,y
              poseenemigo=2;
              if ( animacion > 4 ) animacion = 0;
         }

      blit(buffer, screen, 0, 0, 0, 0, 800, 600);

       rest(45);



   }

 destroy_bitmap(poder);
 destroy_bitmap(mapa);
 destroy_bitmap(prota);
 destroy_bitmap(enemi);


}



