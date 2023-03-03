public int[] solution(int[] lottos, int[] win_nums)
{

    int rightCnt = 0;
    int noAnswerCnt = 0;
    for (int i = 0; i < lottos.Length; i++)
    {
        for (int j = 0; j < win_nums.Length; j++)
        {
            if (lottos[i] == 0)
            {
                noAnswerCnt++;
                break;
            }
            else if (lottos[i] == win_nums[j])
                rightCnt++;
        }
    }

    int max = 7 - rightCnt - noAnswerCnt;
    int min = 7 - rightCnt;
    int[] answer = new int[] {(max> 6) ? 6:max, (min > 6) ? 6: min };

    return answer;
}