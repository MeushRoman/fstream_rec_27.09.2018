#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

ifstream in_file("in.txt");
ofstream out_file("out.txt");

ifstream in1_file("in1.txt");
ifstream in2_file("in2.txt");

//запись файла в обратном порядке с использованием рекурсии используя строки
void file_reverse_write() {
	char str[200];
	if (in_file.eof()) return;
	in_file.getline(str, 200);
	file_reverse_write();
	out_file << str << endl;

}

//запись в файл в обоатном порядке с использованием рекурсии по символу
void file_read() {

	char c;

	while (!in_file.eof()) {
		in_file.get(c);

		if (in_file.eof()) return; //удаление последнего ненужного елемента
		file_read();
		out_file << c;
	}

}

// 7.	Дан текстовый файл. Добавить в него строку из двенадцати черточек (------------), поместив ее после последней из строк, в которых нет пробела. Если таких строк нет, то новая строка должна быть добавлена после всех строк имеющегося файла. Результат записать в другой файл.
void file() {

	int x = 0;
	int k = 0;
	int l = 0;
	char str[100];

	while (!in_file.eof())
	{
		in_file.getline(str, 100);

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] != ' ') {
				x = 1;
			}
			else {
				x = 0;
				break;
			}
		}

		if (x == 1) {
			k++;
		}
	}
	in_file.seekg(0);


	while (!in_file.eof())
	{
		in_file.getline(str, 100);
		out_file << str << endl;

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] != ' ') {
				x = 1;
			}
			else {
				x = 0;
				break;
			}
		}

		if (x == 1) {
			l++;
			if (l == k) out_file << "--------" << endl;
		}
	}
	if (k == 0)  out_file << "--------" << endl;
}

//8.	Дано два текстовых файла. Выяснить, совпадают ли их строки. Если нет, то вывести несовпадающую строку из каждого файла.

void check_files() {

	char str1[500];
	char str2[500];
	int x = 0;

	while (!in1_file.eof(), !in2_file.eof())
	{
		in1_file.getline(str1, 500);
		in2_file.getline(str2, 500);

		for (int i = 0, j = 0; (str1[i] != '\0'), str2[j] != '\0'; i++, j++)
		{

			if (str1[i] == str2[j]) x = 0;
			else {
				x = 1;
				break;
			}

		}

		if (x == 1) cout << str1 << "\t" << str2 << endl;
	}


}

//


int main() {
	setlocale(LC_ALL, "rus");

	//file_reverse_write();

	//file_read();

	//file();
	
	//check_files();



	system("pause");

	return 0;
}