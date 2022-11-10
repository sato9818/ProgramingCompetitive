
// a * x = tar (mod MOD)
// のxを求める
// a, tar, MODはそれぞれ互いに素である必要がある

// mod_inv(x / gcd(x,sum), sum / gcd(x,sum))
// ↑こんな感じで使う
ll ext_gcd(ll a, ll b, ll &x, ll &y, ll tar)
{
  if (b == 0)
  {
    x = tar;
    y = 0;
    return a;
  }

  ll d = ext_gcd(b, a % b, y, x, tar);
  y -= a / b * x;
  return d;
}

ll mod(ll a, ll m)
{
  return (a % m + m) % m;
}

ll mod_inv(ll a, ll tar)
{
  ll x, y;
  ll g = ext_gcd(a, MOD, x, y, tar);
  return mod(x, MOD / g);
}