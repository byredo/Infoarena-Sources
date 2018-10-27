int binary_search(vector<int> &a, int query) {
    int left = 0, right = a.size() - 1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (a[middle) < query) {
              left = middle + 1;
              } else {
              right = middle;
              }
              }
              if (a[left] == query) {
              return left;
              }
              return -1;
              }
