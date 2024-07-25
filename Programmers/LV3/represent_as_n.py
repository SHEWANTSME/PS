from collections import defaultdict# defaultdict를 사용하면 키가 없을 때 자동으로 디폴트 값을 생성
def solution(n, goal_num):
    if n==goal_num: return 1
    # 초기화
    dp = defaultdict(set)
    dp[1].add(n)

    # 최대 8번까지 시도
    for i in range(2, 9):
        for j in range(1, i):
            for x in dp[j]:
                for y in dp[i - j]:
                    dp[i].add(x + y)
                    dp[i].add(x - y)
                    dp[i].add(x * y)
                    if y != 0: dp[i].add(x // y)
        # 숫자의 결합
        dp[i].add(int(str(n) * i))

        # 목표 숫자가 dp[i]에 포함되면 반환
        if goal_num in dp[i]:
            return i

    # 목표 숫자를 만들 수 없을 경우 -1 반환
    return -1
