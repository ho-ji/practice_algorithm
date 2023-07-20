function solution(targets) {
  let answer = 0,
    prev = -1;
  targets.sort((a, b) => a[1] - b[1]);
  for (let i = 0; i < targets.length; i++) {
    const [start, end] = targets[i];

    if (prev <= start) {
      prev = end;
      answer++;
    }
  }
  return answer;
}
