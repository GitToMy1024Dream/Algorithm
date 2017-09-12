#include <iostream>
using namespace std;

int main()
{
	float H = 0, h = 0, x = 0, y = 0, s = 0;
	int t = 0;
	cin >> H >> x >> y >> h >> s;
	float time = h / x;
	float result = 0;
	if (y >= x) {
		if (s >= time) {
			result = h;
		}
		else {
			result = s*x;
		}
	}
	else {
		if (s >= time)
		{
			result = (s - time)*(x - y) + h;
			if (result>H) {
				result = H;
			}

		}
		else {
			result = s*x;
		}

	}
	int res = round(result);
	cout << res<<endl;
	system("pause");
	return 0;
}