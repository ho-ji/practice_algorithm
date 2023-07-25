function solution(s) {
  let count = {},
    answer = [];
  for (let i = 0; i < s.length; i++) {
    if (count[s[i]] === undefined) {
      answer.push(-1);
      count[s[i]] = i;
    } else {
      answer.push(i - count[s[i]]);
      count[s[i]] = i;
    }
  }
  return answer;
}
