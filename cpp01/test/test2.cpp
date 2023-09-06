#include<iostream>
#include<cstring>
using namespace std;
class CopyConstructor
{
    char *s_copy;
    public:
    CopyConstructor(const char *str)
    {
        s_copy = new char[16]; //Dynamic memory allocation
        strcpy(s_copy, str);
    }
	CopyConstructor(const CopyConstructor& rhs)
    {
        s_copy = new char[16]; //Dynamic memory allocation
        strcpy(s_copy, rhs.s_copy);
    }
	//CopyConstructor& operator=(const CopyConstructor& rhs)
    //{
	//	cout << "assignment oper\n";
    //	CopyConstructor temp(rhs);
    //	swap(temp.s_copy, s_copy);
      //  return *this;
    //}
    /* concatenate method */
    void concatenate(const char *str)
    {
        strcat(s_copy, str); //Concatenating two strings
    }
    /* copy destructor */
    ~CopyConstructor ()
    { 
        delete [] s_copy;
    }
    void display()
    {
        cout<<s_copy<<endl;
    }
};
/* main function */
int main()
{
    CopyConstructor c1("Copy");
    CopyConstructor c2 = c1; //Copy constructor
	CopyConstructor c3(c1);
    c1.display();
    c2.display();
	c3.display();
    c1.concatenate("Constructor");    //c1 is invoking concatenate()
    c1.display();
    c2.display();
	c3.display();
    return 0;
}
