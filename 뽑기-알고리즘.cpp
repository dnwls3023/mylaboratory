#include <iostream>
#include <random>
#include <map>
using namespace std;

/*

    알고리즘 설명 : 가중치 확률 아이템을 뽑는다.
    ex) 일반 아이템 : 50% 확률 , 레어 아이템 : 30% 확률, 에픽 아이템 20% 확률 

*/

// 1 일반, 2 레어, 3 에픽
string select(int range) {
    if (1 <= range && range <= 50) return "COMMON";
    else if (range <= 80) return "RARE";
    else if (range <= 100) return "EPIC";
}

int main(void) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100);
    map<string, int> m;
    for (int i = 0; i < 1000; ++i) {
        m[select(dis(gen))]++;
    }
    cout << "일반 50% 레어 30% 에픽 20%" << endl;
    cout << "일반 레어 에픽순 총 1000회 돌림" << endl;
    cout << "기댓값 : 500 300 200" << endl;
    cout << m["COMMON"] << " " << m["RARE"] << " " << m["EPIC"] << endl;
    cout << "오차 범위 : " << m["COMMON"] - 500 << " " 
        << m["RARE"] - 300 << " " << m["EPIC"] - 200 << endl;
    return 0;
}
