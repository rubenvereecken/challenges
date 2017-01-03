/*!
 * \file 
 * \brief  ptaal.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
using namespace std;

bool isVowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'y' || c == 'u' ||
		   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'Y' || c == 'U';
}

int main()
{
	int n;
	cin >> n;

	char testbuff[3];
	cin.getline(testbuff, 3);

	for (int i = 0; i < n; i++) {
		char buffer[1000];
		cin.getline(buffer, 1000);

		//for (int i = 0; i < 1000; i++)
			//cout << "char at " << i+1 << ": (ascii)" << (int) (buffer[i]) << " -> "<< buffer[i] << endl;

		int sentencesize = cin.gcount() - 1;

		string purged;

		for (int i = 0; i < sentencesize; i++) {
			char c = buffer[i];
			//cout << "char: " << c << endl;
			if (c == '\n' || c == '\0')
				continue;
			if (!isVowel(c))
				purged += c;
			else {
				// case 'ij'
				string sofar;
				if ((c == 'i' || c == 'I') && i < 999 && buffer[i + 1] == 'j') {
					sofar += "ij";
					++i;
					while (i + 1 < 1000 && isVowel(buffer[i + 1])) {
						sofar += buffer[i + 1];
						++i;
					}
					if (i + 1 < 1000 && buffer[i + 1] == 'p')
						i += sofar.size() + 1;
				}
				else {
					sofar += c;
					while (i + 1 < 1000 && isVowel(buffer[i + 1])) {
						sofar += buffer[i + 1];
						++i;
					}
					if (i + 1 < 1000 && buffer[i + 1] == 'p')
						i += sofar.size() + 1;
				}
				purged += sofar;
			}
		}

		cout << purged << endl;
	}
}


