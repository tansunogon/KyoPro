#include <iostream>
#include <vector>


namespace gcd {
	// from
	// https://qiita.com/drken/items/3beb679e54266f20ab63
	// by drken

	using namespace std;

	// �G���g�X�e�l�X���
	vector<bool> Eratosthenes(int N)
	{
		vector<bool> isprime((size_t)N + 1, true);
		isprime[1] = false;
		for (int p = 2; p <= N; ++p) {
			if (!isprime[p]) continue;
			for (int q = p * 2; q <= N; q += p) {
				isprime[q] = false;
			}
		}
		return isprime;
	}

	// �����[�[�^�ϊ�
	template<class T> void fast_zeta(vector<T> &f)
	{
		int N = f.size();
		vector<bool> isprime = Eratosthenes(N);
		for (int p = 2; p < N; ++p) {
			if (!isprime[p]) continue;
			for (int k = (N - 1) / p; k >= 1; --k) {
				f[k] += f[(size_t)k * p];
			}
		}
	}

	// �������r�E�X�ϊ�
	template<class T> void fast_mobius(vector<T> &F)
	{
		int N = (int)F.size();
		vector<bool> isprime = Eratosthenes(N);
		for (int p = 2; p < N; ++p) {
			if (!isprime[p]) continue;
			for (int k = 1; k * p < N; ++k) {
				F[k] -= F[(size_t)k * p];
			}
		}
	}

	// �Y�� GCD ��ݍ���
	template<class T> vector<T> conv(const vector<T> &f, const vector<T> &g)
	{
		int N = max(f.size(), g.size());
		vector<T> F(N, 0), G(N, 0), H(N);
		for (int i = 0; i < f.size(); ++i) F[i] = f[i];
		for (int i = 0; i < g.size(); ++i) G[i] = g[i];

		// �����[�[�^�ϊ�
		fast_zeta(F);
		fast_zeta(G);

		// H �����߂�
		for (int i = 1; i < N; ++i) H[i] = F[i] * G[i];

		// �������r�E�X�ϊ�
		fast_mobius(H);

		return H;
	}
}

int main()
{
	// f[0], g[0] �͊֌W�Ȃ��̂œK���Ȓl�����Ă���
	std::vector<int> f = {-1000, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	std::vector<int> g = {-1000, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};

	// ��ݍ���
	auto h = gcd::conv(f, g);

	for (int i = 1; i < h.size(); ++i) {
		std::cout << i << ": " << h[i] << std::endl;
	}
}
