function solution(t, p) {
  let answer = 0;
  const len = p.length;
  const pNum = +p;
  for (let i = 0; i <= t.length - len; i++) {
    let compareNumber = t.substr(i, len);
    if (+compareNumber <= pNum) {
      answer++;
    }
  }
  return answer;
}
