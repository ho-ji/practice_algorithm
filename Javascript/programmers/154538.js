class Queue {
  constructor() {
    this.queue = {}
    this.check = []
    this.front = 0
    this.rear = 0
  }
  size() {
    return this.queue[this.rear - 1] ? this.rear - this.front : 0
  }
  enqueue(data) {
    if (!this.check[data[0]]) {
      this.queue[this.rear++] = data
      this.check[data[0]] = true
    }
  }
  dequeue() {
    let data = this.queue[this.front]
    delete this.queue[this.front]
    this.front++
    return data
  }
}

function solution(x, y, n) {
  let answer = -1
  let list = new Queue()
  list.enqueue([x, 0])

  if (x === y) return 0
  while (list.size() !== 0) {
    let [num, count] = list.dequeue()

    if (num === y) return count
    if (num + n <= y) list.enqueue([num + n, count + 1])
    if (num * 2 <= y) list.enqueue([num * 2, count + 1])
    if (num * 3 <= y) list.enqueue([num * 3, count + 1])
  }

  return answer
}
