function solution(park, routes) {
  var answer = [];
  let x = 0,
    y = 0;
  const moves = {E: [0, 1], S: [1, 0], W: [0, -1], N: [-1, 0]};
  for (let i = 0; i < park.length; i++) {
    const j = park[i].indexOf("S");
    if (j !== -1) {
      x = i;
      y = j;
      break;
    }
  }

  routes.forEach((route) => {
    let [d, n] = route.split(" ");
    n = parseInt(n);
    for (var i = 1; i <= n; i++) {
      var nx = x + moves[d][0] * i;
      var ny = y + moves[d][1] * i;
      if (nx >= 0 && nx < park.length && ny >= 0 && ny < park[0].length) {
        if (park[nx][ny] === "X") {
          break;
        }
      } else {
        break;
      }
    }
    if (i === n + 1) {
      x = nx;
      y = ny;
    }
  });

  answer.push(x);
  answer.push(y);

  return answer;
}
