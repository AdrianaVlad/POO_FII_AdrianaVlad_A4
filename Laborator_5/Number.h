class Number
{
	int baza;
	char* val;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int n);
	Number(const char* n);
	~Number();
	Number(const Number& n);
	Number(Number && n);
	// add operators
	friend Number operator+(const Number& a, const Number& b);
	friend Number operator-(const Number& a, const Number& b);
	void operator--();
	void operator--(int n);
	char operator[](int i);
	bool operator=(const Number& n);
	bool operator=(int n);
	bool operator=(const char* n);
	bool operator+=(const Number& n);
	bool operator-=(const Number& n);
	bool operator>(Number n);
	bool operator<(Number n);
	bool operator>=(Number n);
	bool operator<=(Number n);
	bool operator==(Number n);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};