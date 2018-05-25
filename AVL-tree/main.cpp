#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <algorithm>
#include <tuple>
#define endl "\n"
#define fs first
#define sd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define deb(x) for(auto mew : (x))cout<<mew<<" ";cout<<endl;
#define debs(x) cout<<(x).size()<<": ";for(auto mew : (x))cout<<mew<<" ";cout<<endl;
#define deb_pair(x) cout<<(x).size()<<": ";for(auto mew : (x))cout<<mew.fs<<" "<<mew.sd<<endl;
#define cin_ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef tuple<int, int, int> t3;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<db> vdb;
int inf = 1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

class AVL_tree
{
private:
    struct Node
    {
        int value = 0; //key
        int height = 1; //height of current subtree
        Node* left = nullptr; //left son
        Node* right = nullptr; //right son

        Node(int val)
            :value(val)
        {}

        Node() = default;
        ~Node() = default;
    };

    int height(Node* p) //height of current subtree
    {
        return (p != nullptr ? p->height : 0);
    }

    int balance_factor(Node* p) //difference between heights of left and right subtrees
    {
        return height(p->right) - height(p->left);
    }

    void fix_height(Node* p) //gets maximum height between sons and resets p's height
    {
        int hl = height(p->left);
        int hr = height(p->right);
        p->height = (hl > hr ? hl : hr) + 1;
    }

    Node* rotate_right(Node* p) //rotate right around p, returns pointer to new root of subtree
    {
        Node* left_son = p->left;
        p->left = left_son->right;
        left_son->right = p;
        fix_height(p);
        fix_height(left_son);
        return left_son;
    }

    Node* rotate_left(Node* p) //rotate left around p, returns pointer to new root of subtree
    {
        Node* right_son = p->right;
        p->right = right_son->right;
        right_son->right = p;
        fix_height(p);
        fix_height(right_son);
        return right_son;
    }

    Node* balance(Node* p)
    {
        fix_height(p);

        if (balance_factor(p) == 2)
        {
            if (balance_factor(p->right) < 0)
                p->right = rotate_right(p->right);
            return rotate_left(p);
        }
        if (balance_factor(p) == -1)
        {
            if (balance_factor(p->left) > 0)
                p->left = rotate_left(p->left);
            return rotate_right(p);
        }
        return p;
    }

    Node* _insert(Node* p, int key)
    {
        if (p == nullptr) return new Node(key); //this node will be a leaf
        if (key == p->value) return p; //no need to insert cuz it already exists

        if (key < p->value)
            p->left = _insert(p->left, key); // insert into left subtree
        else
            p->right = _insert(p->right, key); //insert into right subtree

        return balance(p);
    }

    Node* _find_min(Node* p) //find node with smallest key
    {
        return p->left ? _find_min(p->left) : p;
    }

    Node* _remove_min(Node* p) //remove node with smallest key
    {
        if (p->left == nullptr)
        {
            Node* tmp = p->right;
            delete p;
            return (tmp);
        }
        p->left = _remove_min(p->left);
        return balance(p);
    }

    Node* _remove(Node* p, int key)
    {
        if (p == nullptr) return nullptr;
        if (key < p->value)
            p->left = _remove(p->left, key);
        else if (key > p->value)
            p->right = _remove(p->right, key);
        else //key == p->value
        {
            Node* l = p->left;
            Node* r = p->right;
            delete p;
            if (!r) return l;
            Node* min_ = _find_min(r);
            min_->right = _remove_min(r);
            min_->left = l;
            return balance(min_);
        }
        return balance(p);
    }


    Node* root = nullptr;

public:

    AVL_tree() = default;
    ~AVL_tree() = default;

    void insert(int key)
    {
        root = _insert(root, key);
    }

    void remove(int key)
    {
        root = _remove(root, key);
    }


};

int main()
{

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    AVL_tree tr;

    tr.insert(5);
    tr.insert(3);
    tr.insert(1);
    tr.insert(6);
    tr.remove(-1);
    tr.remove(1);


    return 0;
}