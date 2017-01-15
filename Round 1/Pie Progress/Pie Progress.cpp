#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll n, m, dp[305][1005];
vector<vector<ll> >mat(305);

void reset()
{
  for (ll i = 0; i <= n; i++)
    mat[i].clear();

  memset(dp, -1, sizeof dp);
}

ll solve(ll current, ll quan)
{
  if (quan >= n)
    return 0LL;
  if (current == n)
    return INT_MAX;

  if (dp[current][quan] != -1)
    return dp[current][quan];

  ll ans = solve(current+1, quan);

  ll accum = 0,tam = 0;

  for (ll i = 0; i < mat[current].size(); i++)
  {
    ll cost = mat[current][i];
    accum += cost;
    tam++;

    //Um no dia
    ans = min(ans, solve(current+1, quan+1) + cost + 1);

    //Varios no dia
    ans = min(ans, solve(current+1, quan + tam) + accum + tam*tam);
  }

  return dp[current][quan] = ans;
}

main()
{
  ll t, cost, cases=1;
  cin >> t;

  while(t--)
  {
    cin >> n >> m;
    reset();

    for (ll i = 0 ; i < n; i++){
      for (ll j = 0; j < m; j++){
        cin >> cost;
        mat[i].push_back(cost);
      }
      sort(mat[i].begin(), mat[i].end());
    }

    cout << "Case #" << cases++ << ": " << solve(0, 0) << endl;
  }
}
