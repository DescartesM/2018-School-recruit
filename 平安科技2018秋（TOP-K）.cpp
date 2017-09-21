#include <iostream>
#include <queue>
using namespace std;
/*
INPUT: 4 2
1 3 2 4
OUTPUT:
1 2
Description: 一个无序数组由n个不相同的int组成，找出最小的K个整数，并保持原顺序输出。做到时间复杂度为O(n)。
思路TOP-K min 最大堆来维护k，O(nlogk)
*/
struct Node
{
    int value;
    int order;// as index
};
bool operator<(Node a, Node b) {
    return a.value < b.value;
}
bool cmp(Node a, Node b) {
    return a.order < b.order;
}
int main(int argc, char const *argv[])
{
    int n, k, x;
    cin >> n >> k;
    vector<Node> arr;
    priority_queue<Node> pq;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        arr[i].value = x;
        arr[i].order = i + 1;
    }
    for (int i = 0; i < n; ++i) // worst time  O(nlogk)
    {
        if (pq.size() < k) {
            pq.push(arr[i]);
            continue;
        }
        if (arr[i] < pq.top())
        {
            Node temp;
            temp = arr[i];
            pq.pop();
            pq.push(arr[i]);
        }
    }
    vector<Node> ans;
    int len = pq.size();
    for (unsigned int i = 0; i < len; ++i)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin(), ans.end(), cmp);  // cause priority_queue cannot sort
    for (unsigned int i = 0; i < ans.size() - 1; ++i)
    {
        printf("%d ", ans[i].value);
    }
    printf("%d\n", ans[ans.size() - 1].value);
    system("PAUSE");
    return 0;
}


