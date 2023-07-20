function solution(cards1, cards2, goal) {
  var answer = "Yes";
  let pos1 = -1,
    pos2 = -1;

  for (const g of goal) {
    if (pos1 + 1 == cards1.indexOf(g)) pos1++;
    else if (pos2 + 1 == cards2.indexOf(g)) pos2++;
    else {
      answer = "No";
      break;
    }
  }
  return answer;
}
