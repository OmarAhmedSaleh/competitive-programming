// https://www.hackerrank.com/challenges/candies/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dynamic-programming

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    vector<int> dis(n,0);
    vector<pair<int,int>> numberAndIndex(n, {0,0});
    long long numberOfCandies = 0;
    for(int i = 0;i < n ; i++){
        numberAndIndex[i] = {arr[i], i};
    }
    sort(numberAndIndex.begin(), numberAndIndex.end());
    for(int i = 0;i < n ; i++){
        int left = 0, right = 0, index = numberAndIndex[i].second;
        if(index > 0 && arr[index] > arr[index - 1]){
            left = dis[index - 1];
        }
        if(index + 1 < n && arr[index] > arr[index + 1]){
            right = dis[index + 1];
        }
        dis[index] = max(left, right) + 1;
        numberOfCandies += dis[index];
    }
    return numberOfCandies;
}
