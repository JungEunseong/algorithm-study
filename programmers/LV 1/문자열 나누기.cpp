int solution(const char* s) {

    int answer = 0;

    int len = strlen(s);

    char x = *(s + 0);
    int firstChar = 0;
    int diffChar = 0;
    for (int i = 0; i < len; i++)
    {

        if (*(s + i) == x)
            firstChar++;
        else
            diffChar++;

        if (firstChar == diffChar) {
            x = *(s + i + 1);
            answer++;
            continue;
        }




        if (i == (len - 1) && firstChar != diffChar) {
            answer++;
            break;
        }

    }


    return answer;
}