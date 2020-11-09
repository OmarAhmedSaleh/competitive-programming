// https://www.hackerrank.com/challenges/swap-nodes-algo/problem
#include <bits/stdc++.h>

using namespace std;
vector<int> l, r;

void swaper(int idx, int d, int k){
    if(idx <= -1){return;}
    if(d%k == 0){
        swap(l[idx], r[idx]);
    }
    swaper(l[idx], d + 1, k);
    swaper(r[idx], d + 1, k);
}

void inOrder(int idx, vector<int> &order){
    if(idx <= -1){return;}
    inOrder(l[idx], order);
    order.push_back(idx + 1);
    inOrder(r[idx], order);
}
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int n = (int)indexes.size();
    l.resize(n, -1);
    r.resize(n, -1);
    for(int i = 0;i <(int)indexes.size();i++){
        l[i] = indexes[i][0] - 1;
        r[i] = indexes[i][1] - 1;
    }
    vector<vector<int>> orders;
    for(auto q: queries){
        vector<int> order;
        swaper(0,1,q);
        inOrder(0, order);
        orders.push_back(order);
    }
    return orders;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
