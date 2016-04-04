#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int MaxN;
	cin >> MaxN;
	cout << "MaxN = " << MaxN << endl;
	int primelength = (MaxN - 1) / 2;  
	//cout << primelength << endl;
  /*
	for example:when MaxN = 99 , imax = 48 , length = 49;
	            when MaxN = 100 , imax = 48 , length = 49;
  */
    bool isNotprime[primelength] = {0};  //3,5,7,9,11,...,
    int iMax = (int)((sqrt(MaxN) - 3)/2);

    for (int i = 0; i <= iMax ; ++i)
    {
      if(!isNotprime[i])
      for (int j = 2*i*i + 6*i + 3; j <= primelength ; j += 2*i + 3)
       {
       //	cout << j << endl;
    	isNotprime[j] = 1;
       }
    }

    for (int i = 0; i < primelength; ++i)
		if(!isNotprime[i])
		 cout << 2*i + 3 << endl;
	return 0;
  
}