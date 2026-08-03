#include <vector>
#include <string>
#include <iostream>


class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> parenthesisCollection;

        generateValidParenthesis(n, 0, 0, "", parenthesisCollection);

        return parenthesisCollection;
    }

    void generateValidParenthesis(int totalNum, int openCount, int closedCount, std::string currentStr, std::vector<std::string>& parenthesisCollection ) {
        if (totalNum == closedCount) {
            parenthesisCollection.push_back(currentStr);
            return;
        }

        if (openCount < totalNum) {
            std::string updatedStr = currentStr + "(";
            generateValidParenthesis(totalNum, openCount + 1, closedCount, updatedStr, parenthesisCollection);
        }

        if(closedCount < openCount) {
            std::string updatedStr = currentStr + ")";
            generateValidParenthesis(totalNum, openCount, closedCount + 1, updatedStr, parenthesisCollection);
        }
    
    }
};

int main()
{

    Solution* soln = new Solution();

    std::vector<std::string> parenthesis = soln->generateParenthesis(1);
    
    std::cout << "" << std::endl;
    std::cout << "####################################" << std::endl;
    std::cout << "Parenthesis: " << std::endl;
    for (int i = 0; i < parenthesis.size(); i++) {
        std::string current_parenthesis = parenthesis[i];
        std::cout << current_parenthesis << std::endl;
    }
    std::cout << "####################################" << std::endl;
    std::cout << "" << std::endl;


    return 0;
}