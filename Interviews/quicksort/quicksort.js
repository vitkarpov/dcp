module.exports = function quicksort(arr) {
  quicksortHelper(arr, 0, arr.length - 1);
  return arr;
};

function quicksortHelper(arr, start, end) {
  if (start < end) {
    const pivotIndex = partition(arr, start, end);
    quicksortHelper(arr, start, pivotIndex - 1);
    quicksortHelper(arr, pivotIndex + 1, end);
  }
}

function partition(arr, low, high) {
  const pivot = arr[low];
  let i = low;
  let j = high;

  while (i < j) {
    while (i <= high && arr[i] <= pivot) i++;
    while (arr[j] > pivot) j--;
    if (i < j) [arr[i], arr[j]] = [arr[j], arr[i]];
  }

  [arr[low], arr[j]] = [arr[j], pivot];

  return j;
}
