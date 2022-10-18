#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
using namespace std;
bool cmp(pair<int, char> a, pair<int, char> b) {
	return a.second < b.second;
}
int main() {
	fast;
	vector<pair<int,char>> Array;
	vector<pair<int, char>> Array2;
	string Hansoo;
	cin >> Hansoo;
	int ab[26]={0,};
	int flag = 0;
	for (int i = 0; i < Hansoo.size(); i++) {
		ab[Hansoo[i] - 65]++;
	}
	for (int i = 0; i < 26; i++) {
		if (ab[i] == 0) continue;
		if(ab[i]%2==0) Array.push_back(make_pair(ab[i], (char)(i + 65)));
		else  Array2.push_back(make_pair(ab[i], (char)(i + 65)));
	}
	if (Array2.size() >= 2) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	sort(Array.begin(), Array.end(),cmp);
	vector<char> Alpa(Hansoo.size());
	int count = 0;//Alpa배열에 인덱스 +-를 해줄 값
	if (Hansoo.size() % 2 == 0) {
		for(int i=0;i<Array.size();i++){
			while (Array[i].first!=0) {//0이 아닐때까지
				Alpa[count] = Array[i].second;
				Alpa[Alpa.size() - count - 1] = Array[i].second;
				Array[i].first -= 2;
				count++;
			}
		}
		flag = 1;
	}
	else {
		for (int i = 0; i < Array.size(); i++) {
			if (Array[i].second > Array2[0].second) {
				while (Array2[0].first != 1) {
					Alpa[count] = Array2[0].second;
					Alpa[Alpa.size() - count - 1] = Array2[0].second;
					Array2[0].first -= 2;
					count++;
				}
				flag = 1;
			}
			while (Array[i].first != 0) {//0이 아닐때까지
				Alpa[count] = Array[i].second;
				Alpa[Alpa.size() - count - 1] = Array[i].second;
				Array[i].first -= 2;
				count++;
			}
		}
		Alpa[Alpa.size() / 2] = Array2[0].second;
	}
	if (flag == 0) {
		while (Array2[0].first != 1) {
			Alpa[count] = Array2[0].second;
			Alpa[Alpa.size() - count - 1] = Array2[0].second;
			Array2[0].first -= 2;
			count++;
		}
	}
	for (int i = 0; i < Alpa.size(); i++) cout << Alpa[i];
}