#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string ch)
{
	deque<char> de;
	for(int i = 0; i < ch.size(); i++)
	{
		de.push_back(ch[i]);
	}
	while(de.size() > 1)
	{
		if(de.front() != de.back())return false;
		de.pop_back();
		de.pop_front();
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string ch; cin >> ch;
	if (isPalindrome(ch))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}