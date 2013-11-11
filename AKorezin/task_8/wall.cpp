#include "wall.h"
#include <iostream>
#include "QStringList"
#include "QFile"
#include "QDir"
using namespace std;

Wall::Wall()
{
	opened=0;
	error=0;
}

int Wall::getErr()
{
return error;
}

int Wall::fill(QString filename)
{
	walllist.clear();
	if (!opened)
	{
		file.setFileName(filename);
		if (!file.exists())
		{
			cerr<<"file not found"<<endl;
			error=1;
			return 0;
		}

		file.open(QIODevice::ReadOnly);
		opened=1;
	}

	if (file.atEnd())
	{
		file.close();
		return 2;
	}

	QString wall = QString(file.readLine(1000));
	QStringList list=wall.split(", ");
	for (int i=0;i<list.size();i++)
		walllist<<list.at(i).toInt();

		return 1;
}

void Wall::startSet(void)
{
	Left.setPostion(0);
	Right.setPostion(walllist.size()-1);
}

int Wall::waterFill(void)
{
	int vol=0;
	Left.setMax(0);
	Right.setMax(0);
	while(Left.getPosition()<Right.getPosition())
	{
		if(walllist.at(Left.getPosition()) > Left.getMax())
			Left.setMax(walllist.at(Left.getPosition()));
		if(walllist.at(Right.getPosition()) > Right.getMax())
			Right.setMax(walllist.at(Right.getPosition()));
		if(Left.getMax() > Right.getMax())
		{
			vol+=Right.getMax()-walllist.at(Right.getPosition());
			Right.movePos();
		}
		else
		{
			vol+=Left.getMax()-walllist.at(Left.getPosition());
			Left.movePos();
		}

	}
	cout<<vol<<endl;
	return vol;
}
