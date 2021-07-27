#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int n;
vector<int> ipAddress;

int makeSubnetmask() {
	int subnetmask = 0;

	for (int i = 31; i >= 0; i--) {
		int ithBit = 1 << i;
		bool diffFlag = false;

		for (int j = 1; j < n; j++) {
			if ((ipAddress[0] & ithBit) != (ipAddress[j] & ithBit)) {
				diffFlag = true;
				break;
			}
		}

		if (diffFlag) {
			break;
		}

		subnetmask = (subnetmask | ithBit);
	}

	return subnetmask;
}

void printIP(int address) {
	for (int i = 0; i < 4; i++) {
		cout << ((address >> (24 - 8 * i)) & (1 << 8) - 1);

		if (i != 3) {
			cout << ".";
		}
	}
	
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;
	ipAddress.resize(n);

	for (int i = 0; i < n; i++) {
		string ip; cin >> ip;
		string stringBuffer;
		istringstream stringStream(ip);

		while (getline(stringStream, stringBuffer, '.')) {
			ipAddress[i] = (ipAddress[i] << 8);
			ipAddress[i] = (ipAddress[i] | stoi(stringBuffer));
		}
	}

	int subnetmask = makeSubnetmask();
	int networkIP = subnetmask & ipAddress[0];

	printIP(networkIP);
	printIP(subnetmask);

	return 0;
}