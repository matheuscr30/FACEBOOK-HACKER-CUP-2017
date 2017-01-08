#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

main()
{
  vector<ll>vet;
  ll t, n, num, casos=1;
  cin >> t;

  while(t--)
  {
    cin >> n;
    vet.clear();

    for (ll i = 0; i < n; i++)
    {
      cin >> num;
      vet.push_back(num);
    }

    sort(vet.rbegin(), vet.rend());

    cout << "Case #" << casos++ << ": ";

    ll fin = n-1;
    ll ini = 0;

    ll cont = 0, accum = 0, init=0;
    for (ll i = ini; i <= fin; i++)
    {
      if (vet[ini] >= 50){
        cont++;
        ini++;
      }
      else{
        ll accum = init = vet[ini];
        while(accum < 50 and fin > ini)
        {
          accum += init;
          fin--;
        }

        if (accum >= 50){
          cont++;
          ini++;
          accum = 0;
        }
      }

    }

    cout << cont << endl;
  }
}
