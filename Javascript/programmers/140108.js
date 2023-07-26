function solution(s) {
  let x = s[0];
  let cntX = 1,
    cntNotX = 0;
  let answer = 0;
  for (let i = 1; i < s.length - 1; i++) {
    s[i] === x ? cntX++ : cntNotX++;
    if (cntX === cntNotX) {
      answer++;
      x = s[i + 1];
      cntX = 0;
      cntNotX = 0;
    }
  }
  return answer + 1;
}
