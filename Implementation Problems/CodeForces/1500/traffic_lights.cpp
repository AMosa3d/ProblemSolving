#include<iostream>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<fstream>
#include<algorithm>
#include<math.h>
#include<regex>
#include <iomanip>
 
#define ll long long
 
using namespace std;
 
int main() {
 
	//Input Section
	int  l, d, v, g, r; cin>>l>>d>>v>>g>>r;
	//Solving Section
    float time_to_reach_d = float(d) / v;
	int div = time_to_reach_d / (g+r);
	float diff = time_to_reach_d - div*(g+r);
 
    //Output Section
    if(diff - g >= 0) {
        cout << fixed << setprecision(8) <<((float) (l - d) / v) + (div+1) * (g+r) << "\n";
    } else
        cout << fixed << setprecision(8) << (float) l / v << "\n";
 
	return 0;
}
