#pragma once
template <typename T1, typename T2>
class Elem
{
public:
	T1 key;
	T2 value;
	void operator = (T2 cuv)
	{
		value = cuv;
	}
	void operator = (Elem x)
	{
		key = x.key;
		value = x.value;
	}
};

