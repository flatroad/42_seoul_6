#include <iostream>

class Base
{
	private :
		int a_;
	public :
		void basePrint()
		{
			std::cout << "Base " << this->a_ << std::endl;
		}
		void setA(int num)
		{
			a_ = num;
		}
};

class Derived : public Base
{
		private :
			int b_;
	public :
		void derivedPrint()
		{
			std::cout << "Derived " << this->b_ << std::endl;
		}
		void setB(int num)
		{
			b_ = num;
		}
};

int main()
{
	Derived * dptr = new Derived();
	dptr->setB(1);
	dptr->setA(2);
	Base * bptr = dptr;
	bptr->basePrint();
	dptr->basePrint();
	dptr->derivedPrint();
	bptr->setA(3);
	dptr->basePrint();
	bptr->basePrint();
	bptr->setA(4);
	dptr->basePrint();
	bptr->basePrint();

	delete bptr;
}
