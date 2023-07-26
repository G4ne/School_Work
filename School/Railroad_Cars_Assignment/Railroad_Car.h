#ifndef RAILROAD_CAR_H
#define RAILROAD_CAR_H

class Railroad_Car {
public:

	//Getter
	double get_length() const;

	//Setter
	void set_length(double);

	//Class-member Function
	virtual double volume() = 0;

protected:

	//Data Fields
	double length;

};

#endif