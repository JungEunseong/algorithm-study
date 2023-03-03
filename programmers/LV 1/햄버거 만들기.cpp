int solution(vector<int> ingredient) {

    int answer = 0;
    vector<int> stacked_ingredient;


    vector<int> hamburger{ 1,2,3,1 };
    for (auto i = ingredient.begin(); i != ingredient.end(); ++i)
    {

        stacked_ingredient.push_back(*i);



        if (stacked_ingredient.size() >= 4 && vector<int>{ stacked_ingredient.end() - 4, stacked_ingredient.end() } == hamburger)
        {
            answer++;
            for (int k = 0; k < 4; k++)
            {
                stacked_ingredient.pop_back();
            }
        }
    }
    return answer;
}
