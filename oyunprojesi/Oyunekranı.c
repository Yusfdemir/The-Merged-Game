#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include<time.h>
#define BOY 600
#define EN 800

void rastgele_zar_ciz(int rastgelezar);
void zar_ata(int a, int b, int rastgelezar, int ilkekranx[], int ilkekrany[]);

int main() {

	int ilkekranx[5] = { 100,165,230,295,360 };
	int ilkekrany[5] = { 100,165,230,295,360 };
	int pos_x = 100;
	int pos_y = 100;
	int i = 0;
	int random_zar[25] = { 0 };

	for (int i = 1; i < 25; i++) {
		random_zar[i] = 1 + rand() % 6;
	}

	bool done = false;
	bool draw = false;
	bool play_kontrol = true;
	bool oyuna_gec = false;
	bool yerlestir[5][5] = { false };

	ALLEGRO_EVENT_QUEUE* queue = NULL;
	ALLEGRO_DISPLAY* display = NULL;

	if (!al_init()) {
		return -1;
	}
	display = al_create_display(EN, BOY);

	if (!display) {
		return -1;
	}

	al_install_mouse();
	al_install_keyboard();

	queue = al_create_event_queue();
	srand(time(NULL));
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_grab_mouse(display);
	al_set_mouse_xy(display, 500, 250);

	while (!done) {

		if (play_kontrol) {
			al_draw_rectangle(400, 200, 600, 300, al_map_rgb(0, 0, 255), 1);
			al_draw_rectangle(400, 310, 600, 410, al_map_rgb(0, 0, 255), 1);
			ALLEGRO_FONT* font = al_load_font("OpenSans-Regular.ttf", 36, 0);
			ALLEGRO_FONT* font2 = al_load_font("OpenSans-Regular.ttf", 24, 0);
			ALLEGRO_FONT* font1 = al_load_font("OpenSans-Regular.ttf", 18, 0);
			al_draw_text(font1, al_map_rgb(255, 255, 255), 25, 25, 0, "In game you can press esc to exit");
			al_draw_text(font2, al_map_rgb(255, 255, 255), 50, 300, 0, "Welcome to our first game");
			al_draw_text(font, al_map_rgb(255, 255, 255), 435, 225, 0, "P L A Y");
			al_draw_text(font, al_map_rgb(255, 255, 255), 435, 335, 0, "E X I T");
		}

		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

			if (pos_x > 400 && pos_x < 600 && pos_y>200 && pos_y < 300 && ev.mouse.button & 1) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				draw = true;
				play_kontrol = false;
			}
			else if (pos_x > 400 && pos_x < 600 && pos_y>310 && pos_y < 410 && ev.mouse.button & 1) {
				done = true;
			}
			else if (pos_x > 100 && pos_x < 160 && pos_y>100 && pos_y < 160 && ev.mouse.button & 1) {
				yerlestir[0][0] = true;
			}
			else if (pos_x > 165 && pos_x < 225 && pos_y>100 && pos_y < 160 && ev.mouse.button & 1) {
				yerlestir[0][1] = true;
			}
			else if (pos_x > 230 && pos_x < 290 && pos_y>100 && pos_y < 160 && ev.mouse.button & 1) {
				yerlestir[0][2] = true;
			}
			else if (pos_x > 295 && pos_x < 355 && pos_y>100 && pos_y < 160 && ev.mouse.button & 1) {
				yerlestir[0][3] = true;
			}
			else if (pos_x > 360 && pos_x < 420 && pos_y>100 && pos_y < 160 && ev.mouse.button & 1) {
				yerlestir[0][4] = true;
			}
			else if (pos_x > 100 && pos_x < 160 && pos_y>165 && pos_y < 225 && ev.mouse.button & 1) {
				yerlestir[1][0] = true;
			}
			else if (pos_x > 165 && pos_x < 225 && pos_y>165 && pos_y < 225 && ev.mouse.button & 1) {
				yerlestir[1][1] = true;
			}
			else if (pos_x > 230 && pos_x < 290 && pos_y>165 && pos_y < 225 && ev.mouse.button & 1) {
				yerlestir[1][2] = true;
			}
			else if (pos_x > 295 && pos_x < 355 && pos_y>165 && pos_y < 225 && ev.mouse.button & 1) {
				yerlestir[1][3] = true;
			}
			else if (pos_x > 360 && pos_x < 420 && pos_y>165 && pos_y < 225 && ev.mouse.button & 1) {
				yerlestir[1][4] = true;
			}
			else if (pos_x > 100 && pos_x < 160 && pos_y>230 && pos_y < 290 && ev.mouse.button & 1) {
				yerlestir[2][0] = true;
			}
			else if (pos_x > 165 && pos_x < 225 && pos_y>230 && pos_y < 290 && ev.mouse.button & 1) {
				yerlestir[2][1] = true;
			}
			else if (pos_x > 230 && pos_x < 290 && pos_y>230 && pos_y < 290 && ev.mouse.button & 1) {
				yerlestir[2][2] = true;
			}
			else if (pos_x > 295 && pos_x < 355 && pos_y>230 && pos_y < 290 && ev.mouse.button & 1) {
				yerlestir[2][3] = true;
			}
			else if (pos_x > 360 && pos_x < 420 && pos_y>230 && pos_y < 290 && ev.mouse.button & 1) {
				yerlestir[2][4] = true;
			}
			else if (pos_x > 100 && pos_x < 160 && pos_y>295 && pos_y < 355 && ev.mouse.button & 1) {
				yerlestir[3][0] = true;
			}
			else if (pos_x > 165 && pos_x < 225 && pos_y>295 && pos_y < 355 && ev.mouse.button & 1) {
				yerlestir[3][1] = true;
			}
			else if (pos_x > 230 && pos_x < 290 && pos_y>295 && pos_y < 355 && ev.mouse.button & 1) {
				yerlestir[3][2] = true;
			}
			else if (pos_x > 295 && pos_x < 355 && pos_y>295 && pos_y < 355 && ev.mouse.button & 1) {
				yerlestir[3][3] = true;
			}
			else if (pos_x > 360 && pos_x < 420 && pos_y>295 && pos_y < 355 && ev.mouse.button & 1) {
				yerlestir[3][4] = true;
			}
			else if (pos_x > 100 && pos_x < 160 && pos_y>360 && pos_y < 420 && ev.mouse.button & 1) {
				yerlestir[4][0] = true;
			}
			else if (pos_x > 165 && pos_x < 225 && pos_y>360 && pos_y < 420 && ev.mouse.button & 1) {
				yerlestir[4][1] = true;
			}
			else if (pos_x > 230 && pos_x < 290 && pos_y>360 && pos_y < 420 && ev.mouse.button & 1) {
				yerlestir[4][2] = true;
			}
			else if (pos_x > 295 && pos_x < 355 && pos_y>360 && pos_y < 420 && ev.mouse.button & 1) {
				yerlestir[4][3] = true;
			}
			else if (pos_x > 360 && pos_x < 420 && pos_y>360 && pos_y < 420 && ev.mouse.button & 1) {
				yerlestir[4][4] = true;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				done = true;
			}
		}

		if (draw) {

			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					al_draw_filled_rectangle(ilkekranx[i], ilkekrany[j], ilkekranx[i] + 60, ilkekrany[j] + 60, al_map_rgb(50, 50, 50));
				}
			}

			if (random_zar[0] == 0) {
				oyuna_gec = true;
				random_zar[0] = 1 + rand() % 6;
			}

			if (oyuna_gec) {
				rastgele_zar_ciz(random_zar[0]);
			}

			for (int a = 0; a < 5; a++) {
				for (int b = 0; b < 5; b++) {
					if (yerlestir[a][b]) {
						rastgele_zar_ciz(random_zar[a * 5 + b]);
						zar_ata(a, b, random_zar[a * 5 + b], ilkekranx, ilkekrany);
					}
				}
			}
		}
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_display(display);
	al_destroy_event_queue(queue);

	return 0;
}

void rastgele_zar_ciz(rastgelezar) {
	switch (rastgelezar) {
	case 1:
		al_draw_filled_rectangle(200, 450, 260, 510, al_map_rgb(255, 0, 255));
		al_draw_filled_circle(230, 480, 5, al_map_rgb(0, 0, 0));
		break;
	case 2:
		al_draw_filled_rectangle(200, 450, 260, 510, al_map_rgb(200, 150, 0));
		al_draw_filled_circle(215, 465, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(245, 495, 5, al_map_rgb(0, 0, 0));
		break;
	case 3:
		al_draw_filled_rectangle(200, 450, 260, 510, al_map_rgb(255, 0, 0));
		al_draw_filled_circle(215, 465, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(230, 480, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(245, 495, 5, al_map_rgb(0, 0, 0));
		break;
	case 4:
		al_draw_filled_rectangle(200, 450, 260, 510, al_map_rgb(0, 0, 255));
		al_draw_filled_circle(215, 465, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(215, 495, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(245, 465, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(245, 495, 5, al_map_rgb(0, 0, 0));
		break;
	case 5:
		al_draw_filled_rectangle(200, 450, 260, 510, al_map_rgb(0, 255, 0));
		al_draw_filled_circle(215, 465, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(215, 495, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(230, 480, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(245, 465, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(245, 495, 5, al_map_rgb(0, 0, 0));
		break;
	case 6:
		al_draw_filled_rectangle(200, 450, 260, 510, al_map_rgb(125, 125, 0));
		al_draw_filled_circle(215, 465, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(215, 480, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(215, 495, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(245, 465, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(245, 485, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(245, 495, 5, al_map_rgb(0, 0, 0));
		break;
	}
}

void zar_ata(int a, int b, int rastgelezar, int ilkekranx[], int ilkekrany[]) {
	switch (rastgelezar) {
	case 1:
		al_draw_filled_rectangle(ilkekranx[b], ilkekrany[a], ilkekranx[b] + 60, ilkekrany[a] + 60, al_map_rgb(255, 0, 255));
		al_draw_filled_circle(ilkekranx[b] + 30, ilkekrany[a] + 30, 5, al_map_rgb(0, 0, 0));
		break;
	case 2:
		al_draw_filled_rectangle(ilkekranx[b], ilkekrany[a], ilkekranx[b] + 60, ilkekrany[a] + 60, al_map_rgb(200, 150, 0));
		al_draw_filled_circle(ilkekranx[b] + 15, ilkekrany[a] + 15, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 45, ilkekrany[a] + 45, 5, al_map_rgb(0, 0, 0));
		break;
	case 3:
		al_draw_filled_rectangle(ilkekranx[b], ilkekrany[a], ilkekranx[b] + 60, ilkekrany[a] + 60, al_map_rgb(255, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 15, ilkekrany[a] + 15, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 30, ilkekrany[a] + 30, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 45, ilkekrany[a] + 45, 5, al_map_rgb(0, 0, 0));
		break;
	case 4:
		al_draw_filled_rectangle(ilkekranx[b], ilkekrany[a], ilkekranx[b] + 60, ilkekrany[a] + 60, al_map_rgb(0, 0, 255));
		al_draw_filled_circle(ilkekranx[b] + 15, ilkekrany[a] + 15, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 15, ilkekrany[a] + 45, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 45, ilkekrany[a] + 15, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 45, ilkekrany[a] + 45, 5, al_map_rgb(0, 0, 0));
		break;
	case 5:
		al_draw_filled_rectangle(ilkekranx[b], ilkekrany[a], ilkekranx[b] + 60, ilkekrany[a] + 60, al_map_rgb(0, 255, 0));
		al_draw_filled_circle(ilkekranx[b] + 15, ilkekrany[a] + 15, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 15, ilkekrany[a] + 45, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 45, ilkekrany[a] + 15, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 45, ilkekrany[a] + 45, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 30, ilkekrany[a] + 30, 5, al_map_rgb(0, 0, 0));
		break;
	case 6:
		al_draw_filled_rectangle(ilkekranx[b], ilkekrany[a], ilkekranx[b] + 60, ilkekrany[a] + 60, al_map_rgb(125, 125, 0));
		al_draw_filled_circle(ilkekranx[b] + 15, ilkekrany[a] + 15, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 15, ilkekrany[a] + 30, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 15, ilkekrany[a] + 45, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 45, ilkekrany[a] + 15, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 45, ilkekrany[a] + 30, 5, al_map_rgb(0, 0, 0));
		al_draw_filled_circle(ilkekranx[b] + 45, ilkekrany[a] + 45, 5, al_map_rgb(0, 0, 0));
		break;
	}
}
