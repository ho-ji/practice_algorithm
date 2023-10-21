function solution(n, words) {
  const check = {}
  for (let i = 0; i < words.length; i++) {
    if (i !== 0 && words[i - 1][words[i - 1].length - 1] !== words[i][0]) {
      return [(i % n) + 1, parseInt(i / n) + 1]
    }
    if (check[words[i]] !== undefined) {
      return [(i % n) + 1, parseInt(i / n) + 1]
    }

    check[words[i]] = true
  }
  return [0, 0]
}
