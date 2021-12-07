#include <vector>
#include <utility>

// Sieve of Eratosthenes
//
// How to work (by drken)
// https://qiita.com/drken/items/3beb679e54266f20ab63
//
// This code is from (by drken)
// https://atcoder.jp/contests/abc206/submissions/23595267
// and little bit modified by tansu
//
// isprime[n] := is n prime?
// mebius[n] := mebius value of n
// min_factor[n] := the min prime-factor of n
struct Eratos {
	std::vector<int> primes;
	std::vector<bool> isprime;
	std::vector<int> mebius;
	std::vector<int> min_factor;

	Eratos(int MAX) : primes(),
		isprime((size_t)MAX + 1, true),
		mebius((size_t)MAX + 1, 1),
		min_factor((size_t)MAX + 1, -1)
	{
		isprime[0] = isprime[1] = false;
		min_factor[0] = 0, min_factor[1] = 1;
		for (int i = 2; i <= MAX; ++i) {
			if (!isprime[i]) continue;
			primes.push_back(i);
			mebius[i] = -1;
			min_factor[i] = i;
			for (int j = i * 2; j <= MAX; j += i) {
				isprime[j] = false;
				if ((j / i) % i == 0) mebius[j] = 0;
				else mebius[j] = -mebius[j];
				if (min_factor[j] == -1) min_factor[j] = i;
			}
		}
	}

	// prime factorization
	std::vector<std::pair<int, int>> prime_factors(int n)
	{
		std::vector<std::pair<int, int>> res;
		while (n != 1) {
			int prime = min_factor[n];
			int exp = 0;
			while (min_factor[n] == prime) {
				++exp;
				n /= prime;
			}
			res.emplace_back(prime, exp);
		}
		return res;
	}

	// enumerate divisors
	std::vector<int> divisors(int n)
	{
		std::vector<int> res{1};
		auto pf = prime_factors(n);
		for (auto p : pf) {
			int n = (int)res.size();
			for (int i = 0; i < n; ++i) {
				int v = 1;
				for (int j = 0; j < p.second; ++j) {
					v *= p.first;
					res.push_back(res[i] * v);
				}
			}
		}
		return res;
	}
};
