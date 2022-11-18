#include <iostream>
#include <string>
#include <random>
#include <windows.h>
#include <conio.h>

const char lowCase[] = "abcdefghijklmnopqrstuvwxyz";
const char upCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digitalCase[] = "1234567890";
const char specialCase[] = "!@#$%^&*_-=+";
using namespace std;
class PasswordGeneration
{
public:

	PasswordGeneration(int quantitySymbols) {
		if (quantitySymbols <= 0) {
			return;
		}
		this->quantitySymbols = quantitySymbols;
	}
	PasswordGeneration(int  quantitySymbols = 8, bool useLowCase = true, bool useUpCase = true, bool useSpecialCase = true, bool useDigitalCase = true) {
		this->useLowCase = useLowCase;
		this->useUpCase = useUpCase;
		this->useSpecialCase = useSpecialCase;
		this->useDigitalCase = useDigitalCase;
		this->quantitySymbols = quantitySymbols;
	}

	std::string Generate() {
		std::string password = "";
		std::string charsString = GetResaultString();
		srand(time(NULL));
		for (int i = 0; i < quantitySymbols; i++) {
			int rnd = rand() % charsString.length() - 1;
			password += charsString[rnd];
		}
		return password;
	}

private:
	int  quantitySymbols = 8;
	bool useLowCase = true;
	bool useUpCase = true;
	bool useSpecialCase = true;
	bool useDigitalCase = true;

	std::string GetResaultString() {
		std::string resaultStr = "";
		if (this->useLowCase)
			resaultStr += lowCase;
		if (this->useUpCase)
			resaultStr += upCase;
		if (this->useSpecialCase)
			resaultStr += specialCase;
		if (this->useDigitalCase)
			resaultStr += digitalCase;
		return resaultStr;
	}
};

int main() {
	while (true) {
		if (_getch() == 13) {
			PasswordGeneration pass;
			std::cout << pass.Generate() << std::endl;
			Sleep(1000);
		}
	}

}
