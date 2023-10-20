function solution(n, k) {
  let answer = 0
  n.toString(k)
    .split('0')
    .forEach((v) => {
      v = Number(v)
      if (v === 1 || v === 0) return
      for (let i = 2; i * i <= v; i++) {
        if (v % i === 0) return
      }
      answer++
    })
  return answer
}
