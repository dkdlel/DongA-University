#include<bits/stdc++.h>
using namespace std;

ifstream fcin("hull.inp");
ofstream fcout("hull.out");

typedef struct Point {
	int x, y, dx, dy; // dx, dy : ���������� �Ÿ�

    bool operator<(const Point& P) {
        if (dy * P.dx != dx * P.dy) return dy * P.dx < dx* P.dy;
        if (x != P.x) return x < P.x;
        return y < P.y;
    }
};
long long int ccw(const Point& A, const Point& B, const Point& C) {
    return A.x * B.y + B.x * C.y + C.x * A.y - B.x * A.y - C.x * B.y - A.x * C.y;
}

int num;
vector<Point> point;
int main() {
    
    fcin >> num;
    point.resize(num);
    for (int i = 0; i < num; i++) {
        int n1, n2;
        fcin >> n1 >> n2;
        point[i] = Point{ n1,n2,0,1 };
    }
    sort(point.begin(), point.end());
    for (int i = 1; i < num; i++) {
        point[i].dx = point[i].x - point[0].x;
        point[i].dy = point[i].y - point[0].y;
    }
    sort(point.begin() + 1, point.end());

    stack<int> s;
    // ���ÿ� ���� 2�� ���� ����
    s.push(0); s.push(1);
    int next = 2;
    // ������ ã�� ����
    while (next < num) {
        while (s.size() >= 2) {
            int second = s.top(); s.pop();
            int first = s.top();
            if (ccw(point[first], point[second], point[next]) > 0) { // ccw�� ����� ��ȸ��
                s.push(second);
                break;
           }
        }
        s.push(next++);
    }

    fcout << s.size() << '\n';
    // ���ÿ� �ִ°� �Ųٷ� ��� ���ؼ�
    vector<Point> ans(s.size() +1);
    while (!s.empty()) {
        ans[s.size()] = { point[s.top()].x, point[s.top()].y,0,1 };
        s.pop();
    }

    for (int i = 1; i <= ans.size()-1; i++) fcout << ans[i].x << ' ' << ans[i].y << '\n';

	return 0;
}