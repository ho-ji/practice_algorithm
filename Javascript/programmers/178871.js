function solution(players, callings) {
  let position = {};
  players.forEach((player, i) => {
    position[player] = i;
  });
  callings.forEach((calling) => {
    const index = position[calling]--;
    const tempValue = players[index - 1];
    players[index - 1] = players[index];
    players[index] = tempValue;
    position[tempValue] = index;
  });
  return players;
}
