#include <iostream>

class a
{
	private :
		int a_;
	public :
		a():a_(1){};
		void getA()
		{
			std::cout << this->a_ << std::endl;
		}
};

class b : private a
{
	private :
		int b_;
	public :
		b():a(),b_(2){};
		void getB()
		{
			std::cout << this->b_ << std::endl;
		}
		void getgetB()
		{
			getA();
		}
};

int main()
{
	a c1;
	b c2;

	c1.getA();
	c2.getB();
	c2.getgetB();

}