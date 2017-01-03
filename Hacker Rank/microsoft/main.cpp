#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
  int t;
  cin>>t;

  map<string, string> month_map;
  month_map["Jan"] = "01";
  month_map["Feb"] = "02";
  month_map["Mar"] = "03";
  month_map["Apr"] = "04";
  month_map["May"] = "05";
  month_map["Jun"] = "06";
  month_map["Jul"] = "07";
  month_map["Aug"] = "08";
  month_map["Sep"] = "09";
  month_map["Oct"] = "10";
  month_map["Nov"] = "11";
  month_map["Dec"] = "12";

  for (int _=0; _<t; _++) {
    string day, month, year;
    cin >> day;
    cin >> month;
    cin >> year;

    // Constraint checking
    if (int yeari = atoi(year.c_str()) < 1900 || yeari > 2100) {
        // that's cheating
    }

    if (month.size() != 3) {
        // Definitely cheating
    }

    // Day
    if (isdigit(day[1]))
        day = day.substr(0, 2);
    else
        day = day.substr(0, 1);
    int dayout = atoi(day.c_str());

    // Add extra digit before day if single digit
    string dayprefix = (dayout / 10) ? "" : "0";

    cout << year << '-' << month_map[month] << '-' << dayprefix << dayout << endl;
  }

  return 0;
}
