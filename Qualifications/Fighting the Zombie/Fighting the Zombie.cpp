#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

main()
{
  stringstream ss;
  string str;
  char c;
  ll t, h, s, vezes, ndado, value;
  cin >> t;

  while(t--)
  {
    cin >> h >> s;
    cin.ignore();

    ll ans = 0;
    for(ll i = 0 ; i < s; i++)
    {
      ss.clear();
      cin >> str;

      ss << str;
      ss >> vezes;
      ss >> c;
      ss >> ndado;
      ss >> c;

      if (c != 'd')
        ss >> value;

      //cout << vezes << " " << c << " " << ndado << endl;


    }
  }
}
