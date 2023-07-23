function solution(keymap, targets) {
  let count = {};
  let answer = [];
  for(let i=0; i<keymap.length; i++){
      for(let j=0; j<keymap[i].length; j++){
          if(!count[keymap[i][j]] || count[keymap[i][j]] > j){
              count[keymap[i][j]] = j+1;  
          }
      }
  }
  for(let target of targets){
      let sum = 0;
      for(let i=0; i<target.length; i++){
          if(!count[target[i]]){
              sum = -1;
              break;
          }
          sum += parseInt(count[target[i]]);
      }
      answer.push(sum)
  }
  return answer;
}