function solution(jobs) {
    let answer = 0;
    jobs.sort((job1, job2)=>job1[0]-job2[0]);
    
    let pq=[];
    let i=0, time=0;
    while(i< jobs.length || pq.length!==0){
        if(i<jobs.length && jobs[i][0]<=time){
            pq.push(jobs[i++]);
            pq.sort((a,b) => a[1]-b[1]); // 소요시간 오름차순
            continue;
        }
        if(pq.length!==0){
            time+=pq[0][1]; // minheap 값 가져올것
            answer+= time - pq[0][0]; // minheap 값 가져올것
            pq.shift(); // minheap pop
        }else{ // 우선순위큐는 비었지만, jobs를 다 순회하지 않은 경우 -> 들어온 순서대로
            time = jobs[i][0];
        }
    }
    
    return Math.floor(answer/jobs.length); //소수점 이하의 수는 버리기
}