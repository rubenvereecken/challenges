/*!
 * \file 
 * \brief  bloed.cpp
 *
 * \date   Feb 12, 2013
 * \author Ruben Vereecken
 */


#include <iostream>
#include <set>
#include <map>

using namespace std;

enum blood {
	A, B, AB, O
};

set<blood> generateAllel(blood a)
{
	set<blood> allels;
	switch(a) {
	case A:
	{
		allels.insert(A);
		allels.insert(O);
		break;
	}
	case B:
	{
		allels.insert(B);
		allels.insert(O);
		break;
	}
	case AB:
	{
		allels.insert(A);
		allels.insert(B);
		break;
	}
	case O:
	{
		allels.insert(O);
		break;
	}
	}

	return allels;
}

set<blood> mixParents(set<blood> a, set<blood> b)
{
	set<blood> result;

	for (set<blood>::iterator it1 = a.begin(); it1 != a.end(); it1++) {
		blood p1 = *it1;
		for (set<blood>::iterator it2 = b.begin(); it2 != b.end(); it2++) {
			blood p2 = *it2;
			switch (p1) {
			case A:
			{
				switch (p2) {
				case A:
					result.insert(A);
					break;
				case B:
					result.insert(AB);
					break;
				case O:
					result.insert(A);
					break;
				}
				break;
			}
			case B:
			{
				switch (p2) {
				case A:
					result.insert(AB);
					break;
				case B:
					result.insert(B);
					break;
				case O:
					result.insert(B);
					break;
				}
				break;
			}
			case O:
			{
				switch (p2) {
				case A:
					result.insert(A);
					break;
				case B:
					result.insert(B);
					break;
				case O:
					result.insert(O);
					break;
				}
				break;
			}
			}
		}
	}
	return result;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string parent1, parent2, child;
		cin >> parent1 >> parent2 >> child;

		if (child == "?") {
			blood p1, p2;
			bool r1, r2;

			if (parent1[0] == 'O')
				p1 = O;
			else if (parent1[0] == 'A' && parent1[1] == 'B')
				p1 = AB;
			else if (parent1[0] == 'A')
				p1 = A;
			else
				p1 = B;

			if (parent1[parent1.size() - 1] == '-')
				r1 = false;
			else
				r1 = true;

			if (parent2[0] == 'O')
				p2 = O;
			else if (parent2[0] == 'A' && parent2[1] == 'B')
				p2 = AB;
			else if (parent2[0] == 'A')
				p2 = A;
			else
				p2 = B;

			if (parent2[parent2.size() - 1] == '-')
				r2 = false;
			else
				r2 = true;

			set<blood> p1allels, p2allels;
			p1allels = generateAllel(p1);
			p2allels = generateAllel(p2);

			set<blood> result = mixParents(p1allels, p2allels);

			bool generateTwoVersions = r1 || r2;

			cout << parent1 << " " << parent2 << " {";

			for (set<blood>::iterator it = result.begin(); it != result.end(); it++) {
				blood bloody = *it;
				switch(bloody) {
				case A:
					cout << "A-";
					if (generateTwoVersions)
						cout << ",A+";
					break;
				case B:
					cout << "B-";
					if (generateTwoVersions)
						cout << ",B+";
					break;
				case AB:
					cout << "AB-";
					if (generateTwoVersions)
						cout << ",AB+";
					break;
				case O:
					cout << "O-";
					if (generateTwoVersions)
						cout << ",O+";
					break;
				}
				if (it != (result.end() - 1))
					cout << ",";
			}
			cout << "}" << endl;
		}
		else {
			// case unknown parent
			string *known, *unknown;
			if (parent2 == "?") {
				known = &parent1;
				unknown = &parent2;
			}
			else {
				known = &parent2;
				unknown = &parent1;
			}
		}

	}
}

