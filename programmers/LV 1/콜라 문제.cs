public int solution(int a, int b, int n)
{
    int answer = 0;
    while (true)
    {
        if (n < a)
            break;
        int getCokeCnt = n / a * b;
        n %= a;
        n += getCokeCnt;
        answer += getCokeCnt;
    }

    return answer;
}