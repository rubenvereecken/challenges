/*!
 * \file 
 * \brief  gelukkig.cpp
 *
 * \date   Feb 12, 2013
 * \author Ruben Vereecken
 */


#include <iostream>
#include <stack>
#include <set>

using namespace std;

stack<int> digify(int n)
{
	 stack<int> digits;
	 while(n > 0)
	 {
		digits.push(n % 10);
		n = n / 10;
	 }
	 return digits;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		int number = num;
		set<int> history;

		do {
			history.insert(number);
			stack<int> digits = digify(number);
			int newnum = 0;
			while(!digits.empty()) {
				int digit = digits.top();
				digits.pop();
				newnum += digit * digit;
			}
			number = newnum;
		} while (history.count(number) == 0 && number != 1);

		if (number == 1)
			cout << "JA" << endl;
		else
			cout << "NEE" << endl;
	}

}

