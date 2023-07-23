function solution(today, terms, privacies) {
  let termList = {};
  let answer = [];

  for (const term of terms) {
    const [a, b] = term.split(" ");
    termList[a] = parseInt(b);
  }

  const [endYear, endMonth, endDay] = today.split(".").map(Number);
  const endDate = endYear * 12 * 28 + endMonth * 28 + endDay;

  for (let i = 1; i <= privacies.length; i++) {
    const [date, term] = privacies[i - 1].split(" ");
    const [startYear, startMonth, startDay] = date.split(".").map(Number);
    const startDate = startYear * 12 * 28 + startMonth * 28 + startDay;
    if (termList[term] <= (endDate - startDate) / 28) {
      answer.push(i);
    }
  }
  return answer;
}
