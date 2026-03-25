// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int leftVal = arr[left];
      int leftCount = 0;
      while (left < right && arr[left] == leftVal) {
        leftCount++;
        left++;
      }
      int rightVal = arr[right];
      int rightCount = 0;
      while (left <= right && arr[right] == rightVal) {
        rightCount++;
        right--;
      }
      count += leftCount * rightCount;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    int pos = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        pos = mid;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (pos != -1) {
      int first = pos;
      while (first > i && arr[first - 1] == target) {
        first--;
      }
      int last = pos;
      while (last + 1 < len && arr[last + 1] == target) {
        last++;
      }
      count += (last - first + 1);
      while (i + 1 < len && arr[i + 1] == arr[i]) {
        i++;
      }
    }
  }

  return count;
}
