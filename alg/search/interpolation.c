int interpolationSearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));

        if (arr[pos] == key)
            return pos;
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}
