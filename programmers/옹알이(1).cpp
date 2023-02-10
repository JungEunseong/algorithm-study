int solution(vector<string> babbling) {

    string canSay[] = { "aya", "ye", "woo", "ma" };
    int answer = 0;

    for (auto bab = babbling.begin(); bab != babbling.end(); ++bab)
    {
        string b = *bab;
        for (int i = 0; i < sizeof(canSay) / sizeof(*canSay); i++)
        {
            while (b.find(canSay[i]) != string::npos)
                b.replace(b.find(canSay[i]), canSay[i].length(), " ");

        }

        while (b.find(" ") != string::npos)
            b.replace(b.find(" "), 1, "");
        if (b == "") {
            answer++;
        }


    }
    return answer;
}