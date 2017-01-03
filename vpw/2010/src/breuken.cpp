/*!
 * \file 
 * \brief  breuken.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void bubbleSort (vector<T>& vec)
{
	int n = vec.size() - 1;
	bool changed = true;

	while (changed) {
		changed = false;
		for (int i = 0; i < n; i++) {
			if (!(vec[i] < vec[i + 1])) {
				changed = true;
				T temp = vec[i + 1];
				vec[i + 1] = vec[i];
				vec[i] = temp;
			}
		}
		--n;
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string numstr, denomstr;
		vector<char> numvec, denomvec;
		cin >> numstr >> denomstr;

		for (string::const_iterator ch = numstr.begin(); ch != numstr.end(); ch++)
			numvec.push_back(*ch);
		for (string::const_iterator ch = denomstr.begin(); ch != denomstr.end(); ch++)
			denomvec.push_back(*ch);


		for (vector<char>::iterator itn = numvec.begin(); itn != numvec.end(); itn++) {
			char symbol = *itn;
			bool found = false;
			for (vector<char>::iterator itd = denomvec.begin(); itd != denomvec.end(); itd++) {
				char desymbol = *itd;
				if (symbol == desymbol) {
					found = true;
					*itd = 0;
					break;
				}
			}
			if (found)
				*itn = 0;
		}

		bubbleSort(numvec);
		bubbleSort(denomvec);

		string numresult, denomresult;
		for (vector<char>::iterator itn = numvec.begin(); itn != numvec.end(); itn++)
			if (*itn)
				numresult += *itn;
		for (vector<char>::iterator itd = denomvec.begin(); itd != denomvec.end(); itd++)
			if (*itd)
				denomresult += *itd;

		if (!numresult.size())
			cout << 1;
		else
			cout << numresult;
		cout << ' ';

		if (!denomresult.size())
			cout << 1;
		else
			cout << denomresult;
		cout << endl;
	}
}


