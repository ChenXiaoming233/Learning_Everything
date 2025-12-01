#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin >> n;
	int nsqrt = sqrt(n) + 1;
	long long current_product = 1;
	int max_len = 0;
	long long first_num = 0;
	for(int i = 2; i < nsqrt; i++)
	{
		long long j = i;
		long long current_product = 1;
		while(true){
			current_product *= j;
			if (current_product > n){
				break;
			}
			if (n % current_product == 0){
				int current_len = j - i + 1;
				if(current_len > max_len){
					max_len = current_len;
					first_num = i;
				}
            }
            else{
                break;
            }
			j++;
		}	
	}
    if (max_len == 0) {
        // 如果没有找到连续因子（通常 N 是素数），输出 N 本身
        cout << 1 << endl;
        cout << n << endl;
    } else {
        cout << max_len << endl;
        for (int k = 0; k < max_len; k++) {
            if (k > 0) cout << "*";
            cout << first_num + k;
        }
        cout << endl;
    }
} 