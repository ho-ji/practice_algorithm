function solution(numbers, target) {
  let answer = 0;
  DFS(0, 0);
  function DFS(l, sum) {
    if (l === numbers.length) {
      if (sum === target) answer++;
    } else {
      DFS(l + 1, sum + numbers[l]);
      DFS(l + 1, sum - numbers[l]);
    }
  }

  return answer;
}
