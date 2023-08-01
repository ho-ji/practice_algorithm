function solution(babbling) {
  let answer = 0
  const regex = /^(aya(?!aya)|ye(?!ye)|woo(?!woo)|ma(?!ma))+$/
  for (const b of babbling) {
    if (b.match(regex)) answer++
  }
  return answer
}
