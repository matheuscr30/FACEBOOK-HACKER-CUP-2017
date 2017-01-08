#include <bits/stdc++.h>
#define endl '\n'
#define pi 3.14159265
using namespace std;
typedef long long int ll;

main()
{
  ll t, casos = 1;
  double p, x, y;
  cin >> t;

  while(t--)
  {
    cin >> p >> x >> y;
    double raio = sqrt( (x-50)*(x-50) + (y-50)* (y-50) );
    //cout << raio << endl;

    cout << "Case #" << casos++ << ": ";
    if (raio > 50)
    {
      cout << "white" << endl;
      continue;
    }

    double x2 = x-50;
    double y2 = y-50;

    double angulo = atan2( x2, y2) * 180/pi;
    if (angulo <= 0) angulo += 360;
    double porcentagem = (angulo / 360 * 100);
    //cout << angulo << " " << porcentagem << " ";

    if (porcentagem > p) cout << "white" << endl;
    else cout << "black" << endl;
  }
}
