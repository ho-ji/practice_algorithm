function solution(arr) {
  arr.sort((a, b) => b - a)
  let x = arr[0]
  for (let i = 1; ; i++) {
    x = arr[0] * i
    if (arr.every((v) => x % v === 0)) {
      return x
    }
  }
}
