#include <iostream>
#include <random>
using namespace std;

// 청소구역 짜기 알고리즘
string str[5] = {"청소A","청소B","청소C","청소D","청소E"};
string name[5] = {"친구A","친구B","친구C","친구D","친구E"};

/*
    맨처음 접근 : 
    헤더파일 #include <time.h> 을 추가하여
    srand(time(NULL))를 써서 구현할 생각이었음. 
    but 이렇게 쓰면 균등하게 난수를 생성하지 않는다는 문제점이 있음.
    따라서 새로운 스타일의 난수 생성기를 사용함.
*/

bool visited[5];
int arr[5];

/*
    현재 사용하는 난수 생성기는 수학적 알고리즘을 통해 생성되는 가짜 난수가
    아닌 컴퓨터가 실행하면서 마주치는 무작위적인 요소들 (ex 장치드라이버의 noise)
    등을 기반으로한 난수를 사용한다. 

    mt19937은 메르센 트위스터 라는 알고리즘을 사용한다. 그러나 
    객체 자체의 메모리가 크기 때문에(2kb 이상)메모리가 부족하다면
    minstd_rand가 더 적합할 수 있다.

    참고 사이트 : https://modoocode.com/304

*/

int main(void){
    random_device rd;
    mt19937 gen(rd());
    // 0부터 4까지 균등하게 나타내는 난수열을 생성하기 위해 균등 분포 정의
    uniform_int_distribution<int> dis(0,4);
    int idx = 0;
    // 몇번 수행됐는가?
    int cnt = 0 ;
    while(idx<5) {
        int data = dis(gen);
        if(!visited[data]){
            visited[data] = true;
            arr[idx] = data;
            idx++;
        }
        cnt++;
    }
    cout<<"!!!--오늘의 청소구역은?--!!!"<<endl;
    for(int i = 0 ; i<5;++i){
        cout<<name[i]<<" "<<str[arr[i]]<<endl;
    }
    cout<<"5개를 뽑는데에 대한 실행 횟수 : " <<cnt<<endl;
    return 0;
}
