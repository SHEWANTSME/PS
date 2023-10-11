# 타이핑 - S1 - 2023/10/08
string =input()
flag = False # flag : 마름모 activate 여부
cnt =0 # cnt : 특수문자 누른 횟수
for i in range(len(string)):
    if i == len(string)-1:
        if flag == False and string[-1].isupper(): # 마름모 비활성 + 마지막문자 대문자
            cnt+=1 # 별을 눌러줘야하니 cnt+=1
        elif flag == True and string[-1].islower():# 마름모 활성 + 마지막문자 소문자
            cnt+=1 # 별을 눌러줘야하니 cnt+=1
    else:
        if flag == False: # 마름모 비활성
            if string[i].isupper():# 현재 문자가 대문자일 때
                if string[i+1].isupper():# 다음 문자도 대문자일 때
                    flag=True # 마름모 활성화
                cnt+=1  # 특수문자 누른 횟수 증가
        else: # 마름모 활성
            if string[i].islower():# 현재 문자가 소문자일 때
                if string[i+1].islower():# 다음 문자도 소문자일 때
                    flag=False# 마름모 비활성화
                cnt+=1# 특수문자 누른 횟수 증가
print(len(string)+cnt)

