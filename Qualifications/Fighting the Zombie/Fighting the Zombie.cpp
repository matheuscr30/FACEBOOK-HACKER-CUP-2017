#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll h, num;

ll solve(ll ndado, ll value)
{
  num--;
  ll lo = 1, hi = ndado;

  while(lo <= hi)
  {
    ll mid = (lo+hi)/2;

    if (mid + num -value == h)
    {
      num += mid;
      return mid;
    }
    else if (mid + num - value > h)
    {
      hi = mid;
    }
    else if (mid + num - value < h)
    {
      lo = mid + 1;
    }

  }

  num += ndado;
  return ndado;
}

main()
{
  stringstream ss;
  string str;
  char c;
  ll t, s, vezes, ndado, value;
  cin >> t;

  while(t--)
  {
    cin >> h >> s;
    cin.ignore();

    double ans = 0;
    for(ll i = 0 ; i < s; i++)
    {
      ss.clear();
      cin >> str;

      ss << str;
      ss >> vezes;
      ss >> c;
      ss >> ndado;
      ss >> c;

      value = 0;
      if (c != 'd')
        ss >> value;

      if (c == '+')
        value *= -1;

      bool flag = true;
      ll quan = 0;
      num = vezes;
      for (ll j = 1; j <= vezes && flag; j++)
      {
        if (j == 1)
          quan = solve(ndado, value);
        else
          quan *= solve(ndado, value);

        if (num-value >= h) flag = false;
        //cout << j << " " << quan << endl;
      }

      quan--;

      double tot = pow(ndado, vezes);
      double minus = tot - quan;
      double res = minus/tot;

      ans = max(ans, res);
      //cout << fixed << setprecision(6) <<  res << endl;
      //cout << " " << quan << " " << porcent << endl;
    }
    cout << fixed << setprecision(6) << ans << endl;
  }
}
