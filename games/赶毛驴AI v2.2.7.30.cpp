#include <bits/stdc++.h>
#include <windows.h>
#define set_color(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x)
#define VER "2.2.7.30"	//添加电脑摸牌冷却时间（0.5s） 
using namespace std;
struct player {string name; int score;} p[1005];
int ptot, pos; 
void liyuanchen2021(int nowcolor) {
	set_color(nowcolor);
	cout << " _ _                              _                ____   ___ ____  _ \n";
	cout << "| (_)_   _ _   _  __ _ _ __   ___| |__   ___ _ __ |___ \\ / _ \\___ \\/ |\n";
	cout << "| | | | | | | | |/ _` | '_ \\ / __| '_ \\ / _ \\ '_ \\  __) | | | |__) | |\n"; 
	cout << "| | | |_| | |_| | (_| | | | | (__| | | |  __/ | | |/ __/| |_| / __/| |\n";
	cout << "|_|_|\\__, |\\__,_|\\__,_|_| |_|\\___|_| |_|\\___|_| |_|_____|\\___/_____|_|\n";
	cout << "     |___/                                                            \n";
	set_color(15), cout << "赶毛驴AI v" << VER << endl;
	cout << "Loading...\n";
	Sleep(1000);
	system("cls"); 
} 
void Add(int add) {
	p[pos].score += add;
	ofstream fout("赶毛驴AI.txt");
	fout << ptot << endl;
	for (int i = 1; i <= ptot; i++)	fout << p[i].name << ' ' << p[i].score << endl;
	fout.close();
}
struct poke {
	int number, color;
	bool joker, Joker;
	void pokee(int _number, int _color) {
		number = color = 0, joker = Joker = false;
		if (_number == 0 && _color == 1)	joker = true;
		else if (_number == 0 && _color == 2)	Joker = true;
		number = _number, color = _color;
	}
	void output() {
		if (Joker == true) {set_color(4); cout << "大王"; set_color(15); return;}
		else if (joker == true) {set_color(15); cout << "小王"; return;}
		else if (color == 2 || color == 4) {
			set_color(4);
			if (color == 2)	cout << "红桃";
			else	cout << "方片";
		} else {
			set_color(15);
			if (color == 1)	cout << "黑桃";
			else	cout << "梅花";
		} 
		string s = "0A234567890JQK";
		if (number == 10)	cout << 10;
		else	cout << s[number];
		set_color(15); 
	}
	void _output() {
		set_color(8);
		if (Joker == true) {cout << "大王"; set_color(15); return;}
		else if (joker == true) {cout << "小王"; set_color(15); return;}
		if (color == 2)	cout << "红桃";
		else if (color == 4)	cout << "方片";
		else if (color == 1)	cout << "黑桃";
		else	cout << "梅花";
		string s = "0A234567890JQK";
		if (number == 10)	cout << 10;
		else	cout << s[number];
		set_color(15); 
	} 
	void print() {output(); cout << '\n';}
	void _print() {output(); cout << ' ';}
	void grey_print() {_output(); cout << '\n';}
	void _grey_print() {_output(); cout << ' ';}
};
int lv[41] = {0, 1, 50, 100, 150, 200, 300, 400, 600, 800, 1000, 1500, 2000, 3000, 4000, 6000, 8000, 10000, 15000, 20000, 30000, 40000, 50000, 60000, 80000, 100000, 150000, 200000, 300000, 400000, 600000, 800000, 1000000, 1500000, 2000000, 3000000, 4000000, 5000000, 6000000, 8000000, 10000000};
int get_level(int score) {
	for (int i = 1; i <= 40; i++)
		if (score < lv[i])	return i - 1;
	return 38;
}
int get_color(string String) {
	int len = min(String.size(), min(String.find('['), String.find('(')));
	string _string = String.substr(0, len);
	int nowpos = -1;
	for (int i = 1; i <= ptot; i++)
		if (p[i].name == _string) {
			nowpos = i; break;
		}
	if (nowpos == -1)	return 0;
	int nowlevel = get_level(p[nowpos].score);
	if (nowlevel < 1)	return 8;
	else if (nowlevel < 3)	return 1;
	else if (nowlevel < 6)	return 3;
	else if (nowlevel < 10)	return 11;
	else if (nowlevel < 15)	return 2;
	else if (nowlevel < 20)	return 10;
	else if (nowlevel < 25)	return 6;
	else if (nowlevel < 30)	return 12;
	else if (nowlevel < 40)	return 4;
	else	return 13;
}
void name(string String) {set_color(get_color(String)), cout << String, set_color(15);}
void name1(string String) {set_color(15); cout << String;}
void name2(string String) {name1(String);}
queue<poke> pl;
bool hand[3][20][20];
poke poo[54];
void setup() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 20; j++)
			for (int k = 0; k < 20; k++)
				hand[i][j][k] = false;
	while (!pl.empty())	pl.pop();
	int i, j;
	poo[0].pokee(0, 1), poo[1].pokee(0, 2);
	for (i = 2, j = 1; i <= 14; i++, j++)	poo[i].pokee(j, 1);
	for (i = 15, j = 1; i <= 27; i++, j++)	poo[i].pokee(j, 2);
	for (i = 28, j = 1; i <= 40; i++, j++)	poo[i].pokee(j, 3);
	for (i = 41, j = 1; i <= 53; i++, j++)	poo[i].pokee(j, 4);
	random_shuffle(poo, poo + 54);
	for (i = 0; i < 54; i++)	pl.push(poo[i]);
	for (int idx = 0; idx <= 2; idx++) {
		for (i = 1; i <= 7; i++) {
			poke now = pl.front();
			pl.pop(), hand[idx][now.number][now.color] = true;
		}
	}
}
int A[14] = {0, 12, 13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
bool fff[3], first = true;
string s;
void init() {
	memset(fff, false, sizeof(fff));
	set_color(15); srand(time(0));
	ifstream fin("赶毛驴AI.txt");
	fin >> ptot;
	for (int i = 1; i <= ptot; i++)	fin >> p[i].name >> p[i].score;
	fin.close();
}
void putline() {
	for (int i = 1; i <= 40; i++)	cout << '-';
	cout << '\n';
}
string num_to_str(int x) {
	bool fu = false;
	if (x < 0)	x = -x, fu = true;
	string str;
	while (x)	str += (char)('0' + x % 10), x /= 10;
	if (fu)	str += '-';
	reverse(str.begin(), str.end());
	if (!str.size())	return "0"; 
	return str;
} 
int sortcolor[14] = {0, 2, 5, 3, 9, 0, 7, 0, 1, 0, 6, 4, 8, 10};
int main() {
	int covercolor = 8;
	init();
	for (int i = 1; i <= ptot; i++) {
		int Nowcolor = get_color(p[i].name);
		if (sortcolor[Nowcolor] > sortcolor[covercolor])	covercolor = Nowcolor;
	}
	liyuanchen2021(covercolor);
	while (1) {
		init();
		if (first) {
			cout << "赶毛驴AI v" << VER << endl;
			cout << "有BUG欢迎私信反馈，洛谷用户名：liyuanchen2021" << endl;
			putline();
			cout << "游戏规则" << endl;
			cout << "1.准备：每个玩家摸7张牌" << endl;
			cout << "2.出牌：每轮一人出一张牌，按花色出牌，大小王能当任何花色" << endl;
			cout << "3.跟牌：一人选择出一张牌，对方必须出同花色的牌；如果没有，要从剩余的牌里拿，直到拿到同花色的牌或大小王为止" << endl;
			cout << "4.跟牌时，大小王也可以当任一花色的牌使用，但是比任何牌都小；但是在每轮第一次出牌时比任何牌都大，且大王>小王，跟牌时可以跟任意花色的牌" << endl;
			cout << "5.牌的大小以数字为准，比较大小定下一轮谁先出；大小顺序：大王>小王>2>A>K>Q>J>10>9>8>7>6>5>4>3" << endl;
			cout << "6.先出完者为胜；越先出完牌，拿到的分数越多，每局最高198分，等级最高为Lv.40；游戏持续到只剩下一位玩家为止" << endl;
			putline(), cout << "请输入玩家ID，以开始游戏：", cin >> s;
			bool F = false;
			for (int i = 1; i <= ptot; i++)
				if (p[i].name == s) {
					F = true, pos = i; break;
				}
			if (F) {
				cout << "欢迎回来，";
				name(p[pos].name + "[Lv." + num_to_str(get_level(p[pos].score)) + ']' + '(' + num_to_str(p[pos].score) + ')');
				cout << '\n';
			} else {
				ptot++, p[ptot].name = s, p[ptot].score = 0, pos = ptot;
				cout << "已为您注册新ID：";
				name(p[pos].name + "[Lv." + num_to_str(get_level(p[pos].score)) + ']' + '(' + num_to_str(p[pos].score) + ')');
				cout << '\n', Add(0);
			}
			s = p[pos].name + "[Lv." + num_to_str(get_level(p[pos].score)) + ']' + '(' + num_to_str(p[pos].score) + ')';
			cout << "3秒后将进入...\n";
			Sleep(3000), system("cls");
		}
		int _level = get_level(p[pos].score);
		first = false;
		cout << "本局玩家" << endl;
		string pc1, pc2;
		for (int i = 1; i <= 6; i++)	pc1 += rand() % 26 + 'A', pc2 += rand() % 26 + 'A';
		pc1 += "[电脑]", pc2 += "[电脑]";
		int add = 0;
		name(s); cout << endl;
		name1(pc1); cout << endl;
		name2(pc2); cout << endl;
		putline(); setup();
		int hs = 0, xs = rand() % 3, p0c = 0, p1c = 0, p2c = 0, rp0 = 7, rp1 = 7, rp2 = 7, pass = 0, Pass = 0, fe0 = 0, fe1 = 0, fe2 = 0, final, w1, w2, remain = 3, num = 0;
		bool flag, Flag = false, jokerf = false, rfirst = false, gfirst = true;
		poke po;
		while ((rp0 != 0) + (rp1 != 0) + (rp2 != 0) > 1) {
			rfirst = false;
			if (gfirst)	rfirst = true, gfirst = false;
			if (fff[xs]) {
				if (xs == 0)	xs = 1, p0c = -2;
				else if (xs == 1)	xs = 2, p1c = -2;
				else	xs = 0, p2c = -2;
				if (num % remain == 0 && num != 0) {
					hs = 0;
					if (p0c > p1c && p0c > p2c)
						name(s), cout << "的牌最大" << endl, xs = 0;
					else if (p1c > p0c && p1c > p2c)
						name1(pc1), cout << "的牌最大" << endl, xs = 1;
					else if (p2c > p0c && p2c > p1c)
						name2(pc2), cout << "的牌最大" << endl, xs = 2;
					p0c = p1c = p2c = 0, jokerf = false, rfirst = true;
					if (remain == 3)	putline();
					if (Flag && remain == 3)	remain--, num = 0;
				}
				continue;
			}
			if (num % remain == 0 && num != 0) {
				hs = 0;
				if (p0c > p1c && p0c > p2c)
					name(s), cout << "的牌最大" << endl, xs = 0;
				else if (p1c > p0c && p1c > p2c)
					name1(pc1), cout << "的牌最大" << endl, xs = 1;
				else if (p2c > p0c && p2c > p1c)
					name2(pc2), cout << "的牌最大" << endl, xs = 2;
				p0c = p1c = p2c = 0, jokerf = false, rfirst = true;
				putline();
				if (Flag && remain == 3)	remain--, num = 0;
			}
			if (xs == 1) {
				Sleep(1000);
				w1 = hand[1][0][1] + hand[1][0][2];
				flag = false;
				if (jokerf) {
					if ((p0c == 14 || p2c == 14) && hand[1][0][2]) {
						hand[1][0][2] = false;
						name1(pc1);
						cout << "打出了";
						po.pokee(0, 2);
						po.print();
						rp1--;
						p1c = 15;
						flag = true;
					} else {
						for (int i = 3; i <= 13 && !flag; i++) {
							for (int j = 1; j <= 4 && !flag; j++) {
								if (!hand[1][i][j])	continue;
								hand[1][i][j] = false;
								name1(pc1);
								cout << "打出了";
								po.pokee(i, j);
								po.print();
								rp1--;
								p1c = A[i];
								flag = true;
							}
						}
						for (int i = 1; i <= 2 && !flag; i++) {
							for (int j = 1; j <= 4 && !flag; j++) {
								if (!hand[1][i][j])	continue;
								hand[1][i][j] = false;
								name1(pc1);
								cout << "打出了";
								po.pokee(i, j);
								po.print();
								rp1--;
								p1c = A[i];
								flag = true;
							}
						}
						if (hand[1][0][1] && !flag) {
							hand[1][0][1] = false;
							name1(pc1);
							cout << "打出了";
							po.pokee(0, 1);
							po.print();
							rp1--;
							p1c = 14;
							flag = true;
						}
						if (hand[1][0][2] && !flag) {
							hand[1][0][2] = false;
							name1(pc1);
							cout << "打出了";
							po.pokee(0, 2);
							po.print();
							rp1--;
							p1c = 15;
							flag = true;
						}
					}
				}
				if (!flag && w1 == rp1 - 1 && rp0 > w1 && rp2 > w1) {
					if (hand[1][0][2]) {
						hand[1][0][2] = false;
						name1(pc1);
						cout << "打出了";
						po.pokee(0, 2);
						po.print();
						rp1--;
						p1c = 15;
						flag = true;
						if (rfirst)	jokerf = true;
					}
					if (!flag && hand[1][0][1]) {
						hand[1][0][1] = false;
						name1(pc1);
						cout << "打出了";
						po.pokee(0, 1);
						po.print();
						rp1--;
						p1c = 14;
						flag = true;
						if (rfirst)	jokerf = true;
					}
				}
				if (!flag && hs == 0 && pass != 0) {
					for (int i = 2; i >= 1; i--) {
						if (hand[1][i][pass]) {
							hand[1][i][pass] = false;
							name1(pc1);
							cout << "打出了";
							po.pokee(i, pass);
							po.print();
							flag = true;
							rp1--;
							p1c = A[i];
							hs = pass;
							break;
						}
					}
					if (!flag) {
						for (int i = 13; i >= 3; i--) {
							if (hand[1][i][pass]) {
								hand[1][i][pass] = false;
								name1(pc1);
								cout << "打出了";
								po.pokee(i, pass);
								po.print();
								flag = true;
								rp1--;
								p1c = A[i];
								hs = pass;
								break;
							}
						}
					}
				}
				if (!flag) {
					if (hs == 0) {
						for (int i = 2; i >= 1; i--) {
							for (int j = 1; j <= 4; j++) {
								if (hand[1][i][j]) {
									hand[1][i][j] = false;
									name1(pc1);
									cout << "打出了";
									po.pokee(i, j);
									po.print();
									flag = true;
									rp1--;
									p1c = A[i];
									hs = j;
									break;
								}
							}
							if (flag)	break;
						}
						if (!flag) {
							for (int i = 13; i >= 3; i--) {
								for (int j = 1; j <= 4; j++) {
									if (hand[1][i][j]) {
										hand[1][i][j] = false;
										name1(pc1);
										cout << "打出了";
										po.pokee(i, j);
										po.print();
										flag = true;
										rp1--;
										p1c = A[i];
										hs = j;
										break;
									}
								}
								if (flag)	break;
							}
						}
						if (!flag) {
							if (hand[1][0][1]) {
								hand[1][0][1] = false;
								name1(pc1);
								cout << "打出了";
								po.pokee(0, 1);
								po.print();
								rp1--;
								p1c = 14;
								flag = true;
							}
						}
						if (!flag) {
							if (hand[1][0][2]) {
								hand[1][0][2] = false;
								name1(pc1);
								cout << "打出了";
								po.pokee(0, 2);
								po.print();
								rp1--;
								p1c = 15;
								flag = true;
							}
						}
					}
					else {
						while (1) {
							for (int i = 2; i >= 1; i--) {
								if (hand[1][i][hs]) {
									hand[1][i][hs] = false;
									name1(pc1);
									cout << "打出了";
									po.pokee(i, hs);
									po.print();
									flag = true;
									rp1--;
									p1c = A[i];
									break;
								}
							}
							if (flag)	break;
							for (int i = 13; i >= 3; i--) {
								if (hand[1][i][hs]) {
									hand[1][i][hs] = false;
									name1(pc1);
									cout << "打出了";
									po.pokee(i, hs);
									po.print();
									flag = true;
									rp1--;
									p1c = A[i];
									break;
								}
							}
							if (flag)	break;
							if (!flag) {
								if (hand[1][0][1]) {
									hand[1][0][1] = false;
									name1(pc1);
									cout << "打出了";
									po.pokee(0, 1);
									po.print();
									rp1--;
									p1c = 0;
									flag = true;
									Pass = hs;
								}
							}
							if (flag)	break;
							if (!flag) {
								if (hand[1][0][2]) {
									hand[1][0][2] = false;
									name1(pc1);
									cout << "打出了";
									po.pokee(0, 2);
									po.print();
									rp1--;
									p1c = 0;
									flag = true;
									Pass = hs;
								}
							}
							if (flag)	break;
							if (!pl.empty()) {
								poke now = pl.front();
								pl.pop();
								hand[1][now.number][now.color] = true;
								rp1++;
								name1(pc1);
								cout << "摸了一张牌" << endl;
								Sleep(500);
							} else {
								name1(pc1);
								cout << "无牌可出" << endl;
								p1c = -1;
								break;
							}
							Pass = hs;
						}
					}
				}
				xs = 2; name1(pc1);
				if (!rp1) {
					set_color(4);
					cout << "已出完\n";
					set_color(15);
					final = 1;
				} else {
					cout << "剩余牌数：";
					if (rp1 == 1)	set_color(4);
					cout << rp1; cout << "张" << endl; set_color(15);
				}
			} else if (xs == 2) {
				Sleep(1000);
				w2 = hand[2][0][1] + hand[2][0][2];
				flag = false;
				if (jokerf) {
					if ((p0c == 14 || p1c == 14) && hand[1][0][2]) {
						hand[1][0][2] = false;
						name2(pc2);
						cout << "打出了";
						po.pokee(0, 2);
						po.print();
						rp1--;
						p1c = 15;
						flag = true;
					} else {
						for (int i = 3; i <= 13 && !flag; i++) {
							for (int j = 1; j <= 4 && !flag; j++) {
								if (!hand[1][i][j])	continue;
								hand[1][i][j] = false;
								name2(pc2);
								cout << "打出了";
								po.pokee(i, j);
								po.print();
								rp1--;
								p2c = A[i];
								flag = true;
							}
						}
						for (int i = 1; i <= 2 && !flag; i++) {
							for (int j = 1; j <= 4 && !flag; j++) {
								if (!hand[1][i][j])	continue;
								hand[1][i][j] = false;
								name2(pc2);
								cout << "打出了";
								po.pokee(i, j);
								po.print();
								rp1--;
								p2c = A[i];
								flag = true;
							}
						}
						if (hand[1][0][1] && !flag) {
							hand[1][0][1] = false;
							name2(pc2);
							cout << "打出了";
							po.pokee(0, 1);
							po.print();
							rp1--;
							p1c = 14;
							flag = true;
						}
						if (hand[1][0][2] && !flag) {
							hand[1][0][2] = false;
							name2(pc2);
							cout << "打出了";
							po.pokee(0, 2);
							po.print();
							rp1--;
							p1c = 15;
							flag = true;
						}
					}
				}
				if (w2 == rp2 - 1 && rp0 > w2 && rp1 > w2) {
					if (hand[2][0][2]) {
						hand[2][0][2] = false;
						name2(pc2);
						cout << "打出了";
						po.pokee(0, 2);
						po.print();
						rp2--;
						p2c = 15;
						flag = true;
						if (rfirst)	jokerf = true;
					}
					if (!flag && hand[2][0][1]) {
						hand[2][0][1] = false;
						name2(pc2);
						cout << "打出了";
						po.pokee(0, 1);
						po.print();
						rp2--;
						p2c = 14;
						flag = true;
						if (rfirst)	jokerf = true;
					}
				}
				if (hs == 0 && Pass != 0) {
					for (int i = 2; i >= 1; i--) {
						if (hand[1][i][Pass]) {
							hand[1][i][Pass] = false;
							name2(pc2);
							cout << "打出了";
							po.pokee(i, Pass);
							po.print();
							flag = true;
							rp1--;
							p2c = A[i];
							hs = Pass;
							break;
						}
					}
					if (!flag) {
						for (int i = 13; i >= 3; i--) {
							if (hand[1][i][Pass]) {
								hand[1][i][Pass] = false;
								name2(pc2);
								cout << "打出了";
								po.pokee(i, Pass);
								po.print();
								flag = true;
								rp1--;
								p2c = A[i];
								hs = Pass;
								break;
							}
						}
					}
				}
				if (!flag && hs == 0) {
					for (int i = 2; i >= 1; i--) {
						for (int j = 1; j <= 4; j++) {
							if (hand[2][i][j]) {
								hand[2][i][j] = false;
								name2(pc2);
								cout << "打出了";
								po.pokee(i, j);
								po.print();
								flag = true;
								rp2--;
								p2c = A[i];
								hs = j;
								break;
							}
						}
						if (flag)	break;
					}
					if (!flag) {
						for (int i = 13; i >= 3; i--) {
							for (int j = 1; j <= 4; j++) {
								if (hand[2][i][j]) {
									hand[2][i][j] = false;
									name2(pc2);
									cout << "打出了";
									po.pokee(i, j);
									po.print();
									flag = true;
									rp2--;
									p2c = A[i];
									hs = j;
									break;
								}
							}
							if (flag)	break; 
						}
					}
					if (!flag) {
						if (hand[2][0][1]) {
							hand[2][0][1] = false;
							name2(pc2);
							cout << "打出了";
							po.pokee(0, 1);
							po.print();
							rp2--;
							p2c = 14;
							flag = true;
						}
					}
					if (!flag) {
						if (hand[2][0][2]) {
							hand[2][0][2] = false;
							name2(pc2);
							cout << "打出了";
							po.pokee(0, 2);
							po.print();
							rp2--;
							p2c = 15;
							flag = true;
						}
					}
				}
				else if (!flag) {
					while (1) {
						for (int i = 3; i <= 13 && A[i] > max(p0c, p1c); i++) {
							if (hand[2][i][hs]) {
								hand[2][i][hs] = false;
								name2(pc2);
								cout << "打出了";
								po.pokee(i, hs);
								po.print();
								flag = true;
								rp2--;
								p2c = A[i];
								break;
							}
						}
						if (flag)	break;
						for (int i = 1; i <= 2 && A[i] > max(p0c, p1c); i++) {
							if (hand[2][i][hs]) {
								hand[2][i][hs] = false;
								name2(pc2);
								cout << "打出了";
								po.pokee(i, hs);
								po.print();
								flag = true;
								rp2--;
								p2c = A[i];
								break;
							}
						}
						if (flag)	break;
						for (int i = 3; i <= 13 && A[i] < max(p0c, p1c); i++) {
							if (hand[2][i][hs]) {
								hand[2][i][hs] = false;
								name2(pc2);
								cout << "打出了";
								po.pokee(i, hs);
								po.print();
								flag = true;
								rp2--;
								p2c = A[i];
								break;
							}
						}
						if (flag)	break;
						for (int i = 1; i <= 2 && A[i] < max(p0c, p1c); i++) {
							if (hand[2][i][hs]) {
								hand[2][i][hs] = false;
								name2(pc2);
								cout << "打出了";
								po.pokee(i, hs);
								po.print();
								flag = true;
								rp2--;
								p2c = A[i];
								break;
							}
						}
						if (flag)	break;
						if (!flag) {
							if (hand[2][0][1]) {
								hand[2][0][1] = false;
								name2(pc2);
								cout << "打出了";
								po.pokee(0, 1);
								po.print();
								rp2--;
								p2c = 0;
								flag = true;
								pass = hs;
							}
						}
						if (flag)	break;
						if (!flag) {
							if (hand[2][0][2]) {
								hand[2][0][2] = false;
								name2(pc2);
								cout << "打出了";
								po.pokee(0, 2);
								po.print();
								rp2--;
								p2c = 0;
								flag = true;
								pass = hs;
							}
						}
						if (flag)	break;
						pass = hs;
						if (!pl.empty()) {
							poke now = pl.front();
							pl.pop();
							hand[2][now.number][now.color] = true;
							rp2++;
							name2(pc2);
							cout << "摸了一张牌" << endl;
							Sleep(500);
						} else {
							name2(pc2);
							cout << "无牌可出" << endl;
							p2c = -1;
							break;
						}
					}
				}
				xs = 0; name2(pc2);
				if (!rp2) {
					set_color(4);
					cout << "已出完\n";
					set_color(15);
					final = 2;
				} else {
					cout << "剩余牌数：";
					if (rp2 == 1)	set_color(4);
					cout << rp2; cout << "张" << endl; set_color(15);
				}
			} else {
				name(s);
				cout << "的手牌" << endl;
				int pocnt = 0;
				if (hand[0][0][2]) {
					po.pokee(0, 2), pocnt++;
					if (pocnt != 1 && pocnt % 10 == 1)	cout << '\n'; 
					po._print();
				}
				if (hand[0][0][1]) {
					po.pokee(0, 1), pocnt++;
					if (pocnt != 1 && pocnt % 10 == 1)	cout << '\n'; 
					po._print();
				}
				for (int j = 1; j <= 4; j++) {
					bool grey_flag = false;
					if (hs && j != hs)	grey_flag = true;
					for (int i = 2; i >= 1; i--) {
						if (!hand[0][i][j])	continue;
						po.pokee(i, j), pocnt++;
						if (pocnt != 1 && pocnt % 10 == 1)	cout << '\n'; 
						if (grey_flag)	po._grey_print();
						else	po._print();
					}
					for (int i = 13; i >= 3; i--) {
						if (!hand[0][i][j])	continue;
						po.pokee(i, j), pocnt++;
						if (pocnt != 1 && pocnt % 10 == 1)	cout << '\n'; 
						if (grey_flag)	po._grey_print();
						else	po._print();
					}
					set_color(15);
				}
				cout << '\n';
				while (1) {
					if (hs) {
						cout << "摸牌堆剩余牌数：";
						if (pl.size() > 10)	cout << pl.size() << "张";
						else if (!pl.size())	set_color(4), cout << "无牌";
						else	set_color(6), cout << pl.size() << "张";
						set_color(15), cout << '\n'; 
					}
					int x, y;
					cout << "数字（1代表A，11代表J，12代表Q，13代表K，14代表小王，15代表大王，摸牌输入0）：";
					cin >> x;
					if (x == 0) {
						if (hs == 0) {
							cout << "目前尚未确定花色，无法摸牌" << endl;
							continue;
						}
						if (!pl.empty()) {
							poke now = pl.front();
							pl.pop();
							hand[0][now.number][now.color] = true, rp0++;
							name(s), cout << "摸了一张牌：";
							if (hs && now.color != hs)	now.grey_print();
							else	now.print();
						} else {
							name(s), cout << "无牌可出" << endl;
							p0c = -1;
							break;
						}
						pass = Pass = hs;
					}
					else if (x == 14) {
						if (!hand[0][0][1]) {
							cout << "错误！" << endl;
							continue;
						}
						po.pokee(0, 1);
						name(s);
						cout << "打出了";
						po.print();
						hand[0][0][1] = false;
						rp0--;
						if (hs == 0)	p0c = 14; 
						else	p0c = 0;
						if (rfirst)	jokerf = true;
						pass = Pass = hs;
						break;
					} 
					else if (x == 15) {
						if (!hand[0][0][2]) {
							cout << "错误！" << endl;
							continue;
						}
						po.pokee(0, 2);
						name(s);
						cout << "打出了";
						po.print();
						hand[0][0][2] = false;
						rp0--;
						if (hs == 0)	p0c = 15;
						else	p0c = 0;
						if (rfirst)	jokerf = true;
						pass = Pass = hs;
						break;
					}
					else if (hs != 0) {
						if (!hand[0][x][hs]) {
							cout << "错误！" << endl;
							continue;
						}
						po.pokee(x, hs);
						name(s);
						cout << "打出了";
						po.print();
						hand[0][x][hs] = false;
						rp0--;
						p0c = A[x];
						break;
					}
					else if (x != 0) {
						cout << "花色（1代表黑桃，2代表红桃，3代表梅花，4代表方片）：";
						cin >> y;
						if (!hand[0][x][y] || (hs != 0 && hs != y)) {
							cout << "错误！" << endl;
							continue;
						}
						po.pokee(x, y);
						name(s);
						cout << "打出了";
						po.print();
						hand[0][x][y] = false;
						hs = y;
						rp0--;
						p0c = A[x];
						break;
					}
				}
				xs = 1, name(s);
				if (!rp0) {
					set_color(4);
					cout << "已出完\n";
					set_color(15);
					final = 0;
				} else {
					cout << "剩余牌数：";
					if (rp0 == 1)	set_color(4);
					cout << rp0; cout << "张" << endl; set_color(15);
				}
			}
			if ((rp0 == 0 || rp1 == 0 || rp2 == 0) && !Flag) {
				Flag = true;
				if (rp0 == 0) {
					int x = rp1 + rp2, y;
					x /= 2;
					if (x < 1)	x = 1;
					if (x > 11)	x = 11;
					y = rand() % 9 + 1;
					add = fe0 = x * y * 2;
					s = p[pos].name + "[Lv." + num_to_str(get_level(p[pos].score + add)) + ']' + '(' + num_to_str(p[pos].score + add) + ')';
					name(s);
					cout << "获得" << fe0 << "分" << endl;
					Add(fe0);
					fff[0] = true;
					p0c = -2;
				} else if (rp1 == 0) {
					int x = rp0 + rp2, y;
					x /= 2;
					if (x < 1)	x = 1;
					if (x > 11)	x = 11;
					y = rand() % 9 + 1;
					add = fe1 = x * y * 2;
					name1(pc1);
					cout << "获得" << fe1 << "分" << endl;
					fff[1] = true;
					p1c = -2;
				} else if (rp2 == 0) {
					int x = rp1 + rp2, y;
					x /= 2;
					if (x < 1)	x = 1;
					if (x > 11)	x = 11;
					y = rand() % 9 + 1;
					add = fe2 = x * y * 2;
					name2(pc2);
					cout << "获得" << fe2 << "分" << endl;
					fff[2] = true;
					p2c = -2;
				}
			}
			num++; 
		}
		if (final == 0) {
			fe0 = add / 2;
			s = p[pos].name + "[Lv." + num_to_str(get_level(p[pos].score + fe0)) + ']' + '(' + num_to_str(p[pos].score + fe0) + ')';
			name(s), cout << "获得" << fe0 << "分" << endl;
			Add(fe0);
			p0c = -2; 
		}
		else if (final == 1)
			fe1 = add / 2, name1(pc1), cout << "获得" << fe1 << "分" << endl, p1c = -2;
		else if (final == 2)
			fe2 = add / 2, name2(pc2), cout << "获得" << fe2 << "分" << endl, p2c = -2;
		putline(); cout << "游戏结果" << endl; name(s);
		if (fe0 == 0)	cout << " 毛驴";
		else	cout << " +" << fe0;
		cout << endl; name1(pc1);
		if (fe1 == 0)	cout << " 毛驴";
		else	cout << " +" << fe1;
		cout << endl; name2(pc2);
		if (fe2 == 0)	cout << " 毛驴";
		else	cout << " +" << fe2;
		cout << endl;
		if (get_level(p[pos].score) != _level)	cout << "恭喜升级：Lv." << get_level(p[pos].score) << "！\n";
		else if (get_level(p[pos].score) < 38)	cout << "距离下次升级还需要" << lv[_level + 1] - p[pos].score << "分\n";
		else	cout << "已满级，累计获得" << p[pos].score << "分\n";
		cout << "是否继续游戏？[y/n] ";
		char abcdefg; cin >> abcdefg;
		if (abcdefg != 'Y' && abcdefg != 'y')	break;
		system("cls");
	}
	return 0;
}
