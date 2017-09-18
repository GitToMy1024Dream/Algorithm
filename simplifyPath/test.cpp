#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

//class Solution {
//public:
//	string simplifyPath(string test) {
//		string path = test + "/";
//
//		vector<string> temp_result;
//		string result = "/";
//		int j = 0;
//		string temp;
//		for (int i = 0; i<path.size(); ++i) {
//			if (path[i] == '/') {
//				temp = path.substr(j, i - j);
//				j = i + 1;
//				if (temp.size()>0) {
//					if (temp == "..") { if (!temp_result.empty())temp_result.pop_back(); }
//					else if (temp == ".") {}
//					else { temp_result.push_back(temp); }
//				}
//			}
//		}
//		for (int i = 0; i < temp_result.size(); ++i)result += (i == 0) ? temp_result[i] : ("/" + temp_result[i]);
//		return result;
//	}
//};

class Solution {
public:
	string simplifyPath(string path) {
		if (path.empty())return "";
		stack<string> paths;
		int index = 0;
		int size = path.size();
		while (index < size) {
			switch (path[index]) {
			case '/':index++; break;
			case '.': {
				if (index < size - 1 && path[index + 1] == '.') {
					if (index == size - 2 || (index < size - 2 && path[index + 2] == '/')) {
						index += 2;
						if (!paths.empty())paths.pop();
					}
					else {
						string tmp;
						while (index < size && path[index] != '/') {
							tmp.push_back(path[index]);
							index++;
						}
						paths.push(tmp);
					}
				}
				else if (index == size - 1 || (index < size - 1 && path[index + 1] == '/')) {
					index++;
				}
				else {
					string tmp;
					while (index < size && path[index] != '/') {
						tmp.push_back(path[index]);
						index++;
					}
					paths.push(tmp);
				}
				break;
			}
			default: {
				string tmp;
				while (index < size && path[index] != '/') {
					tmp.push_back(path[index]);
					index++;
				}
				paths.push(tmp);
				break;
			}
			}
		}
		string result = "";
		string temp;
		while (!paths.empty()) {
			result = "/" + paths.top() + result;
			paths.pop();
		}
		return (result == "") ? "/" : result;
	}
};

int main()
{
	Solution s;
	char str[64] = { 0 };
	cin >> str;
	string ret = s.simplifyPath(str);
	cout << ret << endl;
	system("pause");
	return 0;
}