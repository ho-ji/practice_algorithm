function solution(s, skip, index) {
  let list = "abcdefghijklmnopqrstuvwxyz",
    answer = "";
  for (const skipWord of skip) {
    list = list.replace(skipWord, "");
  }
  for (const x of s) {
    answer += list[(list.indexOf(x) + index) % list.length];
  }
  return answer;
}
