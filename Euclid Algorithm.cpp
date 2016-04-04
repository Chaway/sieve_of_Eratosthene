//Euclid Algorithm
#include <iostream>
using namespace std;
int main()
{
	int a,b,temp;
	cin >> a >> b;
	if (a < b)
	{
       temp = b;
       b = a;
       a = temp; 
	}
    
	while((temp = a%b) != 0)
	{
        a = b;
        b = temp;  
	}
	cout << b << endl;
	return 0;
}
