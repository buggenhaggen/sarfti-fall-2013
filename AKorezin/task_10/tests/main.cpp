#include <QApplication>
#include <QTest>
#include "wall.h"
#include <iostream>
#include "test.h"
using namespace std;


int main(int argc, char *argv[])
{
	QTest::qExec(new Test, argc,argv);
	return 0;

}
