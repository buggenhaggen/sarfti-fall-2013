#include <iostream.h>

#include <string.h>

class computer_screen

{ 
public:
   computer_screen(char *, long, int, int);
   void show_screen(void);
private:
   char type[32];
   long colors;
   int x_resolution;
   int y_resolution;
};

computer_screen::computer_screen(char *type, long colors, int x_res, int y_ree)

{
   strcpy(computer_screen::type, type);
   computer_screen::colors = colors;
   computer_screen::x_resolution = x_res;
   computer_screen::y_resolution = y_res;
}

void computer_screen::show_screen(void)

{
   cout << "Тип экрана: " << type << endl;
   cout << "Цветов: " << colors << endl;
   cout << "Разрешение: " << x_resolution << " на " << y_resolution << endl;
}

class mother_board

{
public:
   mother_board(int, int, int);
   void show_mother_board(void);
private:
   int processor;
   int speed;
   int RAM;
};

mother_board::mother_board(int processor, int speed, int RAM)

{
   mother_board::processor = processor;
   mother_board::speed = speed;
   mother_board::RAM = ram;
}

void mother_board::show_mother_board(void)

{
   cout << "Процессор: " << processor << endl;
   cout << "Частота: " << speed << "МГц" << endl;
   cout << "ОЗУ: " << RAM << " МВайт" << endl;
}

class computer : public computer_screen, public mother_board

{
public:
   computer(char *, int, float, char *, long, int, int, int, int, int);
   void show_computerf void);
private:
   char name [64];
   int hard_disk;
   float floppy;
};

computer::computer(char *name, int hard_disk, float floppy, char *screen, long colors, int x_res, int y_res, int processor, int speed, int RAM) : computer_screen(screen, colors, x_res, y_res), mother_board(processor, speed, ram)

{
   strcpy(computer::name, name);
   computer::hard_disk = hard_disk;
   computer::floppy = floppy;
}

void computer::show_computer(void)

{
   cout << "Тип: " << name << endl;
   cout << "Жесткий диск: " << hard_disk << "МВайт" << endl;
   cout << "Гибкий диск: " << floppy << "МВайт" << endl;
   show_mother_board();
   show_screen();
}

void main(void)

{
   computer my_pc("Compaq", 212, 1.44, "SVGA", 16000000, 640, 480, 486, 66, 8);
   my_pc.show_computer();
}