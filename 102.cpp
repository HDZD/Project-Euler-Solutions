#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;

struct pt{
    long long x, y;
    pt(){}
    pt(long long _x, long long _y):x(_x), y(_y){}
    pt operator+(const pt & p) const { return pt(x + p.x, y + p.y); }
    pt operator-(const pt & p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt & p) const { return x * p.y - y * p.x; }
    long long dot(const pt & p) const { return x * p.x + y * p.y; }
    long long cross(const pt & a, const pt & b) const { return (a - *this).cross(b - *this); }
    long long dot(const pt & a, const pt & b) const { return (a - *this).dot(b - *this); }
    long long sqrLen() const { return this->dot(*this); }
};

bool pointInTriangle(pt a, pt b, pt c, pt point){
    long long s1 = abs(a.cross(b, c));
    long long s2 = abs(point.cross(a, b)) + abs(point.cross(b, c)) + abs(point.cross(c, a));
    return s1 == s2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("triangles.txt","r",stdin);

    ll res = 0;
    pt p1,p2,p3,p0;
    p0.x = 0;
    p0.y = 0;
    for (int i =0;i < 1e3;i++){
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        res += pointInTriangle(p1,p2,p3,p0);
    }

    cout << res << endl;
}