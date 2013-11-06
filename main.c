  #include <allegro5/allegro.h>
  #include <allegro5/allegro_image.h>
  #include "variables.h"
  #include <stdio.h>
  int drawPlayer(int x, int y, ALLEGRO_BITMAP * player, int type, int position){
    al_draw_bitmap_region(player, 50, 310, 30, 30, 150, 4, 0);/*Dibuja una imagen en la pantalla*/
    if(position == 0)
      al_draw_bitmap_region(player, playerNormal[type][0], playerNormal[type][1],playerNormal[type][2],playerNormal[type][3],x, y, 0);
    else
      al_draw_bitmap_region(player, playerCorrer[type][0], playerCorrer[type][1],playerCorrer[type][2],playerCorrer[type][3],x, y, 0);

    return 0;
  }

  int main()
  {
    //Inicializacion
    ALLEGRO_DISPLAY *display = NULL;/*Declaracion de el display*/
    ALLEGRO_BITMAP *player = NULL;
    ALLEGRO_EVENT ev;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL; /*Cola de eventos*/
    int px = 0, py = 0, typeImg = 0, multi = 1, cont=0, mover = 0;
    int piedra[2]={150, 4};
    if(!al_init()) /*Inicializacion de allegro*/
    {
      printf("error");
    } 
    al_init_image_addon();/*Inicializacion de las imagenes*/
    if(!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }
    display = al_create_display(600, 480);
    if(!display){
      printf("Error");
    }
    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_change_directory(al_path_cstr(path, '/'));
    al_destroy_path(path);/*Se cambia el path a el path del projecto*/
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    player = al_load_bitmap("img/marco.png");/*Se carga la imagen */

    if(!player){
      printf("Error");
      exit(22);
    }
    do
    {
      
      
      //Entrada y salida
      if(!al_event_queue_is_empty(event_queue)){
        al_get_next_event(event_queue, &ev);/*Recibe algun evento del teclado*/
        if( ev.type == ALLEGRO_EVENT_KEY_DOWN) {
           fprintf(stderr, "%d\n", ev.keyboard.keycode);
           if(ev.keyboard.keycode == 83){
            //fprintf(stderr, "derecha\n");
            mover++;
           }
           else if(ev.keyboard.keycode == 82)
           {
            mover--;
           }
        }
      }
      
      //Logica
      if(typeImg%8 == 0)
        typeImg=1;
      if(mover>0 && px<piedra[0])
      {
        mover=0;
        px+=10;
      }  	
      else if(mover<0){
        mover=0;
        px-=10;
      }
      typeImg++;
      cont++;

      //Dibujo
      al_clear_to_color(al_map_rgb(13, 13,13));
      drawPlayer(px, py, player, typeImg, 1);
      al_flip_display();
      al_rest(0.5);/*Segundos a esperar entre un dibujo y otro*/
    }while(1);
    al_destroy_display(display);

    return 0;
  }
