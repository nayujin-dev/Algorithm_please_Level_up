function solution(numbers) {
    var answer = [];
    let num=numbers.split('');
    // 가능한 모든 숫자의 순열 찾기
    const getPermutations=(fixed,arr)=>{
        // arr: 아직 선택 안된 수 배열
        // fixed: 선택된수
        if(arr.length>=1){
            for(let i=0;i<arr.length;i++){
                const newNum = fixed+ arr[i];
                const copyArr=[...arr];
                copyArr.splice(i,1);
                if(!answer.includes(+newNum) && isPrimeNum(+newNum)){
                    answer.push(+newNum);
                }
                getPermutations(newNum,copyArr);
            }
        }
    }
    
    // 찾은 순열에 대해, 소수인지 확인
    
    const isPrimeNum=(n)=>{
        if(n<=1) return false;
        for(let i=2;i*i<=n;i++){
            if(n%i===0) return false;
        }
        return true;
    }
    getPermutations('',num);
    return answer.length;
}