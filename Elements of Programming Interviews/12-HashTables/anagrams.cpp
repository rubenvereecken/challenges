/*!
 * \file 
 * \brief  anagrams.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#include "hashTables.h"
#include <algorithm>

using namespace std;

set<set<string> > anagram(set<string> dictionary) {
	map<string, set<string> > hash;
	set<set<string> > anagramGroups;

	for(auto word : dictionary) {
		string sortedWord(word);
		sort(word.begin(), word.end());
		hash[sortedWord].insert(word);
	}

	for (auto anagramGroup : hash) {
		if (anagramGroup.second.size() > 1)
			anagramGroups.insert(anagramGroup.second);
	}
}
