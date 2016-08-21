#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>

using namespace std;

#define MODULE 1000000007
#define MP make_pair


typedef pair<int, int> P;
typedef long long LL;
const int MAXWH = 1000;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

//-----Template---------
int w, h;
int main()
{
	std::cin >> w>>h;
	int sho = w / 4;
	if(h/sho==3)
	{
		std::cout << "4:3" << endl;;
	}else
	{
		std::cout << "16:9" << endl;
	}
	return 0;
}