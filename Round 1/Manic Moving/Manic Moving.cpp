#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
ll n, m;
unordered_map<ll, ii>interval;
map<ii,ll>has;
vector<vector<ii> >g(105);
vector<ii>vet;
bool visitados[105];

void reset()
{
  for (ll i = 0; i <= n; i++)
    g[i].clear();
  interval.clear();
  has.clear();
}

ll dijkstra(ll origem, ll destino)
{
  priority_queue< ii, vector<ii>, greater<ii> > pq;
  memset(visitados, false, sizeof visitados);

  pq.push(mp(0, origem));

  while(!pq.empty())
  {
    ll cost = pq.top().first;
    ll u = pq.top().second;
    pq.pop();
    visitados[u] = true;

    if (u == destino)
      return cost;

    for (ll i = 0; i < g[u].size(); i++)
    {
      ll v = g[u][i].first;
      ll ncost = g[u][i].second;

      if (!visitados[v])
      {
        pq.push(mp(cost+ncost, v));
      }
    }
  }

  return -1;
}

main()
{
  ll t, k, a, b, h, s, d;
  cin >> t;

  while(t--)
  {
    cin >> n >> m >> k;
    reset();

    while(m--)
    {
      cin >> a >> b >> h;
      g[a].push_back(mp(b, h));
      g[b].push_back(mp(a, h));
    }

    ll indice = 0;
    while(k--)
    {
      cin >> s >> d;
      vet.push_back(mp(s, d));

      interval[indice] = mp(s, d);
      has[mp(s, d)] = indice;
      indice++;
    }

    bool flag = false;
    ll custo = 0, partir = 1, res, res1, res2;
    for (ll i = 0 ; i < vet.size(); i++)
    {
      res1 = res2 = 0;
      s = interval[i].first;
      d = interval[i].second;
      if (s != -1 and d != -1)
      {
        res1 = dijkstra(partir, s);
        res2 = dijkstra(s, d);
        res = res1 + res2;
        cout << res << " " << res1 << " " << res2 << endl;
        if (res1 == -1 || res2 == -1) flag = true;

        partir = vet[i].second;
      }
    }
  }
}
