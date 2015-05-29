
#include <QDebug>

#include "game.h"

int main(int argc, char *argv[])
{
   qDebug() <<"Hello World"<< endl;

   Game game;

   game.init();
   game.run();
   game.cleanup();

   return 0;
}
