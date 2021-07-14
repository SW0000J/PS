#include <iostream>
#include <string>
using namespace std;

int main() {
	string ucpc;
	bool flag[4] = { false };

	getline(cin, ucpc);

	for (int i = 0; i < ucpc.size(); i++) {
		if (ucpc[i] == 'U') {
			flag[0] = true;
		}

		if (ucpc[i] == 'C') {
			if (flag[0]) {
				flag[1] = true;
			}

			if (flag[2]) {
				flag[3] = true;
				break;
			}
		}

		if (ucpc[i] == 'P') {
			if (flag[1]) {
				flag[2] = true;
			}
		}
	}

	if (flag[3]) { 
		cout << "I love UCPC\n"; 
	}
	else { 
		cout << "I hate UCPC\n"; 
	}

	return 0;
}