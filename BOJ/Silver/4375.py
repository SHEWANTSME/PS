#  1 - S3 - 2023/08/27
# python 코드
def Func(n):
    num = 1
    ones = 1
    while True:
        if ones % n == 0:
            return num
        ones = ones * 10 + 1 # python은 big integer를 지원하기 때문에 overflow가 발생하지 않음
        num += 1
while True:
    try: # python에서는 try & except로 EOFError를 처리해줘야함
        n=int(input())
        print(Func(n))
    except EOFError: # c++의 cin.eof()랑 비슷한거라고 보면 됨
        break