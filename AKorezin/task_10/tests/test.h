#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject
{
	Q_OBJECT
public:
	Test();
private slots:
	void fill_data();
	void fill();


};

#endif // TEST_H
