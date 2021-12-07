// ABC230 E Fraction Floor Sum
// sum_{i=1}^N [N/i]
long long ffsum(long long N)
{
	long long ret = 0;
	long long i = 1;
	while (i <= N) {
		long long v = N / i;
		long long j = N / v + 1;
		ret += v * (j - i);
		i = j;
	}
	return ret;
}

// AtCoder Library Practice Contest C Floor Sum
// submission: https://atcoder.jp/contests/practice2/submissions/18805092
// submitted by rsk0315
// how to work: https://atcoder.jp/contests/practice2/editorial/579
//
// modified by tansu
//
// sum_i=0^{N-1} [(A*i+B)/M]
long long fsum(long long n, long long m, long long a, long long b)
{
	long long ret = 0;
	if (a >= m) {
		ret += (n - 1) * n * (a / m) / 2;
		a %= m;
	}
	if (b >= m) {
		ret += n * (b / m);
		b %= m;
	}

	long long y_max = a * (n - 1) + b;
	if (y_max < m) {
		return ret;
	}
	long long y_max_div = y_max / m;
	long long y_max_mod = y_max % m;
	ret += y_max_div + fsum(y_max_div, a, m, y_max_mod);
	return ret;
}
