function solution(numbers) {
    const answer = [];
    let nums = numbers.split(''); 

    // // 소수 판별
    // const isPrimeNum = (num) => {
    //     if(num === 1) return false; //1은 소수가 아니다.
    //     // 1과 자기자신을 제외하고 반복문을 수행하도록 한다.
    //     for(let i = 2; i < num; i++) {
    //         if(num % i === 0) return false;
    //         //num이 다른 수로 나눠떨어진다면 소수가 아니다.
    //     } 
    //     return true; //반복문을 종료할때까지 if문이 실행되지 않았다면 소수이다.
    // }

    const isPrimeNum = (num) => {
        if(num<=1) return false;
        for (let i = 2; i*i <= num; i++) {
            if (num % i === 0) return false;
        }
        return true;
    }

  
    // 순열 만들기
    const getPermutation = (arr, fixed) => {
        if(arr.length >= 1) {
            for (let i=0; i<arr.length; i++) {
                const newNum = fixed + arr[i];
                const copyArr = [...arr];
                copyArr.splice(i, 1);
                // console.log(i+" "+newNum);
                // console.log(typeof(newNum));
                // console.log(typeof(+newNum));
                
                if (!answer.includes(+newNum) && isPrimeNum(+newNum)){
                    answer.push(+newNum) 
                }
                getPermutation(copyArr, newNum); 
            }
        }
    }
    
    getPermutation(nums, '');
    return answer.length;
}