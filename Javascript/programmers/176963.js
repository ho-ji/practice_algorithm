function solution(name, yearning, photo) {
  var answer = [];
  let score = {};

  name.forEach((item, i) => {
    score[item] = yearning[i];
  });

  photo.forEach((list) => {
    let sum = 0;
    list.forEach((item) => {
      sum += score[item] || 0;
    });
    answer.push(sum);
  });

  return answer;
}
