class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;
		int res = 0;
		int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
		long long divid = labs(dividend);
		long long divis = labs(divisor);
		while (divid >= divis) {
			long long div = divis;
			long long plus = 1;
			while (divid >= (div + div)) {
				div += div;
				plus += plus;
			}
			divid -= div;
			res += plus;
		}
		return sign == 1 ? res : -res;
	}
};
