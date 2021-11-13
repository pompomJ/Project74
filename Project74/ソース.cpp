#include <iostream>
#include <vector>

class Ringo
{
public:
	enum color_index {color_red,color_green,color_yellow};
	color_index color;
	double weight;
	std::string kind;

	Ringo() {
		color = color_red;
		weight = 320.0;
		kind = "�ӂ�";
	}
	Ringo(const enum color_index &c, const double w, const char *k) {
		color = c;
		weight = w;
		kind = k;
	}
	const char *GetColorName() {
		static const char *color_name[] = { "��", "��", "��" };
		return color_name[color];
	}
	void PrintData() {
		printf("�F=%s �d��=%5.1fg �i��=%s\n",
			GetColorName(), weight, kind.c_str());
	}
};

class RingoBox
{
public:
	RingoBox() { Empty(); }

	bool Add(Ringo &r);
	bool Del(int index);
	void Empty() { ringo.clear(); }
	int GetTotalNum() { return (int)ringo.size(); }
	double GetTotalWeight();
	void PrintData();

private:
	std::vector<Ringo> ringo;
};

bool RingoBox::Add(Ringo &r)
{
	if (ringo.size() > 40) return false;
	ringo.push_back(r);
	return true;
}

bool RingoBox::Del(int index)
{
	if (index < 1 || index >(int)ringo.size()) return false;
	ringo.erase(ringo.begin() + index - 1);
	return true;
}

double RingoBox::GetTotalWeight()
{
	double w = 0;
	for (std::vector<Ringo>::iterator i = ringo.begin(); i != ringo.end(); i++)
		w += (*i).weight;
	return w;
}

void RingoBox::PrintData()
{
	int n = GetTotalNum();

	for (int i = 0; i < n; i++)
		ringo[i].PrintData();
	printf("%d�̂�񂲂�����܂��B\n", n);
	printf("���d��%5.1fg\n", GetTotalWeight());
}

int main()
{
	static const char init_num = 4;
	Ringo myRingo[] = {
		Ringo(Ringo::color_red,316.2, "�ӂ�"),
		Ringo(Ringo::color_green,352.1, "����"),
		Ringo(Ringo::color_red,341.8, "����"),
		Ringo(Ringo::color_yellow,320.7, "�S�[���f���f���V���X")
	};

	RingoBox myRingoBox;
	//���ɑS�ē����
	for (int i = 0; i < init_num; i++) {
		bool ret = myRingoBox.Add(myRingo[i]);
		if (ret)
			std::cout << "1�ǉ�" << std::endl;
	}

	//�Q�Ԗڂ̂��̂𔠂���o��
	bool ret = myRingoBox.Del(2);
	if (ret)
		std::cout << "1�폜" << std::endl;

	//�f�[�^��S�ĕ\������
	myRingoBox.PrintData();
}