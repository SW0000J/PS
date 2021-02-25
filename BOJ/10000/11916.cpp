#include <iostream>
#include <algorithm>

bool base[4];
int loss = 0;
int ballcount = 0;

void moveBase(int num) {
	if (num == 1) {
		if (base[3] && base[2] && base[1]) {
			loss++;
			//std::cout << "����!\n";
		}
		else if (base[2] && base[1]) {
			base[3] = true;
		}
		else if (base[1]) {
			base[2] = true;
		}
		else {
			base[1] = true;
		}
		//std::cout << "��ī��Ʈ: " <<ballcount << " 1��: " << base[1] << " 2��: " << base[2] << " 3��: " << base[3] << "\n";
	}
	else if (num == 2) {
		for (int i = 3; i > 0; i--) {
			if (i == 3 && base[i]) {
				base[i] = false;
				loss++;
				//std::cout << "����!\n";
			}
			else if (base[i]) {
				base[i] = false;
				base[i + 1] = true;
			}
		}
		//std::cout << "��ī��Ʈ: " << ballcount << " 1��: " << base[1] << " 2��: " << base[2] << " 3��: " << base[3] << "\n";
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;

	for (int tc = 0; tc < N; tc++) {
		int num; std::cin >> num;

		ballcount++;

		if (num == 1 && ballcount == 4) {
			ballcount = 0;
			moveBase(1);
		}
		else if (num == 2) {
			ballcount = 0;
			moveBase(1);
		}
		else if (num == 3 && ballcount == 4) {
			ballcount = 0;
			moveBase(2);
			base[1] = true;
		}
		else if (num == 1) {
			//std::cout << "��ī��Ʈ: " << ballcount << " 1��: " << base[1] << " 2��: " << base[2] << " 3��: " << base[3] << "\n";
			continue;
		}
		else {
			moveBase(2);
		}
	}

	std::cout << loss << "\n";

	return 0;
}