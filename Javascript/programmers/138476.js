function solution(k, tangerine) {
  let map = new Map()
  for (const t of tangerine) {
    map.set(t, map.get(t) ? map.get(t) + 1 : 1)
  }
  let count = [...map]
  count.sort((a, b) => b[1] - a[1])
  for (let i = 0; i < count.length; i++) {
    if (k <= count[i][1]) {
      return i + 1
    }
    k -= count[i][1]
  }
}
