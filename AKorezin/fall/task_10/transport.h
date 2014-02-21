#ifndef TRANSPORT_H
#define TRANSPORT_H

class Transport
{
protected:
	int position;
	int max;
public:
	Transport();
	void setPostion(int);
	int getPosition(void);
	virtual void movePos(void){};
	void setMax(int);
	int getMax(void);

};

#endif // TRANSPORT_H
