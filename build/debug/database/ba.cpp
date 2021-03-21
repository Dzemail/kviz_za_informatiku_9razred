#include<iostream>
#include<algorithm>
#include<random>
#include<list>
#include<vector>
#include<chrono>
#include <fstream>
using namespace std;
 
mt19937 gen( chrono::system_clock::now().time_since_epoch().count() );

//============================



//============================

template <class T > void listShuffle( vector<T> &L )
{
   vector<T> V( L.begin(), L.end() );
   shuffle( V.begin(), V.end(), gen );
   L.assign( V.begin(), V.end() );
}

//============================

int main()
{
  vector<int> lat;
for(int i = 1;i<=100;i++){
	ofstream object(to_string(i) + ".dat",ios::app);
	object.close();
  
   
   

}
}