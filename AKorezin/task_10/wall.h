#ifndef WALL_H
#define WALL_H

#include "QList"
#include "QRegExp"
#include "QFile"
#include "QDir"
#include "transportleft.h"
#include "transportright.h"

class Wall
{
private:
	TransportLeft Left;
	TransportRight Right;
	QList <int> walllist;
	QFile file;
	int opened;
	int error;

public:
	Wall();
	int fill(QString);
	void startSet(void);
	int waterFill(void);
	int getErr(void);

};

#endif // WALL_H
