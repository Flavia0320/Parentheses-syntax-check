#include<iostream>
#include<stack>
#include<fstream>

int priority(const char& p)
{
	if (p == '(' || p == ')') return 0;
	if (p == '[' || p == ']') return 1;
	return 2;
}

bool parantezareCorecta(std::string cale)
{
	std::ifstream f(cale);
  std::stack<char> S;
	char p;
	while (f >> p)
	{
		if (p == '(' || p == '[' || p == '{')
		{
			if (S.empty() == true || priority(p) == priority(S.top()) - 1)
				S.push(p);
			else return false;
		}
		else if (priority(p) == priority(S.top()))
			S.pop();
		else
			return 0;
	}
	if (S.empty() == false)
		return false;
	return true;

}

int main()
{
	if (parantezareCorecta("expression.txt"))
		std::cout << "Expresie corecta";
  else std::cout << "Expresie incorecta";

  return 0;
}
