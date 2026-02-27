#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <bitset>
#include <list>
#include <algorithm>

using namespace std;

// --- Forward Declarations (The "Secret Sauce" for nested containers) ---
void _print(int t);
void _print(long long t);
void _print(string t);
void _print(char t);
void _print(long double t);
void _print(double t);
void _print(unsigned long long t);
void _print(bool t);

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack <T> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(deque <T> v);
template <class T> void _print(list <T> v);
template <class T> void _print(priority_queue <T> v);
template <size_t N> void _print(bitset<N> v);

// --- Basic Types ---
void _print(int t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << "\"" << t << "\""; }
void _print(char t) { cerr << "'" << t << "'"; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
void _print(bool t) { cerr << (t ? "true" : "false"); }

// --- Container Definitions ---
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(list <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <size_t N> void _print(bitset<N> v) {cerr << v;}

// --- Adapters (Copying is required to avoid modifying original) ---
template <class T> void _print(stack <T> v) {
    cerr << "[ "; stack<T> temp = v; 
    while (!temp.empty()) { _print(temp.top()); cerr << " "; temp.pop(); } cerr << "]";
}
template <class T> void _print(queue <T> v) {
    cerr << "[ "; queue<T> temp = v;
    while (!temp.empty()) { _print(temp.front()); cerr << " "; temp.pop(); } cerr << "]";
}
template <class T> void _print(deque <T> v) {
    cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";
}
template <class T> void _print(priority_queue <T> v) {
    cerr << "[ "; priority_queue<T> temp = v;
    while (!temp.empty()) { _print(temp.top()); cerr << " "; temp.pop(); } cerr << "]";
}

// --- The Macro ---
#ifndef ONLINE_JUDGE
#define debug(x) cerr << "Line " << __LINE__ << ": " << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#endif