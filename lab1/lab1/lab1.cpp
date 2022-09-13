#include <iostream>
#include <time.h>

const int LENGTH_OF_STRING = 1000;
const int START_OF_ALPHABET = 97;
const int END_OF_ALPHABET = 122;

std::string generateString();

int main()
{
    setlocale(LC_ALL, "rus");

	std::string str = generateString();
	
	std::cout << str << std::endl;

	int iterations = 0;
	int all_itearions = 0;
	int max_iterations = 0;
	for (int i = 0; i < LENGTH_OF_STRING; i++) {
		for (int j = START_OF_ALPHABET; j <= END_OF_ALPHABET; j++) {
			iterations++;
			all_itearions++;

			if (str[i] == (char)j) {
				if (max_iterations < iterations) {
					max_iterations = iterations;
					iterations = 0;
				}
				break;
			}
		}
		iterations = 0;
	}

	std::cout << "Всего итераций: " << all_itearions << std::endl;
	std::cout << "Максимальное количество попыток угадать один символ: " << max_iterations << std::endl;
}

/*
 * Создание строки из маленьких букв английского алфавита
 *
 * @return возвращает строку длиной LENGTH_OF_STRING, состоящую из маленьких букв английского алфвита
 */
std::string generateString() {
	srand(time(0));
	std::string result = "";
	for (int i = 0; i < LENGTH_OF_STRING; i++)
	{
		result += (char)(START_OF_ALPHABET + rand() % (END_OF_ALPHABET - START_OF_ALPHABET + 1));
	}
	return result;
}
