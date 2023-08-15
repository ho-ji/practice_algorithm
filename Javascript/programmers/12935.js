function solution(arr) {
  if (arr.length === 1) return [-1]
  let minIndex = 0
  for (let i = 1; i < arr.length; i++) {
    if (arr[minIndex] > arr[i]) minIndex = i
  }
  arr.splice(minIndex, 1)
  return arr
}
