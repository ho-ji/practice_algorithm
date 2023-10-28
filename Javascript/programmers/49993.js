function solution(skill, skill_trees) {
  let answer = 0
  for (const skill_tree of skill_trees) {
    let check = false
    let prev = -1
    for (let i = 0; i < skill.length; i++) {
      let pos = skill_tree.indexOf(skill[i])
      if (check && pos !== -1) {
        answer--
        break
      }
      if (pos === -1) check = true
      else if (prev < pos) prev = pos
      else {
        answer--
        break
      }
    }
    answer++
  }
  return answer
}
