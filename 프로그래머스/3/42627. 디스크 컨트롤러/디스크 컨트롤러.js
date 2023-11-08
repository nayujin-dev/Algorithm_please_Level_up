function solution(jobs) {
    let answer = 0;
    jobs.sort((job1, job2)=>job1[0]-job2[0]);
    
    let priorityQueue=[];
    let i=0, time=0;
    while(i< jobs.length || priorityQueue.length!==0){
        if(i<jobs.length && jobs[i][0]<=time ){
            priorityQueue.push(jobs[i++]);
            priorityQueue.sort((a,b) => a[1]-b[1]);
            continue;
        }
        if(priorityQueue.length!==0){
            time+=priorityQueue[0][1]; // minheap 값 가져올것
            answer+= time - priorityQueue[0][0];
            priorityQueue.shift(); // minheap pop
        }else{
            time = jobs[i][0];
        }
    }
    
    return Math.floor(answer/jobs.length);
}