function solution(a, b) {
  const dayList = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
  const date = new Date(`2016/${a}/${b}`)
  return dayList[date.getDay()]
}
