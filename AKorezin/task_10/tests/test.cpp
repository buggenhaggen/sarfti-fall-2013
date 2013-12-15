#include <QTest>
#include "test.h"
#include "wall.h"
#include <iostream>
using namespace std;
Test::Test()
{
}

void Test::fill_data()
{
	int *results = new int[2];
	results[0]=17;
	results[1]=10;
	QTest::addColumn<int>("exec");
	QTest::addColumn<int>("result");
	Wall a;
	int i=0;
	while(a.fill("array")==1)
	{
		a.startSet();
		QTest::newRow(QString::number(i).toUtf8().data()) <<a.waterFill()<< results[i];
		i++;
	}
	delete results;
}

void Test::fill()
{
	QFETCH(int, exec);
	QFETCH(int, result);
	QCOMPARE(exec,result);
}
