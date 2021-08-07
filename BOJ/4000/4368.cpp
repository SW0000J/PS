#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	map<string, int> treeMap;

	string stringBuffer;
	int stringCount = 0;

	while (getline(cin, stringBuffer)) {
		treeMap[stringBuffer]++;
		stringCount++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto iter = treeMap.begin(); iter != treeMap.end(); iter++) {
		cout << iter->first << " " << iter->second * 100.0 / stringCount << "\n";
	}

	return 0;
}