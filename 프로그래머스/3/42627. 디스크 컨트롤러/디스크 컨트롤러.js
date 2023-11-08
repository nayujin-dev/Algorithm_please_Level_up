class PriorityQueue {
  constructor() {
    this.item = [];
  }

  get length() {
    return this.item.length;
  }

  get heap() {
    return this.item;
  }

  getParent(index) {
    return Math.floor((index - 1) / 2);
  }

  getLeftChild(index) {
    return index * 2 + 1;
  }

  getRightChild(index) {
    return index * 2 + 2;
  }

  swap(a, b) {
    
    // 구조분해 할당을 이용하면 임시 변수를 생성할 필요 없이 값을 쉽게 교환할 수 있다.
    [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
  }

  // 노드를 추가할 때 bubbleUp 방식으로 부모와 값을 비교하며 heapify를 실행한다.
  bubbleUp(index) {
    if (index < 0) return;

    const left = this.getLeftChild(index);
    const right = this.getRightChild(index);

    const swapChildren =
      this.item[right] && this.item[right][1] < this.item[left][1]
        ? right
        : left;
        
    if (this.item[swapChildren][1] < this.item[index][1]) {
      this.swap(swapChildren, index);
      this.bubbleUp(this.getParent(index));
    }
  }

  // 루트 노드를 삭제한 후 bubbleDown 방식으로 자식들과 값을 비교하며 heapify를 실행한다.
  bubbleDown(index) {
    if(index > Math.floor(this.length / 2) - 1) return;

    const left = this.getLeftChild(index);
    const right = this.getRightChild(index);

    const swapChildren =
      this.item[right] && this.item[right][1] < this.item[left][1]
        ? right
        : left;

    if (this.item[swapChildren][1] < this.item[index][1]) {
      this.swap(swapChildren, index);
    } 

    this.bubbleDown(swapChildren);

  }

  shift() {
    this.swap(0, this.length - 1);
    const pop = this.item.pop();
    this.bubbleDown(0);
    return pop;
  }

  push(value) {
    this.item.push(value);
    this.bubbleUp(this.getParent(this.length - 1));
  }
}

function solution(jobs) {
    let answer = 0;
    jobs.sort((job1, job2)=>job1[0]-job2[0]);
    
    let pq=new PriorityQueue();
    let i=0;
    let time=0; // 현재 시간
    
    while(i< jobs.length || pq.length!==0){
        if(i<jobs.length && jobs[i][0]<=time){ // 작업 진행 중 도착한 작업들 pq에 추가 후 정렬
            pq.push(jobs[i++]);
            continue;
        }
        
        // 현재 도착한 작업이 없을때
        if(pq.length===0){
            time = jobs[i][0]; // 남아있는 것 중 맨 앞 작업 시작. 현재 시간도 그에 맞게 재설정 
        }else{ // 대기하던 작업 처리
            let [start,duration] = pq.shift(); // minheap pop
            answer += time + duration - start;
            time += duration; // 현재 시간 재설정
        }
    }
    
    return Math.floor(answer/jobs.length); //소수점 이하의 수는 버리기
}
