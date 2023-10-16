def solution(s, n):
    answer = ''
    for i in range(len(s)):
        if(65<=ord(s[i])<=90):
            if(ord(s[i])+n>90):
                answer+=chr((ord(s[i])+n)%90+64)
            else:
                answer+=chr((ord(s[i])+n))
        elif (97<=ord(s[i])<=122):
            if(ord(s[i])+n>122):
                answer+=chr((ord(s[i])+n)%122+96)
            else:
                answer+=chr(ord(s[i])+n)
        else:
            answer+=' '
    return answer