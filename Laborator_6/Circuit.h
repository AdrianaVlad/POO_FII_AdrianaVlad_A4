
#include "Car.h"
#include "Weather.h"
class Circuit
{
	Car** v;
	int n, nmax, w, l;
public: 
	Circuit();
	void SetLength(int L);
	void SetWeather(Weather vreme);
	bool AddCar(Car* masina);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

