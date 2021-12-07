#include <iostream>

namespace mod {
	long long pow(long long base, long long index, long long mod)
	{
		long long res = 1;
		long long base_to_power_of_2 = base;
		while (index > 0) {
			if (index & 1) {
				res *= base_to_power_of_2;
				res %= mod;
			}
			base_to_power_of_2 *= base_to_power_of_2;
			base_to_power_of_2 %= mod;
			index >>= 1;
		}
		return res;
	}

	long long inv(long long a, long long mod)
	{
		long long b = mod;
		long long u = 1;
		long long v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		u %= mod;
		if (u < 0) {
			u += mod;
		}
		return u;
	}

	template<long long MOD>
	struct Mint {
		long long v;
		Mint() : v() {};
		Mint(long long v) : v(v) {};
		Mint pow(long long index) const
		{
			return Mint(mod::pow(v, index, MOD));
		}
		Mint inv() const
		{
			return Mint(mod::inv(v, MOD));
		}
		Mint operator+(const Mint &rhs) const
		{
			return Mint((v + rhs.v) % MOD);
		}
		Mint operator-(const Mint &rhs) const
		{
			return Mint((v - rhs.v + MOD) % MOD);
		}
		Mint operator*(const Mint &rhs) const
		{
			return Mint((v * rhs.v) % MOD);
		}
		Mint operator/(const Mint &rhs) const
		{
			return Mint((v * rhs.inv()) % MOD);
		}
		Mint operator+=(const Mint &rhs)
		{
			v = (v + rhs.v) % MOD;
			return *this;
		}
		Mint operator-=(const Mint &rhs)
		{
			v = (v - rhs.v + MOD) % MOD;
			return *this;
		}
		Mint operator*=(const Mint &rhs)
		{
			v = (v * rhs.v) % MOD;
			return *this;
		}
		Mint operator/=(const Mint &rhs)
		{
			v = (v * rhs.inv()) % MOD;
			return *this;
		}
		friend std::ostream &operator<<(std::ostream &os, const Mint<MOD> obj)
		{
			return os << obj.v;
		}
	};

	using mint998 = Mint<998244353>;
	using mint197 = Mint<1000000007>;
}
