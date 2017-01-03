/*!
 * \file 
 * \brief  ascii.cpp
 *
 * \date   Feb 12, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string>& split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

vector<string> merge(const vector<string>& a, const vector<string>& b)
{
	vector<string> ab;
	ab.reserve(a.size() + b.size());
	ab.insert(ab.end(), a.begin(), a.end());
	ab.insert(ab.end(), b.begin(), b.end());
	return ab;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int L;
		cin >> L;
		vector<int> checks(L);

		char buffer[1024];
		cin.getline(buffer, 1024);

		string str;

		for (int j = 0; j < L; j++) {
			cin.getline(buffer, 1024);
			string line(buffer, cin.gcount() - 1);
			checks[j] = split(line, ' ').size();
			//cout << "counted " << checks[j] << " words: " << line << endl;
			str += " " + line;
		}

		vector<string> text = split(str, ' ');

		int commands;
		cin >> commands;

		for (int j = 0; j < commands; j++) {
			int encounters;
			string word;
			cin >> encounters >> word;

			int count = 0;
			for (vector<string>::iterator it = text.begin(); it != text.end(); it++) {
				string& current = *it;
				if (word == current)
					if (encounters == ++count) {
						current = "";
						count = 0;
					}
			}
		}

		int wordcount = 0;
		int linecount = 0;

		for (vector<string>::iterator it = text.begin(); it != text.end(); it++) {

			string current = *it;
			cout << current;

			bool newline = (++wordcount == checks[linecount] + 1);

			if (it != text.begin() && it != text.end() - 1 && *(it+1) != "" && !(newline))
				cout << " ";

			if (newline) {
				wordcount = 0;
				linecount++;
				cout << endl;
			}

		}
	}
}


