#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {

	int j = 0, k = 0, i = 0, s = 0, c = 0;

	ifstream codes("codes.txt");

	string temp = "";

	string res = "";

	string data = "-";

	int size = 0;

	while (!codes.eof())
	{
		getline(codes, data);

		size++;
	}

	codes.close();

	size = (size - 1) / 2;

	//reading the codes and storing them in an array

	string* chrs = new string[size];

	string* cds = new string[size];

	codes.open("codes.txt");

	for (int i = 0; i < (size * 2); i++)
	{
		getline(codes, data);

		if (i % 2 == 0)
		{
			cds[j] = data;

			j++;
		}
		else
		{
			chrs[k] = data;

			k++;
		}
	}

	codes.close();

	for (int i = 0; i < size; i++)
	{
		cout << "The code for " << chrs[i] << " is " << cds[i] << endl;
	}

	//reading the encoded text

	ifstream text("encoded.txt");

	getline(text, data);

	cout << "The code recieved is " << data << endl;

	//decoding the text

	while (data[i] != '\0')
	{
		if (data[i] == '0')
		{
			res = res + chrs[0];

			i++;
		}
		else
		{
			for (int m = 1; m < size; m++)
			{
				temp = cds[m];

				while (temp[s] != '\0')
				{
					s++;
				}

				for (int n = 0; n < s; n++)
				{
					if (data[i + n] == temp[n])
					{
						c++;
					}

					if (c == s)
					{
						res = res + chrs[m];

						i = i + s;

						break;
					}
				}
				c = 0;
				s = 0;
			}
		}
	}

	cout << "The decoded string is : " << res << endl;

	//writing the decoded text on a file

	ofstream final("decoded.txt");

	final << res << endl;

	return 0;
}