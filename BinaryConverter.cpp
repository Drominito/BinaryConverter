#include <iostream>
#include <string>
#include <cstdint>
#include <math.h>
#include <thread>

void GoodByeText(std::string& Text);
std::string ArrayToString(int* Array, int& len);
int* ConvertNumber(int decimal);
int ConvertNumber2(std::string BinaryInput);

int main()
{
	bool CloseProgram = false;

	std::cout << "Hello :D\nThis is an Program that converts for you integer Values in to binary ( so bits!)"
		"\nPress Enter to enter. xD";


	while (!CloseProgram)
	{
		std::cin.get();

		std::system("cls");
		std::cout << "What do you want?\n";
		std::cout << "(1) Binary  -> Decimal\n";
		std::cout << "(2) Decimal -> Binary\n";
		std::cout << "(3) Exit, lol :/\n";


		char MenuInput;
		std::cin >> MenuInput;

		switch (MenuInput)
		{
			case '1':
			{
				std::system("cls");
				std::cout << "Writer your binary number::\n";

				std::string BinaryInput;
				std::cin >> BinaryInput;
				int* len = new int(0);


				int Decimal = ConvertNumber2(BinaryInput);

				std::cout << Decimal;

				std::cin.get();

				break;
			}
			case '2':
			{
				std::system("cls");
				std::cout << "Writer your number what do you want to convert to:\n";

				int* len = new int(0);

				int Input;
				std::cin >> Input;

				int* BinaryArray = ConvertNumber(Input);

				std::string Text = ArrayToString(BinaryArray, *len);
				for (int i = 0; i < *len; i++)
				{
					if (Text[i] == '\0')
					{
						std::cout << "0";
					}
					else
					{
						std::cout << "1";
					}
				}

				std::cin.get();

				break;
			}
			case '3':
			{
				std::system("cls");
				std::string Text = "Bye Bye :D!";
				GoodByeText(Text);

				CloseProgram = true;

				break;
			}

			default:
			{

			}

		}
	}



	return 0;

}

void GoodByeText(std::string &Text)
{
	const int len = Text.length();
	for (int j = 0; j < len; j++)
	{
		for (int i = 0; i < len - j; i++)
		{
			std::cout << Text[i];
		}
		if (j == 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
		std::this_thread::sleep_for(std::chrono::microseconds(500));
		std::system("cls");
	}
}

std::string ArrayToString(int* Array, int& len)
{
	int TempI = 0;
	char TestValue = 0;

	while (Array[TempI] == 0 || Array[TempI] == 1)
	{

		len = ++TempI;
	}

	std::string* Text = new std::string[len];

	for (int i = 0; i < len; i++)
	{
		*Text += Array[i];
		TestValue = Array[i];
	}

	return *Text;
}

int* ConvertNumber(int decimal)
{
	double size_double = log2(decimal);
	int size = static_cast<int>(size_double);
	if (size_double > size)
	{
		size++;
	}
	size += 1; // Because the 0 also counts
	int CurrentValue = decimal;

	int* ResultArray = new int[size];

	int j = 0;

	for (int i = size; i > 0; --i)
	{
		int SeperatePartResult = CurrentValue % 2; // Using the variable to seperate steps to see the values.
		ResultArray[size - j - 1] = SeperatePartResult;
		CurrentValue /= 2;
		j++;
	}

	return ResultArray;
}

int ConvertNumber2(std::string Binary)
{
	int len = 0; // 0=>(-1) counts also
	int len_index = 0;

	while (Binary[len_index] != '\0')
	{
		len = ++len_index;

	}
	int value = 0;

	for (int i = 0; i < len; i++)
	{
		int CurrentIndex = (len - 1) - i;
		if (Binary[CurrentIndex] == '1')
		{
			value += pow(2, i);
		}
	}


	return value;
}