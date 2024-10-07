#include <iostream>
#include <vector>

class Apple
{
public:
	enum color_index {color_red,color_green,color_yellow};
	color_index color;
	double weight;
	std::string kind;

	Apple() {
		color = color_red;
		weight = 320.0;
		kind = "ふじ";
	}
	Apple(const enum color_index &c, const double w, const char *k) {
		color = c;
		weight = w;
		kind = k;
	}
	const char *GetColorName() {
		static const char *color_name[] = { "赤", "青", "黄" };
		return color_name[color];
	}
	void PrintData() {
		printf("色=%s 重さ=%5.1fg 品種=%s\n",
			GetColorName(), weight, kind.c_str());
	}
};

class AppleBox
{
public:
	AppleBox() { Empty(); }

	bool Add(Apple &r);
	bool Del(int index);
	void Empty() { apple.clear(); }
	int GetTotalNum() { return (int)apple.size(); }
	double GetTotalWeight();
	void PrintData();

private:
	std::vector<Apple> apple;
};

bool AppleBox::Add(Apple &r)
{
	if (apple.size() > 40) return false;
	apple.push_back(r);
	return true;
}

bool AppleBox::Del(int index)
{
	if (index < 1 || index >(int)apple.size()) return false;
	apple.erase(ringo.begin() + index - 1);
	return true;
}

double AppleBox::GetTotalWeight()
{
	double w = 0;
	for (std::vector<Apple>::iterator i = apple.begin(); i != apple.end(); i++)
		w += (*i).weight;
	return w;
}

void AppleBox::PrintData()
{
	int n = GetTotalNum();

	for (int i = 0; i < n; i++)
		apple[i].PrintData();
	printf("%d個のりんごがあります。\n", n);
	printf("総重量%5.1fg\n", GetTotalWeight());
}

int main()
{
	static const char init_num = 4;
	Apple myApple[] = {
		Apple(Apple::color_red,316.2, "ふじ"),
		Apple(Apple::color_green,352.1, "王林"),
		Apple(Apple::color_red,341.8, "つがる"),
		Apple(Apple::color_yellow,320.7, "ゴールデンデリシャス")
	};

	AppleBox myAppleBox;
	//箱に全て入れる
	for (int i = 0; i < init_num; i++) {
		bool ret = myAppleBox.Add(myApple[i]);
		if (ret)
			std::cout << "1個追加" << std::endl;
	}

	//２番目のりんごを箱から出す
	bool ret = myAppleBox.Del(2);
	if (ret)
		std::cout << "1個削除" << std::endl;

	//データを全て表示する
	myAppleBox.PrintData();
}
